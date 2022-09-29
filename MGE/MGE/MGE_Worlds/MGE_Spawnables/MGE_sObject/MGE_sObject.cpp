//
//  MGE_sObject.cpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#include "MGE_sObject.hpp"

namespace mge
{
Plane3f sObject::GetMeshTriangle(int i)
{
    float roll  = this->world_rotation.x;
    float pitch = this->world_rotation.y;
    float yaw   = this->world_rotation.z;

    Matrix3x3f rotation_matrix = Matrix3x3f(cos(yaw) * cos(pitch)                                      ,
                                           (cos(yaw) * sin(pitch) * sin(roll)) - (sin(yaw) * cos(roll)),
                                           (cos(yaw) * sin(pitch) * cos(roll)) + (sin(yaw) * sin(roll)),
                                            sin(yaw) * cos(pitch)                                      ,
                                           (sin(yaw) * sin(pitch) * sin(roll)) + (cos(yaw) * cos(roll)),
                                           (sin(yaw) * sin(pitch) * cos(roll)) - (cos(yaw) * sin(roll)),
                                                      -sin(pitch)                                      ,
                                                       cos(pitch) * sin(roll)                          ,
                                                       cos(pitch) * cos(roll)                          );
   
    Plane3f result;
    
    if (0 <= i < this->mesh.size())
    {
        for (int j = 0; j < 3; j++)
        {
            result.point[j] = (rotation_matrix * (this->world_scale * this->mesh.at(i).point[j])) + this->world_location;
        }
    }
    
    return result;
}

bool sObject::LoadFromObjectFromFile(std::string file_name)
{
    std::ifstream file(file_name);
    
    if (!file.is_open())
    {
        return false;
    }
    
    std::vector<Vector3f> vertices;
    
    while (!file.eof())
    {
        char line[128];
        
        file.getline(line, 128);

        std::strstream s;
        
        s << line;

        char junk;

        if (line[0] == 'o')
        {
            vertices.clear();
        }

        if (line[0] == 'v')
        {
            Vector3f v;
            s >> junk >> v.x >> v.y >> v.z;
            vertices.push_back(v);
        }

        if (line[0] == 'f')
        {
            int f[3];
            s >> junk >> f[0] >> f[1] >> f[2];
            this->mesh.push_back(Plane3f(vertices[f[0] - 1], vertices[f[1] - 1], vertices[f[2] - 1]));
        }
    }

    return true;
}
}
