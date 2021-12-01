#pragma once
#include <exception>
class ArrayException : public std::exception
{

public:
	enum Error {
		INDEX_LESS_0,
		INDEX_BIGGER_MAX_SIZE,
		INDEX_ERROR,
		MAX_SIZE_LESS_0,
		MAX_SIZE_ERROR,
		MAP_KEY_NOT_FOUND,
		MAP_KEY_EMPTY,
		NEGATIVE_VALUE
	};

	ArrayException(int code);

	const char* what() const throw();

private:
	int code;
};

