//
// Created by jro03 on 2025/08/11.
//

#include "Colour.h"

#include <cmath>

namespace Colour {
    Colour::Colour(float r, float g, float b, float a) {
        this->r = std::floor(r*255);
        this->g = std::floor(g*255);
        this->b = std::floor(b*255);
        this->a = std::floor(a*255);
    }

    Colour::Colour(int r, int g, int b, int a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    Colour::Colour(const float *rgba) {
        this->r = std::floor(rgba[0]*255);
        this->g = std::floor(rgba[1]*255);
        this->b = std::floor(rgba[2]*255);
        this->a = std::floor(rgba[3]*255);
    }

    Colour::Colour(const int *rgba) {
        this->r = rgba[0];
        this->g = rgba[1];
        this->b = rgba[2];
        this->a = rgba[3];
    }

    Colour::Colour(const float *rgb, float a) {
        this->r = std::floor(rgb[0]*255);
        this->g = std::floor(rgb[1]*255);
        this->b = std::floor(rgb[2]*255);
        this->a = std::floor(a*255);
    }

    Colour::Colour(const int *rgb, int a) {
        this->r = rgb[0];
        this->g = rgb[1];
        this->b = rgb[2];
        this->a = a;
    }

    Colour::Colour(int hex) {
        this->r = (hex >> 16) & 0xFF;
        this->g = (hex >> 8) & 0xFF;
        this->b = hex & 0xFF;
        this->a = 255;
    }

    std::array<float,4> Colour::getRGBAIntensity() const {
        std::array<float, 4> rgba{};
        rgba[0] = r/255.0f;
        rgba[1] = g/255.0f;
        rgba[2] = b/255.0f;
        rgba[3] = a/255.0f;
        return rgba;
    }
} // render