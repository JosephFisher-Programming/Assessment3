#include "Marine.h"
#include "Entity.h"

//  The basic constructor for Marines that sets their health.

Marine::Marine()
{
	maxHealth = 50;
	health = 50;
}

//  The basic destructor for the marines.

Marine::~Marine()
{
}

//  A function that returns their damage value.

int Marine::attack()
{
	return 5;
}

//  A function that lowers the health for the marine.

void Marine::takeDamage(int damage)
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
	}	
}

//  A boolean to check if the marine is currently alive.

bool Marine::isAlive() 
{
	return health > 0;
}
