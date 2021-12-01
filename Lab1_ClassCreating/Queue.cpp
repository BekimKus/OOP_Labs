#include "Queue.h"

void Queue::push(int value)
{
	Array::add(value);
}

int Queue::pop()
{
	int temp = getElement(0);
	Array::deleteElement(0);
	return temp;
}

Queue& Queue::operator=(Queue& array)
{
	setPtrArray(array.getPtrArray());
	setArraySize(array.getArraySize());
	setIndex(array.getIndex());
	return *this;
}

Queue& Queue::operator--(void)
{
	int* ptrArr = getPtrArray();

	for (int i = 0; i < getIndex(); i++) {
		if (ptrArr[i] - 1 > 1) {
			ptrArr[i]--;
		}
	}

	setPtrArray(ptrArr);

	return *this;
}

Queue& Queue::operator--(int d)
{
	int* ptrArr = getPtrArray();

	for (int i = 0; i < getIndex(); i++) {
		if (ptrArr[i] - 1 > 1) {
			ptrArr[i]--;
		}
	}

	setPtrArray(ptrArr);

	return *this;
}

Queue& operator+(Queue& queue1, Queue& queue2)
{
	Queue* queue = new Queue();

	queue->setArraySize(queue1.getArraySize() + queue2.getArraySize());
	queue->setIndex(queue1.getIndex() + queue2.getIndex());

	int* ptrRes = new int[queue->getArraySize()];
	memset(ptrRes, -1, queue->getArraySize() * sizeof(int));
	int* ptrArr1 = queue1.getPtrArray();
	int* ptrArr2 = queue2.getPtrArray();

	int i;
	for (i = 0; i < queue1.getIndex(); i++) {
		ptrRes[i] = ptrArr1[i];
	}
	for (int j = 0; j < queue2.getIndex(); j++, i++) {
		ptrRes[i] = ptrArr2[j];
	}

	delete[] ptrArr1;
	delete[] ptrArr2;

	queue->setPtrArray(ptrRes);

	return *queue;
}

Queue& operator-(Queue& queue1, Queue& queue2)
{
	Queue* queue = new Queue();

	int* ptrRes = new int[queue1.getArraySize() + queue2.getArraySize()];
	memset(ptrRes, -1, queue->getArraySize() * sizeof(int));
	int* ptrArr1 = queue1.getPtrArray();
	int* ptrArr2 = queue2.getPtrArray();

	int i = 0;
	for (int j = 0; j < queue1.getIndex(); j++) {
		bool equal = false;
		for (int k = 0; k < queue2.getIndex(); k++) {
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

	queue->setArraySize(i + 2);
	queue->setIndex(i);

	delete[] ptrArr1;
	delete[] ptrArr2;

	queue->setPtrArray(ptrRes);
	queue->collapse();

	return *queue;
}


char* Queue::toString()
{
	char ch[255] = "";
	int* ptr = new int[getArraySize()];
	ptr = getPtrArray();

	for (int i = 0; i < getIndex(); i++) {
		char val[10] = "";
		_itoa_s(ptr[i], val, 10);
		strcat_s(ch, sizeof(ch), val);
		strcat_s(ch, sizeof(ch), "-> \0");
	}

	char* str = new char[sizeof(ch)];
	strcpy_s(str, sizeof(ch), ch);
	delete[] ptr;

	return str;
}
