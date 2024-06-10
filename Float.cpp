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
	Float* res=new Float(val);
	res->val += ((Float*)arg)->val;
	return res;
}

Variable* Float::operator+(Float* arg)
{
	Float* res=new Float(val);
	res->val += arg->val;
	return res;
}

Variable* Float::operator*(Variable* arg)
{
	Float* res= new Float(val);
	res->val *= ((Float*)arg)->val;
	return res;
}

Variable* Float::operator*(Float* arg)
{
	Float* res=new Float(val);
	res->val *= arg->val;
	return res;
}

Variable* Float::operator-(Variable* arg)
{
	Float* res=new Float(val);
	res->val -= ((Float*)arg)->val;
	return res;
}

Variable* Float::operator-(Float* arg)
{
	Float* res=new Float(val);
	res->val -= arg->val;
	return res;
}

Variable* Float::operator/(Variable* arg)
{
	if (((Float*)arg)->getVal() == 0)
	{
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);
	}
	Float* res=new Float(val);
	res->val /= ((Float*)arg)->val;
	return res;
}

Variable* Float::operator/(Float* arg)
{
	if (arg->getVal() == 0)
	{
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);
	}
	Float* res=new Float(val);
	res->val /= arg->val;
	return res;
}

Variable* Float::toUpDegree(Variable* arg)
{
	Float* f = dynamic_cast<Float*>(arg);
	if (f)
	{
		Float* res=new Float(val);
		res->val = pow(val, ((Float*)arg)->val);
		return res;
	}
	else
		throw Exceptions(FORMAT::INVALID_POW);
}

Variable* Float::toUpDegree(Float* arg)
{
	Float* res=new Float(val);
	res->val = pow(val, arg->getVal());
	return res;
}

void Float::print(Variable* arg)
{
	if (arg)
		arg->print();
	else
		cout << val;
}