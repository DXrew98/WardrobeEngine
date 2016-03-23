#pragma once
#include "System.h"
#include "CollisionDetection.h"

class HealthSystem : public CollisionSystem {
	
	bool condition(Collision c) {

		return c.first->health > -1 || c.second->health > -1;
	}

	void update(Collision c) {

		bool hit = c.collisionData.inOverlap;

		
		

		if (hit == true) { c.first->health->currentHealth -= 10; }
	}
};
