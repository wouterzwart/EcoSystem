/*
 * DoublyLinkedList.cpp
 * Based off of Doc Santos's DLL class on Blackboard
 * Added method removeHead() for stack implementation
 *
 *  Created on: Feb 12, 2013
 *      Author: Kendall Farnham
 */

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;


template <class ADT>
DoublyLinkedList<ADT>::~DoublyLinkedList() {
	while(count > 0)
		remove();
}

template <class ADT>
int DoublyLinkedList<ADT>::getLength() {
	return count;
}

template <class ADT>
ADT* DoublyLinkedList<ADT>::getData() {
	if (current == NULL)
		return NULL;
	return (current->getData());
}

template <class ADT>
ADT* DoublyLinkedList<ADT>::removeHead() {			// use for "pop" in stack implementation
	if (head == NULL)
		return NULL;
	moveToHead();
	ADT* headData = new ADT(*(head->getData()));	// make copy of head for returning
	remove();
	return (headData);

}

template <class ADT>
int DoublyLinkedList<ADT>::getIndex() {
	return index;
}

template <class ADT>
bool DoublyLinkedList<ADT>::moveToNext() {
	if (current == NULL || current->getNext() == NULL)
		return false;
	current = current->getNext();
	index++;
	return true;
}

template <class ADT>
bool DoublyLinkedList<ADT>::moveToPrev() {
	if (current == NULL || current->getPrev() == NULL)
		return false;
	current = current->getPrev();
	index--;
	return true;
}

template <class ADT>
void DoublyLinkedList<ADT>::moveToIndex(int i) {
	if (i<0 || i>=count)
		return;

}

template <class ADT>
void DoublyLinkedList<ADT>::moveToHead() {
	if (count > 0) {
		current = head;
		index = 0;
	}
}

template <class ADT>
void DoublyLinkedList<ADT>::moveToTail() {
	if (count > 0) {
		current = tail;
		index = count - 1;
	}
}

template <class ADT>
int DoublyLinkedList<ADT>::search(ADT* d) {
	moveToHead();
	for (int i=0; i < count; i++) {
		if (current->getData() == d)
			return index;
		else {
			current = current->getNext();
			index++;
		}
	}
	return -1;			// if no match
}

template <class ADT>
void DoublyLinkedList<ADT>::remove() {
	if (current == NULL)
		return;
	Element* p = current->getPrev();
	Element* n = current->getNext();

	delete current->getData();
	count--;
	if (p == NULL)
		head = n;
	else p->setNext(n);
	if (n == NULL)
		tail = p;
	else n->setPrev(p);

	delete current;
	if (count == 0) {
		current = NULL;
		index = -1;
	} else {
		if (n != NULL)
			current = n;
		else {
			current = p;
			index--;
		}
	}
}

template <class ADT>
void DoublyLinkedList<ADT>::insertAfter(ADT* d) {
	Element* newLink = new Element(d, current, NULL);

	if (current == NULL) {
		count = 1;
		current = newLink;
		tail = newLink;
		head = newLink;
		index = 0;
		return;
	}

	Element* n = current->getNext();
	current->setNext(newLink);
	if (n == NULL)
		tail = newLink;
	else {
		n->setPrev(newLink);
		newLink->setNext(n);
	}
	count++;
	current = newLink;
	index++;
}

template <class ADT>
void DoublyLinkedList<ADT>::insertBefore(ADT* d) {
	Element* newLink = new Element(d, NULL, current);

	if (current == NULL) {
		count = 1;
		current = newLink;
		tail = newLink;
		head = newLink;
		index = 0;
		return;
		cout << "Current = null" << endl;
	}

	Element* p = current->getPrev();
	current->setPrev(newLink);
	if (p == NULL)
		head = newLink;
	else {
		p->setNext(newLink);
		newLink->setPrev(p);
	}
	count++;
	current = newLink;
}

template <class ADT>
void DoublyLinkedList<ADT>::addToFront(ADT* d) {
	moveToHead();
	insertBefore(d);
}

template <class ADT>
void DoublyLinkedList<ADT>::addToEnd(ADT* d) {
	moveToTail();
	insertAfter(d);
}
