#pragma once
#include "GCData.h"

class Lifespan : public GCData<Lifespan> {
public:
	float lifetime;
	float lifeSpan;

	Lifespan() : lifetime(0), lifeSpan(5) {}
};