#include "Zergling.h"

//  Basic constructor for zerglings that sets health.

Zergling::Zergling()
{
	maxHealth = 10;
	health = 10;
}

//  Basic destructor for zerglings.

Zergling::~Zergling()
{
}

//  The zerglings attack deals damage through the attack.

int Zergling::attack()
{
	return 9;
}

//  A function for the zerling's health to decrease.

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

//  A boolean to check if the zergling is alive.

bool Zergling::isAlive()
{
	return health > 0;
}