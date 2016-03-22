#pragma once
#include "Entity.h"

struct Factory {

	static Handle<Entity> makeBall(vec2 pos, vec2 vel, float radius, float mass) {

		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();

		e->collider->circle.radius = 1 * radius;
		e->collider->shape = Collider::e_Circle;
		e->rigidbody->mass = mass;
		e->rigidbody->vel = vel;
		e->transform->setPosition(pos);
		return e;
	}

	static Handle<Entity> makeWall(vec2 pos, vec2 normal) {

		auto e = Entity::make();
		e->collider = Collider::make();
		e->transform = Transform::make();

		e->transform->setAngle(normal.angle());

		e->collider->plane.normal = vec2{1,0};
		e->collider->shape = Collider::e_Plane;
		e->transform->setPosition(pos);

		return e;
	}

	static Handle<Entity> makeBlock(vec2 pos, vec2 halfPointsScale, vec2 vel, float mass) {

		auto e = Entity::make();
		e->collider  = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();

		e->collider->aabb.halfPoint = .5 * halfPointsScale;
		e->collider->shape = Collider::e_AABB;
		e->rigidbody->mass = mass;
		e->rigidbody->vel = vel;
		e->transform->setPosition(pos);
		return e;
	}
};