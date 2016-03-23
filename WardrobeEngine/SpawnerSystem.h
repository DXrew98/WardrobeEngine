#pragma once
#include "System.h"
#include "Factory.h"
#include "Time.h"

class Spawner : public System {

	bool condition(Handle<Entity> i) {

		return i->transform > -1 && i->spawner > -1;

	}


};