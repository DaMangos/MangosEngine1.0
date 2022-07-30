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

namespace mge
{
class sCamera: public Spawnable
{
    float window_width;
    
    float window_hight;
    
    float render_distance;

    float field_of_view;
    
    float GetFocalLength() const;
    
    Vector3f GetLensNormal() const;
    
    Vector3f GetLocalLensLocation() const;
    
    Matrix3x3f GetLensTransitionMatrix() const;
    
    bool IsTriangleVisable(const Plane3f& triangle) const;
    
    Vector2f GetVertexPojection(const Vector3f& world_vertex_location) const;

    
    
    std::vector<Plane3f> GetVisableTriangles(const std::vector<sObject>& scene);
        
    Triangle2f GetTrianglePojection(const Plane3f& triangle) const;
    
    std::vector<Triangle2f> ClipTriangle(const Triangle2f& triangle);
        
public:
    
    sCamera(unsigned int window_width, unsigned int window_hight, float field_of_view, float render_distance);
};
}
#endif /* MGE_sCamara_hpp */
