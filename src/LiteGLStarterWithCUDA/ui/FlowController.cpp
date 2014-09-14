#include "FlowController.h"
#include "GLUTCallback.h"
#include "../common/common.h"

namespace LGS{

FlowController::FlowController(void)
{
}

FlowController::~FlowController(void)
{
}

void FlowController::StartUI(const BasicConfig& config, int argc, char **argv)
{
	globalParam.init(config);
	_param.init(config);

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize( _param.window_width_init, _param.window_height_init );
	glutInitWindowPosition(1,1);
	_glut_window = glutCreateWindow(_param.window_title.c_str());

	//
	// enable extensions
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		throw "Error initializing GLEW";
	}
	if (!GLEW_VERSION_2_1)
	{
		throw "Fatal Error: OpenGL 2.1 is required";
	}

	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	//
	// register glut callbacks
	//glutDisplayFunc(h_display);
	//glutReshapeFunc(h_Reshape);
	//glutIdleFunc(h_Idle);
	glutTimerFunc(10,GLUTCallback::Timer,0);
	//glutTimerFunc(10,GLUTCallback::Timer,1);
	//glutKeyboardFunc(h_Keyboard);
	//glutSpecialFunc(h_SpecialKey);
	glutSpecialUpFunc(GLUTCallback::SpecialKeyUp);
	//glutMouseFunc(h_Mouse);
	glutMouseWheelFunc(GLUTCallback::Wheel);
	glutMotionFunc(GLUTCallback::Motion);
	glutPassiveMotionFunc(GLUTCallback::PassiveMotion);
	GLUI_Master.set_glutDisplayFunc(GLUTCallback::Display);
	GLUI_Master.set_glutKeyboardFunc( GLUTCallback::Keyboard );
	GLUI_Master.set_glutSpecialFunc( GLUTCallback::SpecialKey );
	GLUI_Master.set_glutMouseFunc( GLUTCallback::Mouse );
	GLUI_Master.set_glutReshapeFunc( GLUTCallback::Reshape );
	GLUI_Master.set_glutIdleFunc( GLUTCallback::Idle );

	//
	// UI controls
	buildGLUIControls();

	//
	// other initializations


	//
	// start glut main loop
	glutMainLoop();
}

void FlowController::buildGLUIControls()
{
	_glui_subwindow = GLUI_Master.create_glui_subwindow(_glut_window, GLUI_SUBWINDOW_TOP);

	//_glui_subwindow->add_button("Clear (C)",GLUI_CB::Test,h_gluicb);

}

}
