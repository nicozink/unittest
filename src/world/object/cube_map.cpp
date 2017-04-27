#include "cube_map.h"

#include "resource/image_utilities.h"

#include <cmath>

CubeMap::CubeMap(std::string pos_x, std::string neg_x, std::string pos_y, std::string neg_y, std::string pos_z, std::string neg_z) :
pos_x{ ImageUtilities::load_png(pos_x) },
neg_x{ ImageUtilities::load_png(neg_x) },
pos_y{ ImageUtilities::load_png(pos_y) },
neg_y{ ImageUtilities::load_png(neg_y) },
pos_z{ ImageUtilities::load_png(pos_z) },
neg_z{ ImageUtilities::load_png(neg_z) }
{
	
}

CubeMap::~CubeMap()
{
	
}

Color CubeMap::get_color(const Ray& r)
{
	Vector3d dir = r.direction();
	
	double abs_x = fabs(dir.x());
	double abs_y = fabs(dir.y());
	double abs_z = fabs(dir.z());
	
	double major_axis = 0.0;
	double u_scale = 0.0;
	double v_scale = 0.0;
	
	Image* img = nullptr;
	
	if (abs_x >= abs_y && abs_x >= abs_z)
	{
		major_axis = abs_x;
		
		if (dir.x() > 0)
		{
			u_scale = -dir.z();
			v_scale = dir.y();
			
			img = &pos_x;
		}
		else
		{
			u_scale = dir.z();
			v_scale = dir.y();
			
			img = &neg_x;
		}
	}
	else if (abs_y >= abs_x && abs_y >= abs_z)
	{
		major_axis = abs_y;
		
		if (dir.y() > 0)
		{
			u_scale = dir.x();
			v_scale = -dir.z();
			
			img = &pos_y;
		}
		else
		{
			u_scale = -dir.x();
			v_scale = -dir.z();
			
			img = &neg_y;
		}
	}
	else if (abs_z >= abs_x && abs_z >= abs_y)
	{
		major_axis = abs_z;
		
		if (dir.z() > 0)
		{
			u_scale = dir.x();
			v_scale = dir.y();
			
			img = &pos_z;
		}
		else
		{
			u_scale = -dir.x();
			v_scale = dir.y();
			
			img = &neg_z;
		}
	}
	
	double u = (u_scale / major_axis + 1.0) / 2.0;
	double v = (v_scale / major_axis + 1.0) / 2.0;
	
	int w = floor(img->width() * u);
	int h = floor(img->height() * v);
	
	return img->get_pixel(w, h);
}
