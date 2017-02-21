/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include "vector3d.h"

// Local Includes

// Project Includes

// System Includes

//
// Constructors
//

// Initialises a new instance of the Vector3d class.
Vector3d::Vector3d()
  : Vector()
{
  
}

// Initialises a new instance of the Vector3d class.
// @param v1 The first value.
// @param v2 The second value.
// @param v3 The third value.
Vector3d::Vector3d(double v1, double v2, double v3)
: Vector({ v1, v2, v3 })
{
  
}
