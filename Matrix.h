#pragma once
#include "Variable.h"
#include <vector>

class Matrix : public Variable
{
private:
	int rows;
	int cols;
	std::vector<std::vector<float>> elements;
public:
	Matrix(std::string name);
	Matrix(std::string name, int rows_, int cols_);
	Variable* operator+(Variable* arg);
	Variable* operator *(Variable* arg);
	Variable* operator-(Variable* arg);
	void operator /(Variable* arg);
	Variable* toUpDegree(int degree);
	friend std::ostream& operator<<(std::ostream& os, const Variable* arg);
};

