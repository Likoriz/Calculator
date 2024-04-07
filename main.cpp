#include "Calculator.h"
#include <iostream>

int main()
{
	Calculator* calc=new Calculator("a+bcd", 1);
	calc->Tokenize();
	system("pause");
}