//
//  MGE_Geometry.cpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#include "MGE_Geometry.hpp"

namespace mge
{
Line2f::Line2f(Vector2f point_0, Vector2f point_1)
{
    this->point[0] = point_0;
    this->point[1] = point_1;
}



Vector2f Line2f::GetDirection() const
{
    return (this->point[0] - this->point[1]);
}

Vector2f Line2f::GetPointOnLine(float t) const
{
    return this->point[0] + ((this->point[1] - this->point[0]) * t);
}



Triangle2f::Triangle2f(Vector2f vertex_0, Vector2f vertex_1, Vector2f vertex_2)
{
    this->vertex[0] = vertex_0;
    this->vertex[1] = vertex_1;
    this->vertex[2] = vertex_2;
}



Vector2f Triangle2f::GetCenter()
{
    return (this->vertex[0] + this->vertex[1] + this->vertex[2]) / 3.0f;
}

bool Triangle2f::IsInside(Vector2f A)
{
    Vector2f local_vertex_1 = this->vertex[1] = this->vertex[0];
    Vector2f local_vertex_2 = this->vertex[2] - this->vertex[0];
    
    float a = (Determinant(Matrix2x2f(A, local_vertex_2)) - Determinant(Matrix2x2f(this->vertex[0], local_vertex_2))) /
               Determinant(Matrix2x2f(local_vertex_1, local_vertex_2));
    
    float b = (Determinant(Matrix2x2f(A, local_vertex_1)) - Determinant(Matrix2x2f(this->vertex[0], local_vertex_1))) /
               Determinant(Matrix2x2f(local_vertex_1, local_vertex_2));
    
    if (a > 0.0f && b < 0.0f && a - b < 1.0f)
    {
        return true;
    }
    
    return false;
}



Vector2f TwoLine2fIntersection(const Line2f& line_0, const Line2f& line_1)
{
    Vector2f value;
    
    float x1 = line_0.point[0].x;
    float y1 = line_0.point[0].y;
    
    float x2 = line_0.point[1].x;
    float y2 = line_0.point[1].y;
    
    float x3 = line_1.point[0].x;
    float y3 = line_1.point[0].y;
    
    float x4 = line_1.point[1].x;
    float y4 = line_1.point[1].y;
    
    
    return line_0.GetPointOnLine(Determinant(Matrix2x2f(x1 - x3, x3 - x4, y1 - y3, y3 - y4)) /
                                 Determinant(Matrix2x2f(x1 - x2, x3 - x4, y1 - y2, y3 - y4)));
}

float SignedShortestDistanceLine(const Line2f& line, const Vector2f& point)
{
    return Determinant(Matrix2x2f(point - line.point[0], line.point[1] - line.point[0]));
}
}
