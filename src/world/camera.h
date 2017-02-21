#include <primitive/ray.h>

class Camera
{
    public:

        Camera();

        Ray get_ray(float s, float t);
};
