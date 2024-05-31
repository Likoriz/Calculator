#include <iostream>

#include "Calculator.h"
#include "Variable.h"
#include "Float.h"
#include "Operator.h"
#include "JsonReader.h"
#include "Exceptions.h"

#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

using namespace std;

int main()
{
	system("chcp 1251");

	int choice;

	try
	{
		while (true)
		{
			cout << "Считать из файла (1) или ввести вручную (2)? ";
			cin >> choice;
			if (cin.fail())
				throw Exceptions(FORMAT::INVALID_FORMAT);

			switch (choice)
			{
			case 1:
			{
				string path;

				cout << "Введите путь к файлу: ";
				cin >> path;
				if (cin.fail())
					throw Exceptions(FORMAT::INVALID_FORMAT);

				Calculator* calc = new Calculator(path);
				calc->Tokenize();

				Variable* a = (Variable*)calc->getTokens()[0];
				//Float* b = (Float*)calc->getTokens()[2];
				Variable* b = (Variable*)calc->getTokens()[2];

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

				break;
			}
			case 2:
			{
				dataType mode;
				string str;

				cout << "Введите режим работы (0 - float, 1 - fraction, 2 - matrix, 3 - bigint, 4 - complex): ";
				scanf_s("%d", &mode);
				if (!(mode == dataType::FLOAT || mode == dataType::BIGINT || mode == dataType::COMPLEX || mode == dataType::FRACTION || mode == dataType::MATRIX))
					throw Exceptions(FORMAT::INVALID_FORMAT);

				cout << "Введите пример:";
				cin >> str;
				if (cin.fail())
					throw Exceptions(FORMAT::INVALID_FORMAT);

				Calculator* calc = new Calculator(str, mode);

				calc->Tokenize();

				//Variable* a = (Variable*)calc->getTokens()[0];
				Float* a = (Float*)calc->getTokens()[0];
				//Float* b = (Float*)calc->getTokens()[2];
				Variable* b = (Variable*)calc->getTokens()[2];

				switch (dynamic_cast<Operator*>((Operator*)calc->getTokens()[1])->getType())
				{
				case operatorsType::PLUS:
				{
					a->print(myPlus(a, b));
					cout << endl;
					break;
				}
				case operatorsType::MINUS:
				{
					a->print(myMinus(a,b));
					cout << endl;
					break;
				}
				case operatorsType::DIV:
				{
					a->print(myDiv(a,b));
					cout << endl;
					break;
				}
				case operatorsType::MULT:
				{
					a->print(myMult(a,b));
					cout << endl;
					break;
				}
				case operatorsType::EXP:
				{
					a->print(a->toUpDegree(b));
					cout << endl;
				}
				}

				break;
			}
			default:
				cout << "Такой опции нет!" << endl;
			}

			cout << endl << endl << endl;
		}
	}
	catch (Exceptions& e)
	{
		cout << "Во время выполнения программы возникла ошибка: " << e.what() << endl;
	}
	catch (...)
	{

		cout << "wut?" << endl;
	}
	system("pause");
}