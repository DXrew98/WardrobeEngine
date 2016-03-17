#pragma once
#include "System.h"
#include "Entity.h"
#include "Time.h"

class LifetimeSystem : public System {

	bool condition(Handle<Entity> i) {
		
		return i->lifespan > -1;
	}

	void update(Handle<Entity> i) {

		if (i->lifespan->lifetime > i->lifespan->lifeSpan) Entity::free(i);
		else i->lifespan->lifetime += Time::instance().getDeltaTime();
	}
};