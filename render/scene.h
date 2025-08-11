//
// Created by jro03 on 2025/08/11.
//

#ifndef SCENE_H
#define SCENE_H

#include "../Engine.h"

class scene {

    public:
    void init();
    void update();
    void render();
    void destroy();

    private:
    std::pmr::vector<LazyEngine::Module> m_all_modules;
    LazyEngine::Engine m_engine;
    std::pmr::vector<std::unique_ptr<LazyEngine::Module>> m_root_modules;
    std::pmr::vector<std::unique_ptr<LazyEngine::Module>> m_rendererable_modules;





};



#endif //SCENE_H
