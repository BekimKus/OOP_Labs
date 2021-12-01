#pragma once
#include "Array.h"
class Map : public Array
{
public:

	Map();

	Map(char** keysArray, int* values);

	void add(const char* key, int value);

	int getElement(const char* key);

	char* findElement(int value);

	void replace(const char* key, int value);

	void deleteElement(const char* key);

	void setKeysArray(char** keysArray);

	char** getKeysArray();

	Map& operator=(Map& map);

	friend Map& operator+(Map& map1, Map& map2);

	friend Map& operator-(Map& map1, Map& map2);

	//friend Map& operator-(Map& array, const char* key);

	Map& operator--(void);

	Map& operator--(int d);

	virtual char* toString();

	~Map();

private:
	char** keysArray;
};

