/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include "test_info.h"

// Local Includes

// Project Includes

// System Includes

/*
 * Constructors
 */

// Creates a new instance of the TestInfo class.
// @param testCase The name of the test case.
// @param testName The name of the test.
TestInfo::TestInfo(std::string test_case, std::string test_name,
	UnitTestBase* unit_test)
{
	this->test_case = test_case;
	this->test_name = test_name;
	this->unit_test = unit_test;
}

// Deletes this instance of the TestInfo class.
TestInfo::~TestInfo()
{
	delete unit_test;
}

/*
 * Public Methods
 */
 
// Gets the error message.
// @returns The error message.
std::string TestInfo::get_error()
{
	return unit_test->get_error();
}

// Gets the result of the unit test.
// @returns The unit test result.
UnitTestResult TestInfo::get_result()
{
	return unit_test->get_result();
}

// Gets the name of the test case.
// @returns The name of the test case.
std::string TestInfo::get_test_case()
{
	return test_case;
}

// Gets the name of the test.
// @returns The test name.
std::string TestInfo::get_test_name()
{
	return test_name;
}

// Runs the unit test.
void TestInfo::run()
{
	unit_test->run();
}

