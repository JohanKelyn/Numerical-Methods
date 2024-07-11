#pragma once

#include<iostream>
#include<math.h>
#include "Vector3D.h"
#include "Vector4D.h"

struct Matrix3D {
    private:
    float M[3][3];

    public:
    Matrix3D() = default;
    Matrix3D(float n00, float n01, float n02,  float n10, float n11, float n12,  float n20, float n21, float n22) {  
        M[0][0] = n00; M[0][1] = n10; M[0][2] = n20;  
        M[1][0] = n01; M[1][1] = n11; M[1][2] = n21;  
        M[2][0] = n02; M[2][1] = n12; M[2][2] = n22; 
    }
    
    Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)  {  
        M[0][0] = a.x; M[0][1] = a.y; M[0][2] = a.z;  
        M[1][0] = b.x; M[1][1] = b.y; M[1][2] = b.z;  
        M[2][0] = c.x; M[2][1] = c.y; M[2][2] = c.z;  
    }

};