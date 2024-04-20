#pragma once
#include "Variable.h"
#include <vector>

class Float;

class Matrix : public Variable
{
private:
	int rows;
	int cols;
	std::vector<std::vector<float>> elements;
public:
	Matrix(std::string name);
	Matrix(int rows_, int cols_);
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
};

