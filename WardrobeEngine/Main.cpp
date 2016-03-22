#include "MainDependencies.h"

int main() {

	auto &window	= Window::instance();
	auto &input		= Input::instance();
	auto &time		= Time::instance();

	window.init();
	input.init();
	time.init();
	
	//Factory::makeBall({ 200, 200 }, { 20, 20 }, 20, 10);
	Factory::makeBall({ 500, 500 }, { -45, -45 }, 20, 5);
	Factory::makeWall({ 300, 300 }, { 1, 1 });
	Factory::makeBlock({ 150,100 }, { 100, 100 }, { 0, 25 }, 1);
	//Factory::makeBlock({ 50,100 }, { 100, 100 }, { 0, 0 }, 1);
	Factory::makeBlock({ 150,400 }, { 100, 100 }, { 0, 0 }, 1);

	DebugDraw debugDraw;
	RigidBodyDynamics rigidBodies;

	CollisionDetectionSystem collDetect;
	DynamicResolution collResolve;

	while (window.step()) {

		input.step();
		time.step();

		debugDraw.step();
		rigidBodies.step();

		collDetect.step();
		collResolve.step();

	}
	time.term();
	window.terminte();
	
}