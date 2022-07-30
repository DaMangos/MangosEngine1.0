//
//  MGE_sObject.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#ifndef MGE_sObject_hpp
#define MGE_sObject_hpp

#include <stdio.h>
#include <vector>
#include "MGE_Spawnable.hpp"

namespace mge
{
class sObject: public Spawnable
{
public:
    
    std::vector<Plane3f> mesh;
    
    Plane3f GetMeshTriangle(int index);
};
}

#endif /* MGE_sObject_hpp */
