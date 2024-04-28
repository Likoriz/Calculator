#pragma once
#include "Token.h"
#include <iostream>

class Float;

class Variable:public Token
{
private:
	dataType typeOfData;
	std::string nameOfVariable;
public:
	Variable(std::string name);
	Variable();
	Variable(std::string name, int i);
	virtual Variable* operator+(Variable* arg)=0;
	virtual Variable* operator+(Float* arg) = 0;

	virtual Variable* operator*(Variable* arg)=0;
	virtual Variable* operator*(Float* arg) = 0;

	virtual Variable* operator-(Variable* arg)=0;
	virtual Variable* operator-(Float* arg) = 0;

	virtual Variable* operator/(Variable* arg)=0;
	virtual Variable* operator/(Float* arg) = 0;

	virtual Variable* toUpDegree(Variable* arg) = 0;
	virtual Variable* toUpDegree(Float* arg) = 0;
	
	dataType getDataType();
	void setDataType(dataType type);
	virtual void print(Variable* arg = nullptr) = 0;
};
