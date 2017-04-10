#include "scene.h"

#include "object/sphere.h"
#include "object/plane.h"

#include "math/vector3d.h"

#include <cmath>

Scene::Scene()
{
    lights.push_back(new Light(Vector3d(-6, 4, -10), Color(1.0, 0.7, 0.6)));
    lights.push_back(new Light(Vector3d(6, 8, -12), Color(0.6, 0.2, 0.3)));

    traceables.push_back(new Sphere(Vector3d(-0.5, 0.0, 2.0), 0.4));
    traceables.push_back(new Sphere(Vector3d(0.5, 0.0, 2.0), 0.4));
    
    traceables.push_back(new Plane(Vector3d(0.0, -1.0, 0.0), Vector3d(0.0, 1.0, 0.0)));
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

Color Scene::trace(const Ray r, int max_depth) const
{
    const double k_specular = 0.2;
    const double k_diffuse = 0.8;
    const double spec_shiny = 50;
    
    Intersection i;

    if (find_intersection(r, i))
    {
        Color c(0.0, 0.0, 0.0);

        for (auto& light : lights)
        {
            Ray light_ray = light->get_ray_to_light(r.get_position(i.distance));

            if (!find_intersection(light_ray))
            {
                double diff_dot = i.normal.dot(light_ray.direction());

                if (diff_dot > 0.0)
                {
                    c = c + i.color * diff_dot * k_diffuse;
                }

                Vector3d reflection = i.normal * 2.0 * diff_dot - light_ray.direction();
                double spec_dot = (r.direction() * -1.0).dot(reflection);
                
                if (spec_dot > 0.0)
                {
                    c = c + Color(1.0, 1.0, 1.0, 1.0) * pow(spec_dot, spec_shiny) * k_specular;
                }
            }
        }

        if (max_depth > 0)
        {
            double diff_dot = i.normal.dot(r.direction());
            Vector3d reflection = r.direction() - i.normal * 2.0 * diff_dot;
        
            Ray r_reflect(r.get_position(i.distance), reflection);
        
            c = c + trace(r_reflect, max_depth - 1) * k_specular;
        }
        
        return c;
    }

    return Color(0.0, 0.0, 0.0);
}

bool Scene::find_intersection(const Ray &r) const
{
    const double MIN_DIST = 0.001;
    
    for (auto& traceable : traceables)
    {
        if (traceable->trace(r, MIN_DIST))
        {
            return true;
        }
    }
    
    return false;
}

bool Scene::find_intersection(const Ray &r, Intersection &i) const
{
    const double MIN_DIST = 0.001;
    
    for (auto& traceable : traceables)
    {
        if (traceable->trace(r, i, MIN_DIST))
        {
            return true;
        }
    }
    
    return false;
}
