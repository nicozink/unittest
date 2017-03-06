#pragma once

#include "traceable.h"

class Sphere : public Traceable
{
public:

    Sphere(Vector3d position, double radius);

    ~Sphere();

    bool trace(const Ray& r, Intersection& intersection) override;

private:

    Vector3d position;

    double radius;
};
