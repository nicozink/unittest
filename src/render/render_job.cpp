/*
Copyright © 2017, Nico Zink
All rights reserved.
*/

#include "render_job.h"

RenderJob::RenderJob(std::function<void()> job)
{
	this->job = job;
}

void RenderJob::run() const
{
	job();
}
