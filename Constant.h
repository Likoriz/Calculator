#pragma once
#include "Token.h"
class Constant : public Token
{
private:
	float value;
public:
	Constant(float v);
	float getVal();
};

