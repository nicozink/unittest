#pragma once

#include <math/vector3d.h>
#include <primitive/color.h>

struct Intersection
{
    double distance;

    Vector3d normal;

    Color color;
};