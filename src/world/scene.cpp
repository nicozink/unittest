#include "scene.h"

#include "object/sphere.h"

#include "math/vector3d.h"

Scene::Scene()
{
    traceables.push_back(new Sphere(Vector3d(0.0, 0.0, 2.0), 0.5));
}

Scene::~Scene()
{
    for (auto& traceable : traceables)
    {
        delete traceable;
    }
}

Color Scene::trace(const Ray r)
{
    Color c;

    for (auto& traceable : traceables)
    {
        if (traceable->trace(r, c))
        {
            return c;
        }
    }

    return Color(0.0, 0.0, 0.0);
}