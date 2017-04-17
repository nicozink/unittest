#include "triangle.h"

Triangle::Triangle(Vector3d v0, Vector3d v1, Vector3d v2, const Material* material, const bool single_sided)
: Traceable(material)
{
    this->v0 = v0;
    this->v1 = v1;
    this->v2 = v2;
    
    this->single_sided = single_sided;
}

Triangle::~Triangle()
{
    
}

bool Triangle::trace(const Ray& r, Intersection& intersection, double min_distance)
{
    /*
     * Given the following:
     * - O = origin
     * - D = direction
     *
     * A point along the ray at distance t is:
     * O + xD
     *
     * A point on a triangle is:
     * P(u, v) = (1 - u - v) V0 + uV1 + vV2
     *
     * The intersection between a ray and a triangle is:
     * O + xD = (1 - u - v) V0 + uV1 + vV2
     *
     * The Möller–Trumbore intersection algorithm gives:
     * [x, u, v]^T = 1 / (P.E1) [Q.E2, P.T, Q.D]^T
     *
     * Where:
     * E1 = V1 - V0
     * E2 = V2 - V0
     * T = O - V0
     * P = D x E2
     * Q = T x E1
     */
    
    const double EPSILON = 0.001;
    
    Vector3d e1 = v1 - v0;
    Vector3d e2 = v2 - v0;
    
    Vector3d p = r.direction().cross(e2);
    
    double det = p.dot(e1);
    
    if (single_sided && det < EPSILON)
    {
        return false;
    }
    else if (!single_sided && det > -EPSILON && det < EPSILON)
    {
        return false;
    }
    
    double inv_det = 1.0 / det;
    
    Vector3d t = r.origin() - v0;
    
    double u = p.dot(t) * inv_det;
    
    if (u < 0 || u > 1.0)
    {
        return false;
    }
    
    Vector3d q = t.cross(e1);
    
    double v = q.dot(r.direction()) * inv_det;
    
    if (v < 0 || u + v > 1.0)
    {
        return false;
    }
    
    double x = q.dot(e2) * inv_det;
    
    if (x < min_distance)
    {
        return false;
    }
    
    Vector3d normal = e1.cross(e2);
    normal.normalise();
    
    if (det < 0.0)
    {
        normal = normal * -1.0;
    }
    
    intersection.distance = x;
    intersection.material = material;
    intersection.normal = normal;
    
    return true;
}
