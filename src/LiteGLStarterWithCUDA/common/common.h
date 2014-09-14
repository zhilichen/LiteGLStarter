#pragma once
#include "gl/opengl_essential.h"
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include "../ui/BasicConfig.h"

namespace LGS{

struct GlobalParam{
	bool verbose_glut_callback;

	GlobalParam() { init(); }
	GlobalParam(const BasicConfig& config) { init(config); }

	void init()
	{
		verbose_glut_callback = true;
	}

	void init(const BasicConfig& config)
	{
		init();
		config.get("verbose_glut_callback", verbose_glut_callback);
	}
};

static GlobalParam globalParam;

}