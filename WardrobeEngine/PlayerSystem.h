#pragma once
#include "System.h"
#include "Input.h"
#include "Time.h"

class PlayerCarSystem : public System {

	bool condition(Handle<Entity> i) {
		
		return i->rigidbody > -1 && i->controller > -1;
	}

	void update(Handle<Entity> i) {

		auto &input = Input::instance();
		auto &c = *i->controller;
		auto &r = *i->rigidbody;
		float dt = Time::instance().getDeltaTime();

		if (input.getKey(c.turnLEFT)) { r.addTorque(-c.turnSpeed); }
		if (input.getKey(c.turnRIGHT)) { r.addTorque(c.turnSpeed); }
		if (input.getKey(c.ACC)) { r.addTorque(i->transform->getUp * c.speed); }
	}
};