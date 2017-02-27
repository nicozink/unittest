#pragma once

#include "primitive/color.h"
#include "primitive/ray.h"

class Traceable
{
public:

    virtual ~Traceable();

    virtual Color trace(const Ray& r) = 0;
};
