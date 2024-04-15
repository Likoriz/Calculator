#include "Fraction.h"

Fraction::Fraction(std::string name):Variable(name)
{
	setDataType(dataType::FRACTION);
	std::cout<<"введите сначала числитель, затем знаменатель:";
}

Variable* Fraction::operator+(Variable* arg)
{
	return this;
}

Variable* Fraction::operator*(Variable* arg)
{
	return this;
}

Variable* Fraction::operator-(Variable* arg)
{
	return this;
}

Variable* Fraction::operator/(Variable* arg)
{
	return this;
}

Variable* Fraction::toUpDegree(int degree)
{
	return this;
}