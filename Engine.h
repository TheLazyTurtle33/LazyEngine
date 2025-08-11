#ifndef LAZYENGINE_LIBRARY_H
#define LAZYENGINE_LIBRARY_H

#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>

#include "property/property.h"
#include "render/scene.h"

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
        T* getProperty();

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

    private:
        std::string m_name;
        std::unordered_map<std::type_index, std::unique_ptr<property::Property>> m_properties;
        std::vector<std::unique_ptr<Module>> m_children;

    };

    class Engine {
    public:

    public:
        Engine();
        ~Engine() {
            stop();
        }


        static void start(int width, int height,const char* title);
        static void stop();



        void addUpdateFunc(void (*func)(int deltaT));

    private:
        scene currentScene;
        void (*m_update_game)(int deltaT) = nullptr;

    private:
        void update();
    };

} // namespace LazyEngine

#endif // LAZYENGINE_LIBRARY_H