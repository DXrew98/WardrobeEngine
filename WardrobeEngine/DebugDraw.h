#pragma once
#include "System.h"
#include "Entity.h"
#include "cRenderUtils.h"

class DebugDraw : public System {

	bool condition(Handle<Entity> i) {

		return i->transform > -1;
	}

	void update(Handle<Entity> i) {

		drawTransform(*(i->transform));

		if (i->collider > -1) drawCollider(*(i->transform), *(i->collider));
		if (i->rigidbody  > -1) drawRigidBody(*(i->transform), *(i->rigidbody));
	}
};