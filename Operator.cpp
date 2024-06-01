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

char Operator::getSymbol() {
    switch (typeOfOperator) {
    case operatorsType::PLUS:
        return '+';
    case operatorsType::MINUS:
        return '-';
    case operatorsType::MULT:
        return '*';
    case operatorsType::DIV:
        return '/';
    case operatorsType::EXP:
        return '^';
    default:
        return '?';  // ����������� ��������
    }
}