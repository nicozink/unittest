#include "traceable.h"

Traceable::~Traceable()
{

}

bool Traceable::trace(const Ray& r)
{
    Intersection i;

    return trace(r, i);
}
