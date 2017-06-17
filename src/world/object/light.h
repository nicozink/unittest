#pragma once

#include "light_type.h"

#include "math/vector3d.h"
#include "primitive/color.h"
#include "primitive/ray.h"

class Light
{
public:

    Light(Color color);

	virtual ~Light();
	
    virtual Ray get_ray_to_light(const Vector3d& origin, bool random_sample) = 0;

    Color get_light_intensity();
	
	virtual LightType get_light_type() = 0;

private:

    Color color;
};
