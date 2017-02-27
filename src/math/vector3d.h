/*
Copyright © 2017, Nico Zink
All rights reserved.
*/

#ifndef VECTOR3D_H
#define VECTOR3D_H

// Local Includes
#include "vector.h"

// Project Includes

// External Includes

// This declares a vector containing three double values.
class Vector3d : public Vector<double, 3>
{
  public:

    //
    // Constructors
    //

    // Initialises a new instance of the Vector3d class.
    Vector3d();

    // Initialises a new instance of the Vector3d class.
    // @param v1 The first value.
    // @param v2 The second value.
    // @param v3 The third value.
    Vector3d(double v1, double v2, double v3);

    double dot(const Vector3d& other) const;

    double& x();
    double x() const;

    double& y();
    double y() const;

    double& z();
    double z() const;

    Vector3d operator-(const Vector3d& other) const;
};

#endif
