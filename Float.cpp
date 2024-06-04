#include "Float.h"
#include "Exceptions.h"
#include <iostream>
#include <string>

using namespace std;

Float::Float(std::string name) :Variable(name)
{
	cout << "¬ведите Float:";
	setDataType(dataType::FLOAT);
	std::cin >> val;
}

Variable* myPlus(Variable* left, Variable* right)
{
	switch (left->getDataType())
	{
	case dataType::FLOAT: return *right + dynamic_cast<Float*>(left); 
	default: return left->operator+(right); 
	}
}

Variable* myMinus(Variable* left, Variable* right)
{
	switch (left->getDataType())
	{
    	case dataType::FLOAT: return right->operator* (new Float(-1))->operator+(left); 
	    default: return *left - right; 
	}
}

Variable* myMult(Variable* left, Variable* right)
{
	switch (left->getDataType())
	{
	case dataType::FLOAT: return *right* left; 
	default: return left->operator*(right); 
	}
}

Variable* myDiv(Variable* left, Variable* right)
{
	switch (left->getDataType())
	{
	case dataType::FLOAT: return right->toUpDegree(new Float(-1))->operator*(left); 
	default: return *left / right; 
	}
}

Float::Float(double value)
{
	setDataType(dataType::FLOAT);
	setTokenType(tokenType::CONST);
	val = value;
	setName(to_string(value));
}

Float::Float(string name, double value) : Variable(name, 0)
{
	setDataType(dataType::FLOAT);
	val = value;
}

double Float::getVal()
{
	return val;
}

void Float::setVal(float value)
{
	val=value;
}

Variable* Float::operator+(Variable* arg)
{
	val += ((Float*)arg)->val;
	return this;
}

Variable* Float::operator+(Float* arg)
{
	val += arg->val;
	return this;
}

Variable* Float::operator*(Variable* arg)
{
	val *= ((Float*)arg)->val;
	return this;
}

Variable* Float::operator*(Float* arg)
{
	val *= arg->val;
	return this;
}

Variable* Float::operator-(Variable* arg)
{
	val -= ((Float*)arg)->val;
	return this;
}

Variable* Float::operator-(Float* arg)
{
	val -= arg->val;
	return this;
}

Variable* Float::operator/(Variable* arg)
{
	if (((Float*)arg)->getVal() == 0)
	{
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);
	}
	val /= ((Float*)arg)->val;
	return this;
}

Variable* Float::operator/(Float* arg)
{
	if (arg->getVal() == 0)
	{
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);
	}
	val /= arg->val;
	return this;
}

Variable* Float::toUpDegree(Variable* arg)
{
	Float* f = dynamic_cast<Float*>(arg);
	if (f)
	{
		val = pow(val, ((Float*)arg)->val);
		return this;
	}
	else
		throw Exceptions(FORMAT::INVALID_POW);
}

Variable* Float::toUpDegree(Float* arg)
{
	val = pow(val, arg->getVal());
	return this;
}

void Float::print(Variable* arg)
{
	if (arg)
		arg->print();
	else
		cout << val;
}