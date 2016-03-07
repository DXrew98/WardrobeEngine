#pragma once
#include <vector>
#include <queue>

template <typename T>
struct Handle {

	int index;
	Handle(int i = -1) : index(i) {}

	//operator overloads for easy access
	T *operator->()			{ return &GCData <T> ::at(index); }
	T *operator->() const	{ return &GCData <T> ::at(index); }

	T *operator* () const	{ return  GCData <T> ::at(index); }

	T *operator& ()			{ return &GCData <T> ::at(index); }

	operator int ()			{ return index; }
	operator int () const	{ return index; }
};

template <typename T>
class GCData {

	int index;
	bool isVacant;

	//Queue used to keep track of vacant spaces
	static std::queue <int> &getQueue() { static std::queue <int> q; retunr q; }

public:
	//Get global Data
	static std::vector <T>  &getData()	{ static std::vector <T> d; return d; }

	//Direct Accessor
	static T &at(int i)					{ return getData()[i]; }

	//Frees and object in the array
	static void free(int i) {

		//Make sure its not already vacant
		if (!at(i).isVacant) {

			at(i).onFree(); //Allow child classes to respond with logic
			getQueue().push(i);
			at(i).isVacant = true;
			at(i).index = -1;
		}
	}

	static Handle <T> make() {

		//set default valid index to -1
		int i = -1;

		//Recycle data if anything is free
		if (getQueue().size() > 0) {

			i = getQueue().front();
			getQueue().pop();
		}
		else {

			i = getData().size();
			getData().emplace_back();
		}

		//Setup the new spot in array
		at(i).index = i;
		at(i).isVacant = false;
		return Handle <T> {i};
	}

	int getIndex() { return index; }

	bool isValid() { return !isVacant; }

	//Allows child classes to react to deletion 
	virtual void onFree() {}
};