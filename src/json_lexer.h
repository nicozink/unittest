/*
Copyright © Nico Zink
All rights reserved.
*/

#pragma once

// Local includes
#include "json_token.h"

// Project includes

// System Includes
#include <istream>

class JSON_Lexer
{
public:
	JSON_Lexer(std::istream& input);

	JSON_Token read_next();

private:

	void skip();

	void skip(std::string str);

	void skip_whitespace();

	int current_char;

	std::istream& input;
};