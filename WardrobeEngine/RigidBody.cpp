#include "Rigidbody.h"
#include "Transform.h"

Rigidbody::Rigidbody() : mass(1), vel(vec2{ 0,0 }), acc(vec2{ 0,0 }), 
						force(vec2{0,0}), drag(.1), torque(0), 
						angularVel(0), angularAcc(0) { }

void Rigidbody::addForce(const vec2 & a)	{ force = force + a; }

void Rigidbody::addTorque(float a)			{ torque += a; }

void Rigidbody::integrate(Transform * t, float deltaTime){

	jerk = force / mass - acc;
	acc  = acc + jerk * deltaTime;
	vel  = vel + acc  * deltaTime;
	t->setPosition(t->getPosition() + vel * deltaTime);

	vel = vel - vel * drag * deltaTime;
	force = { 0,0 };

	angularAcc = torque / mass;
	angularVel = angularAcc * deltaTime;

	t->setAngle(t->getAngle() + angularVel * deltaTime);
	torque = 0;
}




