#include "point_light.h"

PointLight::PointLight(Vector3d position, Color color)
: Light(color)
{
    this->position = position;
}

Ray PointLight::get_ray_to_light(const Vector3d& origin, bool random_sample)
{
    Vector3d direction_to_light = position - origin;

    direction_to_light.normalise();

    return Ray(origin, direction_to_light);
}

LightType PointLight::get_light_type()
{
	return LightType::PointLight;
}
