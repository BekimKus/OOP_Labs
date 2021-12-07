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

std::ostream& operator<<(std::ostream& out, Queue& queue)
{
	out << queue.toString();

	return out;
}

std::istream& operator>>(std::istream& in, Queue& queue)
{
	int arraySize;
	cout << "Array size: ";
	in >> arraySize;
	queue.setArraySize(arraySize);

	int index;
	cout << "Index: ";
	in >> index;
	cout << "Array: ";
	queue.setIndex(index);

	int* ptr = new int[queue.getArraySize()];
	memset(ptr, -1, queue.getArraySize() * sizeof(int));

	for (int i = 0; i < queue.getIndex(); i++) {
		in >> ptr[i];
	}
	queue.setPtrArray(ptr);

	return in;
}

std::ifstream& operator>>(std::ifstream& in, Queue& queue)
{
	int arraySize;
	in >> arraySize;
	queue.setArraySize(arraySize);

	int index;
	in >> index;
	queue.setIndex(index);

	int* ptr = new int[queue.getArraySize()];
	memset(ptr, -1, queue.getArraySize() * sizeof(int));

	for (int i = 0; i < queue.getIndex(); i++) {
		in >> ptr[i];
	}
	queue.setPtrArray(ptr);

	return in;
}

std::ofstream& operator<<(std::ofstream& out, Queue& queue)
{
	int sizeCh = 512;
	char* ch = new char[sizeCh];
	ch[0] = '\0';
	char val[10] = "";
	_itoa_s(queue.getArraySize(), val, 10);
	strcat_s(ch, sizeCh, val);
	strcat_s(ch, sizeCh, " ");
	_itoa_s(queue.getIndex(), val, 10);
	strcat_s(ch, sizeCh, val);
	strcat_s(ch, sizeCh, "\t");
	strcat_s(ch, sizeCh, queue.Array::toString());
	strcat_s(ch, sizeCh, "\n\0");

	out << ch;

	return out;
}
