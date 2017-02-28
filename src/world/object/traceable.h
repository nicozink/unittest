#pragma once

#include "primitive/color.h"
#include "primitive/ray.h"

class Traceable
{
public:

    virtual ~Traceable();

    virtual bool trace(const Ray& r, Color& color) = 0;
};
