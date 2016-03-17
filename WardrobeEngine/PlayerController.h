#pragma once
#include "GCData.h"

class PlayerController : public GCData<PlayerController> {

public:
	char turnLEFT, turnRIGHT, ACC;
	float speed;
	float turnSpeed;

	PlayerController() : turnLEFT('A'), turnRIGHT('D'), ACC('W'), speed(300), turnSpeed(300) {}
};