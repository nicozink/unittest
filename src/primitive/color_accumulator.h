#pragma once

#include "color.h"

class ColorAccumulator
{
public:

	ColorAccumulator();

	void add(const Color& c);
	
	Color average(int count) const;
	
private:

	long double channels[4];
};
