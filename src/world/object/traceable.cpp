#include "traceable.h"

Traceable::Traceable(const Material* material)
{
    this->material = material;
}

Traceable::~Traceable()
{
    
}

bool Traceable::trace(const Ray& r, double min_distance)
{
    Intersection i;

    return trace(r, i, min_distance);
}
