//
// Created by jro03 on 2025/08/11.
//

#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include "../math/vector.h"
#include "Colour.h"

namespace Shape {

class Shape {
    public:
    Shape(std::vector<LEMath::Vector2> verts, std::vector<unsigned int> inds)
        : vertices(std::move(verts)), indices(std::move(inds)) {}
    std::vector<LEMath::Vector2> vertices; // x, y, z
    std::vector<unsigned int> indices;
    Colour::Colour colour{Colour::Black};
};

    const Shape triangle = {
        {
            {0,150},
            {200,-150},
            {-200,-150}
        },
        {0,1,2}
    };


} // render

#endif //SHAPE_H
