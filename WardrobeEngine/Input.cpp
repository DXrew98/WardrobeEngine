#include "Input.h"
#include "Window.h"
#include "sfwdraw.h"
#include <cstring>

bool Input::init()
{
	memset(keyRelease,		0, 100);
	memset(keyPress,		0, 100);
	memset(mouseRelease,	0, 100);
	memset(mousePress,		0, 100);

	mouseX = 0;
	mouseY = 0;

	return isInit = Window::instance().isInitialized();
}

bool Input::step()
{
	INIT_ASSERT(Input);

	for (unsigned i = 0; i < 100; ++i) {

		keyState[i] =		keyPress[i] > keyRelease[i];
		if (sfw::getKey(i)) keyPress[i] = sfw::getTime();
		else				keyRelease[i] = sfw::getTime();
	}

	for (unsigned i = 0; i < 10; ++i) {

		mouseState[i] =				mousePress[i] > mouseRelease[i];
		if (sfw::getMouseButton(i)) mousePress[i] = sfw::getTime();
		else						mouseRelease[i] = sfw::getTime();
	}

	mouseX = sfw::getMouseX();
	mouseY = sfw::getMouseY();

	return false;
}

bool Input::getKey(unsigned key)			{ INIT_ASSERT(Input); return keyPress[key]	>	keyRelease	[key]; }
bool Input::getKeyPress(unsigned key)		{ INIT_ASSERT(Input); return getKey(key)	&& !keyState	[key]; }
bool Input::getKeyReleased(unsigned key)	{ INIT_ASSERT(Input); return !getKey(key)	&&	keyState	[key]; }

bool Input::getMouseButton(unsigned key)		{ INIT_ASSERT(Input); return mousePress[key]		>	mouseRelease[key]; }
bool Input::getMouseButtonPress(unsigned key)	{ INIT_ASSERT(Input); return getMouseButton(key)	&& !mouseState	[key]; }
bool Input::getMouseButtonReleased(unsigned key){ INIT_ASSERT(Input); return !getMouseButton(key)	&&	mouseState	[key]; }

float Input::keyDelta(unsigned key) { INIT_ASSERT(Input); return keyPress[key] - keyRelease[key]; }

float Input::getMouseX() { INIT_ASSERT(Input); return mouseX; }
float Input::getMouseY() { INIT_ASSERT(Input); return mouseY; }
