#include "image.h"

#include <algorithm>
#include <cmath>
#include <iterator>
#include <png.h>

Image::Image(int w, int h)
{
    this->h = h;
    this->w = w;

    colors.resize(w * h);
}

Image::Image(const Image &obj)
{
	this->h = obj.h;
	this->w = obj.w;
	
	colors = obj.colors;
}

Image::Image(Image &&obj)
{
	this->h = obj.h;
	this->w = obj.w;
	
	colors = std::move(obj.colors);
}

Image& Image::operator=(const Image &obj)
{
	this->h = obj.h;
	this->w = obj.w;
	
	colors = obj.colors;
	
	return *this;
}

Image& Image::operator=(Image &&obj)
{
	this->h = obj.h;
	this->w = obj.w;
	
	colors = std::move(obj.colors);
	
	return *this;
}

Image::~Image()
{
	
}

Color Image::get_pixel(const int x, const int y) const
{
    return colors[y * w + x];
}

void Image::set_pixel(const int x, const int y, const Color& c)
{
    colors[y * w + x] = c;
}

int Image::width() const
{
	return w;
}

int Image::height() const
{
	return h;
}
