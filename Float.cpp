#include "Float.h"
#include <iostream>

using namespace std;

Float::Float(std::string name):Variable(name)
{
	cout<<"введите Float:";
	setDataType(dataType::FLOAT);
	std::cin>>val;
}

Float::Float(double value)
{
	val = value;
}

Float::Float(string name, double value) :Variable(name, 0)
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
	val+=((Float*)arg)->val;
	return this;
}

Variable* Float::operator+(Float* arg)
{
	return this;
}

Variable* Float::operator*(Variable* arg)
{
	val*=((Float*)arg)->val;
	return this;
}

Variable* Float::operator*(Float* arg)
{
	return this;
}

Variable* Float::operator-(Variable* arg)
{
	val-=((Float*)arg)->val;
	return this;
}

Variable* Float::operator-(Float* arg)
{
	return this;
}

Variable* Float::operator/(Variable* arg)
{
	val/=((Float*)arg)->val;
	return this;
}

Variable* Float::operator/(Float* arg)
{
	return this;
}

Variable* Float::toUpDegree(Variable* arg)
{
	return this;
}

Variable* Float::toUpDegree(Float* arg)
{
	val=pow(val, arg->getVal());
	return this;
}

void Float::print(Variable* arg)
{
	cout << val;
}