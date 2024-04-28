#pragma once
#include "Variable.h"
#include <vector>
class Float;

class BigInteger : public Variable
{
private:
	int BASE=1000000000;
	std::vector<int> _digits;
	bool _is_negative;
public: 
	BigInteger(std::string name);
	Variable* operator+(Variable* arg);
	Variable* operator+(Float* arg);

	Variable* operator*(Variable* arg);
	Variable* operator*(Float* arg);

	Variable* operator-(Variable* arg);
	Variable* operator-(Float* arg);

	Variable* operator/(Variable* arg);
	Variable* operator/(Float* arg);

	Variable* toUpDegree(int degree);
	void print(Variable* arg = nullptr);

	void remove_leading_zeros();
};

