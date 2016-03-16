#pragma once
#include "GCData.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "LifeSpan.h"
#include "PlayerController.h"

struct Entity : GCData<Entity> {

	Handle<Transform> transform;
	Handle<Rigidbody> rigidbody;
	Handle<Collider > collider;
	Handle<Lifespan> lifespan;
	Handle<PlayerController> controller;

	void onFree() {
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		Collider ::free(collider .index);
		Lifespan ::free(lifespan .index);
		PlayerController::free(controller.index);
	}
};