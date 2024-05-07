#include "Variable.h"
using namespace std;
dataType Variable::getDataType()
{
	return typeOfData;
}

void Variable::setDataType(dataType type)
{
	typeOfData=type;
}

Variable::Variable()
{

}

Variable::Variable(std::string name)
{
	setTokenType(tokenType::VARIABLE);
	nameOfVariable=name;
	std::cout<<"¬ведите значение переменной "<<name<<" в следующем виде: ";
}

Variable::Variable(string name, int i)
{
	setTokenType(tokenType::VARIABLE);
	nameOfVariable = name;
}

string Variable::getName()
{
	return nameOfVariable;
}