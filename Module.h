//
// Created by jro03 on 2025/08/11.
//

#ifndef MODULE_H
#define MODULE_H

#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>
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

        // Add or get a property of type T. If it already exists, returns the existing one.
        template <typename T, typename... Args>
        requires std::derived_from<T, property::Property>
        T& addProperty(Args&&... args);

        template <typename T>
        requires std::derived_from<T, property::Property>
        T* getProperty() noexcept;

        template <typename T>
        requires std::derived_from<T, property::Property>
        const T* getProperty() const noexcept;

        template <typename T>
        requires std::derived_from<T, property::Property>
        bool hasProperty() const noexcept;

        template <typename T>
        requires std::derived_from<T, property::Property>
        void removeProperty() noexcept;

        // Add a child entity
        void addChild(std::unique_ptr<Module> module);
        void removeChild(std::unique_ptr<Module> module);
        void removeChild(int index);
        void removeChild(const char* name);
        void removeChild(const std::string& name);

        std::vector<render::renderObject> getRenderObjects() const;

    private:
        std::string m_name;
        std::unordered_map<std::type_index, std::unique_ptr<property::Property>> m_properties;
        std::vector<std::unique_ptr<Module>> m_children;

    };

} // LazyEngine

#endif //MODULE_H
