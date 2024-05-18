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
public: 
	BigInteger(std::string name);
	BigInteger(Float* arg);
	BigInteger(std::string name, std::string bi);
	BigInteger* operator -();
	BigInteger* operator +();
	Variable* operator+(Float* arg);
	Variable* operator+(Variable* arg);

	Variable* operator*(Variable* arg);
	Variable* operator*(Float* arg);

	Variable* operator-(Variable* arg);
	Variable* operator-(Float* arg);

	Variable* operator/(Variable* arg);
	Variable* operator/(Float* arg);

	Variable* toUpDegree(Variable* arg);
	Variable* toUpDegree(Float* arg);

	void print(Variable* arg = nullptr);
	bool getNegative();
	std::vector<int> getDigits();
	void remove_leading_zeros();
	void turnStrToBi(std::string name, std::string bi);
};

bool operator >(BigInteger& left, BigInteger& right);
bool operator >=(BigInteger& left, BigInteger& right);
bool operator <=(BigInteger& left, BigInteger& right);
bool operator !=(BigInteger& left, BigInteger& right);
bool operator <(BigInteger& left, BigInteger& right);