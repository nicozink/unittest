#include "bitmap.h"

#include <cmath>

Bitmap::Bitmap(int w, int h)
{
    this->h = h;
    this->w = w;

    colors = new Color[w * h];
}

Bitmap::~Bitmap()
{
    delete[] colors;
}

Color Bitmap::get_pixel(const int x, const int y)
{
    return colors[y * w + x];
}

void Bitmap::set_pixel(const int x, const int y, const Color& c)
{
    colors[y * w + x] = c;
}

void Bitmap::save(std::string file)
{
  FILE *fp = fopen(file.c_str(), "w");
  fprintf(fp, "P3\n%d %d\n255\n", w, h);

  for (int y = h - 1; y >= 0; --y)
  {
    for (int x = 0; x < w; ++x)
    {
      const Color c = get_pixel(x, y);

      unsigned char out[3];
      out[0] = fmin(c.r(), 1.0) * (double)255;
      out[1] = fmin(c.g(), 1.0) * (double)255;
      out[2] = fmin(c.b(), 1.0) * (double)255;
      fprintf(fp, "%d %d %d\n", out[0], out[1], out[2]);
    }
  }
  
  fclose(fp);
}
