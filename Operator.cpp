#include "Operator.h"

//���� ����� �������, �������� �� ������, �� � �� ������, ��� � ���� ���� �����, ������ ���� ���� ����������...
Operator::Operator(operatorsType type)
{
	setTokenType(tokenType::OPERATOR);
	typeOfOperator=type;
}
