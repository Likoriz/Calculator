#include "Float.h"
#include <iostream>
using namespace std;
Float::Float(std::string name):Variable(name)
{
	cout<<"введите Float:";
	setDataType(dataType::FLOAT);
	std::cin>>val;
}

Variable* Float::operator+(Variable* arg)
{
	val+=((Float*)arg)->val;
	return this;
}

Variable* Float::operator*(Variable* arg)
{
	val*=((Float*)arg)->val;
	return this;
}

Variable* Float::operator-(Variable* arg)
{
	val-=((Float*)arg)->val;
	return this;
}

Variable* Float::operator/(Variable* arg)
{
	val/=((Float*)arg)->val;
	return this;
}

std::ostream& operator << (std::ostream& os, const Float& variable)
{
	return os<<variable.val<<std::endl;
}

Variable* Float::toUpDegree(int degree)
{
	val=pow(val, degree);
	return this;
}
