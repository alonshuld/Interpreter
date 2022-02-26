#pragma once
#include "InterpreterException.h"
#include "IndentationException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "Integer.h"
#include "Boolean.h"
#include "String.h"
#include "Void.h"
#include "List.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>


class Parser
{
public:
    static Type* parseString(std::string str);
    static Type* getType(std::string str);
    static void ClearVars();
private:
    static bool isLegalVarName(std::string str);
    static bool makeAssignment(std::string str);
    static Type* getVariableValue(std::string str);
    static bool isList(const std::string& e);
};
