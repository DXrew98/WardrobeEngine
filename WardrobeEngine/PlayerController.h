#pragma once
#include "GCData.h"

class PlayerController : public GCData<PlayerController> {

public:
	char turnLEFT, turnRIGHT, ACC, SLOW;
	float speed, brakeStrength;
	float turnSpeed;
	float mass;

	PlayerController() : turnLEFT('A'), turnRIGHT('D'), ACC('W'), SLOW('S'), speed(1), brakeStrength(1), turnSpeed(1), mass(1) {}
};