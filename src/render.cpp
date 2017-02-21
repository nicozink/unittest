/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include "render.h"

// Local Includes

// Project Includes
#include <resource/bitmap.h>
#include <world/Camera.h>
#include <world/Scene.h>

// External Includes
#include <iostream>
#include <string>

// Runs the main program.
int run(std::string scene_location)
{
  Bitmap bmp(800, 600);

  Camera camera;
  Scene scene;

  const int X_MAX = 800;
  const int Y_MAX = 600;

  for (int x = 0; x < X_MAX; ++x)
  {
    for (int y = 0; y < Y_MAX; ++y)
    {
      Ray r = camera.get_ray((double)(x) / (double)(X_MAX), (double)(y) / (double)(Y_MAX));

      const Color c = scene.trace(r);

      bmp.set_pixel(x, y, c);
    }
  }
  
  bmp.save("out.ppm");

  return 0;
}
