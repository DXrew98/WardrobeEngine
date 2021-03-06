#include "MainDependencies.h"

int main() {

	auto &window	= Window::instance();
	auto &input		= Input::instance();
	auto &time		= Time::instance();

	window.init();
	input.init();
	time.init();

	Asset::instance().loadTexture("Shippie", "../Textures/Spaceship14.png");
	
	Factory::makePlayer({ 400,240 }, 100, 100, 35);

	Factory::makeWorldEdge({ 400, 0 }, { 400, 1 }); //bot
	Factory::makeWorldEdge({ 400, 600 }, { 400, 1 }); //top
	Factory::makeWorldEdge({ 0, 299 }, { 1, 298 }); //left
	Factory::makeWorldEdge({ 800, 299 }, { 1, 298 }); //right

	Factory::makeBall({ 200, 200 }, { 0, 0 }, 20, 1);
	Factory::makeBall({ 500, 500 }, { -30, -80 }, 20, 1);
	Factory::makeBlock({ 110,100 }, { 20, 20 }, { 0, 0 }, 1);
	Factory::makeBlock({ 550,100 }, { 50, 50 }, { -60, 0 }, 1);
	Factory::makeTempBlock({ 300, 100 }, { 30, 30 }, { 0, 0 }, 1, .1);

	DebugDraw debugDraw;
	RigidBodyDynamics rigidBodies;
	PlayerCarSystem driveSystem;
	LifetimeSystem lifetimes;

	CollisionDetectionSystem collDetect;
	//HealthSystem health;

	DynamicResolution collResolve;
	StaticResolution staticResolve;
	
	RenderSystem render;

	while (window.step()) {

		input.step();
		time.step();

		driveSystem.step();
		lifetimes.step();
		
		rigidBodies.step();

		collDetect.step();
		collResolve.step();
		staticResolve.step();

		render.step();
		debugDraw.step();
	}
	time.term();
	window.terminte();
	
}