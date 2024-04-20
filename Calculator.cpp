#include "Calculator.h"
#include "Bracket.h"
#include "Constant.h"
#include "Variable.h"
#include "Operator.h"
#include "BigInteger.h"
#include "Matrix.h"
#include "Float.h"
#include "Fraction.h"
#include "Complex.h"
#include <algorithm>

using namespace std;

Calculator::Calculator(string str, dataType mode)
{
	expression = str;
	workingMode = mode;
}

Calculator::~Calculator()
{

}

void Calculator::Tokenize()
{
	for (auto it = expression.begin(); it != expression.end(); it++)
	{
		switch (*it)
		{
		case '(':
			tokens.push_back(new Bracket(true)); break;
		case ')':
			tokens.push_back(new Bracket(false)); break;
		case '+':
			tokens.push_back(new Operator(operatorsType::PLUS)); break;
		case '-':
			tokens.push_back(new Operator(operatorsType::MINUS)); break;
		case '/':
			tokens.push_back(new Operator(operatorsType::DIV)); break;
		case '*':
			tokens.push_back(new Operator(operatorsType::MULT)); break;
		case '^':
			tokens.push_back(new Operator(operatorsType::EXP)); break;
		default:
			if (*it >= '0' && *it <= '9')
				{
					float value = 0;
					string stringVal;
					do {
						stringVal += *it;
					} while (++it != expression.end() && (*it >= '0' && *it <= '9' || *it == '.'));
					value = stof(stringVal);
					tokens.push_back(new Float(value));
				}
				else if (*it >= 'a' && *it <= 'z' || *it >= 'A' && *it <= 'Z')
				{
					string name;
					do {
						name += *it;
					} while (++it != expression.end() && (*it >= 'a' && *it <= 'z' || *it >= 'A' && *it <= 'Z'));
					switch (workingMode)
					{
					case dataType::BIGINT:
						tokens.push_back(new BigInteger(name)); break;
					case dataType::FLOAT:
						tokens.push_back(new Float(name)); break;
					case dataType::MATRIX:
						tokens.push_back(new Matrix(name)); break;
					case dataType::IMAGINARY:
						tokens.push_back(new Complex(name)); break;
					case dataType::FRACTION:
						tokens.push_back(new Fraction(name)); break;
					}
				}
			it--;
		}
	}
	//for (auto it = tokens.begin(); it != tokens.end(); it++)
	//{
	//	(*it)->printYourType();
	//}
	//cout<<endl;
}


void Calculator::turnToRPN()
{

}

void Calculator::calculateRPN()
{

}

std::vector <Token*> Calculator::getTokens()
{
	return tokens;
}
