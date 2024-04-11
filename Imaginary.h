#pragma once
#include "Variable.h"
class Imaginary :
    public Variable
{
public: 
	Imaginary(std::string name);
	Variable* operator +(Variable* arg);
	Variable* operator *(Variable* arg);
	Variable* operator -(Variable* arg);
	void operator /(Variable* arg);
	Variable* toUpDegree(int degree);
};

