#include "GLUTCallback.h"
#include <thread>
#include "Eigen/Core"
#include "../common/common.h"

namespace LGS{

void GLUTCallback::Display(void)
{
	glutSwapBuffers();
}

void GLUTCallback::Reshape(int width, int height)
{
	if(globalParam.verbose_glut_callback) printf("Reshape %d %d\n", width, height);
}

void GLUTCallback::Idle(void)
{
	int a, b;
	GLUTCallback obj;
	//std::thread thd(&test3, a);
	//std::thread thd2([obj]()obj.test3(a)});
	//thd.join();
	//thd2.join();

	if (globalParam.verbose_glut_callback) printf("Idle\n");
}

void GLUTCallback::Timer(int value)
{
	if (globalParam.verbose_glut_callback) printf("Timer trigger at value %d\n", value);
}

void GLUTCallback::Keyboard(unsigned char key, int x, int y)
{
	if (globalParam.verbose_glut_callback) printf("Keybooard %d at %d, %d\n", key, x, y);
}

void GLUTCallback::SpecialKey(int key, int x, int y)
{
	if (globalParam.verbose_glut_callback) printf("SpecialKey %d at %d, %d\n", key, x, y);
}

void GLUTCallback::SpecialKeyUp(int key, int x, int y)
{
	if (globalParam.verbose_glut_callback) printf("SpecialKeyUp %d at %d, %d\n", key, x, y);
}

void GLUTCallback::Mouse(int button, int state, int x, int y)
{
	if (globalParam.verbose_glut_callback) printf("Mouse %d state %d at %d, %d\n", button, state, x, y);
}

void GLUTCallback::Wheel(int button, int dir, int x, int y)
{
	if (globalParam.verbose_glut_callback) printf("Wheel button %d in direction %d at %d, %d\n", button, dir, x, y);
}

void GLUTCallback::Motion(int x, int y)
{
	if (globalParam.verbose_glut_callback) printf("Motion %d, %d\t", x, y);
}

void GLUTCallback::PassiveMotion(int x, int y)
{
	if (globalParam.verbose_glut_callback) printf("PassiveMotion %d, %d\t", x, y);
}

}