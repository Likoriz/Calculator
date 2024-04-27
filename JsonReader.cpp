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
		throw exception("����������� ���� ��� ������������ ��� �����!");

	try
	{
		data = json::parse(f);

		if (data.find("type") != data.end())
		{
			if (data["type"].is_string())
			{
				type = data["type"];
				cout << type << endl;
			}
			else
				throw  exception("��� ������ �� �������� �������!");
		}
		else
			throw exception("����������� ��� ������!");

		if (data.find("expression") != data.end())
		{
			if (data["expression"].is_string())
			{
				expression = data["expression"];
				cout << expression << endl;
			}
			else
				throw exception("��������� �� �������� �������!");
		}
		else
			throw exception("����������� ���������!");

		if (data.find("variables") != data.end()) 
		{
			json v = data["variables"];
			for (json::iterator it = v.begin(); it != v.end(); ++it) 
			{
				if (type == "float")
				{
					variables.push_back(new Float(it.key(), it.value()));
				}
				else if (type == "fraction")
				{

				}
			}

			
		}
	}
	catch (const json::parse_error& e)
	{
		cout << e.what() << endl;
		throw exception("������ ��� ������ JSON - �����!");
	}


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
		throw exception("����������� ��� ������������!");
}

string JsonReader::getExpression()
{
	return expression;
}

vector<Variable*> JsonReader::getVariables()
{
	return variables;
}