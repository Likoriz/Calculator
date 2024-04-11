#include "Float.h"
#include <iostream>
Float::Float(std::string name):Variable(name)
{
	setDataType(dataType::FLOAT);
}

Variable* Float::operator+(Variable* arg)
{
	val+=((Float*)arg)->val;
}

Variable* Float::operator*(Variable* arg)
{
	val*=((Float*)arg)->val;
}

Variable* Float::operator-(Variable* arg)
{
	val-=((Float*)arg)->val;
}

void Float::operator/(Variable* arg)
{
	val/=((Float*)arg)->val;
}

std::ostream& operator << (std::ostream& os, const Float& variable)
{
	return os<<variable.val<<std::endl;
}
}

Variable* Float::toUpDegree(int degree)
{
	return nullptr;
}
