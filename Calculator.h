#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Token.h"

class Calculator
{
private:
	dataType workingMode;
	std::vector <Token*> tokens;
	std::string expression;
public:
	Calculator(std::string str, dataType mode);
	~Calculator();
	void Tokenize();
	void turnToRPN();
	void calculateRPN();
	std::vector <Token*> getTokens();
};

