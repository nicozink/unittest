/*
Copyright © Nico Zink
All rights reserved.
*/

#pragma once

#ifndef UNITTESTCOMPARE_H
#define UNITTESTCOMPARE_H

// Local Includes
#include "test_info.h"

// Project Includes

// External Includes

// Stores struct containing a comparison operator for two TestInfo
// objects.
struct TestInfoCompare
{
	// Operator which compares the two objects, and
	// returns true if i is smaller than j, and false
	// otherwise.
	// @param i The first TestInfo object.
	// @param j The second TestInfo object.
	bool operator() (TestInfo* i, TestInfo* j)
	{
		if (i->get_test_case() < j->get_test_case())
		{
			return true;
		}
		else if (i->get_test_case() == j->get_test_case() && i->get_test_name() < j->get_test_name())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

#endif

