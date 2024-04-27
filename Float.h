#pragma once
#include "Variable.h"

class Float : public Variable
{
private:
	double val;
public:
	Float(std::string name);
	Float(double value);
	Float(std::string name, double value);

	double getVal();
	Variable* operator+(Variable* arg);
	Variable* operator+(Float* arg);

	Variable* operator *(Variable* arg);
	Variable* operator *(Float* arg);

	Variable* operator -(Variable* arg);
	Variable* operator-(Float* arg);

	Variable* operator /(Variable* arg);
	Variable* operator/(Float* arg);

	Variable* toUpDegree(Variable* arg);
	Variable* toUpDegree(Float* arg);

	void print(Variable* arg = nullptr);
};

