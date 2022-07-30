//
//  MGE_Stereometry.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#ifndef MGE_Stereometry_hpp
#define MGE_Stereometry_hpp

#include <stdio.h>
#include "MGE_Geometry.hpp"

namespace mge
{
struct Line3f
{
    Vector3f point[2];
    
    
        
    Line3f(Vector3f point_0 = Vector3f(), Vector3f point_1 = Vector3f());
    
    
    
    Vector3f GetDirection() const;
    
    Vector3f GetPointOnLine(float t) const;
    
    bool LiesOnLine(const Vector3f& A) const;
};



struct Plane3f
{
    Vector3f point[3];
    
    
        
    Plane3f(Vector3f point_0 = Vector3f(), Vector3f point_1 = Vector3f(), Vector3f point_2 = Vector3f());
    
    
    
    Vector3f GetNormal() const;

    Vector3f GetCenter() const;
    
    Matrix3x3f GetTransitionMatrix() const;
    
    Vector2f ReduceDimensions(const Vector3f& A) const;
    
    Triangle2f ReduceDimensionsOfPoints() const;
    
    bool LiesOnPlane(const Vector3f& A) const;
    
};



Vector3f Plane3fLine3fIntersection(const Plane3f& plane, const Line3f& line);

Vector3f Plane3fLine3fIntersection(const Vector3f& plane_normal, const Vector3f& plane_point, const Line3f& line);
}
#endif /* MGE_Stereometry_hpp */
