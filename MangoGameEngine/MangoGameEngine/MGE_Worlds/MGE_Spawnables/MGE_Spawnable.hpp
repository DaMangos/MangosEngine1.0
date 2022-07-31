//
//  MGE_Spawnable.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#ifndef MGE_Spawnable_hpp
#define MGE_Spawnable_hpp

#include <stdio.h>
#include "MGE_MathsLibrary.h"

namespace mge
{
class Spawnable
{
public:
    
    Vector3f world_location;
    
    Vector3f world_rotation;
    
    Vector3f world_scale;
    
    
    
    Spawnable();

    
    
    Spawnable Move(const Vector3f& A);
    
    Spawnable Rotate(const Vector3f& A);

    Spawnable Scale(const Vector3f& A);
    
protected:
    
    Matrix3x3f GetRotationMatrix();
};
}
#endif /* MGE_Spawnable_hpp */
