#include "camera.h"

Camera::Camera()
{

}

Ray Camera::get_ray(float s, float t)
{
    Vector3d origin(0.0, 0.0, 0.0);
    Vector3d dest((s - 0.5), (t - 0.5) * 6.0 / 8.0, 1.0);

    return Ray(origin, dest);
}
