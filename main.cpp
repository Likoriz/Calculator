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

int main() {
    system("chcp 1251");

    int choice;

    try {
        while (true) {
            cout << "Считать из файла (1) или ввести вручную (2)? ";
            cin >> choice;
            if (cin.fail())
                throw Exceptions(FORMAT::INVALID_FORMAT);

            switch (choice) {
            case 1:
            {
                string path;

                cout << "Введите путь к файлу: ";
                cin >> path;
                if (cin.fail())
                    throw Exceptions(FORMAT::INVALID_FORMAT);

                Calculator* calc = new Calculator(path);
                calc->Tokenize();

                cout << "Tokens after tokenization: ";
                calc->printTokens(calc->getTokens());

                calc->turnToRPN();

                cout << "Tokens in RPN: ";
                calc->printTokens(calc->getTokens());

                calc->calculateRPN();

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
				getchar();
				getline(cin, str);
                if (cin.fail())
                    throw Exceptions(FORMAT::INVALID_FORMAT);

                Calculator* calc = new Calculator(str, mode);

                calc->Tokenize();

                cout << "Tokens after tokenization: ";
                calc->printTokens(calc->getTokens());

                // Преобразуем в ОПЗ
                calc->turnToRPN();

                cout << "ОПН: ";
                calc->printTokens(calc->getTokens());

                // Вычисляем результат
                calc->calculateRPN();

                break;
            }
            default:
                cout << "Такой опции нет!" << endl;
            }

            cout << endl << endl << endl;
        }
    }
    catch (Exceptions& e) {
        cout << "Во время выполнения программы возникла ошибка: " << e.what() << endl;
    }
    catch (...) {
        cout << "wut?" << endl;
    }
    system("pause");
}
