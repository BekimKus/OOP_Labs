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
		MAX_SIZE_ERROR
	};

	ArrayException(int code);

	const char* what() const throw();

private:
	int code;
};

