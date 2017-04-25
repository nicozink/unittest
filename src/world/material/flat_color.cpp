#include "flat_color.h"

FlatColor::FlatColor(Color color, double k_diffuse, double k_specular, double spec_shiny)
{
    this->color = color;
    this->k_diffuse = k_diffuse;
    this->k_specular = k_specular;
    this->spec_shiny = spec_shiny;
}

Surface FlatColor::get_surface(double u, double v) const
{
    Surface s;
    
    s.color = color;
    s.k_diffuse = k_diffuse;
    s.k_specular = k_specular;
    s.spec_shiny = spec_shiny;
    
    return s;
}
