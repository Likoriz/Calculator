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
#include "Exceptions.h"
#include <stack>
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
	map<string, Variable*> v;
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
						variables.insert({ name, (Variable*)(tokens[tokens.size() - 1]) });
					}
					else
					{
						tokens.push_back(variables[name]);
					}
				}
				else
				{
					if (v.find(name) != v.end())
					{
						tokens.push_back(v[name]);
						k++;
					}
					else
						throw Exceptions(JSON::VARIABLE_ABSENCE);
				}

			}
			it--;
		}
	}
}


int Calculator::getOperatorPrecedence(operatorsType type) {
    switch (type) {
    case operatorsType::PLUS:
    case operatorsType::MINUS:
        return 1;
    case operatorsType::MULT:
    case operatorsType::DIV:
        return 2;
    case operatorsType::EXP:
        return 3;
    default:
        return 0;
    }
}

void Calculator::turnToRPN() {
    std::vector<Token*> output;
    std::stack<Token*> operators;

    for (Token* token : tokens) {
        if (token->getTokenType() == tokenType::CONST || token->getTokenType() == tokenType::VARIABLE) {
            output.push_back(token);
        }
        else if (token->getTokenType() == tokenType::OPERATOR) {
            Operator* op = static_cast<Operator*>(token);
            while (!operators.empty() && operators.top()->getTokenType() == tokenType::OPERATOR) {
                Operator* topOp = static_cast<Operator*>(operators.top());
                if (getOperatorPrecedence(topOp->getType()) >= getOperatorPrecedence(op->getType())) {
                    output.push_back(topOp);
                    operators.pop();
                }
                else {
                    break;
                }
            }
            operators.push(op);
        }
        else if (token->getTokenType() == tokenType::BRACKET) {
            Bracket* bracket = static_cast<Bracket*>(token);
            if (bracket->isOpen()) {
                operators.push(bracket);
            }
            else {
                while (!operators.empty() && operators.top()->getTokenType() != tokenType::BRACKET) {
                    output.push_back(operators.top());
                    operators.pop();
                }
                if (!operators.empty() && operators.top()->getTokenType() == tokenType::BRACKET) {
                    operators.pop();
                }
            }
        }
    }

    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    tokens = output;
}

void Calculator::calculateRPN() {
    std::stack<Variable*> stack;

    for (Token* token : tokens) {
        if (token->getTokenType() == tokenType::CONST || token->getTokenType() == tokenType::VARIABLE) {
            stack.push(static_cast<Variable*>(token));
        }
        else if (token->getTokenType() == tokenType::OPERATOR) {
            Operator* op = static_cast<Operator*>(token);
            if (stack.size() < 2) {
                throw std::runtime_error("Insufficient operands for operation");
            }
            Variable* right = stack.top(); stack.pop();
            Variable* left = stack.top(); stack.pop();
            Variable* result = nullptr;

            switch (op->getType()) {
            case operatorsType::PLUS:
                result = myPlus(left, right);
                break;
            case operatorsType::MINUS:
                result = myMinus(left, right);
                break;
            case operatorsType::MULT:
                result = myMult(left, right);
                break;
            case operatorsType::DIV:
                result = myDiv(left, right);
                break;
            case operatorsType::EXP:
                result = left->toUpDegree(right);
                break;
            default:
                throw std::runtime_error("Unknown operator type");
            }

            stack.push(result);
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error in expression evaluation");
    }

    Variable* result = stack.top();
    std::cout << "Result: ";
    result->print();
    std::cout << std::endl;
}

std::vector <Token*> Calculator::getTokens()
{
	return tokens;
}
