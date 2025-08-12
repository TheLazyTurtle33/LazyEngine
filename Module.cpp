//
// Created by jro03 on 2025/08/11.
//
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>
#include "Module.h"

#include "property/rendererable.h"
#include "render/renderObject.h"

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

    std::vector<render::renderObject> Module::getRenderObjects() const {
        std::vector<render::renderObject> objects;
        if (auto* r = getProperty<property::rendererable>()) {
                // use existing
            const render::renderObject object{r->getShapeTransformed()};
            objects.push_back(object);
        }
        for (auto &child : m_children) {
            objects.insert(objects.end(), child->getRenderObjects().begin(), child->getRenderObjects().end());
        }
        return objects;
    }


    void Module::start() {
        for (auto &child : m_children) {
            child->start();
        }
        for (auto &property : m_properties) {
            property->start();
        }
    }

    void Module::update(int deltaT) {
        for (auto &child : m_children) {
            child->update(deltaT);
        }
        for (auto &property : m_properties) {
            property->update(deltaT);
        }
    }

} // LazyEngine