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
	/*cout<<"введите размер матрицы, а затем каждый элемент:";*/
	//cout<<"введите Float:";
	//cout<<"введите BigInt:";
	//cout<<"введите сначала числитель, затем знаменатель:";
	//cout<<"введите а и б:";
}