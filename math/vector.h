//
// Created by jro03 on 2025/08/10.
//

#ifndef VECTOR_H
#define VECTOR_H

namespace LEMath {
    class Vector2 {
    public:
        float x, y;
    public:
        Vector2(float x, float y);
        ~Vector2();
        [[nodiscard]] float length() const;
        [[nodiscard]] float lengthSquared() const;
        [[nodiscard]] Vector2 normalized() const;
        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator*(const Vector2& other) const;
        Vector2 operator/(const Vector2& other) const;
        Vector2 operator*(float scalar) const;
        Vector2 operator/(float scalar) const;
        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        Vector2& operator*=(const Vector2& other);
        Vector2& operator/=(const Vector2& other);
        Vector2& operator*=(float scalar);
        Vector2& operator/=(float scalar);
        Vector2& rotatePoint(float radians);

    };

    class Vector2i {
    public:
        int x, y;
    public:
        Vector2i(int x, int y);
        ~Vector2i();
        [[nodiscard]] int length() const;
        [[nodiscard]] int lengthSquared() const;
        [[nodiscard]] Vector2i normalized() const;
        Vector2i operator+(const Vector2i& other) const;
        Vector2i operator-(const Vector2i& other) const;
        Vector2i operator*(const Vector2i& other) const;
        Vector2i operator/(const Vector2i& other) const;
        Vector2i operator*(int scalar) const;
        Vector2i operator/(int scalar) const;
        Vector2i& operator+=(const Vector2i& other);
        Vector2i& operator-=(const Vector2i& other);
        Vector2i& operator*=(const Vector2i& other);
        Vector2i& operator/=(const Vector2i& other);
        Vector2i& operator*=(int scalar);
        Vector2i& operator/=(int scalar);

    };

    class Vector3 {
    public:
        float x, y, z;
    public:
        Vector3(float x, float y, float z);
        ~Vector3();
        [[nodiscard]] float length() const;
        [[nodiscard]] float lengthSquared() const;
        [[nodiscard]] Vector3 normalized() const;
        Vector3 operator+(const Vector3& other) const;
        Vector3 operator-(const Vector3& other) const;
        Vector3 operator*(const Vector3& other) const;
        Vector3 operator/(const Vector3& other) const;
        Vector3 operator*(float scalar) const;
        Vector3 operator/(float scalar) const;
        Vector3& operator+=(const Vector3& other);
        Vector3& operator-=(const Vector3& other);
        Vector3& operator*=(const Vector3& other);
        Vector3& operator/=(const Vector3& other);
        Vector3 operator*=(float scalar);
        Vector3 operator/=(float scalar);


    };

    class Vector3i {
    public:
        int x, y, z;
    public:
        Vector3i(int x, int y, int z);
        ~Vector3i();
        [[nodiscard]] int length() const;
        [[nodiscard]] int lengthSquared() const;
        [[nodiscard]] Vector3i normalized() const;
        Vector3i operator+(const Vector3i& other) const;
        Vector3i operator-(const Vector3i& other) const;
        Vector3i operator*(const Vector3i& other) const;
        Vector3i operator/(const Vector3i& other) const;
        Vector3i operator*(int scalar) const;
        Vector3i operator/(int scalar) const;
        Vector3i& operator+=(const Vector3i& other);
        Vector3i& operator-=(const Vector3i& other);
        Vector3i& operator*=(const Vector3i& other);
        Vector3i& operator/=(const Vector3i& other);
        Vector3i& operator*=(int scalar);
        Vector3i& operator/=(int scalar);
    };

    class Vector4 {
    public:
        float x, y, z, w;
    public:
        Vector4(float x, float y, float z, float w);
        ~Vector4();
        [[nodiscard]] float length() const;
        [[nodiscard]] float lengthSquared() const;
        [[nodiscard]] Vector4 normalized() const;
        Vector4 operator+(const Vector4& other) const;
        Vector4 operator-(const Vector4& other) const;
        Vector4 operator*(const Vector4& other) const;
        Vector4 operator/(const Vector4& other) const;
        Vector4 operator*(float scalar) const;
        Vector4 operator/(float scalar) const;
        Vector4& operator+=(const Vector4& other);
        Vector4& operator-=(const Vector4& other);
        Vector4& operator*=(const Vector4& other);
        Vector4& operator/=(const Vector4& other);
        Vector4& operator*=(float scalar);
        Vector4& operator/=(float scalar);
    };

    class Vector4i {
    public:
        int x, y, z, w;
    public:
        Vector4i(int x, int y, int z, int w);
        ~Vector4i();
        [[nodiscard]] int length() const;
        [[nodiscard]] int lengthSquared() const;
        [[nodiscard]] Vector4i normalized() const;
        Vector4i operator+(const Vector4i& other) const;
        Vector4i operator-(const Vector4i& other) const;
        Vector4i operator*(const Vector4i& other) const;
        Vector4i operator/(const Vector4i& other) const;
        Vector4i operator*(int scalar) const;
        Vector4i operator/(int scalar) const;
        Vector4i& operator+=(const Vector4i& other);
        Vector4i& operator-=(const Vector4i& other);
        Vector4i& operator*=(const Vector4i& other);
        Vector4i& operator/=(const Vector4i& other);
        Vector4i& operator*=(int scalar);
        Vector4i& operator/=(int scalar);
    };


    // To be implemented
    class Quaternion {
    public:
        float x, y, z, w;
    };

    // To be implemented
    class Matrix4x4 {
    public:
        Vector4 x, y, z, w;
    public:
        Matrix4x4(Vector4 x, Vector4 y, Vector4 z, Vector4 w);
        ~Matrix4x4();
    };

    // To be implemented
    class Matrix3x3 {
    public:
        Vector3 x, y, z;
    };

    // To be implemented
    class Matrix2x2 {
    public:
        Vector2 x, y;
    };

} // LEMath

#endif //VECTOR_H
