#pragma once
#include "Token.h"
#include <iostream>
class Variable:public Token
{
private:
	dataType typeOfData;
	std::string nameOfVariable;
public:
	Variable(std::string name);
	Variable();
	virtual Variable* operator+(Variable* arg)=0;
	virtual Variable* operator *(Variable* arg)=0;
	virtual Variable* operator -(Variable* arg)=0;
	virtual Variable* operator /(Variable* arg)=0;
	virtual Variable* toUpDegree(int degree) = 0;
	dataType getDataType();
	void setDataType(dataType type);
	virtual void print(Variable* arg = nullptr) = 0;
};
