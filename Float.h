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
	void setVal(float value);
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
Variable* myDiv(Variable* left, Variable* right);
Variable* myPlus(Variable* left, Variable* right);
Variable* myMult(Variable* left, Variable* right);
Variable* myMinus(Variable* left, Variable* right);

