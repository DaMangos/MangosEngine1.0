//
//  MGE_Matrices.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 25/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#ifndef MGE_Matrices_hpp
#define MGE_Matrices_hpp

#include <stdio.h>
#include "MGE_Vectors.hpp"

namespace mge
{
struct Matrix2x2f
{
    float element[2][2];

    
        
    Matrix2x2f(float A = 0.0f, float B = 0.0f,
               float C = 0.0f, float D = 0.0f);
    
    Matrix2x2f(const Vector2f& A, const Vector2f& B, bool set_rows = false);
    
    
    
    bool EqualTo(const Matrix2x2f& A) const;
        
    bool operator==(const Matrix2x2f& A) const;

    bool NotEqualTo(const Matrix2x2f& A) const;

    bool operator!=(const Matrix2x2f& A) const;
    
    

    Matrix2x2f Addition(const Matrix2x2f& A) const;
    
    Matrix2x2f operator+(const Matrix2x2f& A) const;
    
    Matrix2x2f AdditionAssignment(const Matrix2x2f& A);
    
    Matrix2x2f operator+=(const Matrix2x2f& A);
    
    

    Matrix2x2f Subtraction(const Matrix2x2f& A) const;
    
    Matrix2x2f operator-(const Matrix2x2f& A) const;
    
    Matrix2x2f SubtractionAssignment(const Matrix2x2f& A);
        
    Matrix2x2f operator-=(const Matrix2x2f& A);
    
    

    Matrix2x2f Multiplication(float A) const;
    
    Matrix2x2f operator*(float A) const;
    
    Matrix2x2f MultiplicationAssignment(float A);
    
    Matrix2x2f operator*=(float A);
    
    Matrix2x2f Multiplication(const Matrix2x2f& A) const;
    
    Matrix2x2f operator*(const Matrix2x2f& A) const;
    
    Matrix2x2f MultiplicationAssignment(const Matrix2x2f& A);
      
    Matrix2x2f operator*=(const Matrix2x2f& A);
    
    Vector2f Multiplication(const Vector2f& A) const;
    
    Vector2f operator*(const Vector2f& A) const;
    
    

    Matrix2x2f Division(float A) const;

    Matrix2x2f operator/(float A) const;

    Matrix2x2f DivisionAssignment(float A);
        
    Matrix2x2f operator/=(float A);
    
    
    
    Matrix2x2f Inverse() const;
    
    Matrix2x2f Transpose() const;
};



struct Matrix3x3f
{
    float element[3][3];

    
    
    Matrix3x3f(float A = 0.0f, float B = 0.0f, float C = 0.0f,
               float D = 0.0f, float E = 0.0f, float F = 0.0f,
               float G = 0.0f, float H = 0.0f, float I = 0.0f);
    
    Matrix3x3f(const Vector3f& A, const Vector3f& B, const Vector3f& C, bool set_rows = false);
          
    
    
    bool EqualTo(const Matrix3x3f& A) const;
        
    bool operator==(const Matrix3x3f& A) const;

    bool NotEqualTo(const Matrix3x3f& A) const;

    bool operator!=(const Matrix3x3f& A) const;
    
    

    Matrix3x3f Addition(const Matrix3x3f& A) const;
    
    Matrix3x3f operator+(const Matrix3x3f& A) const;
    
    Matrix3x3f AdditionAssignment(const Matrix3x3f& A);
    
    Matrix3x3f operator+=(const Matrix3x3f& A);
    
    

    Matrix3x3f Subtraction(const Matrix3x3f& A) const;
    
    Matrix3x3f operator-(const Matrix3x3f& A) const;
    
    Matrix3x3f SubtractionAssignment(const Matrix3x3f& A);
        
    Matrix3x3f operator-=(const Matrix3x3f& A);
    
    

    Matrix3x3f Multiplication(float A) const;
    
    Matrix3x3f operator*(float A) const;
    
    Matrix3x3f MultiplicationAssignment(float A);
    
    Matrix3x3f operator*=(float A);
    
    Matrix3x3f Multiplication(const Matrix3x3f& A) const;
    
    Matrix3x3f operator*(const Matrix3x3f& A) const;
    
    Matrix3x3f MultiplicationAssignment(const Matrix3x3f& A);
      
    Matrix3x3f operator*=(const Matrix3x3f& A);
    
    Vector3f Multiplication(const Vector3f& A) const;
    
    Vector3f operator*(const Vector3f& A) const;
    
    

    Matrix3x3f Division(float A) const;

    Matrix3x3f operator/(float A) const;

    Matrix3x3f DivisionAssignment(float A);
        
    Matrix3x3f operator/=(float A);
    
    
    
    Matrix3x3f Inverse() const;
    
    Matrix3x3f Transpose() const;
};



float Determinant(const Matrix2x2f& A);

float Determinant(const Matrix3x3f& A);



float Trace(const Matrix2x2f& A);

float Trace(const Matrix3x3f& A);



bool IsIdenty(const Matrix2x2f& A);

bool IsIdenty(const Matrix3x3f& A);



bool IsZero(const Matrix2x2f& A);

bool IsZero(const Matrix3x3f& A);
}
#endif /* MGE_Matrices_hpp */
