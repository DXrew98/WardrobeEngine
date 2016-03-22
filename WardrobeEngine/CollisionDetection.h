#pragma once
#include "System.h"
#include <iostream>

struct Collision {

	Handle<Entity> first, second;
	CollisionData collisionData;

	static std::vector<Collision> &getData() {

		static std::vector<Collision> data;
		return data;
	}
};

class CollisionSystem {

	virtual bool condition	(Collision a) = 0;
	virtual void update		(Collision a) = 0;
	virtual void onStep		() {}

public:
	void step(){
		
		onStep();
		for each (auto c in Collision::getData())
			if(condition(c))	
				update(c);
	}
};

class CollisionDetectionSystem : public BinarySystem {

	void onStep() { Collision::getData().clear(); }

	bool condition(Handle<Entity> i) { return i->transform > -1 && i->collider > -1; }

	void update(Handle<Entity> i, Handle<Entity> j) {
		
		auto cd = EvaluCollision(*i->transform, *i->collider, *j->transform, *j->collider);

		if (cd.inOverlap) {
			Collision::getData().push_back(Collision{ i, j, cd });
		}
	}
};