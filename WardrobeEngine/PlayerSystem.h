#pragma once
#include "System.h"
#include "Input.h"
#include "Time.h"
#include "Factory.h"

class PlayerCarSystem : public System {

	bool condition(Handle<Entity> i) {
		
		return i->rigidbody > -1 && i->transform > -1 && i->controller > -1;
	}

	void update(Handle<Entity> i) {

		float vel = i->rigidbody->vel.mag();
		
		auto &input = Input::instance();
		auto &c = *i->controller;
		auto &r = *i->rigidbody;
		float dt = Time::instance().getDeltaTime();

		if (input.getKey(c.turnLEFT)) { r.addTorque(c.turnSpeed); }
		if (input.getKey(c.turnRIGHT)){ r.addTorque(-c.turnSpeed); }
		if (input.getKey(c.ACC))
		{
			vec2 accl = (i->transform->getUp() * c.speed);
			vec2 up = i->transform->getUp();
			r.addForce(accl);
		}
		if (input.getKey(c.SLOW))
		{ 
			// if moving fwd, then brake
			if (i->rigidbody->vel.mag() < 1)
			{
				i->rigidbody->acc = {0,0};
				i->rigidbody->vel = { 0, 0 };
			}
			else
			{
				// apply a backwards force
				r.addForce(i->rigidbody->vel.normal() * -c.speed);
			}
			
			//else c.speed = 0;
		}
	}
};