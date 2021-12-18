#include "List.h"

List::List()
{
	head = NULL;
	length = 0;
}

void List::add(Array& array)
{
	Node* temp, * p;
	temp = (Node*)malloc(sizeof(Node));
	Array& arr = array;

	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));		
		head->array = &array;
		head->next = head;
		head->prev = head;
		//head->type = Type::Arr;
		length++;
		return;
	}

	p = head->prev;
	p->next = temp;
	head->prev = temp;

	temp->array = &array;
	temp->next = head;
	temp->prev = p;
	//temp->type = Type::Arr;

	length++;
}

void List::add(Map& map)
{
	Node* temp, * p;
	temp = (Node*)malloc(sizeof(Node));

	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->array = &map;
		head->next = head;
		head->prev = head;
		//head->type = Type::Mp;
		length++;
		return;
	}

	p = head->prev;
	p->next = temp;
	head->prev = temp;

	temp->array = &map;
	temp->next = head;
	temp->prev = p;

	length++;
	//temp->type = Type::Mp;
}

void List::add(Queue& queue)
{
	Node* temp, * p;
	temp = (Node*)malloc(sizeof(Node));

	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->array = &queue;
		head->next = head;
		head->prev = head;
		//head->type = Type::Que;
		length++;
		return;
	}

	p = head->prev;
	p->next = temp;
	head->prev = temp;

	temp->array = &queue;
	temp->next = head;
	temp->prev = p;

	length++;
	//temp->type = Type::Que;
}

void List::insert(Array& array, int index)
{
	Node* current = head;
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->array = &array;
		head->next = head;
		head->prev = head;
		//head->type = Type::Arr;
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

	temp->array = &array;
	temp->next = current;
	temp->prev = p;
	//temp->type = Type::Arr;

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
		head->array = &map;
		head->next = head;
		head->prev = head;
		//head->type = Type::Mp;
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

	temp->array = &map;
	temp->next = current;
	temp->prev = p;
	//temp->type = Type::Mp;

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
		head->array = &queue;
		head->next = head;
		head->prev = head;
		//head->type = Type::Que;
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

	temp->array = &queue;
	temp->next = current;
	temp->prev = p;
	//temp->type = Type::Que;

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

	return *current->array;
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

	if (current == head) {
		head = second;
	}
	delete current;
	length--;
}

int List::find(Array& array)
{
	Node* current = head;
	for (int i = 0; i < length; i++) {
		Array arr;
		arr = *current->array;
		if (arr.getArraySize() == array.getArraySize() &&
			arr.getIndex() == array.getIndex() &&
			arr.isEqual(array)) {
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
		Array arr;
		arr = *current->array;
		if (arr.getArraySize() == queue.getArraySize() &&
			arr.getIndex() == queue.getIndex() &&
			arr.isEqual(queue)) {
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
		Array arr;
		arr = *current->array;
		if (arr.getArraySize() == map.getArraySize() &&
			arr.getIndex() == map.getIndex() &&
			arr.isEqual(map)) {
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
		Array& arr = *current->array;

		char* temp = new char[1];
		temp[0] = '\0';
		temp = arr.toString();

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
