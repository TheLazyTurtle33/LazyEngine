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

        // Mark constructors constexpr
        constexpr Colour(float r, float g, float b, float a = 1.0f)
            : r(static_cast<int>(r * 255)), g(static_cast<int>(g * 255)),
              b(static_cast<int>(b * 255)), a(static_cast<int>(a * 255)) {}

        constexpr Colour(int r, int g, int b, int a = 255)
            : r(r), g(g), b(b), a(a) {}

        constexpr explicit Colour(int hex)
            : r((hex >> 16) & 0xFF),
              g((hex >> 8) & 0xFF),
              b(hex & 0xFF),
              a(255) {}

        constexpr std::array<float,4> getRGBAIntensity() const {
            return { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f };
        }
    };

    // Now constexpr variables will work
    constexpr Colour White   = Colour(1.0f, 1.0f, 1.0f);
    constexpr Colour Black   = Colour(0.0f, 0.0f, 0.0f);
    constexpr Colour Red     = Colour(1.0f, 0.0f, 0.0f);
    constexpr Colour Green   = Colour(0.0f, 1.0f, 0.0f);
    constexpr Colour Blue    = Colour(0.0f, 0.0f, 1.0f);

} // namespace Colour

#endif //COLOUR_H
