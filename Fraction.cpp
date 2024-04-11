#include "Fraction.h"

Fraction::Fraction(std::string name):Variable(name)
{
	setDataType(dataType::FRACTION);
}

Variable* Fraction::operator+(Variable* arg)
{
	return nullptr;
}

Variable* Fraction::operator*(Variable* arg)
{
	return nullptr;
}

Variable* Fraction::operator-(Variable* arg)
{
	return nullptr;
}

void Fraction::operator/(Variable* arg)
{
}

Variable* Fraction::toUpDegree(int degree)
{
	return nullptr;
}