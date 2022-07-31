//
//  MGE_Geometry.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#ifndef MGE_Geometry_hpp
#define MGE_Geometry_hpp

#include <stdio.h>
#include "MGE_Matrices.hpp"

namespace mge
{
struct Line2f
{
    Vector2f point[2];
    
    

    Line2f(Vector2f point_0 = Vector2f(), Vector2f point_1 = Vector2f());
    
    
    
    Vector2f GetDirection() const;
    
    Vector2f GetPointOnLine(float t) const;
    
    float SignedShortestDistance(const Vector2f& A) const;
};



struct Triangle2f
{
    Vector2f vertex[3];
    
    
    
    Triangle2f(Vector2f vertex_0 = Vector2f(), Vector2f vertex_1 = Vector2f(), Vector2f vertex_2 = Vector2f());
    
    
    
    Vector2f GetCenter();

    bool IsInside(Vector2f A);
};



Vector2f TwoLine2fIntersection(const Line2f& line_0, const Line2f& line_1);
}
#endif /* MGE_Geometry_hpp */
