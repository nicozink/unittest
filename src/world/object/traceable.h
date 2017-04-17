#pragma once

#include "primitive/intersection.h"
#include "primitive/ray.h"
#include "world/material/material.h"

#include <cfloat>

class Traceable
{
public:

    Traceable(const Material* material);
    
    virtual ~Traceable();

    virtual bool trace(const Ray& r, Intersection& intersection, double min_distance) = 0;

    bool trace(const Ray& r, double min_distance);
    
protected:
    
    const Material* material;
};
