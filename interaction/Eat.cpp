/*
 * Eat.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: Kendall
 */

#include "Eat.h"
#include "Animal.h"
#include "Plant.h"
#include "PseudoEngs65AnimalTrial02.cpp"

Eat::Eat() {}

Eat::~Eat() {}

Eat::Eat(animal* a1, animal* a2) {
	if (a1->tier == a2->tier) {
		a1->move();			// walk by each other...no fight
		a2->move();
	}
	else if (a1->tier > a2->tier) {
		a1->moreenergy((a2->tier) * SCALE + 1);		// would increase energy, decrease hunger level, etc.
		a1->lesshunger((a2->tier) * SCALE + 1);
		delete a2;
	} else {
		a2->moreenergy((a1->tier) * SCALE + 1);		// would increase energy, decrease hunger level, etc.
		a2->lesshunger((a1->tier) * SCALE + 1);
		delete a1;
	}
}


Eat::Eat(animal* a, plant* p) {
	a.gotFood();
	p.gotEaten();		// deplete resource a little bit
}


void Eat::eatGrass(animal* a) {
	a->moreenergy(1);		// would increase energy, decrease hunger level, etc.
	a->lesshunger(1);
}
