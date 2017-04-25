#pragma once

#include "image.h"

#include <string>

class ImageUtilities
{
public:
	static Image load_png(std::string path);
	static void save_png(const Image& image, std::string path);
};
