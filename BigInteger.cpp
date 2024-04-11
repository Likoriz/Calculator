#include "BigInteger.h"
using namespace std;
BigInteger::BigInteger(string name):Variable(name)
{
	setDataType(dataType::BIGINT);
}

Variable* BigInteger::operator+(Variable* arg)
{
	return nullptr;
}

Variable* BigInteger::operator*(Variable* arg)
{
	return nullptr;
}

Variable* BigInteger::operator-(Variable* arg)
{
	return nullptr;
}

void BigInteger::operator/(Variable* arg)
{
}

Variable* BigInteger::toUpDegree(int degree)
{
	return nullptr;
}