#include "primitive/Color.h"

#include <string>

class Bitmap
{
    public:

        Bitmap(int w, int h);

        ~Bitmap();

        Color get_pixel(const int x, const int y);

        void set_pixel(const int x, const int y, const Color& c);

        void save(std::string file);

    private:

        Color* colors;

        int h;

        int w;
};
