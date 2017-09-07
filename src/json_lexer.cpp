/*
Copyright © Nico Zink
All rights reserved.
*/

#include "json_lexer.h"

// System includes
#include <sstream>

JSON_Lexer::JSON_Lexer(std::istream& input)
	: input{ input }
{
	skip();
}

JSON_Token JSON_Lexer::read_next()
{
	skip_whitespace();

	switch (current_char)
	{
		case '{':
			return JSON_Token::begin_object;
		
		case '}':
			return JSON_Token::end_object;
			
		case '[':
			return JSON_Token::begin_array;
		
		case ']':
			return JSON_Token::end_array;
		
		case 'n':
			skip("null");
			return JSON_Token::literal_null;

		case 't':
			skip("true");
			return JSON_Token::literal_true;
		
		case 'f':
			skip("false");
			return JSON_Token::literal_false;

		case ':':
			return JSON_Token::separator_colon;

		case ',':
			return JSON_Token::separator_comma;

		case '"':
			return JSON_Token::value_string;

		case 0:
			return JSON_Token::end_of_input;
	}

	return JSON_Token::literal_null;
}

void JSON_Lexer::skip()
{
	if (input.eof())
	{
		current_char = 0;
	}
	else
	{
		current_char = input.get();
	}
}

void JSON_Lexer::skip(std::string str)
{
	for each (auto c in str)
	{
		if (current_char == c)
		{
			skip();
		}
		else
		{
			throw "Unexpected character in token.";
		}
	}
}

void JSON_Lexer::skip_whitespace()
{
	while (current_char == ' ' || current_char == '\t' || current_char == '\n' || current_char == '\r')
	{
		skip();
	}
}
