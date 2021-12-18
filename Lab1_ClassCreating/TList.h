#include <iostream>
#pragma once

using std::cout;
using std::endl;
template <class T> class TList
{
	struct Node {

		Node(T* v) {
			value = v;
			prev = nullptr;
			next = nullptr;
		}

		~Node() {
			delete[] value, prev, next;
		}

		T* value;
		Node* prev;
		Node* next;
	};



public:

	TList() {
		head = nullptr;
	}

	void add(T* v, int index = -1);
	T* getElement(int index);
	void del(int index = 0);
	bool isEmpty();
	char* toString();
	void show();
	

private:

	Node* head;
};


template<class T>
inline void TList<T>::add(T* v, int index)
{
	if (index < -1) throw "!Exception: Index less then null";
	Node* init = new Node(v);

	if (this->isEmpty()) {
		init->next = init;
		init->prev = init;
		head = init;
		return;
	}

	Node* current = head;

	if (index == -1) { // Insert before head

		do {
			current = current->next;
		} while (current->next != head);

		init->next = head;
		current->next = init;
		head->prev = init;
		init->prev = current;

	}
	else { // Insert by index

		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		if (current->prev == head) head = init;

		init->next = current;
		init->prev = current->prev;
		current->prev->next = init;
		current->prev = init;

	}
}

template<class T>
inline T* TList<T>::getElement(int index)
{
	if (head == nullptr) throw "!Exception: Empty list";
	if (index < 0) throw "!Exception: Index less then null";
	Node* current = head;

	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	T* elem = head->value;

	return elem;
}

template<class T>
inline void TList<T>::del(int index)
{
	if (head == nullptr) throw "!Exception: Empty list";
	Node* current = head;

	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	if (current == head) {
		head = head->next;
	}

	current->prev->next = current->next;
	current->next->prev = current->prev;
}

template<class T>
inline bool TList<T>::isEmpty()
{
	if (head == nullptr) return true;
	return false;

}

template<class T>
inline void TList<T>::show()
{

	Node* p = head;
	cout << endl;
	do {
		std::cout << *(p->value) << endl;
		p = p->next;
	} while (p != head);
	cout << endl;

}

inline char* TList<int>::toString()
{
	if (head == nullptr) throw "!Exception: Empty list";
	Node* current = head;
	char* ch = new char[512];
	ch[0] = '\0';

	do {
		char val[10] = "";
		int num = *(current->value);
		_itoa_s(num, val, 10);
		strcat_s(ch, 512, val);
		strcat_s(ch, 512, " ==> \0");

		current = current->next;
	} while (current != head);

	return ch;
}

inline char* TList<float>::toString()
{
	if (head == NULL) throw "!Exception: Empty list";
	Node* current = head;
	char* ch = new char[512];
	ch[0] = '\0';
	do {
		char val[20] = "";
		float num = *(current->value);

		sprintf_s(val, sizeof(val), "%f ==> \0", num);
		strcat_s(ch, 512, val);

		current = current->next;
	} while (current != head);

	return ch;
}

inline char* TList<Array>::toString()
{
	if (head == nullptr) throw "!Exception: Empty list";
	Node* current = head;
	char ch[1024];
	ch[0] = '\0';
	char* ptr = new char[sizeof(ch)];

	do {
		Array arr;
		arr = *(current->value);

		char* temp = new char[1];
		temp[0] = '\0';
		temp = arr.toString();

		sprintf_s(ptr, sizeof(ch), "%s==> \0", temp);
		strcat_s(ch, sizeof(ch), ptr);
		delete[] temp;

		current = current->next;
	} while (current != head);

	strcpy_s(ptr, sizeof(ch), ch);

	return ptr;
}
