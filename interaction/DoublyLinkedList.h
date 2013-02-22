/*
 * DoublyLinkedList.h
 * Based off of Doc Santos's DLL class on Blackboard
 *
 *  Created on: Feb 12, 2013
 *      Author: Kendall Farnham
 */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_
#define NULL '\0'

template <class ADT>
class DoublyLinkedList {
	class Element {
		ADT* data;
		class Element* prev;
		class Element* next;

	public:
		Element() {}
		Element(ADT* d, class Element* p, class Element* n) {
			data = d;
			prev = p;
			next = n;
		}

		ADT* getData() {
			return data;	}

		class Element* getPrev() {
			return prev; }

		class Element* getNext() {
			return next;	}

		void setPrev(Element* p) {
			prev = p;	}

		void setNext(Element* n) {
			next = n;	}
	};

	Element* head;
	Element* tail;
	Element* current;
	int index;
	int count;

public:
	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
		current = NULL;
		index = -1;
		count = 0;
	}
	virtual ~DoublyLinkedList();
	void deepDelete();		// helper function to delete

	int getLength();
	ADT* getData();
	ADT* removeHead();
	int getIndex();
	int search(ADT*);
	bool moveToNext();
	bool moveToPrev();
	void moveToIndex(int i);
	void moveToHead();
	void moveToTail();
	void remove();
	void insertAfter(ADT* d);
	void insertBefore(ADT* d);
	void addToFront(ADT* d);
	void addToEnd(ADT* d);
};

#endif /* DOUBLYLINKEDLIST_H_ */
