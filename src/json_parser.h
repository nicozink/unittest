/*
Copyright © Nico Zink
All rights reserved.
*/

#pragma once;

// Local includes
#include "JSON_Lexer.h"

// Project insludes
#include <json/json.h>

// System includes
#include <istream>

class JSON_Parser
{
public:
	JSON_Parser(std::istream& input);

	void Parse(JSON_Value& value);

private:

	void read_json_value(JSON_Value& value);

	JSON_Token last_token;

	JSON_Lexer lexer;
};