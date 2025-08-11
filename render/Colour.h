//
// Created by jro03 on 2025/08/11.
//

#ifndef COLOUR_H
#define COLOUR_H

#include <array>
namespace Colour {

class Colour {
    public:
    int r, g, b, a;
    Colour(float r, float g, float b, float a = 1.0f);
    Colour(int r, int g, int b, int a = 255);
    explicit Colour(const float* rgba);
    explicit Colour(const int* rgba);
    explicit Colour(const float* rgb, float a = 1.0f);
    explicit Colour(const int* rgb, int a = 255);
    // explicit Colour(const char* hex);
    explicit Colour(int hex);

    std::array<float,4> getRGBAIntensity() const;
};



    constexpr auto White = Colour(1.0f, 1.0f, 1.0f);
    constexpr auto Black = Colour(0.0f, 0.0f, 0.0f);
    constexpr auto Red = Colour(1.0f, 0.0f, 0.0f);
    constexpr auto Green = Colour(0.0f, 1.0f, 0.0f);
    constexpr auto Blue = Colour(0.0f, 0.0f, 1.0f);
    constexpr auto Yellow = Colour(1.0f, 1.0f, 0.0f);
    constexpr auto Cyan = Colour(0.0f, 1.0f, 1.0f);
    constexpr auto Magenta = Colour(1.0f, 0.0f, 1.0f);
    constexpr auto Orange = Colour(1.0f, 0.5f, 0.0f);
    constexpr auto Purple = Colour(0.5f, 0.0f, 0.5f);
    constexpr auto Pink = Colour(1.0f, 0.0f, 0.5f);

} // render

#endif //COLOUR_H
