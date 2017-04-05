#pragma once

#include "traceable.h"

class Plane : public Traceable
{
public:
    
    Plane(Vector3d position, Vector3d normal);
    
    ~Plane();
    
    bool trace(const Ray& r, Intersection& intersection, double min_distance) override;
    
private:
    
    Vector3d position;
    
    Vector3d normal;
};
