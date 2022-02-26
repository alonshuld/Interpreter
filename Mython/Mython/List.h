#pragma once
#include "Sequence.h"
#include "Type.h"
#include "Parser.h"
#include <vector>

class List : public Sequence
{
public:
	List(std::string s);
	bool isPrintable() const;
	std::string toString() const;
private:
	std::vector<Type*> _value;
};