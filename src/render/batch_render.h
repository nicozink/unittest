/*
Copyright © 2017, Nico Zink
All rights reserved.
*/

#pragma once

#include "render_job.h"
#include "resource/image.h"
#include "world/camera.h"
#include "world/scene.h"

// A renderer which dispatches rendering jobs in batches, which
// can be done in parallel.
class BatchRender
{
public:

	BatchRender(Image& image, const Camera& camera, const Scene& scene);

	std::vector<RenderJob> get_render_jobs(int num_threads) const;

	void run() const;

private:
	
	Image& image;
	
	const Camera& camera;
	
	const Scene& scene;
};
