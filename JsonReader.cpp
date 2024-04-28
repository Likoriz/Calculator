#include "JsonReader.h"

#include "Variable.h"
#include "Calculator.h"
#include "Float.h"
#include "BigInteger.h"
#include "Fraction.h"
#include "Matrix.h"
#include "Complex.h"

using namespace std;
using json = nlohmann::json;

JsonReader::JsonReader(string path)
{
	ifstream f(path);

	if (f.fail())
		throw exception("Отсутствует файл или неправильное имя файла!");

	try
	{
		data = json::parse(f);

		if (data.find("type") != data.end())
		{
			if (data["type"].is_string())
				type = data["type"];
			else
				throw  exception("Тип данных не является строкой!");
		}
		else
			throw exception("Отсутствует тип данных!");

		if (data.find("expression") != data.end())
		{
			if (data["expression"].is_string())
				expression = data["expression"];
			else
				throw exception("Выражение не является строкой!");
		}
		else
			throw exception("Отсутствует выражение!");

		if (data.find("variables") != data.end())
		{
			json v = data["variables"];
			if (type == "matrix")
			{
				for (auto& variable : v.items())
				{
					string vname = variable.key();
					json vdata = variable.value();

					if (vdata.find("size") != vdata.end())
					{
						vector<int> s = vdata["size"];
						if (vdata.find("elements") != vdata.end())
						{
							vector<double> e = vdata["elements"];
							if (s[0] * s[1] != e.size())
								throw exception("Неверные размеры матрицы!");

							variables.push_back(new Matrix(vname, s[0], s[1], e));
						}
						else
							throw exception("Отсутствуют элементы матрицы!");
					}
					else
						throw exception("Отсутствуют размеры матрицы!");
				}
			}
			else
				for (json::iterator it = v.begin(); it != v.end(); ++it)
					if (type == "float")
					{
						variables.push_back(new Float(it.key(), it.value()));
					}
					else if (type == "fraction")
					{
						vector<int> f = it.value();
						variables.push_back(new Fraction(it.key(), f[0], f[1]));
					}
					else if (type == "bigint")
					{
						if (it.value().is_string())
							variables.push_back(new BigInteger(it.key(), it.value()));
						else
							throw exception("Значение не является строкой!");
					}
					else if (type == "complex")
					{
						vector<double> c = it.value();
						variables.push_back(new Complex(it.key(), c[0], c[1]));
					}
					else
						throw exception("Неизвестный тип данных!");
		}
	}
	catch (const json::parse_error& e)
	{
		cout << e.what() << endl;
		throw exception("Ошибка при чтении JSON - файла!");
	}
}

JsonReader::~JsonReader()
{

}

dataType JsonReader::getType()
{
	if (type == "float")
		return dataType::FLOAT;
	else if (type == "fraction")
		return dataType::FRACTION;
	else if (type == "matrix")
		return dataType::MATRIX;
	else if (type == "bigint")
		return dataType::BIGINT;
	else if (type == "complex")
		return dataType::COMPLEX;
	else
		throw exception("Отсутствует тип калькулятора!");
}

string JsonReader::getExpression()
{
	return expression;
}

vector<Variable*> JsonReader::getVariables()
{
	return variables;
}