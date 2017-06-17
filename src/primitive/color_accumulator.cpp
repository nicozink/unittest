#include "color_accumulator.h"

ColorAccumulator::ColorAccumulator()
{
	channels[0] = 0.0;
	channels[1] = 0.0;
	channels[2] = 0.0;
	channels[3] = 0.0;
}

void ColorAccumulator::add(const Color& c)
{
	channels[0] += c[0];
	channels[1] += c[1];
	channels[2] += c[2];
	channels[3] += c[3];
}

Color ColorAccumulator::average(int count) const
{
	Color c;
	
	c[0] = channels[0] / count;
	c[1] = channels[1] / count;
	c[2] = channels[2] / count;
	c[3] = channels[3] / count;
	
	return c;
}
