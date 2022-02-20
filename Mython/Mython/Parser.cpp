#include "Parser.h"
#include <iostream>


Type* Parser::parseString(std::string str)
{
	if (str[0] == ' ' || str[0] == '\t')
	{
		throw(IndentationException());
	}
	if (str.length() > 0)
	{
		Helper::rtrim(str);
		return getType(str);
	}
	return nullptr;
}

Type* Parser::getType(std::string str)
{
	Helper::trim(str);
	if (Helper::isInteger(str))
	{
		int value;
		std::stringstream ssValue(str); //converts string to int
		ssValue >> value;
		Integer* e = new Integer(value);
		e->setTemp(true);
		return e;
	}
	if (Helper::isBoolean(str))
	{
		bool value;
		if (str == "True") //converting to bool
			value = true;
		else
			value = false;
		Boolean* e = new Boolean(value);
		e->setTemp(true);
		return e;
	}
	if (Helper::isString(str))
	{
		String* e = new String(str);
		e->setTemp(true);
		return e;
	}
	return nullptr;
}


