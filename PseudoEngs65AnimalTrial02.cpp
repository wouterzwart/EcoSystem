/*
 * PseudoEngs65AnimalTrial02.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: yeunun
 */


#include <iostream>
using namespace std;

class grid
{
	/*
	 * I am going to pretend that this is the grid class for the animal
	 */
};

class animal
{
private:

	float energy, thirst, hunger, currenthealth, foodvalue;
	/*
	 *  how much energy this animal has
	 *  how thirsty this animal is
	 *  how hungry this animal is
	 *  how healthy this animal is, on the scale of 0 to 1
	 *  how much a prdatator's energy increase if he eats this animal
	 *
	 */
	int myx, myy, enemyx, enemyy;
	/*
	 *  this animal's current location
	 *  	and its closest enemy's location
	 *  if there is no enemy around
	 *  	then enemy location is (-1,-1)
	 */
	int awareness;
	/*
	 *  how far an animal can see
	 *
	 */
	int isitfree;
	/*
	 *  if this animal can do a free move, whatever that is, in this turn.
	 *  if this animal has gone through an interaction by the interaction class
	 *  	then this animal cannot do a free move
	 *  if this animal remains untouched by the interaction class
	 *  	then it can do whatever it can do e.g. move, rest, drink
	 */
	float bedtime, wakeuptime; int isitsleeping;
	/*
	 *  each animal has its own circadian rhythm to sleep and wake up
	 *  set isitsleeping = 1 if sleeping
	 *  set isitsleeping = 0 if awake
	 */
	float age, maxage;
	/*
	 *  the age of an animal increases in the beginning of every turn
	 *  e.g. age = age + timeperturn;
	 *  the animal interaction class kills an animal if age>maxage
	 *
	 */
	int sex, tier;
	/*
	 *  sex == 1 if male
	 *  sex == 2 if female
	 *
	 *  tier 0 animals are herbivores
	 *  tier n carnivore can eat tier n-1 carnivore and below
	 *
	 */
	animal *hunttarget;
	/*
	 *  this animal's target for hunting in this turn
	 *  this target is reset in the beginning of every turn
	 *  the interaction class goes through all the targeted animals
	 *  	and determines if the hunting was successful
	 *
	 */
	grid thisworld;
	/*
	 *  an animal must know in which world it exists
	 */

	void findenemy();
		// look for an enemy
	void findtarget();
		// look for a target to hunt
	void findgrass();
		// look for a grass field
	void findwater();
		// look for a source of water

	void move();
		// have this animal move freely
	void eatgrass();
		// eat grass and become less hungry
	void drinkwater();
		// drink water now
	void sleep();
		// have this animal fall asleep
	void wakeup();
		// have this animal be awake
	void moreage();
		// have this animal age
	void rest();
		// regains energy at the cost of hunger and thirst

public:

	void moreenergy(float amount);
		// increase the energy by the amount given
	void lessenergy(float amount);
		// decrease the energy by the amount given
	void morethirst(float amount);
		// increase the thirst by the amount given
	void lessthirst(float amount);
		// decrease the thirst by the amount given
	void morehunger(float amount);
		// increase the hunger by the amount given
	void lesshunger(float amount);
		// decrease the hunger by the amount given
	void morehealth(float amount);
		// increase the health by the amount given
	void lesshealth(float amount);
		// decrease the health by the amount given

	int returnfreedomstatus();
		/*
		 *  returns isitfree variable
		 *  if this animal was moved by the interaction
		 *  	then this should be 0
		 *  if this animal was not moved the interaction
		 *  	then this should be 1
		 *
		 */
	int returnsex();
		// return the sex of this animal
	int returntier();
		// return the tier of this animal

	animal* returntarget();
		// return the target of this animal

	void dofreethings();
		// an animal gets do some free things


};

class animalinteraction
{

private:

	class linkedlistofallanimals
	{
	private:
		// this is the interaction class for animals
		class animalentry
		{
		private:
			animal *animalpointer;
			animalentry *previous;
			animalentry *next;

		public:
			animalentry *whoareyou();
				// returns the pointer to the animal
			animalentry *whoisnext();
				// returns the pointer to next entry in this linked list
			animalentry *whoisprevious();
				// returns the pointer to the previous entry in this linked list
			animalentry(animal *pointertonewanimal);
				// constructor with the animal pointer
			~animalentry();
				// destructor
			void resetnext(animalentry *newnext);
				// reset the pointer to next entry
			void reestprevious(animalentry *newprvious);
				// reset the pointer to previous entry
		};
		animalentry *firstentry;
			// remembers the first entry of this linked list
		animalentry *lastentry;
			// remembers the last entry of this linked list
		animalentry *currententry;
			// remembers the current entry of this linked list
	public:
		linkedlistofallanimals();
			// construct the empty linked list
		~linkedlistofallanimals();
			// destructor
		void newanimalborn(animal *newlybornanimal);
			// add the newly born animal to the linked list
		void ananimaldied(animal *deadanimal);
			// remove the dead animal from the linked list
		void givemethefirstanimal();
			// returns the pointer to the animal of the first entry
			// and resets the current entry to the first entry
		void givemethenextanimal();
			// resets the pointer to the next entry
			// and returns that reset pointer
		void givemethelastanimal();
			// returns the point to the last entry
	};

public:

	animalinteraction();
	~animalinteraction();

	void animalsgetoldtiredhungrythirsty();
	/*
	 *  scans through all animals in the linked list and
	 *  	increase their age by the length of time of a turn
	 *  	decrease their energy by a given amount
	 *		increase their hunger by a given amount
	 *		decrease their thirst by a given amount
	 *
	 */
	void animalsdienaturally();
	/*
	 *  this method goes through all animals in the linked list
	 *  and kills all animals with negative energy, thirst, hunger, or health
	 *  animals also die when they become too old
	 *  when an animal dies, it is then deleted from the memory
	 *  without any trace, no tomb, no lamentation, just forgotten.
	 *
	 */
	void huntresult();
	/*
	 *  animals hunt each other, and this interaction class
	 *  	determines if the hunting was successful or not
	 *  first this scans through the linked list of all animals
	 *  	and generate a new linked list of targeted animals
	 *  for each animal in the linked list of targeted animals,
	 *  	searches through all carnivores in the vicinity that do have
	 *  	the targeted animal as their target
	 *  with a random probability, determine if the hunting was successful
	 *  if the hunting was successful
	 *  	then the targeted prey is deleted from the memory
	 *  	and the energy of the predators increase by the food value
	 *  		divided by the number of the predators
	 *  if the hunting was not successful
	 *  	then this function doesn't do anything
	 *
	 */
	void freeanimals();
	/*
	 *  scans through all animals in the linked list
	 *  and if an animal did not go through an interaction
	 *  	then have the animal do a free-thing in that turn
	 *
	 */

	/*
	 *  currently, the only interaction between animals are hunting.
	 *  however, this animal interaction class will have more functions/methods
	 *  when we allow more interactions between animals
	 *  such as mating, playing, etc.
	 *
	 */

};


int main()
{
	return 0;
}
