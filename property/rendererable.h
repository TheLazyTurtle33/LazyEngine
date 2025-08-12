//
// Created by jro03 on 2025/08/11.
//

#ifndef RENDERERABLE_H
#define RENDERERABLE_H
#include <utility>

#include "property.h"
#include "transform.h"
#include "../render/Shape.h"

namespace property {

class rendererable : public Property {

public:
    rendererable();
    explicit rendererable(Shape::Shape shape) : m_shape(std::move(shape)){};
    explicit rendererable(Shape::Shape shape, Colour::Colour colour);
    // void start();
    // void update(int deltaT);
    // void destroy();

    void setParent(LazyEngine::Module *parent) override;

    void setShape(Shape::Shape shape);
    void setShape(std::vector<LEMath::Vector2> verts, std::vector<unsigned int> inds);
    void setTransform(Transform2D *transform);

    [[nodiscard]] Shape::Shape getShapeTransformed() const;



private:
    Transform2D *m_transform = nullptr;
    std::vector<LEMath::Vector2> vertices; // x, y, z
    std::vector<unsigned int> indices;
    Shape::Shape m_shape;

};

} // property

#endif //RENDERERABLE_H
