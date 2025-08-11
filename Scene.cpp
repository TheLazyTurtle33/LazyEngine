//
// Created by jro03 on 2025/08/11.
//

#include "Scene.h"

namespace LazyEngine {
    void Scene::init() {
    }

    void Scene::update() {
    }

    void Scene::render() {
    }

    void Scene::destroy() {
    }

    void Scene::addRootModule(LazyEngine::Module *module) {
        m_root_modules.push_back(module);
    }

    std::vector<render::renderObject> Scene::getRenderObjects() const {
        std::vector<render::renderObject> objects;
        for (auto &modules : m_root_modules) {
            objects.insert(objects.end(), modules->getRenderObjects().begin(), modules->getRenderObjects().end());
        }
        return objects;
    }
} // LazyEngine