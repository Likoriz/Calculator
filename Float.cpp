#include "Float.h"

Float::Float(std::string name):Variable(name)
{
	setDataType(dataType::FLOAT);
}

Variable* Float::operator+(Variable* arg)
{
	return nullptr;
}

Variable* Float::operator*(Variable* arg)
{
	return nullptr;
}

Variable* Float::operator-(Variable* arg)
{
	return nullptr;
}

void Float::operator/(Variable* arg)
{
}

Variable* Float::toUpDegree(int degree)
{
	return nullptr;
}
