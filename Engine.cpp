#include "Engine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace LazyEngine{
    Engine::Engine() = default;

    Engine::~Engine() = default;

    void Engine::addUpdateFunc(void (*func)(int deltaT)) {
        m_update = func;
    }
    int start() {
        // Init GLFW
        if (!glfwInit()) {
            std::cerr << "Failed to init GLFW\n";
            return -1;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create window
        GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create GLFW window\n";
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);

        // Load OpenGL functions via GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to init GLAD\n";
            return -1;
        }

        glfwSetFramebufferSizeCallback(window, reinterpret_cast<GLFWframebuffersizefun>(glfwSetFramebufferSizeCallback));

        // Main loop
        while (!glfwWindowShouldClose(window)) {
            // Clear screen with color
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
        return 0;
    }

}
