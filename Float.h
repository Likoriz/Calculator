#pragma once
#include "Variable.h"
class Float :
    public Variable
{
public:
	Float(std::string name);
	void operator +(Variable* arg);
	void operator *(Variable* arg);
	void operator -(Variable* arg);
	void operator /(Variable* arg);
};

