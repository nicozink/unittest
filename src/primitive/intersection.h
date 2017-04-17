#pragma once

#include <math/vector3d.h>
#include <primitive/color.h>
#include <world/material/material.h>

class Intersection
{
    public:

        Surface get_surface();

        double distance;

        Vector3d normal;
    
        const Material* material;
};
