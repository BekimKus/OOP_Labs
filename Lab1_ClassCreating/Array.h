#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include "ArrayException.h"

using std::cout;

class Array
{
public:
	static int something;

	Array(int arraySize, int index, int* ptrArray);

	Array(Array& array);

	Array(const Array& array);

	Array();

	void sort();

	void add(int value, int index);

	virtual void add(int value);

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

	void toTxtFile(const char* path);

	//void loadFromTxtFile(const char* path);

	virtual char* toString();

	char* toStringWithPtr();

	bool isEqual(Array& array);

	Array& operator=(Array& array);

	friend bool operator< (const Array& array1, const Array& array2);

	friend bool operator> (const Array& array1, const Array& array2);

	friend Array& operator+(Array& array1, Array& array2);

	friend Array& operator-(Array& array1, Array& array2);

	friend Array& operator-(Array& array, int index);

	Array& operator--(void);
	
	Array& operator--(int d);

	int& operator[](const int index);

	friend std::ostream& operator<< (std::ostream& out, Array& array);

	friend std::istream& operator>> (std::istream& in, Array& array);
	
	friend std::ofstream& operator<< (std::ofstream& out, Array& array);

	~Array();

private:
	int arraySize;
	int index;
	int* ptrArray;

	char* intToChar(int number);
};

