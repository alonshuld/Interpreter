#include "NameErrorException.h"

const char* NameErrorException::what() const noexcept
{
    std::string ans = "NameError : name ‘";
    ans += this->_name;
    ans += "’ is not defined";
    return ans.c_str();
}
