#include "Array.h"

Array::Array(int arraySize, int index, int* ptrArray) : arraySize(arraySize), index(index), ptrArray(ptrArray) {}

Array::Array(Array& array)
{
	arraySize = array.getArraySize();
	index = array.getIndex();
	ptrArray = array.getPtrArray();
}

Array::Array()
{
	this->arraySize = 5;
	this->index = 0;
	this->ptrArray = new int[arraySize];
	memset(ptrArray, -1, getArraySize() * sizeof(int));
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
	if (value < 0) throw ArrayException(ArrayException::Error::NEGATIVE_VALUE);

	// Increase memory for array
	if (this->index == arraySize - 1) {
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
	if (value < 0) throw ArrayException(ArrayException::Error::NEGATIVE_VALUE);

	// Increase memory for array
	if (index == arraySize - 1) {
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
	for (int i = 0; i < arraySize; i++) {
		if (value == ptrArray[i]) return i;
	}

	return -1;
}

void Array::replace(int value, int index)
{
	if (index < 0) throw ArrayException(ArrayException::Error::INDEX_LESS_0);
	if (index > this->index) throw ArrayException(ArrayException::Error::INDEX_BIGGER_MAX_SIZE);
	if (value < 0) throw ArrayException(ArrayException::Error::NEGATIVE_VALUE);

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
	if (index < arraySize - 1) {
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
	if (index > arraySize) index == arraySize - 1;

	int* temp = new int[arraySize + 1];
	memset(temp, -1, (arraySize + 1) * sizeof(int));
	memcpy_s(temp, (arraySize + 1) * sizeof(int), ptrArray, arraySize * sizeof(int));
	delete[] ptrArray;
	ptrArray = temp;
}

void Array::setIndex(int index)
{
	if (index < 0) throw ArrayException(ArrayException::Error::INDEX_LESS_0);
	if (index > this->arraySize) throw ArrayException(ArrayException::Error::INDEX_BIGGER_MAX_SIZE);
	this->index = index;
}

void Array::setPtrArray(int* ptrArray)
{
	if (arraySize >= 0 && index >= 0) {
		delete[] this->ptrArray;
	}
	this->ptrArray = ptrArray;

}

void Array::toTxtFile(const char* path)
{
	std::ofstream out(path, std::ios::out);
	out << this;
	out.close();
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

bool Array::isEqual(Array& array)
{
	int* currentArray = ptrArray;
	int* arr2 = array.getPtrArray();
	int i = 0;
	while (*arr2 > 0 && *currentArray > 0 && i < array.getIndex()) {
		if (*arr2 != *currentArray) {
			break;
		}
		else {
			if (*(arr2 + 1) <= 0 && *(currentArray + 1) <= 0) {
				return true;
			}
			if (i >= array.getIndex()) {
				break;
			}
		}
		arr2++;
		currentArray++;
		i++;
	}

	return false;
}

Array& Array::operator= (Array& array)
{
	arraySize = array.getArraySize();
	index = array.getIndex();
	ptrArray = array.getPtrArray();
	return *this;
}

Array& operator+(Array& array1, Array& array2)
{
	Array* arr = new Array();

	arr->setArraySize(array1.getArraySize() + array2.getArraySize());
	arr->setIndex(array1.getIndex() + array2.getIndex());
	
	int* ptrRes = new int[arr->getArraySize()];
	memset(ptrRes, -1, arr->getArraySize() * sizeof(int));
	int* ptrArr1 = array1.getPtrArray();
	int* ptrArr2 = array2.getPtrArray();

	int i;
	for (i = 0; i < array1.getIndex(); i++) {
		ptrRes[i] = ptrArr1[i];
	}
	for (int j = 0; j < array2.getIndex(); j++, i++) {
		ptrRes[i] = ptrArr2[j];
	}
	
	delete[] ptrArr1;
	delete[] ptrArr2;

	arr->setPtrArray(ptrRes);

	return *arr;
}

Array& operator-(Array& array1, Array& array2)
{
	Array* arr = new Array();

	int* ptrRes = new int[array1.getArraySize() + array2.getArraySize()];
	memset(ptrRes, -1, arr->getArraySize() * sizeof(int));
	int* ptrArr1 = array1.getPtrArray();
	int* ptrArr2 = array2.getPtrArray();

	int i = 0;
	for (int j = 0; j < array1.getIndex(); j++) {
		bool equal = false;
		for (int k = 0; k < array2.getIndex(); k++) {
			if (ptrArr1[j] == ptrArr2[k]) {
				equal = true;
				break;
			}
		}

		if (!equal) {
			ptrRes[i] = ptrArr1[j];
			i++;
		}
	}

	arr->setArraySize(i + 2);
	arr->setIndex(i);

	delete[] ptrArr1;
	delete[] ptrArr2;

	arr->setPtrArray(ptrRes);
	arr->collapse();

	return *arr;
}

Array& operator-(Array& array, int index)
{
	array.deleteElement(index);

	return array;
}

std::ostream& operator<<(std::ostream& out, Array& array)
{
	out << array.toString();

	return out;
}

std::istream& operator>>(std::istream& in, Array& array)
{
	in >> array.arraySize;
	in >> array.index;

	int* ptr = new int[array.arraySize];
	memset(ptr, -1, array.getArraySize() * sizeof(int));

	for (int i = 0; i < array.index; i++) {
		in >> ptr[i];
	}
	array.setPtrArray(ptr);

	return in;
}

std::ofstream& operator<<(std::ofstream& out, Array& array)
{
	int sizeCh = 512;
	char* ch = new char[sizeCh];
	ch[0] = '\0';
	char val[10] = "";
	_itoa_s(array.getArraySize(), val, 10);
	strcat_s(ch, sizeCh, val);
	strcat_s(ch, sizeCh, " ");
	_itoa_s(array.getIndex(), val, 10);
	strcat_s(ch, sizeCh, val);
	strcat_s(ch, sizeCh, "\t");
	strcat_s(ch, sizeCh, array.toString());
	strcat_s(ch, sizeCh, "\n\0");

	out << ch;

	return out;
}

Array& Array::operator--()
{
	for (int i = 0; i < index; i++) {
		if (ptrArray[i] - 1 > 1) {
			ptrArray[i]--;
		}
	}

	return *this;
}

Array& Array::operator--(int d)
{
	for (int i = 0; i < index; i++) {
		if (ptrArray[i] - 1 > 1) {
			ptrArray[i]--;
		}
	}

	return *this;
}

int& Array::operator[](const int index)
{
	if (index > this->index) throw ArrayException(ArrayException::Error::INDEX_BIGGER_MAX_SIZE);
	if (index < 0) throw ArrayException(ArrayException::Error::INDEX_LESS_0);

	return ptrArray[index];
}

Array::~Array()
{
	if (index > 0 && arraySize > 0) {
		delete[] ptrArray;
	}
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