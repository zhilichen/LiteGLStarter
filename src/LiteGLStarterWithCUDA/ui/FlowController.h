#pragma once

#include "../ui/BasicConfig.h"

namespace LGS{

enum GLUI_CB:int{
	Test = 0,
	Test2 = 0
};

class FlowController
{
public:
	struct Param
	{
		int window_width_init;
		int window_height_init;
		std::string window_title;

		Param() { init(); }
		Param(const BasicConfig& config) { init(config); }

		void init()
		{
			window_width_init = 1024;
			window_height_init = 768;
			window_title = "Untitled";
		}

		void init(const BasicConfig& config)
		{
			init();
			config.get("title", window_title);
			config.get("window_width_init", window_width_init);
			config.get("window_height_init", window_height_init);
		}
	};

	Param _param;

	struct Status
	{
		int window_width;
		int window_height;

		int mouse_position_window;
		int mouse_position_gl;
		int mouse_position_palette;
		int mouse_zone_current;
		int mouse_zone_started;
	};

	Status _status;
	
	int _glut_window;
	GLUI * _glui_subwindow;
	

public:
	FlowController(void);
	~FlowController(void);
public:
	void StartUI(const BasicConfig& config, int argc = 0, char **argv = NULL);


private:
	void buildGLUIControls();
};

}
