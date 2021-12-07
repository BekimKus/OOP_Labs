#pragma once
#include "Array.h"
class Queue : public Array
{
public:
	void push(int value);

	int pop();

	virtual char* toString();

	Queue& operator=(Queue& queue);

	Queue& operator--(void);

	Queue& operator--(int d);

	friend Queue& operator+(Queue& queue1, Queue& queue2);

	friend Queue& operator-(Queue& queue1, Queue& queue2);

	friend std::ostream& operator<< (std::ostream& out, Queue& queue);

	friend std::istream& operator>> (std::istream& in, Queue& queue);

	friend std::ifstream& operator>> (std::ifstream& in, Queue& queue);

	friend std::ofstream& operator<< (std::ofstream& out, Queue& queue);

};

