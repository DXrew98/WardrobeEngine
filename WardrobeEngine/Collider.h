#pragma once
#include "GCData.h"
#include "Shapes.h"
#include "Collider.h"
#include "Transform.h"

struct Collider : GCData<Collider> {
	enum SHAPE { e_Circle = 1, e_AABB = 2, e_Ray = 4, e_Plane = 8 } shape;

	Collider() : shape(e_Circle), circle{ {0,0}, 1 } {}

	union {

		Circle circle;
		AABB aabb;
		Ray ray;
		Plane plane;
	};
};

CollisionData EvaluCollision(const Transform aTransfrom, const Collider aCollider,
							 const Transform bTransfrom, const Collider bCollider);