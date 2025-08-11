#include "Engine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>


namespace LazyEngine{


    Engine::Engine() = default;

    void Engine::stop() {
        glfwTerminate();
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

            m_update_game(deltaT);



            glfwPollEvents();

            if (glfwWindowShouldClose(glfwGetCurrentContext())) {
                stop();
                return;
            }

        }

    }

    void Engine::start(const int width, const int height,const char* title) {
       m_renderer.init(width, height, title);

    }

}
