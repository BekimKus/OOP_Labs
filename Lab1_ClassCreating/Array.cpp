#include "Array.h"

Array::Array(int arraySize, int index, int* ptrArray) : arraySize(arraySize), index(index), ptrArray(ptrArray) {}

Array::Array(const Array& array) : arraySize(array.arraySize), index(array.index), ptrArray(array.ptrArray) {}

Array::Array()
{
	this->arraySize = 5;
	this->index = 0;
	this->ptrArray = new int[arraySize];

	int* temp = ptrArray;
	for (int i = 0; i < arraySize; i++, temp++) {
		*temp = -1;
	}

}

void Array::sort()
{
	int* temp = ptrArray;

	for (int i = 0; i < index; i++) {
		for (int j = i + 1; j < index; j++) {
			if (temp[i] > temp[j]) {
				int val = temp[i];
				temp[i] = temp[j];
				temp[j] = val;
			}
		}
	}
}

void Array::add(int value, int index)
{	
	if (index > this->index) throw ArrayException(ArrayException::Error::INDEX_BIGGER_MAX_SIZE);
	if (index < 0) throw ArrayException(ArrayException::Error::INDEX_LESS_0);

	// Increase memory for array
	if (this->index == arraySize) {
		int* temp1 = new int[arraySize * 2];
		memcpy_s(temp1, arraySize * sizeof(int) * 2, ptrArray, arraySize * sizeof(int));
		arraySize *= 2;
		ptrArray = temp1;
	}

	int* temp = ptrArray;
	temp += arraySize - 1;

	for (int i = arraySize - 1; i > index; i--, temp--) {
		if (*(temp - 1) != 0) {
			*temp = *(temp - 1);
		}
	}

	this->index++;
	*temp = value;
}

void Array::add(int value)
{
	// Increase memory for array
	if (index == arraySize) {
		int* temp = new int[arraySize * 2];
		memcpy_s(temp, arraySize * sizeof(int) * 2, ptrArray, arraySize * sizeof(int));
		arraySize *= 2;
		ptrArray = temp;
		for (int i = index; i < arraySize; i++)
			ptrArray[i] = -1;
	}
	ptrArray[index] = value;
	this->index++;
}

int Array::getElement(int index)
{
	if (index < 0) throw ArrayException(ArrayException::Error::INDEX_LESS_0);
	if (index > this->index) throw ArrayException(ArrayException::Error::INDEX_BIGGER_MAX_SIZE);
	return ptrArray[index];
}

int Array::findElement(int value)
{
	int* temp = ptrArray;
	for (int i = 0; i < arraySize; i++, temp++) {
		if (value == *temp) {
			return i;
		}
	}

	return -1;
}

void Array::replace(int value, int index)
{
	if (index < 0) throw ArrayException(ArrayException::Error::INDEX_LESS_0);
	if (index > this->index) throw ArrayException(ArrayException::Error::INDEX_BIGGER_MAX_SIZE);
	ptrArray[index] = value;
}

void Array::deleteElement(int index)
{
	if (index < 0) throw ArrayException(ArrayException::Error::INDEX_LESS_0);
	if (index > this->index) throw ArrayException(ArrayException::Error::INDEX_BIGGER_MAX_SIZE);


	int* temp = ptrArray;
	temp += index;

	if (index == arraySize - 1) {
		*temp = -1;
		return;
	}

	for (int i = index; i < arraySize - 1; i++, temp++) {
		*temp = *(temp + 1);
	}

	this->index--;
	*temp = -1;
}

void Array::collapse()
{
	if (index < arraySize) {
		int* temp = new int[index];
		memcpy_s(temp, index * sizeof(int), ptrArray, index * sizeof(int));
		delete[] ptrArray;
		ptrArray = temp;
		arraySize = index;
	}
}

int Array::getArraySize()
{
	return arraySize;
}

int Array::getIndex()
{
	return index;
}

int* Array::getPtrArray()
{
	int* ptrArrayCopy = new int[arraySize];
	memcpy(ptrArrayCopy, ptrArray, arraySize * sizeof(int));
	return ptrArrayCopy;
}

void Array::setArraySize(int arraySize)
{
	if (arraySize < 0) throw ArrayException(ArrayException::Error::MAX_SIZE_LESS_0);

	this->arraySize = arraySize;
	if (index > arraySize) index == arraySize;

	int* temp = new int[arraySize + 1];
	memcpy_s(temp, (arraySize + 1) * sizeof(int), ptrArray, (arraySize + 1) * sizeof(int));
	delete[] ptrArray;
	ptrArray = temp;
	for (int i = index; i < arraySize; i++)
		ptrArray[i] = -1;
}

void Array::setIndex(int index)
{
	if (index < 0) throw ArrayException(ArrayException::Error::INDEX_LESS_0);
	if (index > this->index) throw ArrayException(ArrayException::Error::INDEX_BIGGER_MAX_SIZE);
	this->index = index;
}

void Array::setPtrArray(int* ptrArray)
{
	delete[] this->ptrArray;
	this->ptrArray = ptrArray;
}

char* Array::toString()
{
	char ch[255] = "";

	for (int i = 0; i < index; i++) {
		char val[10] = "";
		_itoa_s(ptrArray[i], val, 10);
		strcat_s(ch, sizeof(ch), val);
		strcat_s(ch, sizeof(ch), " \0");
	}

	char* ptr = new char[sizeof(ch)];
	strcpy_s(ptr, sizeof(ch), ch);

	return ptr;
}

char* Array::toStringWithPtr()
{
	char* ch = new char[255];
	char* chPtr = ch;
	int* temp = ptrArray;
	char* ptr1 = intToChar(*temp++);
	int i = 0;

	while (true) {
		if (*(temp - 1) <= 0 || i >= index) {
			break;
		}

		if (*ptr1) {
			*chPtr = *ptr1;
			chPtr++;
			ptr1++;
		}
		else {
			*chPtr = ' ';
			chPtr++;
			i++;
			ptr1 = intToChar(*temp++);
		}
	}
	*chPtr = '\0';
	return ch;
}

Array::~Array()
{
	delete[] ptrArray;
}

char* Array::intToChar(int number)
{
	int n;
	int length = 0;
	int reversedNumber = 0;
	int countZero = 0;

	while (number != 0) {
		n = number % 10;
		if (n == 0) {
			countZero++;
		}
		reversedNumber = reversedNumber * 10 + n;
		number /= 10;
		length++;
	}

	char* ch = new char[length];
	char* chPtr = ch;
	for (int i = 0; reversedNumber != 0; i++, reversedNumber /= 10, chPtr++) {
		*chPtr = reversedNumber % 10 + '0';
	}
	while (countZero > 0) {
		*chPtr = 0 + '0';
		chPtr++;
		countZero--;
	}
	*chPtr = '\0';

	return ch;
}