#include "List.h"

List::List(std::string s)
{
	s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
	int i = 0;
	int startIndex = 0, endIndex = 0;
	if (s[0] == '[' && s[s.length() - 1] == ']')
	{
		s.erase(remove(s.begin(), s.end(), '['), s.end()); //remove [ from string
		s.erase(remove(s.begin(), s.end(), ']'), s.end()); //remove ] from string
		while (i <= s.length())
		{
			if (s[i] == ',' || i == s.length())
			{
				endIndex = i;
				std::string subStr = "";
				subStr.append(s, startIndex, endIndex - startIndex);
				Type* var = Parser::getType(subStr);
				this->_value.push_back(var);
				startIndex = endIndex + 1;
			}
			i++;
		}
	}
}

bool List::isPrintable() const
{
	return true;
}

std::string List::toString() const
{
	std::string ans = "[";
	for (int i = 0; i < this->_value.size(); i++)
	{
		if(this->_value[i]->isPrintable())
			ans += this->_value[i]->toString() + ", ";
	}
	if (ans.length() > 1)
		ans = ans.substr(0, ans.length() - 2);
	ans += "]";
	return ans;
}
