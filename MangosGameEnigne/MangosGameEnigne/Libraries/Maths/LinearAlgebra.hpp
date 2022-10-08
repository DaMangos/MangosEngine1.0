#ifndef LinearAlgebra_hpp
#define LinearAlgebra_hpp

#define _USE_MATH_DEFINES

#define M_Ef        static_cast<float>(M_E)
#define M_LOG2Ef    static_cast<float>(M_LOG2E)
#define M_LOG10Ef   static_cast<float>(M_LOG10E)
#define M_LN2f      static_cast<float>(M_LN2)
#define M_LN10f     static_cast<float>(M_LN10)
#define M_PIf       static_cast<float>(M_PI)
#define M_PI_2f     static_cast<float>(M_PI_2)
#define M_PI_4f     static_cast<float>(M_PI_4)
#define M_1_PIf     static_cast<float>(M_1_PI)
#define M_2_PIf     static_cast<float>(M_2_PI)
#define M_2_SQRTPIf static_cast<float>(M_2_SQRTPI)
#define M_SQRT2f    static_cast<float>(M_SQRT2)
#define M_SQRT1_2f  static_cast<float>(M_SQRT1_2)

#include <iostream>
#include <compare>
#include <functional>
#include <array>
#include <cmath>

namespace mge
{
    struct float1;
    struct float2;
    struct float3;
    struct float2x2;
    struct float3x3;
    struct line2;
    struct line3;
    struct triangle2;
    struct triangle3;


    struct float2
    {
        float x, y;
        
        float2(float A = 0.0f);
        
        float2(float x, float y, bool polar = false);
        
        explicit float2(const float3& A);
                    
        auto operator<=>(const float2& A) const = default;
        
        float2 operator+(const float2& A) const;
            
        float2 operator-(const float2& A) const;
                    
        float2 operator*(const float2& A) const;
                    
        float2 operator/(const float2& A) const;
        
        float2 operator+=(const float2& A);
        
        float2 operator-=(const float2& A);
        
        float2 operator*=(const float2& A);

        float2 operator/=(const float2& A);
        
        float Dot(const float2& A) const;
        
        float LengthSquared() const;
        
        float Length() const;
        
        float PolarPhi() const;
        
        float2 Normalize() const;
        
        float Angle(const float2& A) const;
    };


    struct float3
    {
        float x, y, z;
        
        float3(float A = 0.0f);

        float3(float x, float y, float z, bool spherical = false);
        
        explicit float3(const float2& A);
                
        auto operator<=>(const float3& A) const = default;
        
        float3 operator+(const float3& A) const;
            
        float3 operator-(const float3& A) const;
                    
        float3 operator*(const float3& A) const;
                    
        float3 operator/(const float3& A) const;
        
        float3 operator+=(const float3& A);
        
        float3 operator-=(const float3& A);
        
        float3 operator*=(const float3& A);

        float3 operator/=(const float3& A);
        
        float Dot(const float3& A) const;
        
        float3 Cross(const float3& A) const;
        
        float LengthSquared() const;
        
        float Length() const;
        
        float SphericalTheta() const;
        
        float SphericalPhi() const;
        
        float3 Normalize() const;
        
        float Angle(const float3& A) const;
    };


    struct float2x2
    {
        std::array<std::array<float, 2>, 2> e;
         
        
        float2x2(float A = 0);

        float2x2(float A, float B, float C, float D);
        
        explicit float2x2(const float2& A, const float2& B, bool rows = false);
                
        bool operator==(const float2x2& A) const;
        
        bool operator!=(const float2x2& A) const;
        
        std::array<float, 2> operator[](int i) const;
        
        std::array<float, 2>& operator[](int i);

        float2x2 operator+(const float2x2& A) const;
            
        float2x2 operator-(const float2x2& A) const;
            
        float2x2 operator*(float A) const;
        
        float2   operator*(const float2& A) const;
        
        float2x2 operator*(const float2x2& A) const;
                
        float2x2 operator/(float A) const;
            
        float2x2 operator+=(const auto& A);
        
        float2x2 operator-=(const auto& A);
        
        float2x2 operator*=(const auto& A);
        
        float2x2 operator/=(const auto& A);
        
        float2x2 Inverse() const;
        
        float2x2 Transpose() const;
        
        float Det() const;
        
        float Trace() const;
    };


    struct float3x3
    {
        std::array<std::array<float, 3>, 3> e;
        
        float3x3(float A = 0.0f);
        
        float3x3(float A, float B, float C,
                 float D, float E, float F,
                 float G, float H, float I);
        
        explicit float3x3(const float3& A, const float3& B, const float3& C, bool rows = false);
                
        bool operator==(const float3x3& A) const;
        
        bool operator!=(const float3x3& A) const;
        
        std::array<float, 3> operator[](int i) const;
        
        std::array<float, 3>& operator[](int i);

        float3x3 operator+(const float3x3& A) const;
            
        float3x3 operator-(const float3x3& A) const;
            
        float3x3 operator*(float A) const;
        
        float3x3 operator*(const float3x3& A) const;
            
        float3   operator*(const float3& A) const;
        
        float3x3 operator/(float A) const;
            
        float3x3 operator+=(const auto& A);
        
        float3x3 operator-=(const auto& A);

        float3x3 operator*=(const auto& A);

        float3x3 operator/=(const auto& A);
        
        float3x3 Inverse() const;
        
        float3x3 Transpose() const;
        
        float Det() const;
        
        float Trace() const;
    };


    struct line2
    {
        std::array<float2, 2> p;
        
        
        line2(const float2& A = 0.0f, const float2& B = 0.0f);
        
        float2 operator[](int i) const;
        
        float2& operator[](int i);

        float2 Direction() const;
        
        float2 PointOnLine(float t) const;
        
        bool LiesOnLine(const float2& A) const;
    };


    struct line3
    {
        std::array<float3, 2> p;
        
        
        line3(const float3& A = 0.0f, const float3& B = 0.0f);
        
        float3 operator[](int i) const;
        
        float3& operator[](int i);
            
        float3 Direction() const;
        
        float3 PointOnLine(float t) const;
        
        bool LiesOnLine(const float3& A) const;
    };


    struct triangle2
    {
        std::array<float2, 3> v;
        
        
        triangle2(const float2& A = 0.0f, const float2& B = 0.0f, const float2& C = 0.0f);
        
        float2 operator[](int i) const;
        
        float2& operator[](int i);

        float2 Center() const;
        
        bool Inside(const float2& A) const;
    };


    struct triangle3
    {
        std::array<float3, 3> v;
        
        
        triangle3(const float3& A = 0.0f, const float3& B = 0.0f, const float3& C = 0.0f);
                
        float3 operator[](int i) const;
        
        float3& operator[](int i);
        
        float3 Normal() const;
        
        float3 Center() const;
        
        float3x3 TransitionMatrix() const;
        
        float2 ReduceDimensionsOfPoint(const float3& A) const;
        
        triangle2 ReduceDimensionsOfVertices() const;
        
        bool LiesOnPlane(const float3& A) const;
        
        bool Inside(const float3& A) const;
        
        bool Behind(const triangle3& A) const;
    };


    float2 Intersection(const line2& A, const line2& B);

    float3 Intersection(const triangle3& triangle3, const line3& line);

    float3 Intersection(const float3& triangle3_normal, const float3& triangle3_point, const line3& line);

    float ShortestDistance(const line2& line, const float2& point);

    float ShortestDistance(const float3& plane_normal, const float3& plane_point, const float3& point);

    float ShortestDistance(const triangle3& plane, const float3& point);
}   // end of namespace mge

namespace std
{
    ostream& operator<<(ostream& stream, const mge::float2& A);

    ostream& operator<<(ostream& stream, const mge::float3& A);

    ostream& operator<<(ostream& stream, const mge::float2x2& A);

    ostream& operator<<(ostream& stream, const mge::float3x3& A);
    
    template<>
    struct hash<mge::float2>
    {
        size_t operator()(const mge::float2& A) const;
    };
    
    template<>
    struct hash<mge::float3>
    {
        size_t operator()(const mge::float3& A) const;
    };
    
    template<>
    struct hash<mge::float2x2>
    {
        size_t operator()(const mge::float2x2& A) const;
    };
    
    template<>
    struct hash<mge::float3x3>
    {
        size_t operator()(const mge::float3x3& A) const;
    };
    
}   // end of namespace std

mge::float2 fabs(const mge::float2& A);

mge::float3 fabs(const mge::float3& A);

mge::float2x2 fabs(const mge::float2x2& A);

mge::float3x3 fabs(const mge::float3x3& A);

mge::float2 fmod(const mge::float2& A, const mge::float2& B);

mge::float3 fmod(const mge::float3& A, const mge::float3& B);

mge::float2x2 fmod(const mge::float2x2& A, const mge::float2x2& B);

mge::float3x3 fmod(const mge::float3x3& A, const mge::float3x3& B);


#endif

