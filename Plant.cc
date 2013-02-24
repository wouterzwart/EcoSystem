/*
 * Plant.cc
 *
 *  Created on: Feb 24, 2013
 *      Author: Wouter
 */

#include <gameboard.h>
#include <iostream>
using namespace std;



class Plant
{
private:

  float quantity; //amount there is to be eaten before it is deplenished. if quantity = 0 delete
	float food_value; //amount of energy gained if eaten
	float water_value;
	int X_loaction, Y_Location; //plant's location in the grid

	float age, maxage;
		/*
		 *  the age of a plant increases in the beginning of every turn
		 *  e.g. age = age + timeperturn;
		 *  the plant interaction class kills an plant if age>maxage
		 */
	bool isitfree;
		/*
		 *  1 = free; 0 not free;
		 *  if the plant is free it grow in this turn.
		 *  if this plant has been eaten it cannot grow
		 */
public:
	void grow(); //increase quantity -depends on water and sunlight (if we have weather/rain)
	int returnfree();
		/*
		 *  returns isitfree variable
		 *  can only grow if not being eaten this turn
		 *  If plant was not eaten the interaction
		 *  	then this should be 1
		 */
	void get_goteaten();
	int return_food_value();
	int return_water_value();

};

class Plant_Interaction
{
private:
	class LinkedList_Plants
	{
	private:
		// this is the interaction class for plants
		class Plant_Entry
		{
		private:
			Plant *plantpointer;
			Plant_Entry *previous;
			Plant_Entry *next;

		public:
			Plant_Entry *getplantname();
				// returns the pointer to the plant
			Plant_Entry *next_plant();
				// returns the pointer to next entry in this linked list
			Plant_Entry *previous_plant();
				// returns the pointer to the previous entry in this linked list
			Plant_Entry(Plant *Ptr_for_new_Plant);
				// constructor with the plant pointer
			~Plant_Entry();
				// destructor
			void resetnext(Plant_Entry *newnext);
				// reset the pointer to next entry
			void reestprevious(Plant_Entry *newprvious);
				// reset the pointer to previous entry
		};
		Plant_Entry *firstentry;
			// remembers the first entry of this linked list
		Plant_Entry *lastentry;
			// remembers the last entry of this linked list
		Plant_Entry *currententry;
			// remembers the current entry of this linked list

	public:
		LinkedList_Plants();
			// construct the empty linked list
		~LinkedList_Plants();
			// destructor
		void New_Plant(Plant *new_plant);
			// add the newly created plant to the linked list
		void Plant_deceased(Plant *dead_plant);
			// remove the dead plant from the linked list
		void First_Plant();
			// returns the pointer to the plant of the first entry
			// and resets the current entry to the first entry
		void Next_Plant();
			// resets the pointer to the next entry
			// and returns that reset pointer
		void Last_Plant();
			// returns the point to the last entry
	};

public:

	Plant_Interaction();
	~Plant_Interaction();

	void Age_Plant();
	/*
	 *  scans through all plants in the linked list and
	 *  	increase their age by the length of time of a turn
	 */
	void Plant_die_naturally();
	/*
	 *  this method goes through all plants in the linked list
	 *  and kills all plants with negative energy qauntity or old age
	 *  deletes plant from the memory
	 *
	 */

	void free_plants();
	/*
	 *  scans through all plants in the linked list
	 *  and if an plant did not go through an interaction
	 *  	then have the plant do a free-thing in that turn
	 *
	 */

};
