#pragma once

#include "math/vector3d.h"

class Ray
{
    public:

        Ray(Vector3d o, Vector3d d);

        Vector3d& origin();
        const Vector3d& origin() const;

        Vector3d& direction();
        const Vector3d& direction() const;

        Vector3d get_position(double distance) const;

    private:

        Vector3d o;
        Vector3d d;
};
