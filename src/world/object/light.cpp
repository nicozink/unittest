#include "light.h"

Light::Light(Vector3d position, Color color)
{
    this->position = position;
    this->color = color;
}

Ray Light::get_ray_to_light(const Vector3d& origin)
{
    Vector3d direction_to_light = position - origin;

    direction_to_light.normalise();

    return Ray(origin, direction_to_light);
}

Color Light::get_light_intensity()
{
    return color;
}
