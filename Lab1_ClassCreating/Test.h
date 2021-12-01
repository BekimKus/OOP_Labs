#pragma once
#include "Array.h"
#include "ArrayException.h"
#include "Map.h"
#include "Queue.h"
#include "List.h"

class Test
{
public:
	void static test1();

	void static test2();

	void static test3();

	void static test4();

	void static test5();

	void static test6();

	void static test7();

private:
	static bool equal(Array& realArray, int* expectedArray);
};