#include "LinearAlgebra.hpp"

namespace mge
{
    float2::float2(float A)
    :   x(A),
        y(A)
    {}

    float2::float2(float x, float y, bool polar)
    :   x(polar ? fabs(x) * cos(y) : x),
        y(polar ? fabs(x) * sin(y) : y)
    {}

    float2::float2(const float3& A)
    :   x(A.x),
        y(A.y)
    {}

    float2 float2::operator+(const float2& A) const
    {
        return float2(this->x + A.x, this->y + A.y);
    }

    float2 float2::operator-(const float2& A) const
    {
        return float2(this->x - A.x, this->y - A.y);
    }

    float2 float2::operator*(const float2& A) const
    {
        return float2(this->x * A.x, this->y * A.y);
    }

    float2 float2::operator/(const float2& A) const
    {
        return float2(this->x / A.x, this->y / A.y);
    }

    float2 float2::operator+=(const float2& A)
    {
        *this = *this + A;
        
        return *this;
    }

    float2 float2::operator-=(const float2& A)
    {
        *this = *this - A;
        
        return *this;
    }

    float2 float2::operator*=(const float2& A)
    {
        *this = *this * A;
        
        return *this;
    }

    float2 float2::operator/=(const float2& A)
    {
        *this = *this / A;
        
        return *this;
    }

    float float2::Dot(const float2& A) const
    {
        return this->x * A.x + this->y * A.y;
    }

    float float2::LengthSquared() const
    {
        return this->Dot(*this);
    }

    float float2::Length() const
    {
        return sqrt(this->LengthSquared());
    }

    float float2::PolarPhi() const
    {
        return fmod(atan2(this->y, this->x), 2.0f * M_PIf);
    }

    float2 float2::Normalize() const
    {
        return *this / this->Length();
    }

    float float2::Angle(const float2& A) const
    {
        return acos(this->Dot(A) / (this->Length() * A.Length()));
    }
    
    float3::float3(float A)
    :   x(A),
        y(A),
        z(A)
    {}


    float3::float3(float x, float y, float z, bool spherical)
    :   x(spherical ? fabs(x) * sin(y) * cos(z) : x),
        y(spherical ? fabs(x) * sin(y) * sin(z) : y),
        z(spherical ? fabs(x) * cos(y) : z)
    {}

    float3::float3(const float2& A)
    :   x(A.x),
        y(A.y),
        z(0.0f)
    {}

    float3 float3::operator+(const float3& A) const
    {
        return float3(this->x + A.x, this->y + A.y, this->z + A.z);
    }

    float3 float3::operator-(const float3& A) const
    {
        return float3(this->x - A.x, this->y - A.y, this->z - A.z);
    }

    float3 float3::operator*(const float3& A) const
    {
        return float3(this->x * A.x, this->y * A.y, this->z * A.z);
    }

    float3 float3::operator/(const float3& A) const
    {
        return float3(this->x / A.x, this->y / A.y, this->z / A.z);
    }

    float3 float3::operator+=(const float3& A)
    {
        *this = *this + A;
        
        return *this;
    }

    float3 float3::operator-=(const float3& A)
    {
        *this = *this - A;
        
        return *this;
    }

    float3 float3::operator*=(const float3& A)
    {
        *this = *this * A;
        
        return *this;
    }

    float3 float3::operator/=(const float3& A)
    {
        *this = *this / A;
        
        return *this;
    }

    float float3::Dot(const float3& A) const
    {
        return this->x * A.x + this->y * A.y + this->z * A.z;
    }

    float3 float3::Cross(const float3& A) const
    {
        return float3((this->y * A.z) - (this->z * A.y),
                      (this->z * A.x) - (this->x * A.z),
                      (this->x * A.y) - (this->y * A.x));
    }

    float float3::LengthSquared() const
    {
        return this->Dot(*this);
    }

    float float3::Length() const
    {
        return sqrt(this->LengthSquared());
    }

    float float3::SphericalTheta() const
    {
        return acos(this->z / this->Length());
    }

    float float3::SphericalPhi() const
    {
        return fmod(atan2(this->y, this->x), 2.0f * M_PIf);
    }

    float3 float3::Normalize() const
    {
        return *this / this->Length();
    }

    float float3::Angle(const  float3& A) const
    {
        return acos(this->Dot(A) / (this->Length() * A.Length()));
    }

    float2x2::float2x2(float A)
    :   e{A, 0.0f, 0.0f, A}
    {}
    
    float2x2::float2x2(float A, float B, float C, float D)
    :   e{A, B, C, D}
    {}

    float2x2::float2x2(const float2& A, const float2& B, bool rows)
    :   e{A.x, rows ? A.y : B.x, rows ? B.x : A.y, B.y}
    {}

    bool float2x2::operator==(const float2x2& A) const
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (this->e[i][j] != A[i][j])
                {
                    return false;
                }
            }
        }
        
        return true;
    }

    bool float2x2::operator!=(const float2x2& A) const
    {
        return !(*this == A);
    }

    std::array<float, 2> float2x2::operator[](int i) const
    {
        return this->e[i];
    }
    
    std::array<float, 2>& float2x2::operator[](int i)
    {
        return this->e[i];
    }

    float2x2 float2x2::operator+(const float2x2& A) const
    {
        float2x2 result;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result[i][j] = this->e[i][j] + A[i][j];
            }
        }
        
        return result;
    }

    float2x2 float2x2::operator-(const float2x2& A) const
    {
        {
            float2x2 result;
            
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    result[i][j] = this->e[i][j] - A[i][j];
                }
            }
            
            return result;
        }
    }

    float2x2 float2x2::operator*(float A) const
    {
        float2x2 result;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result[i][j] = this->e[i][j] * A;
            }
        }
        
        return result;
    }

    float2x2 float2x2::operator*(const float2x2& A) const
    {
        float2x2 result;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    result[i][j] = this->e[i][k] * A[k][j];
                }
            }
        }
        
        return result;
    }

    float2 float2x2::operator*(const float2& A) const
    {
        return float2(this->e[0][0] * A.x + this->e[0][1] * A.y,
                      this->e[1][0] * A.x + this->e[1][1] * A.y);
    }

    float2x2 float2x2::operator/(float A) const
    {
        float2x2 result;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result[i][j] = this->e[i][j] / A;
            }
        }
        
        return result;
    }

    float2x2 float2x2::operator+=(const auto& A)
    {
        *this = *this + A;
        
        return *this;
    }

    float2x2 float2x2::operator-=(const auto& A)
    {
        *this = *this - A;
        
        return *this;
    }

    float2x2 float2x2::operator*=(const auto& A)
    {
        *this = *this * A;
        
        return *this;
    }

    float2x2 float2x2::operator/=(const auto& A)
    {
        *this = *this / A;
        
        return *this;
    }

    float2x2 float2x2::Inverse() const
    {
        float det = this->Det();
        
        return float2x2(this->e[1][1] / det,
                       -this->e[0][1] / det,
                       -this->e[1][0] / det,
                        this->e[0][0] / det);
    }

    float2x2 float2x2::Transpose() const
    {
        float2x2 result;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result[i][j] = this->e[j][i];
            }
        }
        
        return result;
    }

    float float2x2::Det() const
    {
        return this->e[0][0] * this->e[1][1] - this->e[0][1] * this->e[1][0];
    }

    float float2x2::Trace() const
    {
        return this->e[0][0] + this->e[1][1];
    }
    
    float3x3::float3x3(float A)
    :   e{A, 0.0f, 0.0f, 0.0f, A, 0.0f, 0.0f, 0.0f, A}
    {}

    float3x3::float3x3(float A, float B, float C,
                       float D, float E, float F,
                       float G, float H, float I)
    :   e{A, B, C, D, E, F, G, H, I}
    {}

    float3x3::float3x3(const float3& A, const float3& B, const float3& C, bool rows)
    :   e{A.x, rows ? A.y : B.x, rows ? A.z : C.x, rows ? B.x : A.y, B.y, rows ? B.z : C.y, rows ? A.z : C.x, rows ? C.y : B.z, C.z}
    {}

    bool float3x3::operator==(const float3x3& A) const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (this->e[i][j] != A[i][j])
                {
                    return false;
                }
            }
        }
        
        return true;
    }

    bool float3x3::operator!=(const float3x3& A) const
    {
        return !(*this == A);
    }

    std::array<float, 3> float3x3::operator[](int i) const
    {
        return this->e[i];
    }
    
    std::array<float, 3>& float3x3::operator[](int i)
    {
        return this->e[i];
    }

    float3x3 float3x3::operator+(const float3x3& A) const
    {
        float3x3 result;
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result[i][j] = this->e[i][j] + A[i][j];
            }
        }
        
        return result;
    }

    float3x3 float3x3::operator-(const float3x3& A) const
    {
        {
            float3x3 result;
            
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    result[i][j] = this->e[i][j] - A[i][j];
                }
            }
            
            return result;
        }
    }

    float3x3 float3x3::operator*(float A) const
    {
        float3x3 result;
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result[i][j] = this->e[i][j] * A;
            }
        }
        
        return result;
    }

    float3x3 float3x3::operator*(const float3x3& A) const
    {
        float3x3 result;
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    result[i][j] = this->e[i][k] * A[k][j];
                }
            }
        }
        
        return result;
    }

    float3 float3x3::operator*(const float3& A) const
    {
        return float3(this->e[0][0] * A.x + this->e[0][1] * A.y + this->e[0][2] * A.z,
                      this->e[1][0] * A.x + this->e[1][1] * A.y + this->e[1][2] * A.z,
                      this->e[2][0] * A.x + this->e[2][1] * A.y + this->e[2][2] * A.z);
    }

    float3x3 float3x3::operator/(float A) const
    {
        float3x3 result;
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result[i][j] = this->e[i][j] / A;
            }
        }
        
        return result;
    }

    float3x3 float3x3::operator+=(const auto& A)
    {
        *this = *this + A;
        
        return *this;
    }

    float3x3 float3x3::operator-=(const auto& A)
    {
        *this = *this - A;
        
        return *this;
    }

    float3x3 float3x3::operator*=(const auto& A)
    {
        *this = *this * A;
        
        return *this;
    }

    float3x3 float3x3::operator/=(const auto& A)
    {
        *this = *this / A;
        
        return *this;
    }

    float3x3 float3x3::Inverse() const
    {
        float det = this->Det();
        
        return float3x3((this->e[1][1] * this->e[2][2] - this->e[1][2] * this->e[2][1]) / det,
                        (this->e[0][2] * this->e[2][1] - this->e[0][1] * this->e[2][2]) / det,
                        (this->e[0][1] * this->e[1][2] - this->e[0][2] * this->e[1][1]) / det,
                        (this->e[1][2] * this->e[2][0] - this->e[1][0] * this->e[2][2]) / det,
                        (this->e[0][0] * this->e[2][2] - this->e[0][2] * this->e[2][0]) / det,
                        (this->e[0][2] * this->e[1][0] - this->e[0][0] * this->e[1][2]) / det,
                        (this->e[1][0] * this->e[2][1] - this->e[1][1] * this->e[2][0]) / det,
                        (this->e[0][1] * this->e[2][0] - this->e[0][0] * this->e[2][1]) / det,
                        (this->e[0][0] * this->e[1][1] - this->e[0][1] * this->e[1][0]) / det);
    }

    float3x3 float3x3::Transpose() const
    {
        float3x3 result;
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result[i][j] = this->e[j][i];
            }
        }
        
        return result;
    }

    float float3x3::Det() const
    {
        return this->e[0][0] * (this->e[1][1] * this->e[2][2] - this->e[1][2] * this->e[2][1]) +
               this->e[0][1] * (this->e[1][2] * this->e[2][0] - this->e[1][0] * this->e[2][2]) +
               this->e[0][2] * (this->e[1][0] * this->e[2][1] - this->e[1][1] * this->e[2][0]);
    }

    float float3x3::Trace() const
    {
        return this->e[0][0] + this->e[1][1] + this->e[2][2];
    }

    line2::line2(const float2& A, const float2& B)
    :   p{A, B}
    {}

    float2 line2::operator[](int i) const
    {
        return this->p[i];
    }
    
    float2& line2::operator[](int i)
    {
        return this->p[i];
    }

    float2 line2::Direction() const
    {
        return (this->p[0] - this->p[1]);
    }

    float2 line2::PointOnLine(float t) const
    {
        return this->p[0] + this->Direction() * t;
    }

    bool line2::LiesOnLine(const float2& A) const
    {
        if ((A.x - this->p[1].x) / this->Direction().x != (A.y - this->p[1].y) / this->Direction().y)
        {
            return false;
        }
        
        return true;
    }

    line3::line3(const float3& A, const float3& B)
    :   p{A, B}
    {}

    float3 line3::operator[](int i) const
    {
        return this->p[i];
    }
    
    float3& line3::operator[](int i)
    {
        return this->p[i];
    }

    float3 line3::Direction() const
    {
        return this->p[0] - this->p[1];
    }

    float3 line3::PointOnLine(float t) const
    {
        return this->p[0] + this->Direction() * t;
    }

    bool line3::LiesOnLine(const float3& A) const
    {
        if ((A.x - this->p[1].x) / this->Direction().x != (A.y - this->p[1].y) / this->Direction().y)
        {
            return false;
        }
        
        if ((A.y - this->p[1].y) / this->Direction().y != (A.z - this->p[1].z) / this->Direction().z)
        {
            return false;
        }
        
        if ((A.z - this->p[1].z) / this->Direction().z != (A.x - this->p[1].x) / this->Direction().x)
        {
            return false;
        }
        
        return true;
    }

    triangle2::triangle2(const float2& A, const float2& B, const float2& C)
    :   v{A, B, C}
    {}

    float2 triangle2::operator[](int i) const
    {
        return this->v[i];
    }
    
    float2& triangle2::operator[](int i)
    {
        return this->v[i];
    }

    float2 triangle2::Center() const
    {
        return (this->v[0] + this->v[1] + this->v[2]) / 3.0f;
    }

    bool triangle2::Inside(const float2& A) const
    {
        float2 v_1 = this->v[1] - this->v[0];
        
        float2 v_2 = this->v[2] - this->v[0];
        
        float a = (float2x2(A, v_2).Det() - float2x2(this->v[0], v_2).Det()) / float2x2(v_1, v_2).Det();
        
        float b = (float2x2(A, v_1).Det() - float2x2(this->v[0], v_1).Det()) / float2x2(v_1, v_2).Det();
        
        return a > 0.0f && b < 0.0f && a - b < 1.0f;
    }

    triangle3::triangle3(const float3& A, const float3& B, const float3& C)
    :   v{A, B, C}
    {}

    float3 triangle3::operator[](int i) const
    {
        return this->v[i];
    }

    float3& triangle3::operator[](int i)
    {
        return this->v[i];
    }
    
    float3 triangle3::Normal() const
    {
        return (this->v[1] - this->v[0]).Cross(this->v[2] - this->v[0]).Normalize();
    }

    float3 triangle3::Center() const
    {
        return (this->v[0] + this->v[1] + this->v[2]) / 3.0f;
    }

    float3x3 triangle3::TransitionMatrix() const
    {
        float3 normal = this->Normal();
        float theta = this->Normal().SphericalTheta();
        float phi   = this->Normal().SphericalPhi();

        return float3x3(cos(theta) * cos(phi), cos(theta) * sin(phi), -sin(theta), -sin(phi), cos(phi), 0.0f, normal.x, normal.y, normal.z);
    }

    float2 triangle3::ReduceDimensionsOfPoint(const float3& A) const
    {
        return float2(this->TransitionMatrix() * A);
    }

    triangle2 triangle3::ReduceDimensionsOfVertices() const
    {
        return triangle2(ReduceDimensionsOfPoint(this->v[0]),
                         ReduceDimensionsOfPoint(this->v[1]),
                         ReduceDimensionsOfPoint(this->v[2]));
    }

    bool triangle3::LiesOnPlane(const float3& A) const
    {
        return this->Normal().Dot(A - this->v[0]) == 0.0f;
    }

    bool triangle3::Inside(const float3& A) const
    {
        if (this->LiesOnPlane(A))
        {
            return this->ReduceDimensionsOfVertices().Inside(float2(A));
        }
        
        return false;
    }

    float2 Intersection(const line2& A, const line2& B)
    {
        return A.PointOnLine((float2x2(B[0].x - A[0].x, B[1].x - B[0].x, A[0].y - B[0].y, B[0].y - B[1].y).Det() /
                              float2x2(A[1].x - A[0].x, B[0].x - B[1].x, A[0].y - A[1].y, B[1].y - B[0].y).Det())) ;
    }

    float3 Intersection(const triangle3& plane, const line3& line)
    {
        return line.PointOnLine(plane.Normal().Dot(plane[0] - line[0]) / plane.Normal().Dot(line.Direction()));
    }

    float3 Intersection(const float3& plane_normal, const float3& plane_point, const line3& line)
    {
        return line.PointOnLine(plane_normal.Dot(plane_point - line[0]) / plane_normal.Dot(line.Direction()));
    }

    float ShortestDistance(const line2& line, const float2& point)
    {
        return float2x2(point - line[0], line[1] - line[0]).Det();
    }

    float ShortestDistance(const float3& plane_normal, const float3& plane_point, const float3& point)
    {
        return plane_normal.Dot(point - plane_point);
    }

    float ShortestDistance(const triangle3& plane, const float3& point)
    {
        return plane.Normal().Dot(point - plane[0]);
    }
}

namespace std
{
    ostream& operator<<(ostream& stream, const mge::float2& A)
    {
        stream  << A.x << ", " << A.y;
        
        return stream;
    }
    
    ostream& operator<<(ostream& stream, const mge::float3& A)
    {
        stream << A.x << ", " << A.y << ", " << A.z;
        
        return stream;
    }
    
    ostream& operator<<(ostream& stream, const mge::float2x2& A)
    {
        stream << A[0][0] << ", " << A[0][1] << "\n"
               << A[1][0] << ", " << A[1][1] << "\n";
        
        return stream;
    }
    
    ostream& operator<<(ostream& stream, const mge::float3x3& A)
    {
        stream << A[0][0] << ", " << A[0][1] << ", " << A[0][2] << "\n"
               << A[1][0] << ", " << A[1][1] << ", " << A[1][2] << "\n"
               << A[2][0] << ", " << A[2][1] << ", " << A[2][2] << "\n";
        return stream;
    }
    
    size_t hash<mge::float2>::operator()(const mge::float2& A) const
    {
        size_t h1 = hash<float>{}(A.x);
        size_t h2 = hash<float>{}(A.y);
        
        return h1 ^ (h2 << 1);
    }
    
    size_t hash<mge::float3>::operator()(const mge::float3& A) const
    {
        size_t h1 = hash<float>{}(A.x);
        size_t h2 = hash<float>{}(A.y);
        size_t h3 = hash<float>{}(A.z);
        
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
    
    size_t hash<mge::float2x2>::operator()(const mge::float2x2& A) const
    {
        size_t result;
        
        int k = 0;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                k++;

                result ^= hash<float>{}(A[i][j]) << k;
            }
        }
        
        return result;
    }
    
    size_t hash<mge::float3x3>::operator()(const mge::float3x3& A) const
    {
        size_t result;
        
        int k = 0;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                k++;
                
                result ^= hash<float>{}(A[i][j]) << k;
            }
        }
        
        return result;
    }
}

mge::float2 fabs(const mge::float2& A)
{
    return mge::float2(fabs(A.x), fabs(A.y));
}

mge::float3 fabs(const mge::float3& A)
{
    return mge::float3(fabs(A.x), fabs(A.y), fabs(A.z));
}

mge::float2x2 fabs(const mge::float2x2& A)
{
    return mge::float2x2(fabs(A[0][0]), fabs(A[1][0]), fabs(A[0][1]), fabs(A[1][1]));
}

mge::float3x3 fabs(const mge::float3x3& A)
{
    return mge::float3x3(fabs(A[0][0]), fabs(A[0][1]), fabs(A[0][2]),
                         fabs(A[1][0]), fabs(A[1][1]), fabs(A[1][2]),
                         fabs(A[2][0]), fabs(A[2][1]), fabs(A[2][2]));
}

mge::float2 fmod(const mge::float2& A, const mge::float2& B)
{
    return mge::float2(fmod(A.x, B.x), fmod(A.y, B.y));
}

mge::float3 fmod(const mge::float3& A, const mge::float3& B)
{
    return mge::float3(fmod(A.x, B.x), fmod(A.y, B.y), fmod(A.z, B.z));
}

mge::float2x2 fmod(const mge::float2x2& A, const mge::float2x2& B)
{
    return mge::float2x2(fmod(A[0][0], B[0][0]), fmod(A[1][0], B[1][0]), fmod(A[0][1], B[0][1]), fmod(A[1][1], B[1][1]));
    
}

mge::float3x3 fmod(const mge::float3x3& A, const mge::float3x3& B)
{
    return mge::float3x3(fmod(A[0][0], B[0][0]), fmod(A[0][1], B[0][1]), fmod(A[0][2], B[0][2]),
                         fmod(A[1][0], B[1][0]), fmod(B[1][1], A[1][1]), fmod(A[1][2], B[1][2]),
                         fmod(A[2][0], B[2][0]), fmod(B[2][1], A[2][1]), fmod(A[2][2], B[2][2]));
}
