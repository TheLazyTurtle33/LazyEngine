//
// Created by jro03 on 2025/08/11.
//

#include "renderer.h"

namespace render {
    // Shaders with uniform color
static const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos, 1.0);
    }
)";

static const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    uniform vec4 uColor;
    void main() {
        FragColor = uColor;
    }
)";
// Shader compiler helper
    unsigned int renderer::compileShader(unsigned int type, const char* source) {
        unsigned int shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "Shader compile error: " << infoLog << "\n";
        }
        return shader;
    }

    void renderer::resize(int width, int height) {
        m_windowSize = {width,height};
        glViewport(0, 0, width, height);
    }

    bool renderer::start(int width, int height, const char* title) {
        m_windowSize = {width,height};
        if (!glfwInit()) {
            std::cerr << "Failed to start GLFW\n";
            return false;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!m_window) {
            std::cerr << "Failed to create GLFW window\n";
            glfwTerminate();
            return false;
        }
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, this);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to start GLAD\n";
            return false;
        }
        glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
        // Compile shaders
        unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
        unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

        m_shaderProgram = glCreateProgram();
        glAttachShader(m_shaderProgram, vertexShader);
        glAttachShader(m_shaderProgram, fragmentShader);
        glLinkProgram(m_shaderProgram);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return true;
    }

    void renderer::clear() {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void renderer::clear(Colour::Colour colour) {
        auto rgba = colour.getRGBAIntensity();
        glClearColor(rgba[0], rgba[1], rgba[2], rgba[3]);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void renderer::draw(const renderObject& object) {
        renderObject obj = toNDC(object,m_windowSize);
        unsigned int vao, vbo, ebo;

        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, obj.vertices.size() * sizeof(float), obj.vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, obj.indices.size() * sizeof(unsigned int), obj.indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glUseProgram(m_shaderProgram);

        auto rgba = obj.colour.getRGBAIntensity();
        int colorLoc = glGetUniformLocation(m_shaderProgram, "uColor");
        glUniform4f(colorLoc, rgba[0], rgba[1], rgba[2], rgba[3]);

        glDrawElements(GL_TRIANGLES, obj.indices.size(), GL_UNSIGNED_INT, 0);

        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
    }

    void renderer::render(const std::vector<renderObject>& objects) {
        for (const auto& obj : objects) {
            draw(obj);
        }
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool renderer::shouldClose() const {
        return glfwWindowShouldClose(m_window);
    }

    void renderer::destroy() {
        glDeleteProgram(m_shaderProgram);
        if (m_window) {
            glfwDestroyWindow(m_window);
            m_window = nullptr;
        }
        glfwTerminate();
    }

    LEMath::Vector2 renderer::toNDC(const LEMath::Vector2& position,const LEMath::Vector2i& windowSize) {
        return {position.x / (windowSize.x/2.0f), position.y / (windowSize.y/2.0f)};
    }

    renderObject renderer::toNDC(renderObject objs, const LEMath::Vector2i &windowSize) {
        for (int i = 0; i < objs.vertices.size(); i+=3) {
            objs.vertices[i] = toNDC({objs.vertices[i],objs.vertices[i+1]},windowSize).x;
            objs.vertices[i+1] = toNDC({objs.vertices[i],objs.vertices[i+1]},windowSize).y;
            objs.vertices[i+2] = objs.vertices[i+2];
        }
        return objs;
    }
} // render