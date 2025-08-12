//
// Created by jro03 on 2025/08/10.
//

#include "vector.h"

#include <cmath>

namespace LEMath {

#pragma region Vector2
    Vector2::Vector2(float x, float y) {
        this->x = x;
        this->y = y;

    }

    Vector2::~Vector2() = default;

    float Vector2::length() const {
        return std::sqrt(x * x + y * y);
    }

    float Vector2::lengthSquared() const {
        return x * x + y * y;
    }

    Vector2 Vector2::normalized() const {
        const float length = this->length();
        return {x / length, y / length};
    }

    Vector2 Vector2::operator+(const Vector2 &other) const {
        return {x + other.x, y + other.y};
    }

    Vector2 Vector2::operator-(const Vector2 &other) const {
        return {x - other.x, y - other.y};
    }

    Vector2 Vector2::operator*(const Vector2 &other) const {
        return {x * other.x, y * other.y};
    }

    Vector2 Vector2::operator/(const Vector2 &other) const {
        return {x / other.x, y / other.y};
    }

    Vector2 Vector2::operator*(const float scalar) const {
        return {x * scalar, y * scalar};
    }

    Vector2 Vector2::operator/(const float scalar) const {
        return {x / scalar, y / scalar};
    }

    Vector2 & Vector2::operator+=(const Vector2 &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2 & Vector2::operator-=(const Vector2 &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2 & Vector2::operator*=(const Vector2 &other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vector2 & Vector2::operator/=(const Vector2 &other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vector2& Vector2::operator*=(const float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2& Vector2::operator/=(const float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    Vector2 Vector2::rotatePoint(float radians) const {
        float cosA = std::cos(radians);
        float sinA = std::sin(radians);
        return {
            (x * cosA) - (y * sinA),
            (x * sinA) + (y * cosA)
        };

    }

#pragma endregion

#pragma region Vector2i
    Vector2i::Vector2i(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Vector2i::~Vector2i() = default;

    int Vector2i::length() const {
        return floor((std::sqrt(x * x + y * y)));
    }

    int Vector2i::lengthSquared() const {
        return x * x + y * y;
    }

    Vector2i Vector2i::normalized() const {
        const int length = this->length();
        return {x / length, y / length};
    }

    Vector2i Vector2i::operator+(const Vector2i &other) const {
        return {x + other.x, y + other.y};
    }

    Vector2i Vector2i::operator-(const Vector2i &other) const {
        return {x - other.x, y - other.y};
    }

    Vector2i Vector2i::operator*(const Vector2i &other) const {
        return {x * other.x, y * other.y};
    }

    Vector2i Vector2i::operator/(const Vector2i &other) const {
        return {x / other.x, y / other.y};
    }

    Vector2i Vector2i::operator*(const int scalar) const {
        return {x * scalar, y * scalar};
    }

    Vector2i Vector2i::operator/(const int scalar) const {
        return {x / scalar, y / scalar};
    }

    Vector2i & Vector2i::operator+=(const Vector2i &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2i & Vector2i::operator-=(const Vector2i &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2i & Vector2i::operator*=(const Vector2i &other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vector2i & Vector2i::operator/=(const Vector2i &other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vector2i& Vector2i::operator*=(const int scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2i& Vector2i::operator/=(const int scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }
#pragma endregion

#pragma region Vector3
    Vector3::Vector3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3::~Vector3() = default;

    float Vector3::length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    float Vector3::lengthSquared() const {
        return x * x + y * y + z * z;
    }

    Vector3 Vector3::normalized() const {
        const float length = this->length();
        return {x / length, y / length, z / length};
    }

    Vector3 Vector3::operator+(const Vector3 &other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3 Vector3::operator-(const Vector3 &other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3 Vector3::operator*(const Vector3 &other) const {
        return {x * other.x, y * other.y, z * other.z};
    }

    Vector3 Vector3::operator/(const Vector3 &other) const {
        return {x / other.x, y / other.y, z / other.z};
    }

    Vector3 Vector3::operator*(const float scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    Vector3 Vector3::operator/(const float scalar) const {
        return {x / scalar, y / scalar, z / scalar};
    }

    Vector3 & Vector3::operator+=(const Vector3 &other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3 & Vector3::operator-=(const Vector3 &other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3 & Vector3::operator*=(const Vector3 &other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    Vector3 & Vector3::operator/=(const Vector3 &other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    Vector3 Vector3::operator*=(const float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vector3 Vector3::operator/=(const float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }
#pragma endregion

#pragma region Vector3i
    Vector3i::Vector3i(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3i::~Vector3i() = default;

    int Vector3i::length() const {
        return floor(std::sqrt(x * x + y * y + z * z));
    }

    int Vector3i::lengthSquared() const {
        return x * x + y * y + z * z;
    }

    Vector3i Vector3i::normalized() const {
        const int length = this->length();
        return {x / length, y / length, z / length};
    }

    Vector3i Vector3i::operator+(const Vector3i &other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3i Vector3i::operator-(const Vector3i &other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3i Vector3i::operator*(const Vector3i &other) const {
        return {x * other.x, y * other.y, z * other.z};
    }

    Vector3i Vector3i::operator/(const Vector3i &other) const {
        return {x / other.x, y / other.y, z / other.z};
    }

    Vector3i Vector3i::operator*(const int scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    Vector3i Vector3i::operator/(const int scalar) const {
        return {x / scalar, y / scalar, z / scalar};
    }

    Vector3i & Vector3i::operator+=(const Vector3i &other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3i & Vector3i::operator-=(const Vector3i &other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3i & Vector3i::operator*=(const Vector3i &other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    Vector3i & Vector3i::operator/=(const Vector3i &other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    Vector3i& Vector3i::operator*=(const int scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vector3i& Vector3i::operator/=(const int scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

#pragma endregion

#pragma region Vector4
    Vector4::Vector4(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    Vector4::~Vector4() = default;

    float Vector4::length() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    float Vector4::lengthSquared() const {
        return x * x + y * y + z * z + w * w;
    }

    Vector4 Vector4::normalized() const {
        const float length = this->length();
        return {x / length, y / length, z / length, w / length};
    }

    Vector4 Vector4::operator+(const Vector4 &other) const {
        return {x + other.x, y + other.y, z + other.z, w + other.w};
    }

    Vector4 Vector4::operator-(const Vector4 &other) const {
        return {x - other.x, y - other.y, z - other.z, w - other.w};
    }

    Vector4 Vector4::operator*(const Vector4 &other) const {
        return {x * other.x, y * other.y, z * other.z, w * other.w};
    }

    Vector4 Vector4::operator/(const Vector4 &other) const {
        return {x / other.x, y / other.y, z / other.z, w / other.w};
    }

    Vector4 Vector4::operator*(float scalar) const {
        return {x * scalar, y * scalar, z * scalar, w * scalar};
    }

    Vector4 Vector4::operator/(float scalar) const {
        return {x / scalar, y / scalar, z / scalar, w / scalar};
    }

    Vector4 & Vector4::operator+=(const Vector4 &other) {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    Vector4 & Vector4::operator-=(const Vector4 &other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    Vector4 & Vector4::operator*=(const Vector4 &other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
        return *this;
    }

    Vector4 & Vector4::operator/=(const Vector4 &other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        w /= other.w;
        return *this;
    }

    Vector4& Vector4::operator*=(const float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    Vector4& Vector4::operator/=(const float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }
#pragma endregion

#pragma region Vector4i
        Vector4i::Vector4i(int x, int y, int z, int w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    Vector4i::~Vector4i() = default;

    int Vector4i::length() const {
        return floor(std::sqrt(x * x + y * y + z * z + w * w));
    }

    int Vector4i::lengthSquared() const {
        return x * x + y * y + z * z + w * w;
    }

    Vector4i Vector4i::normalized() const {
        const int length = this->length();
        return {x / length, y / length, z / length, w / length};
    }

    Vector4i Vector4i::operator+(const Vector4i &other) const {
        return {x + other.x, y + other.y, z + other.z, w + other.w};
    }

    Vector4i Vector4i::operator-(const Vector4i &other) const {
        return {x - other.x, y - other.y, z - other.z, w - other.w};
    }

    Vector4i Vector4i::operator*(const Vector4i &other) const {
        return {x * other.x, y * other.y, z * other.z, w * other.w};
    }

    Vector4i Vector4i::operator/(const Vector4i &other) const {
        return {x / other.x, y / other.y, z / other.z, w / other.w};
    }

    Vector4i Vector4i::operator*(int scalar) const {
        return {x * scalar, y * scalar, z * scalar, w * scalar};
    }

    Vector4i Vector4i::operator/(int scalar) const {
        return {x / scalar, y / scalar, z / scalar, w / scalar};
    }

    Vector4i & Vector4i::operator+=(const Vector4i &other) {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    Vector4i & Vector4i::operator-=(const Vector4i &other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    Vector4i & Vector4i::operator*=(const Vector4i &other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
        return *this;
    }

    Vector4i & Vector4i::operator/=(const Vector4i &other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        w /= other.w;
        return *this;
    }

    Vector4i & Vector4i::operator*=(const int scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    Vector4i& Vector4i::operator/=(const int scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }
#pragma endregion
} // LEMath