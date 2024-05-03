#include "Float.h"
#include <iostream>

using namespace std;

Float::Float(std::string name) :Variable(name)
{
	cout << "введите Float:";
	setDataType(dataType::FLOAT);
	std::cin >> val;
}

Variable* myPlus(Variable* left, Variable* right)
{
	switch (left->getDataType())
	{
	case dataType::FLOAT: return *right + dynamic_cast<Float*>(left); 
	default: return *left + right; 
	}
}

Variable* myMinus(Variable* left, Variable* right)
{
	switch (left->getDataType())
	{
	case dataType::FLOAT: return right->operator* (new Float(-1))->operator-(left); 
	default: return *left - right; 
	}
}

void print(Variable* arg)
{

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
	case dataType::FLOAT: return right->toUpDegree(new Float(-1))->operator/(left); 
	default: return *left / right; 
	}
}

Float::Float(double value)
{
	setDataType(dataType::FLOAT);
	val = value;
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
		throw exception("Деление на нуль не определено");
	}
	val /= ((Float*)arg)->val;
	return this;
}

Variable* Float::operator/(Float* arg)
{
	if (arg->getVal() == 0)
	{
		throw exception("Деление на нуль не определено");
	}
	val /= arg->val;
	return this;
}

Variable* Float::toUpDegree(Variable* arg)
{
	val = pow(val, ((Float*)arg)->val);
	return this;
}

Variable* Float::toUpDegree(Float* arg)
{
	val = pow(val, arg->getVal());
	return this;
}

void Float::print(Variable* arg)
{
	cout << val;
}