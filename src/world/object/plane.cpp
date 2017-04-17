#include "plane.h"

#include "math/quadratic.h"

#include <algorithm>
#include <cmath>

Plane::Plane(Vector3d position, Vector3d normal, Material* const material)
: Traceable(material)
{
    this->position = position;
    this->normal = normal;
}

Plane::~Plane()
{
    
}

bool Plane::trace(const Ray& r, Intersection& intersection, double min_distance)
{
    /*
     * Given the following:
     * - O = origin
     * - D = direction
     *
     * A point along the ray at distance x is:
     * O + xD
     *
     * A sphere at point V with normal N is:
     * N . (X - V) = 0
     * for all matching points X.
     *
     * The intersection between a ray and a sphere
     * at position V is:
     * N . (O + xD - V) = 0
     *
     * This gives:
     * N . xD + N . (O - V) = 0
     *
     * Rearranging, this gives:
     * x = (N . (V - O)) / (N . D)
     */
    
    double normal_dot_direction = normal.dot(r.direction());
    
    if (fabs(normal_dot_direction) < 0.0001)
    {
        return false;
    }
    
    double x = normal.dot(position - r.origin()) / normal_dot_direction;
    
    if (x < min_distance)
    {
        return false;
    }
    
    intersection.distance = x;
    intersection.material = material;
    intersection.normal = normal;
    
    return true;
}
