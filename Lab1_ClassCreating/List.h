#pragma once
#include "Array.h"
#include "Map.h"
#include "Queue.h"

class List
{
public:
	List();
	
	void add(Array& arr);
	
	void add(Map& map);
	
	void add(Queue& queue);

	void insert(Array& arr, int index);
	
	void insert(Map& map, int index);
	
	void insert(Queue& queue, int index);

	Array& getElement(int index);

	int getLength();

	void del();

	void deleteByIndex(int index);

	// Return position from head
	int find(Array& arr);
	
	int find(Queue& arr);
	
	int find(Map& arr);

	char* toString();

	~List();

private:
	struct Node {
		Array* array;

		Node* next;
		Node* prev;
	};	

	Node* head;
	int length;
};

