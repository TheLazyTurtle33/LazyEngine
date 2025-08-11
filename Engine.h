#ifndef LAZYENGINE_LIBRARY_H
#define LAZYENGINE_LIBRARY_H
#pragma once

#include "scene.h"
#include "render/renderer.h"

namespace LazyEngine {
    class scene;
    class Engine {
    public:

    public:
        Engine();
        ~Engine() {
            stop();
        }

        void start(int width, int height,const char* title);
        static void stop();

        void addUpdateFunc(void (*func)(double deltaT));

    private:
        scene currentScene;
        render::renderer m_renderer;
        void (*m_update_game)(double deltaT) = nullptr;

    private:
        void update();
    };

} // namespace LazyEngine

#endif // LAZYENGINE_LIBRARY_H