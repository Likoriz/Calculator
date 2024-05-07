#include "JsonReader.h"

#include "Variable.h"
#include "Calculator.h"
#include "Float.h"
#include "BigInteger.h"
#include "Fraction.h"
#include "Matrix.h"
#include "Complex.h"

#include "Exceptions.h"

using namespace std;
using json = nlohmann::json;

JsonReader::JsonReader(string path)
{
	ifstream f(path);

	if (f.fail())
		throw Exceptions(JSON::INVALID_FILENAME);

	try
	{
		data = json::parse(f);

		if (data.find("type") != data.end())
		{
			if (data["type"].is_string())
				type = data["type"];
			else
				throw Exceptions(JSON::NOT_STRING_VALUE);
		}
		else
			throw Exceptions(JSON::ABSENT_VALUE);

		if (data.find("expression") != data.end())
		{
			if (data["expression"].is_string())
				expression = data["expression"];
			else
				throw Exceptions(JSON::NOT_STRING_VALUE);
		}
		else
			throw Exceptions(JSON::ABSENT_VALUE);

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
								throw Exceptions(JSON::INVALID_VALUE);

							variables.push_back(new Matrix(vname, s[0], s[1], e));
						}
						else
							throw Exceptions(JSON::ABSENT_VALUE);
					}
					else
						throw Exceptions(JSON::ABSENT_VALUE);
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
						if (f.size() != 2)
							throw Exceptions(JSON::INVALID_VALUE);
						else
							variables.push_back(new Fraction(it.key(), f[0], f[1]));
					}
					else if (type == "bigint")
					{
						if (it.value().is_string())
							variables.push_back(new BigInteger(it.key(), it.value()));
						else
							throw Exceptions(JSON::NOT_STRING_VALUE);
					}
					else if (type == "complex")
					{
						vector<double> c = it.value();
						if (c.size() != 2)
							throw Exceptions(JSON::INVALID_VALUE);
						variables.push_back(new Complex(it.key(), c[0], c[1]));
					}
					else
						throw Exceptions(JSON::UNKNOWN_TYPE);
		}
	}
	catch (const json::parse_error& e)
	{
		cout << e.what() << endl;
		throw Exceptions(JSON::PARSE_ERROR);
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
		throw Exceptions(JSON::ABSENT_VALUE);
}

string JsonReader::getExpression()
{
	return expression;
}

vector<Variable*> JsonReader::getVariables()
{
	return variables;
}