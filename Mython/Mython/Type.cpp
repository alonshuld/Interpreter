#include "Type.h"

Type::Type()
{
	this->_isTemp = false;
}

bool Type::getTemp() const
{
	return this->_isTemp;
}

void Type::setTemp(bool value)
{
	this->_isTemp = value;
}
