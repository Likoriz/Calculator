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
            cout << "������� �� ����� (1) ��� ������ ������� (2)? ";
            cin >> choice;
            if (cin.fail())
                throw Exceptions(FORMAT::INVALID_FORMAT);

            switch (choice) {
            case 1:
            {
                string path;

                cout << "������� ���� � �����: ";
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

                cout << "������� ����� ������ (0 - float, 1 - fraction, 2 - matrix, 3 - bigint, 4 - complex): ";
                scanf_s("%d", &mode);
                if (!(mode == dataType::FLOAT || mode == dataType::BIGINT || mode == dataType::COMPLEX || mode == dataType::FRACTION || mode == dataType::MATRIX))
                    throw Exceptions(FORMAT::INVALID_FORMAT);

                cout << "������� ������:";
				getchar();
				getline(cin, str);
                if (cin.fail())
                    throw Exceptions(FORMAT::INVALID_FORMAT);

                Calculator* calc = new Calculator(str, mode);

                calc->Tokenize();

                cout << "Tokens after tokenization: ";
                calc->printTokens(calc->getTokens());

                // ����������� � ���
                calc->turnToRPN();

                cout << "���: ";
                calc->printTokens(calc->getTokens());

                // ��������� ���������
                calc->calculateRPN();

                break;
            }
            default:
                cout << "����� ����� ���!" << endl;
            }

            cout << endl << endl << endl;
        }
    }
    catch (Exceptions& e) {
        cout << "�� ����� ���������� ��������� �������� ������: " << e.what() << endl;
    }
    catch (...) {
        cout << "wut?" << endl;
    }
    system("pause");
}
