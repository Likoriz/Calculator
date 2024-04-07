#pragma once
#include "Variable.h"
class BigInteger :
    public Variable
{
public: 
	BigInteger(std::string name);
	void operator +(Variable* arg);
	void operator *(Variable* arg);
	void operator -(Variable* arg);
	void operator /(Variable* arg);
};

