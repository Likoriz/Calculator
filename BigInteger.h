#pragma once
#include "Variable.h"
#include <vector>
class Float;

class BigInteger : public Variable
{
private:
	int BASE=1000000000;
	std::vector<int> digits;
	bool is_negative;
public: 
	BigInteger(std::string name);
	BigInteger(std::string name, std::string bi);
	Variable* operator+(Variable* arg);
	Variable* operator+(Float* arg);

	Variable* operator*(Variable* arg);
	Variable* operator*(Float* arg);

	Variable* operator-(Variable* arg);
	Variable* operator-(Float* arg);

	Variable* operator/(Variable* arg);
	Variable* operator/(Float* arg);

	Variable* toUpDegree(Variable* arg);
	Variable* toUpDegree(Float* arg);

	void print(Variable* arg = nullptr);

	void remove_leading_zeros();
};

