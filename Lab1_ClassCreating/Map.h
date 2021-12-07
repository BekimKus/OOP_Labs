#pragma once
#include "Array.h"
class Map : public Array
{
public:

	Map();

	Map(char** keysArray, int* values);

	void add(const char* key, int value);

	int getValue(const char* key);

	char* findKeyByValue(int value);

	void replace(const char* key, int value);

	void deleteElement(const char* key);

	void setKeysArray(char** keysArray);

	char** getKeysArray();

	virtual char* toString();

	Map& operator=(Map& map);

	friend Map& operator+(Map& map1, Map& map2);

	friend Map& operator-(Map& map1, Map& map2);

	friend Map& operator-(Map& map, const char* key);

	Map& operator--(void);

	Map& operator--(int d);

	int& operator[](const char* key);

	friend std::ostream& operator<< (std::ostream& out, Map& map);

	friend std::istream& operator>> (std::istream& in, Map& map);

	friend std::ifstream& operator>> (std::ifstream& in, Map& map);

	friend std::ofstream& operator<< (std::ofstream& out, Map& map);

	
	~Map();

private:
	char** keysArray;
};

