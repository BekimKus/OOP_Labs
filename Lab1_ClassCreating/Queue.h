#pragma once
#include "Array.h"
class Queue : public Array
{
public:
	void push(int value);

	int pop();

	Queue& operator=(Queue& queue);

	Queue& operator--(void);

	Queue& operator--(int d);

	friend Queue& operator+(Queue& queue1, Queue& queue2);

	friend Queue& operator-(Queue& queue1, Queue& queue2);

	virtual char* toString();
};

