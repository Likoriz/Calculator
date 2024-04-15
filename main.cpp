#include "Calculator.h"
#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	system("chcp 1251");
	dataType mode;
	cout<<"¬ведите режим работы:";
	scanf_s("%d", &mode);
	cout<<"¬ведите пример:";string str;cin>>str;Calculator* calc=new Calculator(str,mode);
	calc->Tokenize();
	
	Variable* a=(Variable*)calc->getTokens()[0];
	Variable* b=(Variable*)calc->getTokens()[2];

	cout << dynamic_cast<Matrix*>(a->operator+(b)) << endl;
	cout << dynamic_cast<Matrix*>(a->operator-(b)) << endl;
	cout << dynamic_cast<Matrix*>(a->operator*(b)) << endl;
	cout << dynamic_cast<Matrix*>(a->toUpDegree(3)) << endl;
	system("pause");
}