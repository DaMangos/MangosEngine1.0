//
//  MGE_sCamara.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#ifndef MGE_sCamara_hpp
#define MGE_sCamara_hpp

#include <stdio.h>
#include "MGE_sObject.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace mge
{
class sCamera: public Spawnable
{
public:
    
    sCamera(unsigned int window_width, unsigned int window_hight, float field_of_view, float render_distance);
    
    
    
    Vector3f GetLensNormal() const;
    
    std::vector<Plane3f> GetVisableTrianglesWorld(const std::vector<sObject>& scene) const;

    std::vector<Triangle2f> GetVisableTrianglesScreen(const Plane3f& visable_triangle_world) const;

private:
    
    float window_width;
    
    float window_hight;
    
    float render_distance;

    float field_of_view;
    
    float GetFocalLength() const;
    
    
    Vector3f GetLocalLensLocation() const;
    
    Matrix3x3f GetLensTransitionMatrix() const;
    
    Vector2f GetVertexPojection(const Vector3f& world_vertex_location) const;
    
    Triangle2f GetTrianglePojection(const Plane3f& triangle) const;

    bool IsTriangleVisable(const Plane3f& triangle) const;
        
    std::vector<Triangle2f> ClipTriangleAgainstBoundary(const Triangle2f& triangle, const Line2f& Boundary) const;
    
    std::vector<Triangle2f> GetClipTriangles(const Triangle2f& triangle) const;
};
}
#endif /* MGE_sCamara_hpp */
