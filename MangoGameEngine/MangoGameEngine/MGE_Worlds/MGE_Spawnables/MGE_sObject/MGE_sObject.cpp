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
}
