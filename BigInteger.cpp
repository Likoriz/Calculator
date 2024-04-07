#include "BigInteger.h"
using namespace std;
BigInteger::BigInteger(string name):Variable(name)
{
	setDataType(dataType::BIGINT);
}

void BigInteger::operator+(Variable* arg)
{
}

void BigInteger::operator*(Variable* arg)
{
}

void BigInteger::operator-(Variable* arg)
{
}

void BigInteger::operator/(Variable* arg)
{
}
