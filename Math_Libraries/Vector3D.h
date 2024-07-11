#pragma once

#include<iostream>
#include<math.h>

struct Vector3D {
    float x, y, z;

    // Constructors
    Vector3D() = default;
    Vector3D(float a, float b, float c);
    Vector3D(float v);

    // Print Vector
    friend std::ostream& operator << (std::ostream& os, const Vector3D& v);

    // Indexing
    float& operator [](int i) { return ((&x)[i]); }
    const float& operator [](int i) const { return ((&x)[i]);}

    // Operators
    Vector3D& operator +=(Vector3D v)
    {
        x += v.x;
        y += v.y;
        z += v.z;

        return (*this);
    }

    Vector3D& operator -=(Vector3D v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;

        return (*this);
    }

    Vector3D& operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;

        return (*this);
    }

    Vector3D& operator /=(float s)
    {
        s = 1.0F / s;
        x *= s;
        y *= s;
        z *= s;

        return (*this);
    }

    // Functions
    float norm()
    {
        return (sqrt(x*x + y*y + z*z));
    }

    Vector3D normalize()
    {
        float mag = (*this).norm();
        return Vector3D(x/mag, y/mag, z/mag);
    }

    float dot(Vector3D w)
    {
        return (x * w.x + y * w.y + z* w.z);
    }


};

Vector3D::Vector3D(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}

Vector3D::Vector3D(float v)
{
    x = v;
    y = v;
    z = v;
}

inline Vector3D operator +(const Vector3D& v, const Vector3D& w)
{
    return (Vector3D(v.x + w.x, v.y + w.y, v.z * w.z));
}

inline Vector3D operator -(const Vector3D& v, const Vector3D& w)
{
    return (Vector3D(v.x - w.x, v.y - w.y, v.z - w.z));
}

inline Vector3D operator *(const Vector3D& v, float s)
{
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator *(float s, const Vector3D& v)
{
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator /(const Vector3D& v, float s)
{
    s = 1.0F / s;
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator -(const Vector3D& v)
{
    return (Vector3D(-v.x, -v.y, -v.z));
}

inline float Magnitude(const Vector3D& v)
{
    return (sqrt(v.x*v.x + v.y*v.y + v.z*v.z));
}

inline Vector3D Normalize(const Vector3D& v)
{
    return (v / Magnitude(v));
}

inline float Dot(const Vector3D& v, const Vector3D& w)
{
    return (v.x * w.x + v.y * w.y + v.z * w.z);
}

std::ostream& operator << (std::ostream& os, const Vector3D& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";   
}