#include "Operator.h"

//���� ����� �������, �������� �� ������, �� � �� ������, ��� � ���� ���� �����, ������ ���� ���� ����������...
Operator::Operator(operatorsType type)
{
	setTokenType(tokenType::OPERATOR);
	typeOfOperator=type;
}

operatorsType Operator::getType()
{
	return typeOfOperator;
}