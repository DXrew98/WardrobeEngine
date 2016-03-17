#pragma once
#include "CollisionDetection.h"

class DynamicResolution : public CollisionSystem {

	bool condition(Collision c) {

		return c.first->rigidbody > -1 && c.second->rigidbody > -1;
	}

	void update(Collision c) {
		vec2 MTV = c.collisionData.collisionNormal * c.collisionData.penetrationDepth;

		vec2 p1 = c.first->transform->getPosition()  - MTV / 2;
		vec2 p2 = c.second->transform->getPosition() + MTV / 2;

		c.first->transform->setPosition(p1);
		c.second->transform->setPosition(p2);

		std::swap(c.first->rigidbody->vel, c.second->rigidbody->vel);
	}
};