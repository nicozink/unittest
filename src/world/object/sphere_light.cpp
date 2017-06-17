#include "sphere_light.h"

#include <random>

std::uniform_real_distribution<double> unif(-1.0, 1.0);
std::default_random_engine re;

SphereLight::SphereLight(Vector3d position, double radius, Color color)
: Light(color)
{
	this->position = position;
	this->radius = radius;
}

Ray SphereLight::get_ray_to_light(const Vector3d& origin, bool random_sample)
{
	if (!random_sample)
	{
		Vector3d direction_to_light = position - origin;
	
		direction_to_light.normalise();
	
		return Ray(origin, direction_to_light);
	}
	else
	{
		double x = unif(re);
		double y = unif(re);
		double z = unif(re);
		
		Vector3d random_point_on_sphere(x, y, z);
		random_point_on_sphere.normalise();
		
		random_point_on_sphere = random_point_on_sphere * radius;
		
		Vector3d random_light_position = position + random_point_on_sphere;
		
		Vector3d direction_to_light = random_light_position - origin;
		
		direction_to_light.normalise();
		
		return Ray(origin, direction_to_light);
	}
}

LightType SphereLight::get_light_type()
{
	return LightType::AreaLight;
}
