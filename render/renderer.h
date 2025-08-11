//
// Created by jro03 on 2025/08/11.
//

#ifndef RENDERER_H
#define RENDERER_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "renderObject.h"
#include "../math/vector.h"

namespace render {

class renderer {
public:
    bool init(int width, int height, const char* title);
    void clear(); // defaults to black
    void clear(Colour::Colour colour);
    void draw(const renderObject& object);
    void render(const std::vector<renderObject>& objects);
    void destroy();
    [[nodiscard]] bool shouldClose() const;
    void resize(int width, int height);



private:
    GLFWwindow* m_window = nullptr;
    unsigned int m_shaderProgram = 0;

    unsigned int compileShader(unsigned int type, const char* source);


    LEMath::Vector2i m_windowSize = {0,0};
    static LEMath::Vector2 toNDC(const LEMath::Vector2& position,const LEMath::Vector2i& windowSize);
    static renderObject toNDC(renderObject objs ,const LEMath::Vector2i& windowSize);


    static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        renderer* self = static_cast<renderer*>(glfwGetWindowUserPointer(window));
        if (self) {
            self->resize(width, height);
        }
    }





};

} // render

#endif //RENDERER_H
