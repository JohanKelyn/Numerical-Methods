#pragma once

#include<iostream>
#include<math.h>
#include "Vector3D.h"

struct Vector4D {
    float x, y, z, w;

    // Constructors
    Vector4D() = default;
    Vector4D(float x, float y, float z, float w);
    Vector4D(float k);
    Vector4D(Vector3D v, float k);

    // Print Vector
    friend std::ostream& operator << (std::ostream& os, const Vector4D& v);

    // Indexing
    float& operator [](int i) { return ((&x)[i]); }
    const float& operator [](int i) const { return ((&x)[i]);}

    // Operators
    Vector4D& operator +=(Vector4D v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;

        return (*this);
    }

    Vector4D& operator -=(Vector4D v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;

        return (*this);
    }

    Vector4D& operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;

        return (*this);
    }

    Vector4D& operator /=(float s)
    {
        s = 1.0F / s;
        x *= s;
        y *= s;
        z *= s;
        w *= s;

        return (*this);
    }

    // Functions
    float norm()
    {
        return (sqrt(x*x + y*y + z*z));
    }

    Vector4D normalize()
    {
        float mag = (*this).norm();
        return Vector4D(x/mag, y/mag, z/mag, w/mag);
    }

    float dot(Vector4D v)
    {
        return (x * v.x + y * v.y + z * v.z + w * v.w);
    }
};

// External operators

Vector4D::Vector4D(float a, float b, float c, float d): x(a), y(b), z(c), w(d) {}


Vector4D::Vector4D(float k): x(k), y(k), z(k), w(k) {}

Vector4D::Vector4D(Vector3D v, float k): x(v.x), y(v.y), z(v.z), w(k){}


inline Vector4D operator +(const Vector4D& v1, const Vector4D& v2)
{
    return (Vector4D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w));
}

inline Vector4D operator -(const Vector4D& v1, const Vector4D& v2)
{
    return (Vector4D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w));
}

inline Vector4D operator *(const Vector4D& v, float s)
{
    return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
}

inline Vector4D operator *(float s, const Vector4D& v)
{
    return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
}

inline Vector4D operator /(const Vector4D& v, float s)
{
    s = 1.0F / s;
    return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
}

inline Vector4D operator -(const Vector4D& v)
{
    return (Vector4D(-v.x, -v.y, -v.z, -v.w));
}

inline float Magnitude(const Vector4D& v)
{
    return (sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w * v.w));
}

inline Vector4D Normalize(const Vector4D& v)
{
    return (v / Magnitude(v));
}

inline float Dot(const Vector4D& v, const Vector4D& w)
{
    return (v.x * w.x + v.y * w.y + v.z * w.z + v.w + w.w);
}

std::ostream& operator << (std::ostream& os, const Vector4D& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")\n";   
}