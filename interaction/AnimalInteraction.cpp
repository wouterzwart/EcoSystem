/*
 * AnimalInteraction.cpp
 *
 *  Created on: Feb 22, 2013
 *      Author: Kendall
 */

#include "AnimalInteraction.h"

AnimalInteraction::AnimalInteraction() {
	animalDLL = new DoublyLinkedList<animal>;
	length = 0;
}

AnimalInteraction::~AnimalInteraction() {}

DoublyLinkedList<animal>* AnimalInteraction::getAnimalDLL() {
	animalDLL->moveToHead();
	return animalDLL;
}

int AnimalInteraction::getLength() {
	return length;
}

void AnimalInteraction::createAnimal() {
	animal* a = new animal();
	if (length == 0)
		animalDLL->addToFront(a);
	else {
		animalDLL->moveToTail();
		animalDLL->insertAfter(a);
	}
}

void AnimalInteraction::removeAnimal(animal* a) {
	int index = animalDLL->search(a);
	animalDLL->moveToIndex(index);
	animalDLL->remove();
}

animal* AnimalInteraction::getFirstAnimal() {
	animalDLL->moveToHead();
	return animalDLL->getData();
}

animal* AnimalInteraction::getLastAnimal() {
	animalDLL->moveToTail();
	return animalDLL->getData();
}

animal* AnimalInteraction::findTarget(animal* a) {
	animal* target = getFirstAnimal();
	animal* returnAnimal;
	int index = animalDLL->search(a);
	int min = 100000000;
	int ax = a->myx;
	int ay = a->myy;
	for (int i=0; i<index; i++) {
		int targetx = target->myx;
		int targety = target->myy;
		int dist = findDistance(ax,ay,targetx,targety);
		if (dist < min) {
			min = dist;
			returnAnimal = target;
		}
		bool trash = animalDLL->moveToNext();
		target = animalDLL->getData();
	}
	for (int i=index+1; i<getLength; i++) {
			int targetx = target->myx;
			int targety = target->myy;
			int dist = findDistance(ax,ay,targetx,targety);
			if (dist < min) {
				min = dist;
				returnAnimal = target;
			}
			bool trash = animalDLL->moveToNext();
			target = animalDLL->getData();
		}
	return returnAnimal;
}

int AnimalInteraction::findDistance(int x1, int y1, int, x2, int y2) {
	return ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

