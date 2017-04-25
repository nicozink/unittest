#pragma once

#include "material.h"

#include "resource/image.h"

class Texture : public Material
{
public:
    
    Texture(const Image image, double k_diffuse, double k_specular, double spec_shiny);
    
    Surface get_surface(double u, double v) const override;
    
private:
    
	const Image image;
	
    double k_diffuse;
    
    double k_specular;
    
    double spec_shiny;
};
