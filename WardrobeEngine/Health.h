#pragma once
#include "GCData.h"

class Health : public GCData<Health> {

public:
	float maxHealth, currentHealth, startHealth;

	Health() : maxHealth(100), currentHealth(100), startHealth(100) {}
};