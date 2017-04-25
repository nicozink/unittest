#pragma once

#include <primitive/color.h>

#include <vector>

class Image
{
public:

	Image(int w, int h);

	Image(const Image &obj);
	Image(Image &&obj);
	
	Image& operator=(const Image &obj);
	Image& operator=(Image &&obj);
	
	~Image();

	Color get_pixel(const int x, const int y) const;

	void set_pixel(const int x, const int y, const Color& c);

	int width() const;
	
	int height() const;

private:

	std::vector<Color> colors;

	int h;

	int w;
};
