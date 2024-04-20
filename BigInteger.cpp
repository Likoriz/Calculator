#include "BigInteger.h"
#include "Float.h"

using namespace std;

BigInteger::BigInteger(string name):Variable(name)
{
	setDataType(dataType::BIGINT);
	cout<<"введите BigInt:";
}

Variable* BigInteger::operator+(Variable* arg)
{
	return this;
}

Variable* BigInteger::operator+(Float* arg)
{
	return this;
}

Variable* BigInteger::operator*(Variable* arg)
{
	return this;
}

Variable* BigInteger::operator*(Float* arg)
{
	return this;
}

Variable* BigInteger::operator-(Variable* arg)
{
	return this;
}

Variable* BigInteger::operator-(Float* arg)
{
	return this;
}

Variable* BigInteger::operator/(Variable* arg)
{
	return this;
}

Variable* BigInteger::operator/(Float* arg)
{
	return this;
}

Variable* BigInteger::toUpDegree(int degree)
{
	return this;
}

void BigInteger::print(Variable* arg)
{

}