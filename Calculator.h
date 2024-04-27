#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Token.h"
#include "JsonReader.h"

class Calculator
{
private:
	dataType workingMode;
	std::vector <Token*> tokens;
	std::string expression;
	JsonReader* reader;
public:
	Calculator(std::string str, dataType mode);
	Calculator(std::string path);
	~Calculator();
	void Tokenize();
	void turnToRPN();
	void calculateRPN();
	std::vector<Token*> getTokens();
};

