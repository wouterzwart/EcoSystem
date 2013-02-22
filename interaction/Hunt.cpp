/*
 * Hunt.cpp
 *
 *  Created on: Feb 22, 2013
 *      Author: Kendall
 */

#include "Hunt.h"

Hunt::Hunt() {
	AI = new AnimalInteraction;
	animalDLL = AI->getAnimalDLL();
}

Hunt::~Hunt() {
	// TODO Auto-generated destructor stub
}

animal* Hunt::findTarget(animal* a) {
	animal* target = AI->findTarget(a);
	return target;
}
