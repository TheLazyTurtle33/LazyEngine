//
// Created by jro03 on 2025/08/10.
//

#include "transform.h"

#include <cmath>

#include "property.h"

property::Transform2D::Transform2D() = default;

property::Transform2D::Transform2D(const LEMath::Vector2 &position, const LEMath::Vector2 &scale, float rotation) {
    this->position = position;
    this->scale = scale;
    this->rotation = rotation;
}

// property::Transform2D::~Transform2D() = default;
//
// void property::Transform2D::start() {
//     return;
// }
//
// void property::Transform2D::update(double deltaT) {
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

void property::Transform2D::translate(const LEMath::Vector2 &translation) {
    position += translation;
}

void property::Transform2D::translate(float x, float y) {
    position += LEMath::Vector2(x, y);
}

void property::Transform2D::translate(int x, int y) {
    position += LEMath::Vector2(static_cast<float>(x), static_cast<float>(y));
}

void property::Transform2D::translate(const Transform2D &translation) {
    position += translation.position;
}

void property::Transform2D::translate(const Transform2D *translation) {
    position += translation->position;
}

void property::Transform2D::rotate(int degrees) {
    rotation += degrees;
    rotation = std::fmod(rotation ,360.f);
    if (rotation < 0) {
        rotation += 360.f;
    }
}

void property::Transform2D::rotate(float degrees) {
    rotation += degrees;
    rotation = std::fmod(rotation ,360.f);
    if (rotation < 0) {
        rotation += 360.f;
    }
}

void property::Transform2D::rotateR(int radians) {
    rotation += static_cast<float>(radians*(180.f/LEMath::PI));
    rotation = std::fmod(rotation ,360.f);
    if (rotation < 0) {
        rotation += 360.f;
    }
}

void property::Transform2D::rotateR(float radians) {
    rotation += static_cast<float>(radians*(180.f/LEMath::PI));
    rotation = std::fmod(rotation ,360.f);
    if (rotation < 0) {
        rotation += 360.f;
    }
}

void property::Transform2D::scaleUp(const LEMath::Vector2 &scale) {
    this->scale *= scale;
}

void property::Transform2D::scaleUp(const float x, const float y) {
    this->scale *= LEMath::Vector2(x, y);
}

void property::Transform2D::scaleUp(int x, int y) {
    this->scale *= LEMath::Vector2(static_cast<float>(x), static_cast<float>(y));
}

void property::Transform2D::scaleUp(float scale) {
    this->scale *= scale;
}

void property::Transform2D::scaleUp(int scale) {
    this->scale *= static_cast<float>(scale);
}


LEMath::Vector2 property::Transform2D::getPosition() const {
    return position;
}

LEMath::Vector2 property::Transform2D::getScale() const {
    return scale;
}

float property::Transform2D::getRotation() const {
    return rotation;
}

float property::Transform2D::getRotationR() const {
    return rotation*(LEMath::PI/180.f);
}

LEMath::Vector2 property::Transform2D::getRight() const {
    return {std::sin(rotation*(LEMath::PI/180.f)), -std::cos(rotation*(LEMath::PI/180.f))};
}

LEMath::Vector2 property::Transform2D::getUp() const {
    return {std::cos(rotation*(LEMath::PI/180.f)), std::sin(rotation*(LEMath::PI/180.f))};
}

LEMath::Vector2 property::Transform2D::getWorldPosition() const {
    return position;
}

LEMath::Vector2 property::Transform2D::getWorldScale() const {
    return scale;
}

float property::Transform2D::getWorldRotation() const {
    return rotation;
}

float property::Transform2D::getWorldRotationR() const {
    return rotation*(LEMath::PI/180.f);
}

LEMath::Vector2 property::Transform2D::getWorldForward() const {
    return {std::cos(rotation*(LEMath::PI/180.f)), std::sin(rotation*(LEMath::PI/180.f))};
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
    LEMath::Vector2 dir = target - position;
    float angle = std::atan2(dir.y, dir.x);
    rotation = static_cast<float>(angle*(180.f/LEMath::PI));
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
