//
// Created by jro03 on 2025/08/11.
//
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>
#include "Module.h"

namespace LazyEngine {
    Module::Module(const std::string &name) {
            m_name = name;
        };


    Module::~Module() = default;

    const std::string & Module::getName() const noexcept {
        return m_name;
    }

    void Module::addChild(std::unique_ptr<Module> module) {
        m_children.emplace_back(std::move(module));
    }

    void Module::removeChild(std::unique_ptr<Module> module) {
        for (auto it = m_children.begin(); it != m_children.end(); ++it) {
            if (*it == module) {
                m_children.erase(it);
                return;
            }
        }
    }

    void Module::removeChild(int index) {
        if (index < 0 || index >= m_children.size()) {
            return;
        }
        m_children.erase(m_children.begin() + index);
    }

    void Module::removeChild(const char *name) {
        for (auto it = m_children.begin(); it != m_children.end(); ++it) {
            if ((*it)->getName() == name) {
                m_children.erase(it);
                return;
            }
        }
    }

    void Module::removeChild(const std::string &name) {
        removeChild(name.c_str());
    }


    void Module::start() {
        for (auto &child : m_children) {
            child->start();
        }
        for (auto &property : m_properties) {
            property.second->start();
        }
    }

    void Module::update(int deltaT) {
        for (auto &child : m_children) {
            child->update(deltaT);
        }
        for (auto &property : m_properties) {
            property.second->update(deltaT);
        }
    }

    template<typename T, typename ... Args> requires std::derived_from<T, property::Property>
    T & Module::addProperty(Args &&...args) {
        const auto key = std::type_index(typeid(T));
        auto it = m_properties.find(key);
        if (it != m_properties.end()) {
            return *static_cast<T*>(it->second.get());
        }
        auto ptr = std::make_unique<T>(std::forward<Args>(args)...);
        T* raw = ptr.get();
        raw->setParent(this);
        m_properties.emplace(key, std::move(ptr));
        return *raw;
    }

    template<typename T> requires std::derived_from<T, property::Property>
    T* Module::getProperty() noexcept {
        const auto key = std::type_index(typeid(T));
        auto it = m_properties.find(key);
        return (it == m_properties.end()) ? nullptr : static_cast<T*>(it->second.get());
    }

    template<typename T> requires std::derived_from<T, property::Property>
    bool Module::hasProperty() const noexcept {
        return m_properties.contains(std::type_index(typeid(T)));
    }

    template<typename T> requires std::derived_from<T, property::Property>
    void Module::removeProperty() noexcept {
        m_properties.erase(std::type_index(typeid(T)));
    }


} // LazyEngine