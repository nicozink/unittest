/*
Copyright © Nico Zink
All rights reserved.
*/

#include "unit_tests.h"

// Local Includes
#include "test_info_compare.h"

// Project Includes
#include <unittest/test.h>

// System Includes
#include <algorithm>
#include <exception>
#include <iostream>
#include <map>
#include <vector>

struct UnitTestData
{
	// Stores the registered tests.
	std::vector<TestInfo*> registered_tests;

	// Stores the number of test cases.
	int test_case_count;

	// Stores a comparison method for two unit tests.
	TestInfoCompare test_compare;

	// Stores the total number of tests.
	int test_total_count;

	// Stores the number of tests associated with each test case.
	std::map<std::string, int> test_total_by_case;
};

static UnitTestData* unit_test_data = nullptr;

/*
 * Public Methods
 */

// Register a unit test.
// @param testCase The test case.
// @param testName The test name.
// @param unitTest The unit test definition.
// @param returns The test information.
TestInfo* UnitTests::RegisterTest(std::string testCase, std::string testName,
	UnitTestBase* unitTest)
{
	if (unit_test_data == nullptr)
	{
		unit_test_data = new UnitTestData();
	}

	TestInfo* testInfo = new TestInfo(testCase, testName, unitTest);

	unit_test_data->registered_tests.push_back(testInfo);

	if (unit_test_data->test_total_by_case.find(testCase) == unit_test_data->test_total_by_case.end())
	{
		unit_test_data->test_total_by_case[testCase] = 0;

		++unit_test_data->test_case_count;
	}

	++unit_test_data->test_total_count;
	++unit_test_data->test_total_by_case[testCase];

	return testInfo;
}

// Runs all registered unit tests.
bool UnitTests::Run()
{
	// Sort the list first.
	std::sort(unit_test_data->registered_tests.begin(), unit_test_data->registered_tests.end(), unit_test_data->test_compare);

	std::cout << "Running " << unit_test_data->test_total_count << " tests from "
		<< unit_test_data->test_case_count << " test cases." << std::endl;

	// Keep track of the number of passed and failed tests.
	int passedTestCount = 0;
	int failedTestCount = 0;

	// Keep track of the failed tests.
	std::vector<TestInfo*> failedTests;

	// Set the last prefix for the next loop, and print a test summary
	// for each new test case.
	std::string previousCase = "";

	for (std::vector<TestInfo*>::iterator it = unit_test_data->registered_tests.begin();
		it != unit_test_data->registered_tests.end(); ++it)
	{
		TestInfo* testInfo = *it;

		if (previousCase != testInfo->get_test_case())
		{
			previousCase = testInfo->get_test_case();

			std::cout << std::endl << "Running " << unit_test_data->test_total_by_case[previousCase]
				<< " tests from " << previousCase << "." << std::endl;
		}

		std::cout << testInfo->get_test_case() << "."
			<< testInfo->get_test_name() << " ";

		try
		{
			testInfo->run();
		}
		catch (std::exception&)
		{

		}

		if (testInfo->get_result() == UnitTestResult::TestPassed)
		{
			std::cout << "[PASS]" << std::endl;

			++passedTestCount;
		}
		else
		{
			std::cout << "[FAIL]" << std::endl;
			std::cout << "Error: " << std::endl << testInfo->get_error() << std::endl;

			++failedTestCount;

			failedTests.push_back(testInfo);
		}
	}

	std::cout << std::endl << "Ran " << unit_test_data->test_total_count << " tests." << std::endl;

	if (passedTestCount == 1)
	{
		std::cout << "Passed: 1 test." << std::endl;
	}
	else
	{
		std::cout << "Passed: " << passedTestCount << " tests." << std::endl;
	}

	if (failedTestCount != 0)
	{
		if (failedTestCount == 1)
		{
			std::cout << "Failed: 1 test:" << std::endl;
		}
		else
		{
			std::cout << "Failed: " << failedTestCount << " tests:" << std::endl;
		}

		for (std::vector<TestInfo*>::iterator it = failedTests.begin();
			it != failedTests.end(); ++it)
		{
			TestInfo* testInfo = *it;

			std::cout << testInfo->get_test_case() << "."
				<< testInfo->get_test_name() << std::endl;
		}
	}
	else
	{
		std::cout << "All tests have passed." << std::endl;
	}


	for (std::vector<TestInfo*>::iterator it = unit_test_data->registered_tests.begin();
		it != unit_test_data->registered_tests.end(); ++it)
	{
		delete *it;
	}

	if (failedTestCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

