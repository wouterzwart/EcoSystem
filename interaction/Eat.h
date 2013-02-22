/*
 * Eat.h
 *
 *  Created on: Feb 18, 2013
 *      Author: Kendall
 */

#ifndef EAT_H_
#define EAT_H_
#define SCALE 4
#include "PseudoEngs65AnimalTrial02.cpp"

class Eat {
public:
	Eat();
	Eat(animal*, animal*);
	Eat(animal*, plant*);
	void eatGrass(animal*);
	virtual ~Eat();
};

#endif /* EAT_H_ */
