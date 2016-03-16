#include "MainDependencies.h"

int main() {

	auto &window	= Window::instance();
	auto &input		= Input::instance();
	auto &time		= Time::instance();

	window.init();
	input.init();
	time.init();
	
	Factory::makeBall({ 400,400 }, { 5, 5 }, 50, 10)->rigidbody->addTorque(200);

	DebugDraw debugDraw;
	RigidBodyDynamics rigidBodies;


	while (window.step()) {
		input.step();
		time.step();

		debugDraw.step();
		rigidBodies.step();

	}

	window.terminte();
	
}