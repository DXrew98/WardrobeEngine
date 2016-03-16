#pragma once
#include "System.h"
#include "Assets.h"

class RenderSystem : public System {

	bool condition(Handle<Entity> i) {

		return i->sprite > -1 && i->transform > -1;
	}

	void update(Handle<Entity> i) {

		mat3 m = i->transform->getGlobalTransform() * andMath::translate(i->sprite->offset) 
			       * andMath::scale(i->sprite->dim) * andMath::rotate(i->sprite->angle);



		Asset::instance().drawTexture(i->sprite->assetName, m);
	}
};