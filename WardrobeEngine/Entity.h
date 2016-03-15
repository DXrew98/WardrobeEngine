#pragma once
#include "GCData.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "Transform.h"

struct Entity : GCData<Entity> {

	Handle<Transform> transform;
	Handle<Rigidbody> rigidbody;
	Handle<Collider > collider;

	void onFree() {
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		Collider ::free(collider .index);
	}
};