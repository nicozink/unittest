#include "ray.h"

Ray::Ray(Vector3d o, Vector3d d)
{
    this->o = o;
    this->d = d;
}

Vector3d& Ray::origin()
{
    return o;
}

Vector3d& Ray::direction()
{
    return d;
}
