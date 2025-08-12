//
// Created by jro03 on 2025/08/11.
//

#ifndef MODULE_H
#define MODULE_H

#include <vector>
#include <memory>
#include <type_traits>
#include <cstddef>

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
        T* addProperty(Args&&... args);

        template <typename T>
        void removeProperty();

        template <typename T>
        std::vector<T*> getPropertyAll() const;

        template <typename T>
        T* getProperty(size_t index = 0) const;

        template <typename T>
        T* getPropertyLast() const;

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
