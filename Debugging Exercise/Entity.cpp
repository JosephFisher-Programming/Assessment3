#include "Entity.h"

//  A basic contructor for Entities that sets a basic max health.

Entity::Entity()
{
	maxHealth = 10;
	health = 10;
}

//  A basic destructor for Entities created.

Entity::~Entity()
{
}

//  An attack function with no damage.

int Entity::attack() 
{
	return 0;
}

//  Makes the entity take damage based on the integer given.

void Entity::takeDamage(int damage)
{
	health -= damage;
}

//  Makes a boolean check to see if the entity was alive.

bool Entity::isAlive()
{
	return health > 0;
}
