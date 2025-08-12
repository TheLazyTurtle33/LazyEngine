//
// Created by jro03 on 2025/08/11.
//

#include "rendererable.h"

#include <utility>

#ifndef WORLD_SCALE
#define WORLD_SCALE 100.0f
#endif


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
        std::vector<LEMath::Vector2> transformedVerts;
        transformedVerts.reserve(m_shape.vertices.size());

        const auto worldPos     = m_transform->getWorldPosition();
        const auto worldScale   = m_transform->getWorldScale() * WORLD_SCALE;
        const float worldRotRad = m_transform->getRotationR(); // radians

        for (auto v : m_shape.vertices) {
            v *= worldScale;                 // scale
            v = v.rotatePoint(worldRotRad); // rotate
            v += worldPos;                   // translate
            transformedVerts.push_back(v);
        }

        Shape::Shape result(transformedVerts, m_shape.indices);
        result.colour = m_shape.colour;
        return result;
    }
} // property