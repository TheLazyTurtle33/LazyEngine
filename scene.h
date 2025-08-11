//
// Created by jro03 on 2025/08/11.
//

#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Module.h"


namespace LazyEngine {
class scene {
    public:
        void init();
        void update();
        void render();
        void destroy();

    private:
        std::vector<LazyEngine::Module> m_all_modules;
        // LazyEngine::Engine m_engine;
        std::vector<LazyEngine::Module*> m_root_modules;
        std::vector<LazyEngine::Module*> m_rendererable_modules;
};

} // LazyEngine

#endif //SCENE_H
