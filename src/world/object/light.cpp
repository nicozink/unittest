#include "light.h"

Light::Light(Color color)
{
	this->color = color;
}

Light::~Light()
{
	
}

Color Light::get_light_intensity()
{
	return color;
}
