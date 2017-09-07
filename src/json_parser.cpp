/*
Copyright © Nico Zink
All rights reserved.
*/

#include "json_parser.h"

JSON_Parser::JSON_Parser(std::istream& input)
	: lexer{ input }
{
	last_token = lexer.read_next();
}

void JSON_Parser::Parse(JSON_Value& value)
{
	read_json_value(value);
}

void JSON_Parser::read_json_value(JSON_Value& value)
{
	switch (last_token)
	{
		case JSON_Token::literal_null:
			value.clear();
			break;
		case JSON_Token::literal_true:
			value.set(true);
			break;
		case JSON_Token::literal_false:
			value.set(false);
			break;
		case JSON_Token::begin_array:
			value.empty_array();
			break;
		case JSON_Token::begin_object:
			value.empty_object();
			break;
	}
}