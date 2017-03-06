#pragma once

#include "math/vector3d.h"
#include "primitive/color.h"
#include "primitive/ray.h"

class Light
{
public:

    Light(Vector3d position, Color color);

    Ray get_ray_to_light(const Vector3d& origin);

    Color get_light_intensity();

private:

    Color color;

    Vector3d position;
};