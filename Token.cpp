#include "Token.h"
#include <iostream>
tokenType Token::getTokenType()
{
	return typeOfToken;
}

void Token::setTokenType(tokenType type)
{
	typeOfToken=type;
}

void Token::printYourType()
{
	std::cout<<(int)typeOfToken<<std::endl;
}