/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include "render.h"

// Local Includes

// Project Includes
#include <json/json.h>
#include <render/batch_render.h>
#include <resource/image.h>
#include <resource/image_utilities.h>
#include <world/camera.h>
#include <world/scene.h>

// External Includes
#include <iostream>
#include <string>

// Runs the main program.
int run(std::vector<std::string> args)
{
	JSON config = JSON::ParseFile(std::string("config.json"));

	const int X_MAX = 800;
	const int Y_MAX = 600;
	const int SPP = 16;

	Image img(X_MAX, Y_MAX);

	Camera camera(X_MAX, Y_MAX, SPP);
	Scene scene;
	
	BatchRender render(img, camera, scene);
	render.run();
	
	ImageUtilities::save_png(img, "out.png");
	
	return 0;
}
