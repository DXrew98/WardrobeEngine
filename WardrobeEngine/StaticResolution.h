#pragma once
#include "CollisionDetection.h"

class StaticResolution : public CollisionSystem {

	bool condition(Collision c){

		return c.first->rigidbody > -1 && c.second->rigidbody < 0 ||
			   c.first->rigidbody <  0 && c.second->rigidbody >-1;
	}

	void update(Collision c) {

		if (c.collisionData.inOverlap) {
			Handle<Entity> staticBody;
			Handle<Entity> dynamicBody;
			vec2 normal = c.collisionData.collisionNormal;

			if (c.first->rigidbody > -1) {
				dynamicBody = c.first;
			}
			else {
				dynamicBody = c.second;
				//normal = -normal;
			}

			std::cout << "depth: " << c.collisionData.penetrationDepth
				<< " normal: " << normal.x << ", " << normal.y << std::endl;

			// move the dynamic body by the minimum translate
			vec2 mtv = c.collisionData.penetrationDepth * normal;
			vec2 newPos = dynamicBody->transform->getPosition() + mtv;
			dynamicBody->transform->setPosition(newPos);
			// reflect the velocity of the dynamic body
			dynamicBody->rigidbody->vel = dynamicBody->rigidbody->vel.reflect(c.collisionData.collisionNormal);
		}

	}
};