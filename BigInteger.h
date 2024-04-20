#pragma once
#include "Variable.h"

class Float;

class BigInteger : public Variable
{
public: 
	BigInteger(std::string name);
	Variable* operator+(Variable* arg);
	Variable* operator+(Float* arg);

	Variable* operator*(Variable* arg);
	Variable* operator*(Float* arg);

	Variable* operator-(Variable* arg);
	Variable* operator-(Float* arg);

	Variable* operator/(Variable* arg);
	Variable* operator/(Float* arg);

	Variable* toUpDegree(int degree);
	void print(Variable* arg = nullptr);
};

