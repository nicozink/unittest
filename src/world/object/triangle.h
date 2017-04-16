#pragma once

#include "traceable.h"

class Triangle : public Traceable
{
public:
    
    Triangle(Vector3d v0, Vector3d v1, Vector3d v2, const bool single_sided = true);
    
    ~Triangle();
    
    bool trace(const Ray& r, Intersection& intersection, double min_distance) override;
    
private:
    
    bool single_sided;
    
    Vector3d v0;
    
    Vector3d v1;
    
    Vector3d v2;
};
