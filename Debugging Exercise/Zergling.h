#pragma once

#include "Entity.h"

///  A class deriving from the Entity to receive a health variable for the Zerglings.

class Zergling:Entity
{
public:
	Zergling();
	~Zergling();

	int attack();
	void takeDamage(int damage);
	bool isAlive();

};

