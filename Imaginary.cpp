#include "Imaginary.h"

Imaginary::Imaginary(std::string name):Variable(name)
{
	setDataType(dataType::IMAGINARY);
	std::cout<<"введите а и б:";
}

Variable* Imaginary::operator+(Variable* arg)
{
	return this;
}

Variable* Imaginary::operator*(Variable* arg)
{
	return this;
}

Variable* Imaginary::operator-(Variable* arg)
{
	return this;
}

Variable* Imaginary::operator/(Variable* arg)
{
	return this;
}

Variable* Imaginary::toUpDegree(int degree)
{
	return this;
}

void Imaginary::print(Variable* arg)
{

}