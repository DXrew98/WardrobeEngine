#pragma once
#include "MathDependancies.h"

class Rigidbody : public GCData<Rigidbody> {
public:
	float mass;

	vec2 vel, acc, force, jerk;
	float drag;

	float angularVel, angularAcc, torque;

	Rigidbody();
	void addForce(const vec2 &force);

	void addTorque(float a);

	void integrate(class Transform *t, float dt);
};