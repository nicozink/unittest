/*
Copyright © 2017, Nico Zink
All rights reserved.
*/

#include "batch_render.h"

#include <mutex>
#include <thread>

BatchRender::BatchRender(Image& image, const Camera& camera, const Scene& scene)
: image{ image }, camera{ camera }, scene{ scene }
{
	
}

std::vector<RenderJob> BatchRender::get_render_jobs(int num_threads) const
{
	std::vector<RenderJob> jobs;
	
	for (int x = 0; x < camera.width(); ++x)
	{
		jobs.push_back(RenderJob([&, x]()
		{
			for (int y = 0; y < camera.height(); ++y)
			{
				image.set_pixel(x, y, camera.calculate_pixel(x, y, scene));
			}
		}));
	}
	
	return jobs;
}

void BatchRender::run() const
{
	int num_threads = std::thread::hardware_concurrency();
	
	std::vector<RenderJob> jobs = get_render_jobs(num_threads);
	std::mutex jobs_lock;
	
	std::vector<std::thread> threads;
	
	for (int i = 0; i < num_threads; ++i)
	{
		threads.push_back(std::thread([&]() {
			while (true)
			{
				jobs_lock.lock();
			
				if (jobs.size() == 0)
				{
					jobs_lock.unlock();
					
					break;
				}
				
				RenderJob job = jobs.back();
				jobs.pop_back();
			
				jobs_lock.unlock();
			
				job.run();
			}
		}));
	}
	
	for (auto& thread : threads)
	{
		thread.join();
	}
}
