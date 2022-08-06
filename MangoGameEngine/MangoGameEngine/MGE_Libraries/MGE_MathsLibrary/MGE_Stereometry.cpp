//
//  MGE_Stereometry.cpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#include "MGE_Stereometry.hpp"
namespace mge
{
Line3f::Line3f(Vector3f point_0, Vector3f point_1)
{
    this->point[0] = point_0;
    this->point[1] = point_1;
}



Vector3f Line3f::GetDirection() const
{
    return (this->point[0] - this->point[1]);
}

Vector3f Line3f::GetPointOnLine(float t) const
{
    return this->point[0] + (this->GetDirection() * t);
}

bool Line3f::LiesOnLine(const Vector3f& A) const
{
    if ((A.x - this->point[1].x) / this->GetDirection().x != (A.y - this->point[1].y) / this->GetDirection().y)
    {
        return false;
    }
    
    if ((A.y - this->point[1].y) / this->GetDirection().y != (A.z - this->point[1].z) / this->GetDirection().z)
    {
        return false;
    }
    
    if ((A.z - this->point[1].z) / this->GetDirection().z != (A.x - this->point[1].x) / this->GetDirection().x)
    {
        return false;
    }

    return true;
}



Plane3f::Plane3f(Vector3f point_0, Vector3f point_1, Vector3f point_2)
{
    this->point[0] = point_0;
    this->point[1] = point_1;
    this->point[2] = point_2;
}



Vector3f Plane3f::GetNormal() const
{
    return Normalize(CrossProduct(this->point[1] - this->point[0], this->point[2] - this->point[0]));
}

Vector3f Plane3f::GetCenter() const
{
    return (this->point[0] + this->point[1] + this->point[2]) / 3.0f;
}

Matrix3x3f Plane3f::GetTransitionMatrix() const
{
    Vector3f base_0 = Normalize(this->point[1] - this->point[0]);
    Vector3f Base_1 = CrossProduct(this->GetNormal(), base_0);
    
    return Matrix3x3f(base_0, Base_1, this->GetNormal()).Inverse();
}

bool Plane3f::LiesOnPlane(const Vector3f& A) const
{
    return DotProduct(this->GetNormal(), A - this->point[0]) == 0.0f;
}

Vector2f Plane3f::ReduceDimensions(const Vector3f& A) const
{
    return To2D(this->GetTransitionMatrix() * A);
}

Triangle2f Plane3f::ReduceDimensionsOfPoints() const
{
    Matrix3x3f transition_matrix = this->GetTransitionMatrix();
    
    return Triangle2f(To2D(transition_matrix * this->point[0]),
                      To2D(transition_matrix * this->point[1]),
                      To2D(transition_matrix * this->point[2]));
}

Vector3f Plane3fLine3fIntersection(const Plane3f& plane, const Line3f& line)
{
    Vector3f plane_normal = plane.GetNormal();
    
    return line.GetPointOnLine(DotProduct(plane_normal, line.point[0] - plane.point[0]) / DotProduct(plane_normal, line.GetDirection()));
}

Vector3f Plane3fLine3fIntersection(const Vector3f& plane_normal, const Vector3f& plane_point, const Line3f& line)
{
    return line.GetPointOnLine(DotProduct(plane_normal, line.point[0] - plane_point) / DotProduct(plane_normal, line.GetDirection()));
}

float SignedShortedDistancePlane(const Vector3f& plane_normal, const Vector3f& plane_point, const Vector3f& point)
{
    return DotProduct(plane_normal, point - plane_point);
}
}
