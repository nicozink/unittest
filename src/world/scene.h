#include <primitive/color.h>
#include <primitive/ray.h>

class Scene
{
public:

    Scene();

    Color trace(const Ray r);
};
