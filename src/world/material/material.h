#pragma once

#include "surface.h"

class Material
{
public:
    
    virtual ~Material();
    
    virtual Surface get_surface() const = 0;
};
