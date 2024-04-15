#pragma once
#include "Variable.h"
class BigInteger :
    public Variable
{
public: 
	BigInteger(std::string name);
	Variable* operator +(Variable* arg);
	Variable* operator *(Variable* arg);
	Variable* operator -(Variable* arg);
	Variable* operator /(Variable* arg);
	Variable* toUpDegree(int degree);
	void print(Variable* arg = nullptr);
};

