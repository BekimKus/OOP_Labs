#pragma once
#include "Array.h"
#include "ArrayException.h"

class Test
{
public:
	void static test1();

	void static test2();

	void static test3();

	void static test4();

private:
	static bool equal(Array& realArray, int* expectedArray);
};

