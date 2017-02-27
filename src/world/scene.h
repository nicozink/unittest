#pragma once

#include "object/traceable.h"

#include <primitive/color.h>
#include <primitive/ray.h>

#include <vector>

class Scene
{
public:

    Scene();

    ~Scene();

    Color trace(const Ray r);

private:

    std::vector<Traceable*> traceables;
};
