//
//  MGE_World.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 26/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#ifndef MGE_World_hpp
#define MGE_World_hpp

#include <stdio.h>
#include "MGE_Spawnable.h"

namespace mge
{
class World
{
public:
    
    std::vector<sObject> object;
    
    std::vector<sCamera> camara;

    std::vector<sLight> light;
};
}

#endif /* MGE_World_hpp */
