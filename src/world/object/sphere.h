#pragma once

#include "traceable.h"

class Sphere : public Traceable
{
public:

    Sphere(Vector3d position, double radius);

    ~Sphere();

    Color trace(const Ray& r) override;

private:

    Vector3d position;

    double radius;
};
