#pragma once

///  The class is used to set up some of the others.

class Entity
{
public:
	Entity();
	~Entity();

	virtual int attack();
	virtual void takeDamage(int damage);
	bool isAlive();

	int health;
	int maxHealth;
};

