#pragma once
#include <iostream>
#include <string>

class Type
{
public:
	Type();
	bool getTemp() const;
	void setTemp(bool value);
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
private:
	bool _isTemp;
};
