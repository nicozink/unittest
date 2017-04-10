#include "camera.h"

#include <cmath>

Camera::Camera(int max_x, int max_y, int spp)
{
    this->max_x = max_x;
    this->max_y = max_y;
    this->spp = spp;
}

const Color Camera::calculate_pixel(int x, int y, const Scene& scene)
{
    Color c;
    
    for (const Ray& r : get_pixel_samples(x, y))
    {
        c = c + scene.trace(r);
    }
    
    return c / spp;
}

std::vector<Ray> Camera::get_pixel_samples(int x, int y)
{
    std::vector<Ray> results;
    
    int spp_sqrt = sqrt(spp);
    
    for (int x_i = 0; x_i < spp_sqrt; ++x_i)
    {
        for (int y_i = 0; y_i < spp_sqrt; ++y_i)
        {
            double x_sample = (double)(x * spp_sqrt + x_i) / (double)(max_x * spp_sqrt);
            double y_sample = (double)(y * spp_sqrt + y_i) / (double)(max_y * spp_sqrt);
            
            results.push_back(get_ray(x_sample, y_sample));
        }
    }
    
    return results;
}

Ray Camera::get_ray(float s, float t)
{
    Vector3d origin(0.0, 0.0, 0.0);
    Vector3d dest((s - 0.5), (t - 0.5) * (double)max_y / (double)max_x, 1.0);

    return Ray(origin, dest);
}
