#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H
#include <cstdlib>
class Container {

public:
	class myiterator;
	friend myiterator;

	Container();
	myiterator *begin;
	myiterator *end;
	myiterator begin();
	myiterator end();

	
};

class Node {
public:
	int value;
};

class myiterator {
public:
	Node *p;
	myiterator operator++(int) {
		myiterator tmp = *this;
		if (p->value + 1 <= 10)
			++p->value;
		else p->value = 11;

		return tmp;
	}

	myiterator operator= (myiterator *it) {
		p = it->p;
		return *this;
	}

	int operator!=(myiterator it) {
		return p != it->p;
	}

	myiterator() {
		p = NULL;
	}
	
	int operator*() {
		return p->value;
	}



};


#endif // ! CONTAINER_H