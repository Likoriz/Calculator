#pragma once
#include "Token.h"

class Operator :
	public Token
{
private:
	operatorsType typeOfOperator;
	int priority;
public:
	Operator(operatorsType type);
	operatorsType getType();
};

