//
//  MGE_Spawnable.cpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#include "MGE_Spawnable.hpp"

namespace mge
{
Spawnable::Spawnable()
{
    this->world_location = Vector3f(0.0f, 0.0f, 0.0f);
    this->world_rotation = Vector3f(0.0f, 0.0f, 0.0f);
    this->world_scale    = Vector3f(1.0f, 1.0f, 1.0f);
}



Spawnable Spawnable::Move(const Vector3f& A)
{
    this->world_location += A;
    
    return *this;
}

Spawnable Spawnable::Rotate(const Vector3f& A)
{
    this->world_rotation = vmod(this->world_rotation + A, Vector3f(2.0f * pi, 2.0f * pi, 2.0f * pi));
    
    return *this;
}

Spawnable Spawnable::Scale(const Vector3f& A)
{
    this->world_scale = vabs(this->world_scale + A);
    
    return *this;
}
}
