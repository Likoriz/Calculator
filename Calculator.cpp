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
	reader = nullptr;
	expression = str;
	workingMode = mode;
}

Calculator::Calculator(string path)
{
	reader = new JsonReader(path);
	expression = reader->getExpression();
	workingMode = reader->getType();
}

Calculator::~Calculator()
{

}

void Calculator::Tokenize()
{
	int k = 0;
	vector<Variable*> v;
	if (reader)
		v = reader->getVariables();

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

				if (reader == nullptr)
				{
					if (variables.find(name) == variables.end())
					{
						switch (workingMode)
						{
						case dataType::BIGINT:
							tokens.push_back(new BigInteger(name)); break;
						case dataType::FLOAT:
							tokens.push_back(new Float(name)); break;
						case dataType::MATRIX:
							tokens.push_back(new Matrix(name)); break;
						case dataType::COMPLEX:
							tokens.push_back(new Complex(name)); break;
						case dataType::FRACTION:
							tokens.push_back(new Fraction(name)); break;
						}
						variables.insert({name, (Variable*)(tokens[tokens.size() - 1])});
					}
					else
					{
						tokens.push_back(variables[name]);
					}
				}
				else
				{
					tokens.push_back(v[k]);
					k++;
				}
				
			}
			it--;
		}
	}
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
