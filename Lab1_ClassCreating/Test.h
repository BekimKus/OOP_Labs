#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include "Array.h"
#include "ArrayException.h"
#include "Map.h"
#include "Queue.h"
#include "List.h"
#include "ListT.h"
#include "TStack.h"

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
	
	void static test8();

private:
	static bool equal(Array& realArray, int* expectedArray);
};