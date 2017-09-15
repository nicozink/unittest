/*
Copyright © Nico Zink
All rights reserved.
*/

// Local Includes

// Project Includes
#include <unittest/test.h>

// External Includes

TEST(Example, TestAssert)
{
	int x = 5;

	ASSERT(x == 5);
}

TEST(Example, TestAssertTrue)
{
	int x = 5;

	ASSERT_TRUE(x == 5);
}

TEST(Example, TestAssertEq)
{
	int x = 5;

	ASSERT_EQ(x, 5);
}
