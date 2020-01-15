/*
Copyright © Nico Zink
All rights reserved.
*/

#pragma once

#ifndef GLOBALUNITTESTS_H
#define GLOBALUNITTESTS_H

// Local Includes

// Project Includes

// External Includes
#include <string>

class TestInfo;
class UnitTestBase;

// Stores a global unit test singleton.
namespace UnitTests
{
	// Register a unit test.
	// @param testCase The test case.
	// @param testName The test name.
	TestInfo* RegisterTest(std::string testCase, std::string testName, UnitTestBase* unitTest);
}

#endif
