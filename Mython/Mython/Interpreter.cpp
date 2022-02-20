#include "Type.h"
#include "InterpreterException.h"
#include "SyntaxException.h"
#include "Parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "[Alon Shuldiner]"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		try
		{
			Type* var;
			// parsing command
			var = Parser::parseString(input_string);
			if (var != nullptr)
			{
				if (var->isPrintable() == true)
					std::cout << var->toString() << '\n';
				delete var;
			}
			else
			{
				throw SyntaxException();
			}
		}
		catch(InterpreterException& e)
		{
			std::cout << e.what() << '\n';
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	Parser::ClearVars();
	return 0;
}
