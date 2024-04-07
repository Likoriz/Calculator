#pragma once
#include "Variable.h"
class Imaginary :
    public Variable
{
public: 
	Imaginary(std::string name);
	void operator +(Variable* arg);
	void operator *(Variable* arg);
	void operator -(Variable* arg);
	void operator /(Variable* arg);
};

