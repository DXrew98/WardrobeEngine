#pragma once
#include "Window.h"

class Time {

	bool isInit;
	Time() : isInit(false) {}

public:
	static Time &instance() { static Time instance; return instance; }

	bool init() { return isInit = Window::instance().isInitialized(); }
	bool step() { INIT_ASSERT(Time); return true; }
	bool term() { INIT_ASSERT(Time); }

	bool isInitialized() { return isInit; }

	float getTotalTime();
	float getDeltaTime();
};