//
// Created by jro03 on 2025/08/11.
//

#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Module.h"
#include "render/renderObject.h"

namespace LazyEngine {
class Scene {
    public:
        void start();
        void update(double deltaT);
        // void render();
        void destroy();

        void addRootModule(LazyEngine::Module* module);

        [[nodiscard]] std::vector<render::renderObject> getRenderObjects() const;


    private:
        std::vector<LazyEngine::Module*> m_root_modules;
};

} // LazyEngine

#endif //SCENE_H
