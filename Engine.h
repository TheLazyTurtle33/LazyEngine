#ifndef LAZYENGINE_LIBRARY_H
#define LAZYENGINE_LIBRARY_H

#include <memory>
#include <typeindex>
#include <unordered_map>

#include "property/property.h"

namespace LazyEngine {
    class Entity {
    public:
        void start();
        void update(int deltaT);

        // Add or get a property of type T. If it already exists, returns the existing one.
        template <typename T, typename... Args>
        requires std::derived_from<T, property::Property>
        T& addProperty(Args&&... args) {
            const auto key = std::type_index(typeid(T));
            auto it = m_properties.find(key);
            if (it != m_properties.end()) {
                return *static_cast<T*>(it->second.get());
            }
            auto ptr = std::make_unique<T>(std::forward<Args>(args)...);
            T* raw = ptr.get();
            m_properties.emplace(key, std::move(ptr));
            return *raw;
        }

        template <typename T>
        requires std::derived_from<T, property::Property>
        T* getProperty() noexcept {
            const auto key = std::type_index(typeid(T));
            auto it = m_properties.find(key);
            return (it == m_properties.end()) ? nullptr : static_cast<T*>(it->second.get());
        }

        template <typename T>
        requires std::derived_from<T, property::Property>
        const T* getProperty() const noexcept {
            const auto key = std::type_index(typeid(T));
            auto it = m_properties.find(key);
            return (it == m_properties.end()) ? nullptr : static_cast<const T*>(it->second.get());
        }

        template <typename T>
        requires std::derived_from<T, property::Property>
        bool hasProperty() const noexcept {
            return m_properties.contains(std::type_index(typeid(T)));
        }

        template <typename T>
        requires std::derived_from<T, property::Property>
        void removeProperty() noexcept {
            m_properties.erase(std::type_index(typeid(T)));
        }

    private:
        std::unordered_map<std::type_index, std::unique_ptr<property::Property>> m_properties;
    };

    class Engine {
    public:
        Engine();
        ~Engine();

        int start();

        void addUpdateFunc(void (*func)(int deltaT));

    private:
        void (*m_update)(int deltaT){};
    };

} // namespace LazyEngine

#endif // LAZYENGINE_LIBRARY_H