#pragma once
#include "Entity.h"

class System{

	virtual bool condition	(Handle<Entity> i) = 0;
	virtual void update		(Handle<Entity> i) = 0;

public:
	void step()
	{
		for (unsigned i = 0; i < Entity::getData().size(); ++i)
		{
			if (Entity::at(i).isValid() && condition(i)) update(i);
		}
	}
};

//important thinganmajig:
class BinarySystem {

	virtual bool condition(Handle<Entity> i) = 0;
	virtual void update(Handle<Entity> i, Handle<Entity> j) = 0;
	virtual void onStep() {}

public:
	void step()
	{
		//for each unique pair of entites 
		for (unsigned i = 0; i < Entity::getData().size() - 1; ++i)
			for (unsigned j = i + 1; j < Entity::getData().size(); ++j){

			//if that unique pair meets the criteria
			if (Entity::at(i).isValid() && condition(i) && 
				Entity::at(j).isValid() && condition(j)) 

				//update them!
				update(i, j);
		}
	}
};