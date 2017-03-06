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

const Vector3d& Ray::origin() const
{
    return o;
}

Vector3d& Ray::direction()
{
    return d;
}

const Vector3d& Ray::direction() const
{
    return d;
}

Vector3d Ray::get_position(double distance) const
{
    return o + d * distance;
}
