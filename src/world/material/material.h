#pragma once

#include "surface.h"

class Material
{
public:
    
    virtual ~Material();
    
    virtual Surface get_surface(double u = 0.0f, double v = 0.0f) const = 0;
};
