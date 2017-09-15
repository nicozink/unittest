/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include "main.h" 

// Local Includes

// Project Includes

// External Includes
#include <iostream>

// Main method which initialises the program.
// @param argc The number of arguments.
// @param argv The arguments.
// @returns The success code.
int main(int argc, char** argv)
{
	std::vector<std::string> args;

	for (int x = 1; x < argc; ++x)
	{
		std::string param(argv[1]);

		if (param == "-v" || param == "--version")
		{
			std::cout << "0.0.0.0" << std::endl;
			return 0;
		}

		args.push_back(param);
	}

	return run(args);
}
