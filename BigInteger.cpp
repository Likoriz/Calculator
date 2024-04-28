#include "BigInteger.h"
#include "Float.h"

using namespace std;

BigInteger::BigInteger(string name):Variable(name)
{
	setDataType(dataType::BIGINT);
	cout<<"введите BigInt:";
}

BigInteger::BigInteger(string name, string bi) : Variable(name, 0)
{
	setDataType(dataType::BIGINT);
	val = bi;
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

Variable* BigInteger::toUpDegree(Variable* arg)
{
	return this;
}

Variable* BigInteger::toUpDegree(Float* arg)
{
	return this;
}

void BigInteger::print(Variable* arg)
{

}