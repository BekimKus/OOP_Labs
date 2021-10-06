#pragma once
#include <iostream>
#include <string.h>

using std::cout;

class Array
{
public:
	static int something;

	Array(int arraySize, int index, int* ptrArray);

	Array(const Array& array);

	Array();

	void sort();

	void add(int value, int index);

	void add(int value);

	int getElement(int index);

	int findElement(int value);

	void replace(int value, int index);

	void deleteElement(int index);

	void collapse();

	int getArraySize();

	int getIndex();

	int* getPtrArray();

	void setArraySize(int arraySize);

	void setIndex(int index);

	void setPtrArray(int* ptrArray);

	char* toString();

	~Array();

private:
	int arraySize;
	int index;
	int* ptrArray;

	char* intToChar(int number);
};

