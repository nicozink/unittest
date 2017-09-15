/*
Copyright © Nico Zink
All rights reserved.
*/

#include "unit_test_exception.h"

// Local Includes

// Project Includes

// System Includes

// Creates a new instance of the UnitTestException class.
UnitTestException::UnitTestException()
{

}

const char* UnitTestException::what() const throw()
{
  return "The unit test failed.";
}
