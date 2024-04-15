#include "Constant.h"

Constant::Constant(float v)
{
	setTokenType(tokenType::CONST);
	value=v;
}

float Constant::getVal()
{
	return value;
}