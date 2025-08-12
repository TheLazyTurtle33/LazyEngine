//
// Created by jro03 on 2025/08/11.
//

#include "rendererable.h"

#include <utility>

namespace property {
    rendererable::rendererable() = default;

    rendererable::rendererable(Shape::Shape shape, const Colour::Colour colour): m_shape(std::move(shape)) {
        m_shape = std::move(shape);
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

    Shape::Shape rendererable::getShape() const {
        if (m_transform == nullptr) return m_shape;
        Shape::Shape out(m_shape);
        out.vertices.clear();
        for (auto& v : m_shape.vertices) {
            out.vertices.push_back((v + m_transform->position)*m_transform->scale);
        }
        return out;

    }
} // property