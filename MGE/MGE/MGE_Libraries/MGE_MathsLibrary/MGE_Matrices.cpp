//
//  MGE_Matrices.cpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 25/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#include "MGE_Matrices.hpp"

namespace mge
{
Matrix2x2f::Matrix2x2f(float A, float B,
                       float C, float D)
{
    this->element[0][0] = A;    this->element[0][1] = B;
    this->element[1][0] = C;    this->element[1][1] = D;
}

Matrix2x2f::Matrix2x2f(const Vector2f& A, const Vector2f& B, bool set_rows)
{
    if (set_rows)
    {
        this->element[0][0] = A.x;  this->element[0][1] = A.y;
        this->element[1][0] = B.x;  this->element[1][1] = B.y;
    } else
    {
        this->element[0][0] = A.x;  this->element[0][1] = B.x;
        this->element[1][0] = A.y;  this->element[1][1] = B.y;
    }
}

bool Matrix2x2f::EqualTo(const Matrix2x2f& A) const
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (this->element[i][j] != A.element[i][j])
            {
                return false;
            }
        }
    }
    
    return true;
}

bool Matrix2x2f::operator==(const Matrix2x2f& A) const
{
    return this->EqualTo(A);
}

bool Matrix2x2f::NotEqualTo(const Matrix2x2f& A) const
{
    return !this->EqualTo(A);
}

bool Matrix2x2f::operator!=(const Matrix2x2f& A) const
{
    return this->NotEqualTo(A);
}



Matrix2x2f Matrix2x2f::Addition(const Matrix2x2f& A) const
{
    Matrix2x2f result;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result.element[i][j] = this->element[i][j] + A.element[i][j];
        }
    }
    
    return result;
}

Matrix2x2f Matrix2x2f::operator+(const Matrix2x2f& A) const
{
    return this->Addition(A);
}

Matrix2x2f Matrix2x2f::AdditionAssignment(const Matrix2x2f& A)
{
    *this = this->Addition(A);
    
    return *this;
}

Matrix2x2f Matrix2x2f::operator+=(const Matrix2x2f& A)
{
    return this->AdditionAssignment(A);
}


Matrix2x2f Matrix2x2f::Subtraction(const Matrix2x2f& A) const
{
    Matrix2x2f result;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result.element[i][j] = this->element[i][j] - A.element[i][j];
        }
    }
    
    return result;
}

Matrix2x2f Matrix2x2f::operator-(const Matrix2x2f& A) const
{
    return this->Subtraction(A);
}

Matrix2x2f Matrix2x2f::SubtractionAssignment(const Matrix2x2f& A)
{
    *this = this->Subtraction(A);
    
    return *this;
}

Matrix2x2f Matrix2x2f::operator-=(const Matrix2x2f& A)
{
    return this->SubtractionAssignment(A);
}


Matrix2x2f Matrix2x2f::Multiplication(float A) const
{
    Matrix2x2f result;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result.element[i][j] = this->element[i][j] * A;
        }
    }
    
    return result;
}

Matrix2x2f Matrix2x2f::operator*(float A) const
{
    return this->Multiplication(A);
}

Matrix2x2f Matrix2x2f::MultiplicationAssignment(float A)
{
    *this = this->Multiplication(A);

    return *this;
}

Matrix2x2f Matrix2x2f::operator*=(float A)
{
    return this->MultiplicationAssignment(A);
}

Matrix2x2f Matrix2x2f::Multiplication(const Matrix2x2f& A) const
{
    Matrix2x2f result;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result.element[i][j] = (this->element[i][0] * A.element[0][j]) + (this->element[i][1] * A.element[1][j]);
        }
    }
    
    return result;
}

Matrix2x2f Matrix2x2f::operator*(const Matrix2x2f& A) const
{
    return this->Multiplication(A);
}

Matrix2x2f Matrix2x2f::MultiplicationAssignment(const Matrix2x2f& A)
{
    *this = this->Multiplication(A);

    return *this;
}

Matrix2x2f Matrix2x2f::operator*=(const Matrix2x2f& A)
{
    return this->MultiplicationAssignment(A);
}

Vector2f Matrix2x2f::Multiplication(const Vector2f& A) const
{
    return Vector2f((this->element[0][0] * A.x) + (this->element[0][1] * A.y),
                    (this->element[1][0] * A.x) + (this->element[1][1] * A.y));
}

Vector2f Matrix2x2f::operator*(const Vector2f& A) const
{
    return this->Multiplication(A);
}



Matrix2x2f Matrix2x2f::Division(float A) const
{
    Matrix2x2f result;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result.element[i][j] = this->element[i][j] / A;
        }
    }
    
    return result;
}

Matrix2x2f Matrix2x2f::operator/(float A) const
{
    return this->Division(A);
}

Matrix2x2f Matrix2x2f::DivisionAssignment(float A)
{
    *this = this->Division(A);

    return *this;
}

Matrix2x2f Matrix2x2f::operator/=(float A)
{
    return this->DivisionAssignment(A);
}



Matrix2x2f Matrix2x2f::Inverse() const
{
    float determinant= Determinant(*this);
    
    return Matrix2x2f(this->element[1][1] / determinant,
                     -this->element[0][1] / determinant,
                     -this->element[1][0] / determinant,
                      this->element[0][0] / determinant);
}

Matrix2x2f Matrix2x2f::Transpose() const
{
    Matrix2x2f result;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result.element[i][j] = this->element[j][i];
        }
    }
    
    return result;
}



Matrix3x3f::Matrix3x3f(float A, float B, float C,
                       float D, float E, float F,
                       float G, float H, float I)
{
    this->element[0][0] = A;    this->element[0][1] = B;    this->element[0][2] = C;
    this->element[1][0] = D;    this->element[1][1] = E;    this->element[1][2] = F;
    this->element[2][0] = G;    this->element[2][1] = H;    this->element[2][2] = I;
}

Matrix3x3f::Matrix3x3f(const Vector3f& A, const Vector3f& B, const Vector3f& C, bool set_rows)
{
    if (set_rows)
    {
        this->element[0][0] = A.x;  this->element[0][1] = A.y;  this->element[0][2] = A.z;
        this->element[1][0] = B.x;  this->element[1][1] = B.y;  this->element[1][2] = B.z;
        this->element[2][0] = C.x;  this->element[2][1] = C.y;  this->element[2][2] = C.z;
    } else
    {
        this->element[0][0] = A.x;  this->element[0][1] = B.x;  this->element[0][2] = C.x;
        this->element[1][0] = A.y;  this->element[1][1] = B.y;  this->element[1][2] = C.y;
        this->element[2][0] = A.z;  this->element[2][1] = B.z;  this->element[2][2] = C.z;
    }
}



bool Matrix3x3f::EqualTo(const Matrix3x3f& A) const
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->element[i][j] != A.element[i][j])
            {
                return false;
            }
        }
    }
    
    return true;
}

bool Matrix3x3f::operator==(const Matrix3x3f& A) const
{
    return this->EqualTo(A);
}

bool Matrix3x3f::NotEqualTo(const Matrix3x3f& A) const
{
    return !this->EqualTo(A);
}

bool Matrix3x3f::operator!=(const Matrix3x3f& A) const
{
    return this->NotEqualTo(A);
}



Matrix3x3f Matrix3x3f::Addition(const Matrix3x3f& A) const
{
    Matrix3x3f result;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.element[i][j] = this->element[i][j] + A.element[i][j];
        }
    }
    
    return result;
}

Matrix3x3f Matrix3x3f::operator+(const Matrix3x3f& A) const
{
    return this->Addition(A);
}

Matrix3x3f Matrix3x3f::AdditionAssignment(const Matrix3x3f& A)
{
    *this = this->Addition(A);
    
    return *this;
}

Matrix3x3f Matrix3x3f::operator+=(const Matrix3x3f& A)
{
    return this->AdditionAssignment(A);
}


Matrix3x3f Matrix3x3f::Subtraction(const Matrix3x3f& A) const
{
    Matrix3x3f result;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.element[i][j] = this->element[i][j] - A.element[i][j];
        }
    }
    
    return result;
}

Matrix3x3f Matrix3x3f::operator-(const Matrix3x3f& A) const
{
    return this->Subtraction(A);
}

Matrix3x3f Matrix3x3f::SubtractionAssignment(const Matrix3x3f& A)
{
    *this = this->Subtraction(A);
    
    return *this;
}

Matrix3x3f Matrix3x3f::operator-=(const Matrix3x3f& A)
{
    return this->SubtractionAssignment(A);
}


Matrix3x3f Matrix3x3f::Multiplication(float A) const
{
    Matrix3x3f result;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.element[i][j] = this->element[i][j] * A;
        }
    }
    
    return result;
}

Matrix3x3f Matrix3x3f::operator*(float A) const
{
    return this->Multiplication(A);
}

Matrix3x3f Matrix3x3f::MultiplicationAssignment(float A)
{
    *this = this->Multiplication(A);

    return *this;
}

Matrix3x3f Matrix3x3f::operator*=(float A)
{
    return this->MultiplicationAssignment(A);
}

Matrix3x3f Matrix3x3f::Multiplication(const Matrix3x3f& A) const
{
    Matrix3x3f result;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.element[i][j] = (this->element[i][0] * A.element[0][j]) + (this->element[i][1] * A.element[1][j]);
        }
    }
    
    return result;
}

Matrix3x3f Matrix3x3f::operator*(const Matrix3x3f& A) const
{
    return this->Multiplication(A);
}

Matrix3x3f Matrix3x3f::MultiplicationAssignment(const Matrix3x3f& A)
{
    *this = this->Multiplication(A);

    return *this;
}

Matrix3x3f Matrix3x3f::operator*=(const Matrix3x3f& A)
{
    return this->MultiplicationAssignment(A);
}

Vector3f Matrix3x3f::Multiplication(const Vector3f& A) const
{
    return Vector3f((this->element[0][0] * A.x) + (this->element[0][1] * A.y) + (this->element[0][2] * A.z),
                    (this->element[1][0] * A.x) + (this->element[1][1] * A.y) + (this->element[1][2] * A.z),
                    (this->element[2][0] * A.x) + (this->element[2][1] * A.y) + (this->element[2][2] * A.z));
}

Vector3f Matrix3x3f::operator*(const Vector3f& A) const
{
    return this->Multiplication(A);
}



Matrix3x3f Matrix3x3f::Division(float A) const
{
    Matrix3x3f result;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.element[i][j] = this->element[i][j] / A;
        }
    }
    
    return result;
}

Matrix3x3f Matrix3x3f::operator/(float A) const
{
    return this->Division(A);
}

Matrix3x3f Matrix3x3f::DivisionAssignment(float A)
{
    *this = this->Division(A);

    return *this;
}

Matrix3x3f Matrix3x3f::operator/=(float A)
{
    return this->DivisionAssignment(A);
}



Matrix3x3f Matrix3x3f::Inverse() const
{
    float determinant = Determinant(*this);
    
    return Matrix3x3f(((this->element[1][1] * this->element[2][2]) - (this->element[1][2] * this->element[2][1])) / determinant,
                      ((this->element[0][2] * this->element[2][1]) - (this->element[0][1] * this->element[2][2])) / determinant,
                      ((this->element[0][1] * this->element[1][2]) - (this->element[0][2] * this->element[1][1])) / determinant,
                      ((this->element[1][2] * this->element[2][0]) - (this->element[1][0] * this->element[2][2])) / determinant,
                      ((this->element[0][0] * this->element[2][2]) - (this->element[0][2] * this->element[2][0])) / determinant,
                      ((this->element[0][2] * this->element[1][0]) - (this->element[0][0] * this->element[1][2])) / determinant,
                      ((this->element[1][0] * this->element[2][1]) - (this->element[1][1] * this->element[2][0])) / determinant,
                      ((this->element[0][1] * this->element[2][0]) - (this->element[0][0] * this->element[2][1])) / determinant,
                      ((this->element[0][0] * this->element[1][1]) - (this->element[0][1] * this->element[1][0])) / determinant);
}

Matrix3x3f Matrix3x3f::Transpose() const
{
    Matrix3x3f result;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.element[i][j] = this->element[j][i];
        }
    }
    
    return result;
}



float Determinant(const Matrix2x2f& A)
{
    return (A.element[0][0] * A.element[1][1]) - (A.element[0][1] * A.element[1][0]);
}

float Determinant(const Matrix3x3f& A)
{
    return (A.element[0][0] * ((A.element[1][1] * A.element[2][2]) - (A.element[1][2] * A.element[2][1]))) +
           (A.element[0][1] * ((A.element[1][2] * A.element[2][0]) - (A.element[1][0] * A.element[2][2]))) +
           (A.element[0][2] * ((A.element[1][0] * A.element[2][1]) - (A.element[1][1] * A.element[2][0])));
}



float Trace(const Matrix2x2f& A)
{
    return A.element[0][0] + A.element[1][1];
}

float Trace(const Matrix3x3f& A)
{
    return A.element[0][0] + A.element[1][1] + A.element[2][2];
}



bool IsIdenty(const Matrix3x3f& A)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j && A.element[i][j] != 1.0f)
            {
                return false;
            }
            
            if (i != j && A.element[i][j] != 0.0f)
            {
                return false;
            }
        }
    }
    
    return true;
}

bool IsIdenty(const Matrix2x2f& A)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == j && A.element[i][j] != 1.0f)
            {
                return false;
            }
            
            if (i != j && A.element[i][j] != 0.0f)
            {
                return false;
            }
        }
    }
    
    return true;
}



bool IsZero(const Matrix2x2f& A)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (A.element[i][j] != 0.0f)
            {
                return false;
            }
        }
    }
    
    return true;
}

bool IsZero(const Matrix3x3f& A)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (A.element[i][j] != 0.0f)
            {
                return false;
            }
        }
    }
    
    return true;
}
}
