#pragma once

#include "traceable.h"

class Sphere : public Traceable
{
public:

    Sphere(Vector3d position, double radius, const Material* material);

    ~Sphere();

    bool trace(const Ray& r, Intersection& intersection, double min_distance) override;

private:

    Vector3d position;

    double radius;
};
