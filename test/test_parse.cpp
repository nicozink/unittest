/*
Copyright © Nico Zink
All rights reserved.
*/

// Local Includes

// Project Includes
#include <json/json.h>
#include <unittest/test.h>

// External Includes

TEST(Parse, TestParseEmpty)
{
	auto json = JSON::Parse("");

	ASSERT(json.is_null());
}

TEST(Parse, TestParseNull)
{
	auto json = JSON::Parse(" null ");

	ASSERT(json.is_null());
}

TEST(Parse, TestBooleanTrue)
{
	auto json = JSON::Parse(" true ");

	ASSERT(json.contains<bool>() && json.get<bool>() == true);
}

TEST(Parse, TestBooleanFalse)
{
	auto json = JSON::Parse(" false ");

	ASSERT(json.contains<bool>() && json.get<bool>() == false);
}

TEST(Parse, TestEmptyObject)
{
	auto json = JSON::Parse(" { } ");

	ASSERT(json.is_object() && json.is_empty());
}

TEST(Parse, TestEmptyArray)
{
	auto json = JSON::Parse(" [ ] ");

	ASSERT(json.is_array() && json.is_empty());
}
