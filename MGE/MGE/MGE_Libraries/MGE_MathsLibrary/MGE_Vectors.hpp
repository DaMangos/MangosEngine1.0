//
//  MGE_Vectors.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 25/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserVed.
//

#ifndef MGE_Vectors_hpp
#define MGE_Vectors_hpp

#include <stdio.h>
#include <cmath>
#define pi 3.14159265358979323846f

namespace mge
{
struct Vector2f
{
    float x, y;

    
    
    Vector2f(float x = 0.0f, float y = 0.0f, bool set_polar = false);
    
    
            
    bool EqualTo(const Vector2f& A) const;
       
    bool operator==(const Vector2f& A) const;

    bool NotEqualTo(const Vector2f& A) const;

    bool operator!=(const Vector2f& A) const;
    

    
    Vector2f Addition(const Vector2f& A) const;
    
    Vector2f operator+(const Vector2f& A) const;
    
    Vector2f AdditionAssignment(const Vector2f& A);
    
    Vector2f operator+=(const Vector2f& A);
    
    
    
    Vector2f Subtraction(const Vector2f& A) const;
    
    Vector2f operator-(const Vector2f& A) const;
        
    Vector2f SubtractionAssignment(const Vector2f& A);
        
    Vector2f operator-=(const Vector2f& A);

    

    Vector2f Multiplication(float A) const;
    
    Vector2f operator*(float A) const;
    
    Vector2f MultiplicationAssignment(float A);
        
    Vector2f operator*=(float A);
    
    Vector2f Multiplication(const Vector2f& A) const;
    
    Vector2f operator*(const Vector2f& A) const;
    
    Vector2f MultiplicationAssignment(const Vector2f& A);
        
    Vector2f operator*=(const Vector2f& A);
    
    

    Vector2f Division(float A) const;

    Vector2f operator/(float A) const;

    Vector2f DivisionAssignment(float A);
                                            
    Vector2f operator/=(float A);
    
    Vector2f Division(const Vector2f& A) const;

    Vector2f operator/(const Vector2f& A) const;

    Vector2f DivisionAssignment(const Vector2f& A);
                                            
    Vector2f operator/=(const Vector2f& A);
    
        
    
    float GetLengthSquared() const;
    
    float GetLength() const;
        
    float GetPolarPhi() const;
};



struct Vector3f
{
    float x, y, z;

    
    
    Vector3f(float x = 0.0f, float y = 0.0f, float z = 0.0f, bool set_spherical = false);
    
    
    
    bool EqualTo(const Vector3f& A) const;
       
    bool operator==(const Vector3f& A) const;

    bool NotEqualTo(const Vector3f& A) const;

    bool operator!=(const Vector3f& A) const;
    
    
    
    Vector3f Addition(const Vector3f& A) const;
    
    Vector3f operator+(const Vector3f& A) const;
    
    Vector3f AdditionAssignment(const Vector3f& A);
    
    Vector3f operator+=(const Vector3f& A);
    
    
    
    Vector3f Subtraction(const Vector3f& A) const;
    
    Vector3f operator-(const Vector3f& A) const;
        
    Vector3f SubtractionAssignment(const Vector3f& A);
        
    Vector3f operator-=(const Vector3f& A);

    

    Vector3f Multiplication(float A) const;
    
    Vector3f operator*(float A) const;
    
    Vector3f MultiplicationAssignment(float A);
        
    Vector3f operator*=(float A);
    
    Vector3f Multiplication(const Vector3f& A) const;
    
    Vector3f operator*(const Vector3f& A) const;
    
    Vector3f MultiplicationAssignment(const Vector3f& A);
        
    Vector3f operator*=(const Vector3f& A);
    
    

    Vector3f Division(float A) const;

    Vector3f operator/(float A) const;

    Vector3f DivisionAssignment(float A);
                                            
    Vector3f operator/=(float A);
    
    Vector3f Division(const Vector3f& A) const;

    Vector3f operator/(const Vector3f& A) const;

    Vector3f DivisionAssignment(const Vector3f& A);
                                            
    Vector3f operator/=(const Vector3f& A);
    
        
    
    float GetLengthSquared() const;
    
    float GetLength() const;
    
    float GetSphericalTheta() const;
    
    float GetSphericalPhi() const;
};



Vector2f To2D(const Vector3f& A);

Vector3f To3D(const Vector2f& A);



Vector3f CrossProduct(const Vector3f& A, const Vector3f& B);



float DotProduct(const Vector2f& A, const Vector2f& B);

float DotProduct(const Vector3f& A, const Vector3f& B);



float Angle(const Vector2f& A, const Vector2f& B);

float Angle(const Vector3f& A, const Vector3f& B);



Vector2f Normalize(const Vector2f& A);

Vector3f Normalize(const Vector3f& A);



Vector2f vabs(const Vector2f& A);

Vector3f vabs(const Vector3f& A);



Vector2f vmod(const Vector2f& A, const Vector2f& B);

Vector3f vmod(const Vector3f& A, const Vector3f& B);
}
#endif /* MGE_Vectors_hpp */
