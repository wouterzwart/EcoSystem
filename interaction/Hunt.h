/*
 * Hunt.h
 *
 *  Created on: Feb 22, 2013
 *      Author: Kendall
 */

#ifndef HUNT_H_
#define HUNT_H_
#include "PseudoEngs65AnimalTrial02.cpp"
#include "AnimalInteraction.h"

class Hunt {
	DoublyLinkedList<animal>* animalDLL;
	AnimalInteraction* AI;
public:
	Hunt();
	Hunt(animal*);
	animal* findTarget(animal*)
	virtual ~Hunt();
};

#endif /* HUNT_H_ */
