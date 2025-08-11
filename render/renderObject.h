//
// Created by jro03 on 2025/08/11.
//

#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <vector>

#include "Colour.h"

namespace render {

class renderObject {
public:
    std::vector<float> vertices; // x, y, z
    std::vector<unsigned int> indices;
    Colour::Colour colour{Colour::Black};
    renderObject() = default;
    renderObject(std::vector<float> verts, std::vector<unsigned int> inds, Colour::Colour col)
        : vertices(std::move(verts)), indices(std::move(inds)), colour(col) {}
};

} // render

#endif //RENDEROBJECT_H
