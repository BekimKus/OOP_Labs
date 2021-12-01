#include "List.h"

List::List()
{
	head = NULL;
	length = 0;
}


List::List(Array& arr)
{
	/*head = (Node*)malloc(sizeof(Node));
	head->array = arr;
	head->next = head;
	head->prev = head;
	length = 1;*/
}

void List::add(Array& array)
{
	Node* temp, * p;
	temp = (Node*)malloc(sizeof(Node));

	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->array = array;
		head->next = head;
		head->prev = head;
		head->type = Type::Arr;
		length++;
		return;
	}

	p = head->prev;
	p->next = temp;
	head->prev = temp;

	temp->array = array;
	temp->next = head;
	temp->prev = p;
	temp->type = Type::Arr;

	length++;
}

void List::add(Map& map)
{
	Node* temp, * p;
	temp = (Node*)malloc(sizeof(Node));

	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->map = map;
		head->next = head;
		head->prev = head;
		head->type = Type::Mp;
		length++;
		return;
	}

	p = head->prev;
	p->next = temp;
	head->prev = temp;

	temp->map = map;
	temp->next = head;
	temp->prev = p;

	length++;
	temp->type = Type::Mp;
}

void List::add(Queue& queue)
{
	Node* temp, * p;
	temp = (Node*)malloc(sizeof(Node));

	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->queue = queue;
		head->next = head;
		head->prev = head;
		head->type = Type::Que;
		length++;
		return;
	}

	p = head->prev;
	p->next = temp;
	head->prev = temp;

	temp->queue = queue;
	temp->next = head;
	temp->prev = p;

	length++;
	temp->type = Type::Que;
}

void List::insert(Array& array, int index)
{
	Node* current = head;
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->array = array;
		head->next = head;
		head->prev = head;
		head->type = Type::Arr;
		return;
	}
		
	for (int i = 0; i < index; i++) {
		current = current->next;
	}


	Node* temp, * p;
	temp = (Node*)malloc(sizeof(Node));
	p = current->prev;
	p->next = temp;
	current->prev = temp;

	temp->array = array;
	temp->next = current;
	temp->prev = p;
	temp->type = Type::Arr;

	if (index == 0) {
		head = temp;
	}

	length++;
}

void List::insert(Map& map, int index)
{
	Node* current = head;
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->map = map;
		head->next = head;
		head->prev = head;
		head->type = Type::Mp;
		return;
	}

	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	Node* temp, * p;
	temp = (Node*)malloc(sizeof(Node));
	p = current->prev;
	p->next = temp;
	current->prev = temp;

	temp->map = map;
	temp->next = current;
	temp->prev = p;
	temp->type = Type::Mp;

	if (index == 0) {
		head = temp;
	}

	length++;
}

void List::insert(Queue& queue, int index)
{
	Node* current = head;
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->queue = queue;
		head->next = head;
		head->prev = head;
		head->type = Type::Que;
		return;
	}

	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	Node* temp, * p;
	temp = (Node*)malloc(sizeof(Node));
	p = current->prev;
	p->next = temp;
	current->prev = temp;

	temp->queue = queue;
	temp->next = current;
	temp->prev = p;
	temp->type = Type::Que;

	if (index == 0) {
		head = temp;
	}

	length++;
}

Array& List::getElement(int index)
{
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	switch (current->type) {
		case Type::Arr:
			return current->array;
		case Type::Que:
			return current->queue;
		case Type::Mp:
			return current->map;
	}
}

int List::getLength()
{
	return length;
}

void List::del()
{
	Node* last = head->prev;
	Node* lastP = last->prev;

	lastP->next = head;
	head->prev = lastP;
	delete last;
	length--;
}

void List::deleteByIndex(int index)
{
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	Node* first = current->prev;
	Node* second = current->next;

	first->next = second;
	second->prev = first;
	delete current;

	if (current == head) {
		head = second;
	}
	length--;
}

int List::find(Array& array)
{
	Node* current = head;
	for (int i = 0; i < length; i++) {
		if (current->array.getArraySize() == array.getArraySize() &&
			current->array.getIndex() == array.getIndex() && 
			current->array.isEqual(array)) {
			return i;
		}

		current = current->next;
	}

	return -1;
}

int List::find(Queue& queue)
{
	Node* current = head;
	for (int i = 0; i < length; i++) {
		if (current->queue.getArraySize() == queue.getArraySize() &&
			current->queue.getIndex() == queue.getIndex() &&
			current->queue.isEqual(queue)) {
			return i;
		}

		current = current->next;
	}

	return -1;
}

int List::find(Map& map)
{
	Node* current = head;
	for (int i = 0; i < length; i++) {
		if (current->map.getArraySize() == map.getArraySize() &&
			current->map.getIndex() == map.getIndex() &&
			current->map.isEqual(map)) {
			return i;
		}

		current = current->next;
	}

	return -1;
}

char* List::toString()
{
	Node* current = head;
	char ch[1024];
	ch[0] = '\0';
	char* ptr = new char[sizeof(ch)];

	for (int i = 0; i < length; i++) {
		Array arr;
		Queue queue;
		Map map;

		char* temp = new char[1];
		temp[0] = '\0';

		switch (current->type) {
		case Type::Arr:
			arr = current->array;
			temp = arr.toString();
			break;
		case Type::Que:
			queue = current->queue;
			temp = queue.toString();
			break;
		case Type::Mp:
			map = current->map;
			temp = map.toString();
			break;
		}

		sprintf_s(ptr, sizeof(ch), "%s==> \0", temp);
		strcat_s(ch, sizeof(ch), ptr);
		delete[] temp;

		current = current->next;
	}

	strcpy_s(ptr, sizeof(ch), ch);

	return ptr;
}

List::~List()
{
	Node* current = head->next;
	Node* next = current->next;
	while (current != head) {
		delete current;
		current = next;
		next = current->next;
	}
	delete head;
}