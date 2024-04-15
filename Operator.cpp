#include "Operator.h"

//если будет желание, замените на классы, но я не уверен, что в этом есть смысл, Только если ради приоритета...
Operator::Operator(operatorsType type)
{
	setTokenType(tokenType::OPERATOR);
	typeOfOperator=type;
}
