#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Token.h"

#include <nlohmann/json.hpp>
#include <fstream>

class Variable;

class JsonReader
{
private:
	nlohmann::json data;
	std::string type;
	std::string expression;
	std::vector<Variable*> variables;
public:
	JsonReader(std::string path);
	~JsonReader();
	dataType getType();
	std::string getExpression();
	std::vector<Variable*> getVariables();
};