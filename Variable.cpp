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
	std::cout<<"������� �������� ���������� "<<name<<" � ��������� ����: ";
}