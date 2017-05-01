/*
Copyright © 2017, Nico Zink
All rights reserved.
*/

#pragma once

#include <functional>

// A job which is executed by a render thread.
class RenderJob
{
public:

	RenderJob(std::function<void()> job);

	void run() const;

private:
	
	std::function<void()> job;
};
