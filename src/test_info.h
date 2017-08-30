/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#pragma once

#ifndef TESTINFO_H
#define TESTINFO_H

// Local Includes

// Project Includes
#include <unittest/test.h>

// External Includes
#include <string>

// Stores a unit test's information.
class TestInfo
{
public:

	// Creates a new instance of the TestInfo class.
	 // @param testCase The name of the test case.
	 // @param testName The name of the test.
	TestInfo(std::string testCase, std::string testName,
		UnitTestBase* unitTest);

	// Deletes this instance of the TestInfo class.
	~TestInfo();

	 // Gets the error message.
	 // @returns The error message.
	std::string get_error();

	// Gets the result of the unit test.
	// @returns The unit test result.
	UnitTestResult get_result();

	// Gets the name of the test case.
	// @returns The test case name.
	std::string get_test_case();

	// Gets the name of the test.
	// @returns The test name.
	std::string get_test_name();

	// Runs the unit test.
	void run();

private:

	// Stores the name of the test case.
	std::string test_case;

	// Stores the name of the test.
	std::string test_name;

	// Stores the unit test.
	UnitTestBase* unit_test;
};

#endif
