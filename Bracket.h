#pragma once
#include "Token.h"
class Bracket :
    public Token
{
private:
	bool isLeftBracket;
public:
	Bracket(bool isLeft);
};

