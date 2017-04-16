/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include "render.h"

// Local Includes

// Project Includes
#include <resource/bitmap.h>
#include <world/camera.h>
#include <world/scene.h>

// External Includes
#include <iostream>
#include <string>

// Runs the main program.
int run(std::string scene_location)
{
  const int X_MAX = 800;
  const int Y_MAX = 600;
  const int SPP = 1;

  Bitmap bmp(X_MAX, Y_MAX);

  Camera camera(X_MAX, Y_MAX, SPP);
  Scene scene;

  for (int x = 0; x < X_MAX; ++x)
  {
    for (int y = 0; y < Y_MAX; ++y)
    {
      bmp.set_pixel(x, y, camera.calculate_pixel(x, y, scene));
    }
  }
  
  bmp.save("out.ppm");

  return 0;
}
