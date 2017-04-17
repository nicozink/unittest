#pragma once

#include <primitive/color.h>

struct Surface
{
    Color color;

    double k_diffuse;

    double k_specular;
    
    double spec_shiny;
};
