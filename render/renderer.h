//
// Created by jro03 on 2025/08/11.
//

#ifndef RENDERER_H
#define RENDERER_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace render {

class renderer {
public:
    bool init(int width, int height, const char* title);
    void render();
    void destroy();

private:
    GLFWwindow* m_window = nullptr;
    unsigned int m_vao = 0;
    unsigned int m_vbo = 0;
    unsigned int m_shaderProgram = 0;

    unsigned int compileShader(unsigned int type, const char* source);

};

} // render

#endif //RENDERER_H
