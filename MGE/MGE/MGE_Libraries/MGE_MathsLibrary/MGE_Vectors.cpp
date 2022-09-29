//
//  MGE_Vectors.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 25/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserVed.
//


#include "MGE_Vectors.hpp"

namespace  mge
{
Vector2f::Vector2f(float x, float y, bool set_polar)
{
    if (set_polar)
    {
        this->x = fabs(x) * cos(y);
        this->y = fabs(x) * sin(y);
    } else
    {
        this->x = x;
        this->y = y;
    }
}

bool Vector2f::EqualTo(const Vector2f& A) const
{
    return this->x == A.x && this->y == A.y;
}

bool Vector2f::operator==(const Vector2f& A) const
{
    return this->EqualTo(A);
}

bool Vector2f::NotEqualTo(const Vector2f& A) const
{
    return !this->EqualTo(A);
}

bool Vector2f::operator!=(const Vector2f& A) const
{
    return this->NotEqualTo(A);
}


Vector2f Vector2f::Addition(const Vector2f& A) const
{
    Vector2f value;
    
    value.x = this->x + A.x;
    value.y = this->y + A.y;
    
    return value;
}

Vector2f Vector2f::operator+(const Vector2f& A) const
{
    return this->Addition(A);
}

Vector2f Vector2f::AdditionAssignment(const Vector2f& A)
{
    *this = this->Addition(A);

    return *this;
}

Vector2f Vector2f::operator+=(const Vector2f& A)
{
    return this->AdditionAssignment(A);
}


Vector2f Vector2f::Subtraction(const Vector2f& A) const
{
    Vector2f value;
    
    value.x = this->x - A.x;
    value.y = this->y - A.y;
    
    return value;
}

Vector2f Vector2f::operator-(const Vector2f& A) const
{
    return this->Subtraction(A);
}

Vector2f Vector2f::SubtractionAssignment(const Vector2f& A)
{
    *this = this->Subtraction(A);

    return *this;
}

Vector2f Vector2f::operator-=(const Vector2f& A)
{
    return this->SubtractionAssignment(A);
}



Vector2f Vector2f::Multiplication(float A) const
{
    Vector2f value;
    
    value.x = this->x * A;
    value.y = this->y * A;
    
    return value;
}

Vector2f Vector2f::operator*(float A) const
{
    return this->Multiplication(A);
}

Vector2f Vector2f::MultiplicationAssignment(float A)
{
    *this = this->Multiplication(A);

    return *this;
}

Vector2f Vector2f::operator*=(float A)
{
    return this->MultiplicationAssignment(A);
}

Vector2f Vector2f::Multiplication(const Vector2f& A) const
{
    Vector2f value;
    
    value.x = this->x * A.x;
    value.y = this->y * A.y;
    
    return value;
}

Vector2f Vector2f::operator*(const Vector2f& A) const
{
    return this->Multiplication(A);
}

Vector2f Vector2f::MultiplicationAssignment(const Vector2f& A)
{
    *this = this->Multiplication(A);

    return *this;
}

Vector2f Vector2f::operator*=(const Vector2f& A)
{
    return this->MultiplicationAssignment(A);
}



Vector2f Vector2f::Division(float A) const
{
    Vector2f value;
    
    value.x = this->x / A;
    value.y = this->y / A;
    
    return value;
}

Vector2f Vector2f::operator/(float A) const
{
    return this->Division(A);
}

Vector2f Vector2f::DivisionAssignment(float A)
{
    *this = this->Division(A);

    return *this;
}

Vector2f Vector2f::operator/=(float A)
{
    return this->DivisionAssignment(A);
}

Vector2f Vector2f::Division(const Vector2f& A) const
{
    Vector2f value;
    
    value.x = this->x / A.x;
    value.y = this->y / A.y;
    
    return value;
}

Vector2f Vector2f::operator/(const Vector2f& A) const
{
    return this->Division(A);
}

Vector2f Vector2f::DivisionAssignment(const Vector2f& A)
{
    *this = this->Division(A);

    return *this;
}

Vector2f Vector2f::operator/=(const Vector2f& A)
{
    return this->DivisionAssignment(A);
}


    
float Vector2f::GetLengthSquared() const
{
    return DotProduct(*this, *this);
}

float Vector2f::GetLength() const
{
    return sqrt(this->GetLengthSquared());
}

float Vector2f::GetPolarPhi() const
{
    return fmod(atan2(this->y, this->x), 2.0f * pi);
}



Vector3f::Vector3f(float x, float y, float z, bool set_spherical)
{
    if (set_spherical)
    {
        this->x = fabs(x) * sin(y) * cos(z);
        this->y = fabs(x) * sin(y) * sin(z);
        this->z = fabs(x) * cos(y);
    } else
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
}



bool Vector3f::EqualTo(const Vector3f& A) const
{
    return this->x == A.x && this->y == A.y && this->z == A.z;
}

bool Vector3f::operator==(const Vector3f& A) const
{
    return this->EqualTo(A);
}

bool Vector3f::NotEqualTo(const Vector3f& A) const
{
    return !this->EqualTo(A);
}

bool Vector3f::operator!=(const Vector3f& A) const
{
    return this->NotEqualTo(A);
}


Vector3f Vector3f::Addition(const Vector3f& A) const
{
    Vector3f value;
    
    value.x = this->x + A.x;
    value.y = this->y + A.y;
    value.z = this->z + A.z;
    
    return value;
}

Vector3f Vector3f::operator+(const Vector3f& A) const
{
    return this->Addition(A);
}

Vector3f Vector3f::AdditionAssignment(const Vector3f& A)
{
    *this = this->Addition(A);

    return *this;
}

Vector3f Vector3f::operator+=(const Vector3f& A)
{
    return this->AdditionAssignment(A);
}


Vector3f Vector3f::Subtraction(const Vector3f& A) const
{
    Vector3f value;
    
    value.x = this->x - A.x;
    value.y = this->y - A.y;
    value.z = this->z - A.z;
    
    return value;
}

Vector3f Vector3f::operator-(const Vector3f& A) const
{
    return this->Subtraction(A);
}

Vector3f Vector3f::SubtractionAssignment(const Vector3f& A)
{
    *this = this->Subtraction(A);

    return *this;
}

Vector3f Vector3f::operator-=(const Vector3f& A)
{
    return this->SubtractionAssignment(A);
}



Vector3f Vector3f::Multiplication(float A) const
{
    Vector3f value;
    
    value.x = this->x * A;
    value.y = this->y * A;
    value.z = this->z * A;
    
    return value;
}

Vector3f Vector3f::operator*(float A) const
{
    return this->Multiplication(A);
}

Vector3f Vector3f::MultiplicationAssignment(float A)
{
    *this = this->Multiplication(A);

    return *this;
}

Vector3f Vector3f::operator*=(float A)
{
    return this->MultiplicationAssignment(A);
}

Vector3f Vector3f::Multiplication(const Vector3f& A) const
{
    Vector3f value;
    
    value.x = this->x * A.x;
    value.y = this->y * A.y;
    value.z = this->z * A.z;
    
    return value;
}

Vector3f Vector3f::operator*(const Vector3f& A) const
{
    return this->Multiplication(A);
}

Vector3f Vector3f::MultiplicationAssignment(const Vector3f& A)
{
    *this = this->Multiplication(A);

    return *this;
}

Vector3f Vector3f::operator*=(const Vector3f& A)
{
    return this->MultiplicationAssignment(A);
}



Vector3f Vector3f::Division(float A) const
{
    Vector3f value;
    
    value.x = this->x / A;
    value.y = this->y / A;
    value.z = this->z / A;
    
    return value;
}

Vector3f Vector3f::operator/(float A) const
{
    return this->Division(A);
}

Vector3f Vector3f::DivisionAssignment(float A)
{
    *this = this->Division(A);

    return *this;
}

Vector3f Vector3f::operator/=(float A)
{
    return this->DivisionAssignment(A);
}

Vector3f Vector3f::Division(const Vector3f& A) const
{
    Vector3f value;
    
    value.x = this->x / A.x;
    value.y = this->y / A.y;
    value.z = this->z / A.z;
    
    return value;
}

Vector3f Vector3f::operator/(const Vector3f& A) const
{
    return this->Division(A);
}

Vector3f Vector3f::DivisionAssignment(const Vector3f& A)
{
    *this = this->Division(A);

    return *this;
}

Vector3f Vector3f::operator/=(const Vector3f& A)
{
    return this->DivisionAssignment(A);
}


    
float Vector3f::GetLengthSquared() const
{
    return DotProduct(*this, *this);
}

float Vector3f::GetLength() const
{
    return sqrt(this->GetLengthSquared());
}

float Vector3f::GetSphericalTheta() const
{
    return acos(this->z / this->GetLength());
}

float Vector3f::GetSphericalPhi() const
{
    return fmod(atan2(this->y, this->x), 2.0f * pi);
}



Vector2f To2D(const Vector3f& A)
{
    return Vector2f(A.x, A.y);
}

Vector3f To3D(const Vector3f& A)
{
    return Vector3f(A.x, A.y, 0.0f);
}



Vector3f CrossProduct(const Vector3f& A, const Vector3f& B)
{
    return Vector3f((A.y * B.z) - (A.z * B.y),
                    (A.z * B.x) - (A.x * B.z),
                    (A.x * B.y) - (A.y * B.x));
}


float DotProduct(const Vector2f& A, const Vector2f& B)
{
    return (A.x * B.x) + (A.y * B.y);
}

float DotProduct(const Vector3f& A, const Vector3f& B)
{
    return (A.x * B.x) + (A.y * B.y) + (A.z * B.z);
}


float Angle(const Vector2f& A, const Vector2f& B)
{
    return acos(DotProduct(A, B) / (A.GetLength() * B.GetLength()));
}

float Angle(const Vector3f& A, const Vector3f& B)
{
    return acos(DotProduct(A, B) / (A.GetLength() * B.GetLength()));
}



Vector2f Normalize(const Vector2f& A)
{
    return A / A.GetLength();
}

Vector3f Normalize(const Vector3f& A)
{
    return A / A.GetLength();
}



Vector2f vabs(const Vector2f& A)
{
    return Vector2f(fabs(A.x), fabs(A.y));
}

Vector3f vabs(const Vector3f& A)
{
    return Vector3f(fabs(A.x), fabs(A.y), fabs(A.z));
}



Vector2f vmod(const Vector2f& A, const Vector2f& B)
{
    return Vector2f(fmod(A.x, B.x), fmod(A.y, B.y));
}

Vector3f vmod(const Vector3f& A, const Vector3f& B)
{
    return Vector3f(fmod(A.x, B.x), fmod(A.y, B.y), fmod(A.z, B.z));
}
}
