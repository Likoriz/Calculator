#pragma once
#include "Variable.h"
#include <vector>
class Float;

class BigInteger : public Variable
{
private:
	int BASE=1000000000;
	std::vector<int> digits;
	bool isNegative=0;
	bool isInverted=0;
public:
	BigInteger(std::string name);
	BigInteger(Float* arg);
	BigInteger(int val);
	BigInteger();
	BigInteger(std::string name, std::string bi);
	BigInteger* operator -();
	BigInteger* operator +();
	BigInteger* operator /=(BigInteger* value);
	BigInteger* operator *=(BigInteger* value);

	Variable* operator+(Float* arg);
	Variable* operator+(Variable* arg);

	Variable* operator*(Variable* arg);
	Variable* operator*(Float* arg);
	Variable* operator*(int arg);

	Variable* operator-(Variable* arg);
	Variable* operator-(Float* arg);

	Variable* operator/(Variable* arg);
	Variable* operator/(Float* arg);

	Variable* toUpDegree(Variable* arg);
	Variable* toUpDegree(Float* arg);

	void print(Variable* arg=nullptr);
	bool getNegative();
	std::vector<int> getDigits();
	void removeLeadingZeros();
	void turnStrToBi(std::string name, std::string bi);
	void shiftRight();
	bool odd();
	bool even();
};

bool operator >(BigInteger& left, BigInteger& right);
bool operator >=(BigInteger& left, BigInteger& right);
bool operator <=(BigInteger& left, BigInteger& right);
bool operator !=(BigInteger& left, BigInteger& right);
bool operator <(BigInteger& left, BigInteger& right);