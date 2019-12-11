// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?
// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::endl;

//  Initialize Booleans for later definitions.

bool marineAlive(Marine * marineArr, size_t arrSize);
bool zerglingAlive(Zergling * swarmArr, size_t arrSize);

int main()
{	
	//  Creates a constant Squad Size to affect loops and how many member are in each group.

	const int SQUADSIZE = 10;
	int marineKilled = 0;
	Marine squad[SQUADSIZE];
	
	const int SWARMSIZE = 20;
	int zergKilled = 0;
	Zergling swarm[SWARMSIZE];

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!\n" << endl;

	//  Attack each other until only one team is left alive.
	//  Checks to see if anyone is left alive.

	while (marineAlive(squad, SQUADSIZE) && zerglingAlive(swarm, SWARMSIZE)) 
	{
		//  If there's atleast one marine left alive then continue.

		if (marineAlive(squad, SQUADSIZE)) 
		{
			//  Go through the whole squad and make them attack.

			for (size_t i = marineKilled; i < SQUADSIZE; i++) 
			{
				//  Every marine will attack the first zergling in the swarm.

				cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
				swarm[zergKilled].takeDamage(squad[i].attack());

				//  If the zergling dies, mark it as dead and state the number left.

				if (!swarm[zergKilled].isAlive()) 
				{
					zergKilled++;
					cout << "\nThe zergling target dies, " << SWARMSIZE - zergKilled << " remain.\n" << endl;
				}

				//  If the zergs killed are more than the swarm size, then break the loop.

				if (zergKilled >= SWARMSIZE) 
				{
					break;
				}
			}
		}

		//  If there's at least one zergling alive then run their attack(s).

		if (zerglingAlive(swarm, SWARMSIZE)) 
		{

			//  Loop through however many zerglings there are, and have them attack.

			for (size_t i = zergKilled; i < SWARMSIZE; i++) 
			{

				//  State how much damage they deal, and damage the marines for the correct value.

				cout << "A zergling attacks for " << swarm[i].attack() << " damage." << endl;
				squad[marineKilled].takeDamage(swarm[i].attack());

				//  If the marine they're attacking dies, then reduce their number and state that there are less.

				if (!squad[marineKilled].isAlive())
				{
					cout << "The marine succumbs to his wounds." << endl;
					marineKilled++;
					cout << "\nThere are " << SQUADSIZE - marineKilled << " marines left.\n" << endl;	
				}

				//  If the number of marines killed is more than the squad size, break the loop.

				if (marineKilled >= SQUADSIZE)
				{
					break;
				}
			}
		}
	}

	//  Once one team is completely eliminated, the fight ends and one team wins.

	cout << "The fight is over. ";
	if (marineAlive(squad, SQUADSIZE))
	{
		cout << "The Marines win." << endl;
	} 
	else
	{

		cout << "The Zerg win." << endl;
	}
}

//  Boolean to check if there is a living marine.

bool marineAlive(Marine * marineArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++) 
	{
		if (marineArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

//  Boolean to check if there is a living zergling.

bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (swarmArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}
