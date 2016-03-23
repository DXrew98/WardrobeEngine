#include "MainDependencies.h"

int main() {

	auto &window	= Window::instance();
	auto &input		= Input::instance();
	auto &time		= Time::instance();

	window.init();
	input.init();
	time.init();

	Asset::instance().loadTexture("Shippie", "../Textures/Spaceship14.png");
	
	Factory::makeBall({ 200, 200 }, { 0, 0 }, 20, 10);
	Factory::makeBall({ 500, 500 }, { -20, -20 }, 20, 5);
	Factory::makeBlock({ 110,100 }, { 20, 20 }, { 0, 0 }, 1);
	Factory::makeBlock({ 550,100 }, { 50, 50 }, { -50, 0 }, 1);
	Factory::makeTempBlock({ 300, 100 }, { 30, 30 }, { 0, 0 }, 1, .1f);

	Factory::makePlayer({ 400,240 }, 100, 100, 2000);

	DebugDraw debugDraw;
	RigidBodyDynamics rigidBodies;
	LifetimeSystem lifetimes;

	CollisionDetectionSystem collDetect;
	DynamicResolution collResolve;

	PlayerCarSystem driveSystem;
	RenderSystem render;

	while (window.step()) {

		input.step();
		time.step();

		driveSystem.step();
		lifetimes.step();
		
		rigidBodies.step();

		collDetect.step();
		collResolve.step();

		render.step();
		debugDraw.step();
	}
	time.term();
	window.terminte();
	
}