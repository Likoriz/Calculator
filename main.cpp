#include <iostream>

#include "Calculator.h"
#include "Variable.h"
#include "Float.h"
#include "Operator.h"
#include "JsonReader.h"

#include <nlohmann/json.hpp>
#include <fstream>
using json = nlohmann::json;

using namespace std;

int main()
{
	system("chcp 1251");

	int choice;

	cout << "Считать из файла (1) или ввести вручную (2)? ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		try
		{
			string path;

			cout << "Введите путь к файлу: ";
			cin >> path;

			Calculator* calc = new Calculator(path);
			calc->Tokenize();

			Variable* a = (Variable*)calc->getTokens()[0];
			Float* b = (Float*)calc->getTokens()[2];
			//Variable* b = (Variable*)calc->getTokens()[2];

			switch (dynamic_cast<Operator*>((Operator*)calc->getTokens()[1])->getType())
			{
			case operatorsType::PLUS:
			{
				a->print(a->operator+(b));
				cout << endl;
				break;
			}
			case operatorsType::MINUS:
			{
				a->print(a->operator-(b));
				cout << endl;
				break;
			}
			case operatorsType::DIV:
			{
				a->print(a->operator/(b));
				cout << endl;
				break;
			}
			case operatorsType::MULT:
			{
				a->print(a->operator*(b));
				cout << endl;
				break;
			}
			case operatorsType::EXP:
			{
				a->print(a->toUpDegree(b));
				cout << endl;
			}
			}
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}

		break;
	}
	case 2:
	{
		try
		{
			dataType mode;
			string str;

			cout << "Введите режим работы (0 - float, 1 - fraction, 2 - matrix, 3 - bigint, 4 - complex): ";
			scanf_s("%d", &mode);
			cout << "Введите пример:";
			cin >> str;
			Calculator* calc = new Calculator(str, mode);

			calc->Tokenize();

			Variable* a = (Variable*)calc->getTokens()[0];
			Float* b = (Float*)calc->getTokens()[2];
			//Variable* b = (Variable*)calc->getTokens()[2];

			switch (dynamic_cast<Operator*>((Operator*)calc->getTokens()[1])->getType())
			{
			case operatorsType::PLUS:
			{
				a->print(a->operator+(b));
				cout << endl;
				break;
			}
			case operatorsType::MINUS:
			{
				a->print(a->operator-(b));
				cout << endl;
				break;
			}
			case operatorsType::DIV:
			{
				a->print(a->operator/(b));
				cout << endl;
				break;
			}
			case operatorsType::MULT:
			{
				a->print(a->operator*(b));
				cout << endl;
				break;
			}
			case operatorsType::EXP:
			{
				a->print(a->toUpDegree(b));
				cout << endl;
			}
			}
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Wut?" << endl;
		}

		break;
	}
	default:
		cout << "Такой опции нет!" << endl;
	}
}