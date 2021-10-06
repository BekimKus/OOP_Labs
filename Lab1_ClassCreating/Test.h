#pragma once
#include "Array.h"
class Test
{
public:
	void static test1();

	void static test2();

private:
	static bool equal(Array& realArray, int* expectedArray);
};

