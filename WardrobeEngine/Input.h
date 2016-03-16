#pragma once

class Input {

	bool isInit;

	bool  keyState		[100];
	float keyPress		[100];
	float keyRelease	[100];
	

	bool  mouseState	[10];
	float mousePress	[10];
	float mouseRelease	[10];

	Input::Input() : isInit(false) {}

	float mouseX, mouseY;

public:

	static Input &instance() { static Input instance; return instance; }

	bool init();
	bool step();
	void term() {}

	bool getKey					(unsigned key);
	bool getKeyPress			(unsigned key);
	bool getKeyReleased			(unsigned key);

	bool getMouseButton			(unsigned key);
	bool getMouseButtonPress	(unsigned key);
	bool getMouseButtonReleased	(unsigned key);

	float keyDelta				(unsigned key);

	float getMouseX();
	float getMouseY();

	bool isInitialized() { return isInit; }
};