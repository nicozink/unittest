#include "image_utilities.h"

#include "png.h"

#include <stdlib.h>
#include <stdio.h>
#include <cmath>

Image ImageUtilities::load_png(std::string path)
{
	FILE *fp = fopen(path.c_str(), "rb");

	if (fp == NULL)
		throw "Error opening file";
	
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	
	if (png_ptr == NULL) {
		fclose(fp);
		
		throw "Error reading file";
	}
	
	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fclose(fp);
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		
		throw "Error reading file";
	}
	
	if (setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
		
		throw "Error reading file";
	}
	
	unsigned int sig_read = 0;
	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, sig_read);
	
	png_read_info(png_ptr, info_ptr);
	
	int width = png_get_image_width(png_ptr, info_ptr);
	int height = png_get_image_height(png_ptr, info_ptr);
	
	Image image(width, height);
	
	png_bytep row = (png_bytep) malloc(png_get_rowbytes(png_ptr, info_ptr));
	
	int num_samples = 3;
	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGBA)
	{
		num_samples = 4;
	}
	
	for (int y = height - 1; y >= 0; --y) {
		png_read_row(png_ptr, row, nullptr);
		
		for (int x = 0; x < width; ++x) {
			png_byte* ptr = &(row[x*num_samples]);
			
			Color c;
			
			for (int i = 0; i < num_samples; ++i)
			{
				c[i] = ptr[i] / (double)255;
			}
			
			image.set_pixel(x, y, c);
		}
	}
	
	fclose(fp);
	
	return image;
}

void ImageUtilities::save_png(const Image& image, std::string path)
{
	int width = image.width();
	int height = image.height();
	
	FILE *fp = fopen(path.c_str(), "wb");
	if (!fp)
		throw "Error opening file";
	
	png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	
	if (png_ptr == NULL) {
		fclose(fp);
		
		throw "Error writing file";
	}
	
	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fclose(fp);
		
		throw "Error writing file";
	}
	
	if (setjmp(png_jmpbuf(png_ptr))) {
		fclose(fp);
		
		throw "Error writing file";
	}
	
	png_init_io(png_ptr, fp);
	
	png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
	
	png_write_info(png_ptr, info_ptr);
	
	if (setjmp(png_jmpbuf(png_ptr))) {
		fclose(fp);
		
		throw "Error writing file";
	}
	
	png_bytep row = (png_bytep) malloc(4 * width * sizeof(png_byte));
	
	for (int y = height - 1; y >= 0; --y) {
		for (int x = 0; x < width; ++x) {
			png_byte* ptr = &(row[x*4]);
			
			const Color c = image.get_pixel(x, y);
			ptr[0] = fmin(c.r(), 1.0) * (double)255;
			ptr[1] = fmin(c.g(), 1.0) * (double)255;
			ptr[2] = fmin(c.b(), 1.0) * (double)255;
			ptr[3] = fmin(c.a(), 1.0) * (double)255;
		}
		png_write_row(png_ptr, row);
	}
	
	if (setjmp(png_jmpbuf(png_ptr))) {
		fclose(fp);
		
		throw "Error writing file";
	}
	
	png_write_end(png_ptr, NULL);
	
	png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
	png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
	
	fclose(fp);
}
