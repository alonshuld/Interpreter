#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "InterpreterException.h"
#include "string"

class NameErrorException : public InterpreterException
{
public:
	virtual const char* what() const noexcept;
private:
	std::string _name;
};