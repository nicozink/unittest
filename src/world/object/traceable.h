#pragma once

#include "primitive/intersection.h"
#include "primitive/ray.h"

class Traceable
{
public:

    virtual ~Traceable();

    virtual bool trace(const Ray& r, Intersection& intersection) = 0;

    bool trace(const Ray& r);
};
