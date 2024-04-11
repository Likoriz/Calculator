#include "Variable.h"

dataType Variable::getDataType()
{
	return typeOfData;
}

void Variable::setDataType(dataType type)
{
	typeOfData=type;
}

Variable::Variable(std::string name)
{
	setTokenType(tokenType::VARIABLE);
	nameOfVariable=name;
	printf("Введите значение переменной %s", name);
}