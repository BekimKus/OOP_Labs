#include "ArrayException.h"

ArrayException::ArrayException(int code) : std::exception()
{
    this->code = code;
}

const char* ArrayException::what() const throw()
{
    switch (code) {
        case Error::INDEX_LESS_0:
            return "Exception: Index less then 0";
        case Error::INDEX_BIGGER_MAX_SIZE:
            return "Exception: Index bigger then max array size";
        case Error::INDEX_ERROR:
            return "Exception: Incorrect Index";
        case Error::MAX_SIZE_LESS_0:
            return "Exception: Max array size less then 0";
        case Error::MAX_SIZE_ERROR:
            return "Exception: Incorrect max array size";
        case Error::MAP_KEY_NOT_FOUND:
            return "Exception: The key isn't in the map";
        case Error::MAP_KEY_EMPTY:
            return "Exception: The input key is empty or null";
        case Error::NEGATIVE_VALUE:
            return "Exception: Incorrect input value";
        default:
            return "Unknown exception";
    }
}
