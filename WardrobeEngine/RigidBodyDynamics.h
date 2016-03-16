#pragma once
#include "System.h"
#include "Entity.h"
#include "Time.h"
#include "cRenderUtils.h"

class RigidBodyDynamics : public System {

	bool condition(Handle<Entity> i) {
		
		return i->transform > -1 && i->rigidbody > -1;
	}

	void update(Handle<Entity> i) {

		i->rigidbody->integrate(&i->transform, Time::instance().getDeltaTime());
	}
};