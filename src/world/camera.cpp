#include "camera.h"

Camera::Camera()
{

}

Ray Camera::get_ray(float s, float t)
{
    Vector3d origin(0.0, 0.0, 0.0);
    Vector3d dest(t - 0.5, s - 0.5, 1.0);

    return Ray(origin, dest);
}
