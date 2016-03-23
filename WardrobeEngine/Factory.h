#pragma once
#include "Entity.h"

struct Factory {

	static Handle<Entity> makeBall(vec2 pos, vec2 vel, float radius, float mass) {

		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();

		e->collider->circle.radius = radius;
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

	static Handle<Entity> makePlayer(vec2 pos, float acceleration,float brakeStrength, float turnSpeed) {

		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();
		e->controller = PlayerController::make();
		e->sprite = Sprite::make();

		e->sprite->assetName = "Shippie";
		e->sprite->dim = { 72, 72 };

		e->rigidbody->drag = .5;
		e->collider->aabb.halfPoint = { 20, 20 };
		e->collider->shape = Collider::e_AABB;
		//e->collider->circle.radius = 20;
		//e->collider->shape = Collider::e_Circle;
		e->transform->setPosition(pos);
		e->controller->speed = 1 * acceleration;
		e->controller->brakeStrength = 1 * brakeStrength;
		e->controller->turnSpeed = 100 * turnSpeed;
		return e;
	}

	static Handle<Entity> makeTempBlock(vec2 pos, vec2 halfPointsScale, vec2 vel, float mass, float life) {

		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();
		e->lifespan = Lifespan::make();

		e->collider->aabb.halfPoint = .5 * halfPointsScale;
		e->collider->shape = Collider::e_AABB;
		e->rigidbody->mass = mass;
		e->rigidbody->vel = vel;
		e->transform->setPosition(pos);
		e->lifespan->lifetime = life;
		return e;
	}

	static Handle<Entity> makeTempBall(vec2 pos, vec2 vel, float radius, float mass, float life) {

		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();
		e->lifespan = Lifespan::make();

		e->collider->circle.radius = 1 * radius;
		e->collider->shape = Collider::e_Circle;
		e->rigidbody->mass = mass;
		e->rigidbody->vel = vel;
		e->transform->setPosition(pos);
		e->lifespan->lifetime = life;
		return e;
	}

	static Handle<Entity> makeWorldEdge(vec2 pos, vec2 halfExtents, float mass) {

		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();
		
		e->collider->aabb.halfPoint = halfExtents;

		e->collider->shape = Collider::e_AABB;
		e->rigidbody->mass = mass;
		e->transform->setPosition(pos);
		return e;
	}
};