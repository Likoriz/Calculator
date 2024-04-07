#pragma once
#include "Variable.h"
class Matrix :
    public Variable
{
public:
	Matrix(std::string name);
	void operator +(Variable* arg);
	void operator *(Variable* arg);
	void operator -(Variable* arg);
	void operator /(Variable* arg);
};

