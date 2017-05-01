#pragma once

#include <primitive/color.h>
#include <world/scene.h>

class Camera
{
public:

	Camera(int max_x, int max_y, int spp);

	const Color calculate_pixel(int x, int y, const Scene& scene) const;

	int width() const;

	int height() const;
	
private:

	std::vector<Ray> get_pixel_samples(int x, int y) const;

	Ray get_ray(float s, float t) const;

	int max_x;

	int max_y;

	int spp;
};
