//
//  MGE_sCamara.cpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#include "MGE_sCamara.hpp"


namespace mge
{
sCamera::sCamera(unsigned int window_width, unsigned int window_hight, float field_of_view, float render_distance)
{
    this->window_width    = (float)window_width;
    this->window_hight    = (float)window_hight;
    this->field_of_view   = fmod(field_of_view, (pi / 2.0f) - (2.0f * (pi / 180.f)) + (pi / 180.f));
    this->render_distance = fmax(render_distance, 2.0f * GetFocalLength());
    this->world_rotation  = mge::Vector3f(0.0f, pi / 2.0f, 0.0f);
}



std::vector<Plane3f> sCamera::GetVisableTrianglesWorld(const std::vector<sObject>& scene) const
{
    std::vector<Plane3f> visable_triangles;
    
    for (auto object: scene)
    {
        int number_of_triangles = (int)object.mesh.size();
        
        for (int i = 0; i < number_of_triangles; i++)
        {
            if (this->IsTriangleVisable(object.GetMeshTriangle(i)))
            {
                Plane3f visable_triangle;
                
                for (int j = 0; j < 3; j++)
                {
                    visable_triangle.point[j] = object.GetMeshTriangle(i).point[j] - this->world_location;
                }
                visable_triangles.emplace_back(visable_triangle);
            }
        }
    }

    
    std::sort(visable_triangles.begin(), visable_triangles.end(), [](const Plane3f& A, const Plane3f B)
    {
        for (int i = 0; i < 3; i++)
        {
            Vector3f point_intersection = Plane3fLine3fIntersection(B, Line3f(A.point[i]));
            
            if (B.ReduceDimensionsOfPoints().IsInside(B.ReduceDimensions(point_intersection)))
            {
                if (point_intersection.GetLength() < A.point[i].GetLength())
                {
                    return false;
                }
            }
        }
        
        return true;
    });
    
    return visable_triangles;
}

std::vector<Triangle2f> sCamera::GetVisableTrianglesScreen(const Plane3f& visable_triangle_world) const
{
    return this->GetClipTriangles(this->GetTrianglePojection(visable_triangle_world));
}

float sCamera::GetFocalLength() const
{
    float aspect_raito = this->window_hight / this->window_width;

    return sqrt((1.0f + (aspect_raito * aspect_raito) / 4.0f)) / tan(this->field_of_view);
}

Vector3f sCamera::GetLensNormal() const
{
    return Vector3f(1.0f, this->world_rotation.y, this->world_rotation.z, true);
}

Vector3f sCamera::GetLocalLensLocation() const
{
    return this->GetLensNormal() * this->GetFocalLength();
}

Matrix3x3f sCamera::GetLensTransitionMatrix() const
{
    float theta = this->GetLensNormal().GetSphericalTheta();
    float phi   = this->GetLensNormal().GetSphericalPhi();
    
    return Matrix3x3f(Vector3f(cos(theta) * cos(phi), cos(theta) * sin(phi), -sin(theta)),
                      Vector3f(            -sin(phi),              cos(phi),        0.0f),
                      this->GetLensNormal(), true);
}

Vector2f sCamera::GetVertexPojection(const Vector3f& local_vertex_location) const
{    
    Vector3f vertex_pojection_3D = local_vertex_location * (this->GetFocalLength() / DotProduct(local_vertex_location, this->GetLensNormal()));
    
    Vector2f vertex_pojection_2D = To2D(this->GetLensTransitionMatrix() * (vertex_pojection_3D - this->GetLocalLensLocation()));
        
    Vector2f rotated_vertex_pojection_2D = Vector2f(vertex_pojection_2D.GetLength(),
                                                    vertex_pojection_2D.GetPolarPhi() + this->world_rotation.x + pi / 2.0f, true);
    
    return Vector2f((rotated_vertex_pojection_2D.x * this->window_width) + 0.5f * (this->window_width + 1.0f),
                    (rotated_vertex_pojection_2D.y * this->window_width) + 0.5f * (this->window_hight + (this->window_hight / this->window_width)));
}

Triangle2f sCamera::GetTrianglePojection(const Plane3f& triangle) const
{
    return Triangle2f(this->GetVertexPojection(triangle.point[0]),
                      this->GetVertexPojection(triangle.point[1]),
                      this->GetVertexPojection(triangle.point[2]));
}

bool sCamera::IsTriangleVisable(const Plane3f& triangle) const
{
    Vector3f local_triangle_location = triangle.GetCenter() - this->world_location;
    
    if (Angle(local_triangle_location, triangle.GetNormal()) <= pi / 2.0f)
    {
        return false;
    }
    
    if (Angle(this->GetLensNormal(), triangle.point[0] - this->world_location) > this->field_of_view &&
        Angle(this->GetLensNormal(), triangle.point[1] - this->world_location) > this->field_of_view &&
        Angle(this->GetLensNormal(), triangle.point[2] - this->world_location) > this->field_of_view)
    {
        return false;
    }
    
    if ((triangle.point[0] - this->world_location).GetLength() > this->render_distance ||
        (triangle.point[1] - this->world_location).GetLength() > this->render_distance ||
        (triangle.point[2] - this->world_location).GetLength() > this->render_distance)
    {
        return false;
    }
    
    if (SignedShortedDistancePlane(this->GetLensNormal(), this->world_location, triangle.point[0]) < 0.0f ||
        SignedShortedDistancePlane(this->GetLensNormal(), this->world_location, triangle.point[1]) < 0.0f ||
        SignedShortedDistancePlane(this->GetLensNormal(), this->world_location, triangle.point[2]) < 0.0f)
    {
        return false;
    }
        
    return true;
}

std::vector<Triangle2f> sCamera::ClipTriangleAgainstBoundary(const Triangle2f& triangle, const Line2f& boundary) const
{
    std::vector<Triangle2f> result;
    
    bool is_vertex_visable[3];
    
    int visable_vertices = 0;
    
    for (int j = 0; j < 3; j++)
    {
        if (SignedShortestDistanceLine(boundary, triangle.vertex[j]) < 0.0f)
        {
            is_vertex_visable[j] = true;
            
            visable_vertices += 1;
        } else
        {
            is_vertex_visable[j] = false;
        }
    }
    
    if (visable_vertices == 1)
    {
        for (int j = 0; j < 3; j++)
        {
            if(is_vertex_visable[j])
            {
                result.emplace_back(Triangle2f(triangle.vertex[j],
                                                TwoLine2fIntersection(boundary,Line2f(triangle.vertex[(j + 1) % 3], triangle.vertex[j])),
                                                TwoLine2fIntersection(boundary,Line2f(triangle.vertex[(j + 2) % 3], triangle.vertex[j]))));
            }
        }
    }

    if (visable_vertices == 2)
    {
        for (int j = 0; j < 3; j++)
        {
            if(is_vertex_visable[j] && is_vertex_visable[(j + 1) % 3])
            {
                result.emplace_back(Triangle2f(triangle.vertex[j],
                                               TwoLine2fIntersection(boundary,Line2f(triangle.vertex[(j + 2) % 3], triangle.vertex[(j + 1) % 3])),
                                               TwoLine2fIntersection(boundary,Line2f(triangle.vertex[(j + 2) % 3], triangle.vertex[j]))));

                result.emplace_back(Triangle2f(triangle.vertex[j],
                                               triangle.vertex[(j + 1) % 3],
                                               TwoLine2fIntersection(boundary,Line2f(triangle.vertex[(j + 2) % 3], triangle.vertex[(j + 1) % 3]))));
            }
        }
    }

    if (visable_vertices == 3)
    {
        result.emplace_back(triangle);
    }
        
    return result;
}

std::vector<Triangle2f> sCamera::GetClipTriangles(const Triangle2f& triangle) const
{
    std::vector<Triangle2f> result;
    
    Line2f screen_boundary[4] = {Line2f(Vector2f(0.0f,               0.0f),                 Vector2f(this->window_width, 0.0f)),
                                 Line2f(Vector2f(this->window_width, 0.0f),                 Vector2f(this->window_width, this->window_hight)),
                                 Line2f(Vector2f(this->window_width, this->window_hight),   Vector2f(0.0f,               this->window_hight)),
                                 Line2f(Vector2f(0.0f,               this->window_hight),   Vector2f(0.0f,               0.0f))};

    for (auto triangles_to_clip_0: this->ClipTriangleAgainstBoundary(triangle, screen_boundary[0]))
    {
        if (this->ClipTriangleAgainstBoundary(triangle, screen_boundary[0]).size() > 0)
        {
            for (auto triangles_to_clip_1: this->ClipTriangleAgainstBoundary(triangles_to_clip_0, screen_boundary[1]))
            {
                if (this->ClipTriangleAgainstBoundary(triangles_to_clip_0, screen_boundary[1]).size() > 0)
                {
                    for (auto triangles_to_clip_2: this->ClipTriangleAgainstBoundary(triangles_to_clip_1, screen_boundary[2]))
                    {
                        if (this->ClipTriangleAgainstBoundary(triangles_to_clip_1, screen_boundary[2]).size() > 0)
                        {
                            for (auto triangles_to_clip_3: this->ClipTriangleAgainstBoundary(triangles_to_clip_2, screen_boundary[3]))
                            {
                                if (this->ClipTriangleAgainstBoundary(triangles_to_clip_2, screen_boundary[3]).size() > 0)
                                {
                                    result.emplace_back(triangles_to_clip_3);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return result;
}


}
