#include "texture.h"

#include <cmath>

Texture::Texture(const Image image, double k_diffuse, double k_specular, double spec_shiny)
: image{ image }
{
    this->k_diffuse = k_diffuse;
    this->k_specular = k_specular;
    this->spec_shiny = spec_shiny;
}

Surface Texture::get_surface(double u, double v) const
{
    Surface s;
	
	int w = floor(image.width() * u);
	int h = floor(image.height() * v);
	
    s.color = image.get_pixel(w, h);
    s.k_diffuse = k_diffuse;
    s.k_specular = k_specular;
    s.spec_shiny = spec_shiny;
    
    return s;
}
