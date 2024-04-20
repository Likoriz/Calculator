#pragma once
#include "Variable.h"

class Float : public Variable
{
	friend std::ostream& operator << (std::ostream& os, const Float& variable);
private:
	double val;
public:
	Float(std::string name);
	Float(double value);
	double getVal();
	Variable* operator+(Variable* arg);
	Variable* operator+(Float* arg);

	Variable* operator *(Variable* arg);
	Variable* operator *(Float* arg);

	Variable* operator -(Variable* arg);
	Variable* operator-(Float* arg);

	Variable* operator /(Variable* arg);
	Variable* operator/(Float* arg);

	Variable* toUpDegree(int degree);
	void print(Variable* arg = nullptr);
};

