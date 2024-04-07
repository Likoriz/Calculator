#include "Imaginary.h"

Imaginary::Imaginary(std::string name):Variable(name)
{
	setDataType(dataType::IMAGINARY);
}

void Imaginary::operator+(Variable* arg)
{
}

void Imaginary::operator*(Variable* arg)
{
}

void Imaginary::operator-(Variable* arg)
{
}

void Imaginary::operator/(Variable* arg)
{
}
