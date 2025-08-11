cmake_minimum_required(VERSION 3.31)
project(LazyEngine)

set(CMAKE_CXX_STANDARD 20)


include(FetchContent)

# GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG latest
)
FetchContent_MakeAvailable(glfw)

# GLAD
FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG master
)
FetchContent_MakeAvailable(glad)



add_library(LazyEngine STATIC Engine.cpp
        property/property.h
        property/transform.cpp
        property/transform.h
        math/math.cpp
        math/math.h
        math/vector.cpp
        math/vector.h
        property/rendererable.cpp
        property/rendererable.h
        property/property.cpp
        math/consts.h
        scene.cpp
        scene.h
        render/renderer.cpp
        render/renderer.h
        Module.cpp
        Module.h
        render/renderObject.cpp
        render/renderObject.h
        render/colour.cpp
        render/colour.h
)
target_link_libraries(LazyEngine PRIVATE glfw glad)
