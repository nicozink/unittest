#pragma once

#include "light.h"

#include "math/vector3d.h"
#include "primitive/color.h"
#include "primitive/ray.h"

class SphereLight : public Light
{
public:
	
	SphereLight(Vector3d position, double radius, Color color);
	
	Ray get_ray_to_light(const Vector3d& origin, bool random_sample) override;
	
	LightType get_light_type() override;
	
private:
	
	Vector3d position;
	
	double radius;
};
