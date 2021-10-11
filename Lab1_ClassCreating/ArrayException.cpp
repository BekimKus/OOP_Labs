#include "ArrayException.h"

ArrayException::ArrayException(int code) : std::exception()
{
    this->code = code;
}

const char* ArrayException::what() const throw()
{
    if (code == Error::INDEX_LESS_0) return "Exception: Index less then 0";
    else if (code == Error::INDEX_BIGGER_MAX_SIZE) return "Exception: Index bigger then max array size";
    else if (code == Error::INDEX_ERROR) return "Exception: Incorrect Index";
    else if (code == Error::MAX_SIZE_LESS_0) return "Exception: Max array size less then 0";
    else if (code == Error::MAX_SIZE_ERROR) return "Exception: Incorrect max array size";
    else return "Unknown exception";
}
