#include "Calculator.h"
#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	system("chcp 1251");
	
	Variable* a = new Matrix("a");
	Variable* b = new Matrix("b");

	cout << dynamic_cast<Matrix*>(a->operator+(b)) << endl;
	cout << dynamic_cast<Matrix*>(a->operator-(b)) << endl;
	cout << dynamic_cast<Matrix*>(a->operator*(b)) << endl;
	cout << dynamic_cast<Matrix*>(a->toUpDegree(3)) << endl;
}