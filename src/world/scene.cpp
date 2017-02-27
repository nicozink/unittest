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
    for (auto& traceable : traceables)
    {
        return traceable->trace(r);
    }

    const Vector3d &v = r.direction();

    double cx = v.x() + 0.5;
    double cy = v.y() + 0.5;

    return Color(cx, cy, 0.0);
}