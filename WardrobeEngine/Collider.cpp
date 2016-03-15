#include "Collider.h"
#include "Transform.h"

CollisionData EvaluCollision(const Transform aTransfrom, const Collider aCollider, 
							 const Transform bTransfrom, const Collider bCollider){

	Transform transformLhs = aTransfrom;
	Transform transformRhs = bTransfrom;
	Collider  colliderLhs  = aCollider;
	Collider  colliderRhs  = bCollider;

	if (colliderLhs.shape > colliderRhs.shape) {

		std::swap(colliderLhs,  colliderRhs);
		std::swap(transformLhs, transformRhs);
	}

	CollisionData cd;

	switch (colliderLhs.shape | colliderRhs.shape) {

	case Collider::e_Circle: 
		 cd = iTest(transformLhs.getGlobalTransform() * colliderLhs.circle, 
				    transformRhs.getGlobalTransform() * colliderRhs.circle);

	case Collider::e_Circle | Collider::e_Ray:
		 cd = iTest(transformLhs.getGlobalTransform() * colliderLhs.circle,
					transformRhs.getGlobalTransform() * colliderRhs.ray);

	case Collider::e_Circle | Collider::e_Plane:
		 cd = iTest(transformLhs.getGlobalTransform() * colliderLhs.circle,
					transformRhs.getGlobalTransform() * colliderRhs.plane);

	case Collider::e_AABB:
		 cd = iTest(transformLhs.getGlobalTransform() * colliderLhs.aabb,
					transformRhs.getGlobalTransform() * colliderRhs.aabb);

	case Collider::e_AABB | Collider::e_Circle:
		cd = iTest(transformLhs.getGlobalTransform() * colliderLhs.aabb,
			transformRhs.getGlobalTransform() * colliderRhs.circle);

	case Collider::e_AABB | Collider::e_Ray:
		 cd = iTest(transformLhs.getGlobalTransform() * colliderLhs.aabb,
					transformRhs.getGlobalTransform() * colliderRhs.ray);

	case Collider::e_AABB | Collider::e_Plane:
		 cd = iTest(transformLhs.getGlobalTransform() * colliderLhs.aabb,
					transformRhs.getGlobalTransform() * colliderRhs.plane);

	case Collider::e_Ray | Collider::e_Plane:
		 cd = iTest(transformLhs.getGlobalTransform() * colliderLhs.ray,
					transformRhs.getGlobalTransform() * colliderRhs.plane);
	}
	return cd;
}
