#include "Engine.h"
#include <iostream>
#include <chrono>

#include "property/rendererable.h"
#include "property/transform.h"


namespace LazyEngine{


    Engine::Engine() = default;

    void Engine::stop() {
        m_renderer.destroy();
    };

    void Engine::addUpdateFunc(void (*func)(double deltaT)) {
        m_update_game = func;
    }

    void Engine::update() {
        using clock = std::chrono::high_resolution_clock;
        auto lastTime = clock::now();

        while (true) {
            auto currentTime = clock::now();
            std::chrono::duration<double> elapsed = currentTime - lastTime;
            lastTime = currentTime;

            const double deltaT = elapsed.count(); // seconds as double

            if (m_update_game != nullptr) {
                m_update_game(deltaT);
            }
            m_currentScene.update(deltaT);

            m_renderer.clear(BGColour);
            m_renderer.render(m_currentScene.getRenderObjects());


            if (m_renderer.shouldClose()) {
                stop();
                return;
            }

        }

    }

    void Engine::start(const int width, const int height,const char* title) {
        m_renderer.start(width, height, title);
        m_currentScene.start();

        update();
    }

}
