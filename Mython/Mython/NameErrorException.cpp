#include "NameErrorException.h"

const char* NameErrorException::what() const noexcept
{
    return "NameError : name is not defined";
}
