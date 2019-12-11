#pragma once

#include "Entity.h"

///  A class deriving from the Entity to receive a health variable for the marines.

class Marine:Entity 
{
public:
	Marine();
	~Marine();

	int attack();
	void takeDamage(int damage);
	bool isAlive();

};

