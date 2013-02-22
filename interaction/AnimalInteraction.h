/*
 * AnimalInteraction.h
 *
 *  Created on: Feb 22, 2013
 *      Author: Kendall
 */

#ifndef ANIMALINTERACTION_H_
#define ANIMALINTERACTION_H_
#include "PseudoEngs65AnimalTrial02.cpp"
#include "DoublyLinkedList.h"

class AnimalInteraction {
	DoublyLinkedList<animal>* animalDLL;
	int length;

public:
	AnimalInteraction();
	DoublyLinkedList<animal>* getAnimalDLL();
	int getLength();
	void createAnimal();
	void removeAnimal();
	animal* getFirstAnimal();
	animal* getLastAnimal();
	animal* findTarget(animal*);
	int findDistance(int,int,int,int);
	virtual ~AnimalInteraction();
};

#endif /* ANIMALINTERACTION_H_ */
