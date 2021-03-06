#pragma once
#include "GCData.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "LifeSpan.h"
#include "PlayerController.h"
#include "Sprite.h"
#include "Spawner.h"
#include "Health.h"

struct Entity : GCData<Entity> {

	Handle<Transform> transform;
	Handle<Rigidbody> rigidbody;
	Handle<Collider > collider;
	Handle<Lifespan> lifespan;
	Handle<PlayerController> controller;
	Handle<Sprite> sprite;
	Handle<Spawner> spawner;
	Handle<Health> health;

	void onFree() {
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		Collider ::free(collider .index);
		Lifespan ::free(lifespan .index);
		PlayerController::free(controller.index);
		Sprite::free(sprite.index);
		Spawner::free(spawner.index);
		Health::free(health.index);
	}
};