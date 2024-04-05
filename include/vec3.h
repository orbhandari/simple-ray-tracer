
// A 3D vector to define coordinates, color (RGB), etc.
// Possibly parent class of Point3f, Color3f, etc
// Supports basic vector operations: addition, scalar mult, scalar div, dot product, cross product

#pragma once
#include <cmath>
#include <iostream>

class Vec3 {
   public:
    Vec3(float val) : m_x(val), m_y(val), m_z(val){};

    Vec3(float x, float y, float z) : m_x(x), m_y(y), m_z(z){};

    float x() const {
        return m_x;
    };

    float y() const {
        return m_y;
    };

    float z() const {
        return m_z;
    };

    Vec3 normalized() const {
        return (*this / (*this).norm());
    }

    float norm() const {
        return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
    }

    // Note that order matters.
    // a.cross(b) =/= b.cross(a)
    Vec3 cross(const Vec3& b) const {
        return Vec3{y() * b.z() - z() * b.y(), z() * b.x() - x() * b.z(), x() * b.y() - y() * b.x()};
    }

    // a.dot(b) == b.dot(a)
    float dot(const Vec3& b) const {
        return m_x * b.m_x + m_y * b.m_y + m_z * b.m_z;
    }

    // -v
    Vec3 operator-() const {
        return Vec3{-m_x, -m_y, -m_z};
    };

    // scalar * vector
    friend Vec3 operator*(const float& scalar, const Vec3& vector) {
        return Vec3{scalar * vector.m_x, scalar * vector.m_y, scalar * vector.m_z};
    };

    // vector * scalar
    friend Vec3 operator*(const Vec3& vector, const float& scalar) {
        return Vec3{scalar * vector.m_x, scalar * vector.m_y, scalar * vector.m_z};
    }

    friend Vec3 operator/(const Vec3& vector, const float& scalar) {
        return Vec3{(1.0f / scalar) * vector.m_x, (1.0f / scalar) * vector.m_y, (1.0f / scalar) * vector.m_z};
    };

    friend Vec3 operator+(const Vec3& u, const Vec3& v) {
        return Vec3(u.m_x + v.m_x, u.m_y + v.m_y, u.m_z + v.m_z);
    };

    friend Vec3 operator-(const Vec3& u, const Vec3& v) {
        return Vec3(u.m_x - v.m_x, u.m_y - v.m_y, u.m_z - v.m_z);
    };

    void printVec() {
        std::cout << m_x << ' ' << m_y << ' ' << m_z << '\n';
    }

    // For access only
    float operator[](const int& index) const {
        switch (index) {
            case 0:
                return m_x;
            case 1:
                return m_y;
            case 2:
                return m_z;
            default:
                std::cout << "Index out of bounds!\n";
                return -1;
        }
    }

    // For re-assignment
    float& operator[](const int& index) {
        switch (index) {
            case 0:
                return m_x;
            case 1:
                return m_y;
            case 2:
                return m_z;
            default:
                std::cout << "Index out of bounds! Returning first element...\n";
                return m_x;
        }
    }

   private:
    float m_x{0};
    float m_y{0};
    float m_z{0};
};

// Alias for clarity, in essence they are the same.
// Learnt from "Ray Tracing in One Weekend" series.
using Point3 = Vec3;
