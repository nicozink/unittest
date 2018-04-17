/*
Copyright © Nico Zink
All rights reserved.
*/

// Local Includes

// Project Includes
#include <unittest/test.h>

// System Includes

/*
 * Constructors
 */

// Creates a new instance of the UnitTestError class.
// @param comments The comments.
// @param isCritical A flag indicating whether this
// error is critical.
UnitTestError::UnitTestError(std::string comments, bool is_critical)
{
  
}

// Moves the instance of the UnitTestError class.
// Copy is unsupported due to the stringstream object.
// @param error The other error.
UnitTestError::UnitTestError(const UnitTestError& error)
{
	string_stream << error.string_stream.str();
}

/*
 * Public Methods
 */

// Gets the error message.
// @returns The error message.
std::string UnitTestError::get_error()
{
  return string_stream.str();
}

