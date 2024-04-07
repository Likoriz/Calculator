#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Token.h"

class Calculator
{
private:
	int workingMode;
	std::vector <Token*> tokens;
	std::string expression;
public:
	Calculator(std::string str, int mode);
	~Calculator();
	void Tokenize();
	void turnToRPN();
	void calculateRPN();
};

