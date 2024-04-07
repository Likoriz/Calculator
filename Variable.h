#pragma once
#include "Token.h"
#include <string>
class Variable:public Token
{
private:
	dataType typeOfData;
	std::string nameOfVariable;
public:
	Variable(std::string name);
	virtual void operator +(Variable* arg)=0;
	virtual void operator *(Variable* arg)=0;
	virtual void operator -(Variable* arg)=0;
	virtual void operator /(Variable* arg)=0;
	dataType getDataType();
	void setDataType(dataType type);
};
