#pragma once
#include "Mat3.h"
#include "vec2.h"
#include "Shapes.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Collider.h"

void drawMatrix	(const mat3   &matrix);
void drawVector	(const mat3   &matrix, const vec2 &vector, unsigned TINT = 0x00ffffff);
void drawPLane	(const Plane  &plane,  unsigned TINT);
void drawAABB	(const AABB	  &aabb,   unsigned TINT);
void drawCircle	(const Circle &cirlce, unsigned TINT);
void drawRay	(const Ray	  &ray,    unsigned TINT);

void drawTransform (const Transform &trans);
void drawRigidBody (const Transform &trans, const Rigidbody &rb);
void drawCollider  (const Transform &trans, const Collider  &co);