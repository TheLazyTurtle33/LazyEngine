//
// Created by jro03 on 2025/08/11.
//

#ifndef MODULE_H
#define MODULE_H

#include <vector>
#include <memory>
#include <type_traits>
#include <cstddef>
#include <algorithm>

#include "property/property.h"

namespace render {
    class renderObject;
}

namespace property {
    class Property;
}
namespace LazyEngine {

    class Module {
    public:
        explicit Module(const std::string& name = "");
        ~Module();

        const std::string& getName() const noexcept;

    public:
        void start();
        void update(int deltaT);

    template <typename T, typename... Args>
    T* addProperty(Args&&... args) {
        static_assert(std::is_base_of<property::Property, T>::value,
                      "T must derive from property::Property");
        auto prop = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = prop.get();
        prop->setParent(this);
        m_properties.emplace_back(std::move(prop));
        return ptr;
    }

    template <typename T>
    void removeProperty() {
        static_assert(std::is_base_of<property::Property, T>::value,
                      "T must derive from property::Property");
        m_properties.erase(
            std::remove_if(m_properties.begin(), m_properties.end(),
                [](const std::unique_ptr<property::Property>& p) {
                    return dynamic_cast<T*>(p.get()) != nullptr;
                }),
            m_properties.end()
        );
    }

    template <typename T>
    std::vector<T*> getPropertyAll() const {
        static_assert(std::is_base_of<property::Property, T>::value,
                      "T must derive from property::Property");
        std::vector<T*> result;
        for (auto& p : m_properties) {
            if (auto casted = dynamic_cast<T*>(p.get())) {
                result.push_back(casted);
            }
        }
        return result;
    }

    template <typename T>
    T* getProperty(size_t index = 0) const {
        static_assert(std::is_base_of<property::Property, T>::value,
                      "T must derive from property::Property");
        size_t count = 0;
        for (auto& p : m_properties) {
            if (auto casted = dynamic_cast<T*>(p.get())) {
                if (count++ == index) return casted;
            }
        }
        return nullptr;
    }

    template <typename T>
    T* getPropertyLast() const {
        static_assert(std::is_base_of<property::Property, T>::value,
                      "T must derive from property::Property");
        for (auto it = m_properties.rbegin(); it != m_properties.rend(); ++it) {
            if (auto casted = dynamic_cast<T*>(it->get())) {
                return casted;
            }
        }
        return nullptr;
    }

        // Add a child entity
        void addChild(std::unique_ptr<Module> module);
        void removeChild(std::unique_ptr<Module> module);
        void removeChild(int index);
        void removeChild(const char* name);
        void removeChild(const std::string& name);

        std::vector<render::renderObject> getRenderObjects() const;

    private:
        std::string m_name;
        std::vector<std::unique_ptr<property::Property>> m_properties;
        std::vector<std::unique_ptr<Module>> m_children;

    };

} // LazyEngine

#endif //MODULE_H
