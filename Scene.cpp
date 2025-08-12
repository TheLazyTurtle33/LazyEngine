//
// Created by jro03 on 2025/08/11.
//

#include "Scene.h"

namespace LazyEngine {
    void Scene::start() {
        for (auto &module : m_root_modules) {
            module->start();
        }
    }

    void Scene::update(double deltaT) {
        for (auto &module : m_root_modules) {
            module->update(deltaT);
        }
    }

    // void Scene::render() {
    // }

    void Scene::destroy() {

    }

    void Scene::addRootModule(LazyEngine::Module *module) {
        m_root_modules.push_back(module);
    }

    std::vector<render::renderObject> Scene::getRenderObjects() const {
        std::vector<render::renderObject> objects;
        for (auto &modules : m_root_modules) {
            std::vector<render::renderObject> objs = modules->getRenderObjects();
            objects.insert(objects.end(), objs.begin(), objs.end());
        }
        return objects;
    }
} // LazyEngine