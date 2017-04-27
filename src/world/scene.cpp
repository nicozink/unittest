#include "scene.h"

#include "material/flat_color.h"
#include "material/texture.h"

#include "object/plane.h"

#include "resource/image_utilities.h"

#include "object/sphere.h"
#include "object/triangle.h"
#include "object/plane.h"

#include "math/vector3d.h"

#include <cmath>

Scene::Scene()
{
	Material* sphere_texture = new Texture(ImageUtilities::load_png("texture.png"), 0.8, 0.2, 25);
	materials.push_back(sphere_texture);
	
    Material* sphere_shiny = new FlatColor(Color(0.9, 0.3, 0.4), 0.8, 0.3, 25);
    materials.push_back(sphere_shiny);
    
    Material* plane_matte = new FlatColor(Color(0.0, 1.0, 0.0), 0.9, 0.1, 10);
    materials.push_back(plane_matte);
    
    Material* tri_matte = new FlatColor(Color(0.0, 0.0, 1.0), 0.9, 0.1, 10);
    materials.push_back(tri_matte);
    
    lights.push_back(new Light(Vector3d(-6, 4, -10), Color(1.0, 0.7, 0.6)));
    lights.push_back(new Light(Vector3d(6, 8, -12), Color(0.6, 0.2, 0.3)));

    traceables.push_back(new Sphere(Vector3d(-0.5, 0.0, 2.0), 0.4, sphere_texture));
    traceables.push_back(new Sphere(Vector3d(0.5, 0.0, 2.0), 0.4, sphere_shiny));
    
    traceables.push_back(new Triangle(Vector3d(-3.0, -1.0, 4.0), Vector3d(-3.0, 1.0, 4.0), Vector3d(3.0, 1.0, 4.0), tri_matte, false));
    traceables.push_back(new Triangle(Vector3d(-3.0, -1.0, 4.0), Vector3d(3.0, 1.0, 4.0), Vector3d(3.0, -1.0, 4.0), tri_matte, false));
    
    traceables.push_back(new Plane(Vector3d(0.0, -1.0, 0.0), Vector3d(0.0, 1.0, 0.0), plane_matte));
	
	sky_box = new CubeMap("sky_right.png", "sky_left.png", "sky_up.png", "sky_down.png", "sky_front.png", "sky_back.png");
}

Scene::~Scene()
{
    for (auto& light : lights)
    {
        delete light;
    }

    for (auto& material : materials)
    {
        delete material;
    }
    
    for (auto& traceable : traceables)
    {
        delete traceable;
    }
	
	if (sky_box != nullptr)
	{
		delete sky_box;
	}
}

Color Scene::trace(const Ray r, int max_depth) const
{    
    Intersection i;

    if (find_intersection(r, i))
    {
        Color c(0.0, 0.0, 0.0);

        Surface s = i.get_surface();
        
        for (auto& light : lights)
        {
            Ray light_ray = light->get_ray_to_light(r.get_position(i.distance));

            if (!find_intersection(light_ray))
            {
                if (s.k_diffuse > 0.0)
                {
                    double diff_dot = i.normal.dot(light_ray.direction());

                    if (diff_dot > 0.0)
                    {
                        c = c + s.color * diff_dot * s.k_diffuse;
                    }
                }
                
                if (s.k_specular > 0.0)
                {
                    double diff_dot = i.normal.dot(light_ray.direction());
                    
                    Vector3d reflection = i.normal * 2.0 * diff_dot - light_ray.direction();
                    double spec_dot = (r.direction() * -1.0).dot(reflection);
                
                    if (spec_dot > 0.0)
                    {
                        c = c + Color(1.0, 1.0, 1.0, 1.0) * pow(spec_dot, s.spec_shiny) * s.k_specular;
                    }
                }
            }
        }

        if (s.k_specular > 0.0 && max_depth > 0)
        {
            double diff_dot = i.normal.dot(r.direction());
            Vector3d reflection = r.direction() - i.normal * 2.0 * diff_dot;
        
            Ray r_reflect(r.get_position(i.distance), reflection);
        
            c = c + trace(r_reflect, max_depth - 1) * s.k_specular;
        }
        
        return c;
    }
	else if (sky_box != nullptr)
	{
		return sky_box->get_color(r);
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
