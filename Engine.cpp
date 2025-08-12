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

           //  // Rectangle vertices & indices
           //  std::vector<float> verts = {
           //      200,  150, 0.0f, // top right
           //      200, -150, 0.0f, // bottom right
           //     -200, -150, 0.0f, // bottom left
           //     -200,  150, 0.0f  // top left
           //  };
           //  std::vector<float> verts2 = {
           //      0.4f,  0.4f, 0.0f, // top right
           //      0.4f, -0.4f, 0.0f, // bottom right
           //     -0.4f, -0.4f, 0.0f, // bottom left
           //     -0.4f,  0.4f, 0.0f  // top left
           // };
           //  std::vector<unsigned int> inds = {
           //      0, 1, 3,
           //      1, 2, 3
           //  };
           //
           //  render::renderObject rect(verts, inds, Colour::Red);
           //  render::renderObject rect2(verts2, inds, Colour::Blue);
           //
           //  std::vector<render::renderObject> objs = { rect, rect2 };


            m_update_game(deltaT);
            m_renderer.clear(BGColour);
            m_renderer.render(m_currentScene.getRenderObjects());


            if (m_renderer.shouldClose()) {
                stop();
                return;
            }

        }

    }

    void Engine::start(const int width, const int height,const char* title) {
        m_renderer.init(width, height, title);
        m_currentScene.init();

        update();
    }

}
