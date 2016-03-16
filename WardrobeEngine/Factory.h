#pragma once
#include "Entity.h"

struct Factory {

	static Handle<Entity> makeBall(vec2 pos, vec2 vel, float radius, float mass) {

		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();

		e->collider->circle.radius = radius;
		e->collider->shape = Collider:::e_Circle;
		e->rigidbody->mass = mass;
		e->rigidbody->vel = vel;
		e->transform->setPosition(pos);
		return e;
	}

	static Handle<Entity> makeWall(vec2 pos, vec2 normal) {

		auto e = Entity::make();
		e->collider = Collider::make();
		e->transform = Transform::make();

		e->collider->plane.normal = normal;
		e->collider->shape = Collider::e_Plane;
		e->transform->setPosition(pos);

		return e;
	}
};