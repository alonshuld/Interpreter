#include "String.h"

String::String(std::string value)
{
	this->_value = value;
}

bool String::isPrintable() const
{
	return true;
}

std::string String::toString() const
{
	return this->_value;
}
