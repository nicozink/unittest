#pragma once

#include "math/vector3d.h"

class Ray
{
    public:

        Ray(Vector3d o, Vector3d d);

        Vector3d& origin();
        Vector3d& direction();
    private:

        Vector3d o;
        Vector3d d;
};
