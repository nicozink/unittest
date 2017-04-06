#pragma once

#include "object/light.h"
#include "object/traceable.h"

#include <primitive/color.h>
#include <primitive/ray.h>

#include <vector>

class Scene
{
public:

    Scene();

    ~Scene();

    Color trace(const Ray r, int max_depth = 10);

private:

    bool find_intersection(const Ray &r);
    
    bool find_intersection(const Ray &r, Intersection &i);
    
    std::vector<Light*> lights;

    std::vector<Traceable*> traceables;
};
