#pragma once

namespace LGS{

class GLUTCallback
{
public:
	GLUTCallback(void){};
	~GLUTCallback(void){};
public:
	static void Display(void);
	static void Reshape(int width, int height);
	static void Idle(void);
	static void Timer(int value);
	static void Keyboard(unsigned char key, int x, int y);
	static void SpecialKey(int key, int x, int y);
	static void SpecialKeyUp(int key, int x, int y);
	static void Mouse(int button, int state, int x, int y);
	static void Wheel(int button, int dir, int x, int y);
	static void Motion(int x, int y);
	static void PassiveMotion(int x, int y);
};

}

