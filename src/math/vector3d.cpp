/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include "vector3d.h"

// Local Includes

// Project Includes

// System Includes
#include <cmath>

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

double Vector3d::dot(const Vector3d& other) const
{
  return x() * other.x() + y() * other.y() + z() * other.z();
}

double Vector3d::length() const
{
  return sqrt(x() * x() + y() * y() + z() * z());
}

void Vector3d::normalise()
{
  double l = length();

  x() = x() / l;
  y() = y() / l;
  z() = z() / l;
}

double& Vector3d::x()
{
  return Get(0);
}

double Vector3d::x() const
{
  return Get(0);
}

double& Vector3d::y()
{
  return Get(1);
}

double Vector3d::y() const
{
  return Get(1);
}

double& Vector3d::z()
{
  return Get(2);
}

double Vector3d::z() const
{
  return Get(2);
}

Vector3d Vector3d::operator+(const Vector3d& other) const
{
  Vector3d result(x() + other.x(), y() + other.y(), z() + other.z());

  return result;
}

Vector3d Vector3d::operator-(const Vector3d& other) const
{
  Vector3d result(x() - other.x(), y() - other.y(), z() - other.z());

  return result;
}

Vector3d Vector3d::operator*(const double value) const
{
  Vector3d result(x() * value, y() * value, z() * value);

  return result;
}
