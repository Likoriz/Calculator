#pragma once
#include "Variable.h"
class Float :
    public Variable
{
	friend std::ostream& operator << (std::ostream& os, const Float& variable);
private:
	double val;
public:
	Float(std::string name);
	void operator +(Variable* arg);
	void operator *(Variable* arg);
	void operator -(Variable* arg);
	void operator /(Variable* arg);
};

