//
//  MGE_Vertex.hpp
//  MangoGameEngine
//
//  Created by Oliver Horrigan-Pierre on 29/07/2022.
//  Copyright © 2022 Oliver Horrigan-Pierre. All rights reserved.
//

#ifndef MGE_Vertex_hpp
#define MGE_Vertex_hpp

#include <stdio.h>
#include "MGE_MathsLibrary.h"

namespace mge
{
class Vertex
{
    Vector3f world_position;
    Vector2f screen_position;
    Vector2f texture_coordinates;
};
}
#endif /* MGE_Vertex_hpp */
