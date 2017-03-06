#include "scene.h"

#include "object/sphere.h"

#include "math/vector3d.h"

Scene::Scene()
{
    lights.push_back(new Light(Vector3d(-0.5, -1.0, 0.5), Color(1.0, 0.7, 0.6)));

    traceables.push_back(new Sphere(Vector3d(0.0, 0.0, 2.0), 0.5));
}

Scene::~Scene()
{
    for (auto& light : lights)
    {
        delete light;
    }

    for (auto& traceable : traceables)
    {
        delete traceable;
    }
}

Color Scene::trace(const Ray r)
{
    for (auto& traceable : traceables)
    {
        Intersection i;

        if (traceable->trace(r, i))
        {
            Color c;

            for (auto& light : lights)
            {
                Ray light_ray = light->get_ray_to_light(r.get_position(i.distance));

                if (!traceable->trace(light_ray))
                {
                    double dot = i.normal.dot(light_ray.direction());

                    if (dot > 0.0)
                    {
                        c = c + i.color * dot;
                    }
                }
            }

            return c;
        }
    }

    return Color(0.0, 0.0, 0.0);
}
