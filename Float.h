#pragma once
#include "Variable.h"
class Float :
    public Variable
{
public:
	Float(std::string name);
	Variable* operator +(Variable* arg);
	Variable* operator *(Variable* arg);
	Variable* operator -(Variable* arg);
	void operator /(Variable* arg);
	Variable* toUpDegree(int degree);
};

