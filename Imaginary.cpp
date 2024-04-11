#include "Imaginary.h"

Imaginary::Imaginary(std::string name):Variable(name)
{
	setDataType(dataType::IMAGINARY);
}

Variable* Imaginary::operator+(Variable* arg)
{
	return nullptr;
}

Variable* Imaginary::operator*(Variable* arg)
{
	return nullptr;
}

Variable* Imaginary::operator-(Variable* arg)
{
	return nullptr;
}

void Imaginary::operator/(Variable* arg)
{
}

Variable* Imaginary::toUpDegree(int degree)
{
	return nullptr;
}
