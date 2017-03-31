#include "scene.h"

#include "object/sphere.h"

#include "math/vector3d.h"

#include <cmath>

Scene::Scene()
{
    lights.push_back(new Light(Vector3d(-6, 4, -10), Color(1.0, 0.7, 0.6)));

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
    const double MIN_DIST = 0.001;
    const double k_specular = 0.4;
    const double k_diffuse = 0.8;
    const double spec_shiny = 50;
    
    for (auto& traceable : traceables)
    {
        Intersection i;

        if (traceable->trace(r, i, MIN_DIST))
        {
            Color c;

            for (auto& light : lights)
            {
                Ray light_ray = light->get_ray_to_light(r.get_position(i.distance));

                if (!traceable->trace(light_ray, MIN_DIST))
                {
                    double diff_dot = i.normal.dot(light_ray.direction());

                    if (diff_dot > 0.0)
                    {
                        c = c + i.color * diff_dot * k_diffuse;
                    }

                    Vector3d reflection = i.normal * 2.0 * diff_dot - light_ray.direction();
                    double spec_dot = pow((r.direction() * -1.0).dot(reflection), spec_shiny);
                    
                    if (spec_dot > 0.0)
                    {
                        c = c + Color(1.0, 1.0, 1.0, 1.0) * spec_dot * k_specular;
                    }
                }
            }

            return c;
        }
    }

    return Color(0.0, 0.0, 0.0);
}
