//
// Created by jro03 on 2025/08/10.
//

#include "transform.h"
#include "property.h"

property::Transform2D::Transform2D() = default;

// property::Transform2D::~Transform2D() = default;
//
// void property::Transform2D::start() {
//     return;
// }
//
// void property::Transform2D::update(int deltaT) {
//     return;
// }

void property::Transform2D::destroy() {
    m_parent->removeProperty<typename property::Transform2D>();
}

void property::Transform2D::setPosition(const LEMath::Vector2& position) {
    this->position = position;
}

void property::Transform2D::setScale(const LEMath::Vector2& scale) {
    this->scale = scale;
}

void property::Transform2D::setRotation(const float degrees) {
    this->rotation = degrees;
}

void property::Transform2D::setRotationR(const int radians) {
    rotation = static_cast<float>(radians*(180.f/LEMath::PI));

}

void property::Transform2D::setRotationR(const float radians) {
    rotation = static_cast<float>(radians*(180.f/LEMath::PI));
}

void property::Transform2D::setPosition(const float x, const float y) {
    position = LEMath::Vector2(x, y);
}

void property::Transform2D::setScale(const float x, const float y) {
    scale = LEMath::Vector2(x, y);
}

void property::Transform2D::setPosition(const int x, const int y) {
    position = LEMath::Vector2(static_cast<float>(x), static_cast<float>(y));
}

void property::Transform2D::setScale(const int x, const int y) {
    scale = LEMath::Vector2(static_cast<float>(x), static_cast<float>(y));
}

void property::Transform2D::setRotation(const int degrees) {
    this->rotation = static_cast<float>(degrees);
}

void property::Transform2D::setScale(const float scale) {
    this->scale = LEMath::Vector2(scale, scale);
}

void property::Transform2D::setScale(const int scale) {
    this->scale = LEMath::Vector2(static_cast<float>(scale), static_cast<float>(scale));
}

void property::Transform2D::lookAt(const LEMath::Vector2 &target) {
}

void property::Transform2D::lookAt(float x, float y) {
    lookAt(LEMath::Vector2(x, y));
}

void property::Transform2D::lookAt(int x, int y) {
    lookAt(LEMath::Vector2(static_cast<float>(x), static_cast<float>(y)));
}

void property::Transform2D::lookAt(const Transform2D &target) {
    lookAt(target.position);
}

void property::Transform2D::lookAt(const Transform2D *target) {
    lookAt(target->position);
}
