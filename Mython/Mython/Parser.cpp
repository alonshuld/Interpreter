#include "Parser.h"

std::unordered_map<std::string, Type*> _variables;

Type* Parser::parseString(std::string str)
{
	Type* var;
	if (str[0] == ' ' || str[0] == '\t')
	{
		throw(IndentationException());
	}
	if (str.length() > 0)
	{
		Helper::rtrim(str);
		var = getVariableValue(str);
		if (var != nullptr)
			return var;
		var = getType(str);
		if (var != nullptr)
			return var;
		if (makeAssignment(str))
		{
			var = new Void();
			var->setTemp(true);
			return var;
		}
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
	if (isList(str))
	{
		List* e = new List(str);
		e->setTemp(true);
		return e;
	}
	return nullptr;
}

bool Parser::isList(const std::string& s)
{
	std::string cpStr = s;
	cpStr.erase(std::remove(cpStr.begin(), cpStr.end(), ' '), cpStr.end());
	int i = 0;
	int startIndex = 0, endIndex = 0;
	if (cpStr[0] == '[' && cpStr[cpStr.length() - 1] == ']')
	{
		cpStr.erase(remove(cpStr.begin(), cpStr.end(), '['), cpStr.end()); //remove [ from string
		cpStr.erase(remove(cpStr.begin(), cpStr.end(), ']'), cpStr.end()); //remove ] from string
		while (i <= cpStr.length())
		{
			if (cpStr[i] == ',' || i == cpStr.length())
			{
				endIndex = i;
				std::string subStr = "";
				subStr.append(cpStr, startIndex, endIndex - startIndex);
				if (getType(subStr) == nullptr)
					return false;
				startIndex = endIndex + 1;
			}
			i++;
		}
	}
	else
		return false;
	return true;
}

void Parser::ClearVars()
{
	for (auto it = _variables.begin(); it != _variables.end(); it++)
		delete(it->second);
	_variables.clear();
}

bool Parser::isLegalVarName(std::string str)
{
	for (int i = 0; i < str.length(); i++)
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')) //if not number, upper case, lower case or _ than its false
			return false;
	if (!(str[0] >= '0' && str[0] <= '9'))
		return true;
	return false;
}

bool Parser::makeAssignment(std::string str)
{
	if (!str.find("="))
		return false;
	std::string var_name = str.substr(0, str.find("="));
	std::string var = str.substr(str.find("=") + 1);
	Helper::trim(var_name);
	Helper::trim(var);
	if (!isLegalVarName(var_name))
		throw NameErrorException();
	Type* value_var = getType(var);
	if (value_var == nullptr) //if second part of the string is not a variable
	{
		value_var = getVariableValue(var); //check if there is variable with this name
		if (value_var == nullptr) //if there is not then throw error
			throw NameErrorException();
		value_var = getType(value_var->toString()); //else there is a new var that is a copy of 
	}
	value_var->setTemp(false);
	auto it = _variables.find(var_name);
	if (it != _variables.end())
	{
		delete(it->second);
		it->second = value_var;
	}
	else
		_variables.insert(std::pair<std::string, Type*>(var_name, value_var));
	return true;
}

Type* Parser::getVariableValue(std::string str)
{
	auto it = _variables.find(str);
	if (it != _variables.end())
		return it->second;
	else
		return nullptr;
}


