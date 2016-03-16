#pragma once
#include "GCData.h"
#include "VMMath.h"
#include <string>

class Sprite : public GCData<Sprite> {
public:
	vec2 offset;
	vec2 dim;
	float angle;

	std::string assetName;

	Sprite() : offset({}), dim({ 1, 1 }), angle(0) {}
};