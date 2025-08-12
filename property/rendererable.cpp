//
// Created by jro03 on 2025/08/11.
//

#include "rendererable.h"

#include <utility>

namespace property {

    rendererable::rendererable(): m_shape(Shape::NULLShape) {
        m_shape = Shape::NULLShape;
    } ;

    rendererable::rendererable(Shape::Shape shape, const Colour::Colour colour): m_shape(std::move(shape)) {
        // m_shape = std::move(shape);
        m_shape.colour = colour;
    }

    void rendererable::setParent(LazyEngine::Module *parent) {
        Property::setParent(parent);
        m_transform = parent->getProperty<Transform2D>();
    }

    void rendererable::setShape(Shape::Shape shape) {
        m_shape = std::move(shape);
    }

    void rendererable::setShape(std::vector<LEMath::Vector2> verts, std::vector<unsigned int> inds) {
        m_shape.vertices = std::move(verts);
        m_shape.indices = std::move(inds);
    }

    void rendererable::setTransform(Transform2D *transform) {
        m_transform = transform;
    }

    Shape::Shape rendererable::getShapeTransformed() const {
        if (m_transform == nullptr) return m_shape;
        std::vector<LEMath::Vector2> transformedVerts;
        transformedVerts.reserve(m_shape.vertices.size());

        for (auto v : m_shape.vertices) {
            v *= m_transform->scale;      // scale
            v += m_transform->position;   // translate
            transformedVerts.push_back(v);
        }

        Shape::Shape result(transformedVerts, m_shape.indices);
        result.colour = m_shape.colour; // preserve colour
        return result;

    }
} // property