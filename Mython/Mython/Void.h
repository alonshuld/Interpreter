#pragma once
#include "Type.h"

class Void : public Type
{
public:
	Void();
	bool isPrintable() const;
};
