#include "Fraction.h"
#include "Float.h"

#include "Exceptions.h"

using namespace std;

Fraction::Fraction(std::string name) : Variable(name)
{
	setDataType(dataType::FRACTION);
	cout << "¬ведите сначала числитель, затем знаменатель:" << endl;

	cin >> numerator >> denominator;
	if (cin.fail())
		throw Exceptions(FORMAT::INVALID_FORMAT);

	if (denominator == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
}

Fraction::Fraction()
{
	numerator = 0;
	denominator = 0;
}

Fraction::Fraction(string name, int n, int d) : Variable(name, 0)
{
	setDataType(dataType::FRACTION);
	numerator = n;
	denominator = d;

	if (denominator == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
}

Variable* Fraction::operator+(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Fraction* result = new Fraction();

	if (denominator == f->denominator)
	{
		result->numerator = numerator + f->numerator;
		result->denominator = denominator;
	}
	else
	{
		result->numerator = numerator * f->denominator + f->numerator * denominator;
		result->denominator = denominator * f->denominator;
	}

	if (result->denominator < 0)
	{
		result->numerator *= -1;
		result->denominator *= -1;
	}

	return result;
}

Variable* Fraction::operator+(Float* arg)
{
	//const Fraction* f = turnToFraction(arg->getVal());
	//Fraction* tmp = new Fraction();

	//if (denominator == f->denominator)
	//{
	//	tmp->numerator = numerator + f->numerator;
	//	tmp->denominator = denominator;
	//}
	//else
	//{
	//	tmp->numerator = numerator * f->denominator + f->numerator * denominator;
	//	tmp->denominator = denominator * f->denominator;
	//}

	//if (tmp->denominator < 0)
	//{
	//	tmp->numerator *= -1;
	//	tmp->denominator *= -1;
	//}

	if (denominator == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	Variable* result = new Float((double)numerator / (double)denominator + arg->getVal());

	return result;
}

Variable* Fraction::operator*(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Fraction* result = new Fraction();

	result->numerator = numerator * f->numerator;
	result->denominator = denominator * f->denominator;

	if (result->denominator < 0)
	{
		result->numerator *= -1;
		result->denominator *= -1;
	}

	return result;
}

Variable* Fraction::operator*(Float* arg)
{
	//const Fraction* f = turnToFraction(arg->getVal());
	//Fraction* result = new Fraction();

	//result->numerator = numerator * f->numerator;
	//result->denominator = denominator * f->denominator;

	//if (result->denominator < 0)
	//{
	//	result->numerator *= -1;
	//	result->denominator *= -1;
	//}

	//return result;

	if (denominator == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	Variable* result = new Float(((double)numerator / (double)denominator) * arg->getVal());

	return result;
}

Variable* Fraction::operator-(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Fraction* result = new Fraction();

	if (denominator == f->denominator)
	{
		result->numerator = numerator - f->numerator;
		result->denominator = denominator;
	}
	else
	{
		result->numerator = numerator * f->denominator - f->numerator * denominator;
		result->denominator = denominator * f->denominator;
	}

	if (result->denominator < 0)
	{
		result->numerator *= -1;
		result->denominator *= -1;
	}

	return result;
}

Variable* Fraction::operator-(Float* arg)
{
	//const Fraction* f = turnToFraction(arg->getVal());
	//Fraction* result = new Fraction();

	//if (denominator == f->denominator)
	//{
	//	result->numerator = numerator - f->numerator;
	//	result->denominator = denominator;
	//}
	//else
	//{
	//	result->numerator = numerator * f->denominator - f->numerator * denominator;
	//	result->denominator = denominator * f->denominator;
	//}

	//if (result->denominator < 0)
	//{
	//	result->numerator *= -1;
	//	result->denominator *= -1;
	//}

	//return result;

	if (denominator == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	Variable* result = new Float((double)numerator / (double)denominator - arg->getVal());

	return result;
}

Variable* Fraction::operator/(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Fraction* result = new Fraction();

	if (f->numerator == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	result->numerator = numerator * f->denominator;
	result->denominator = denominator * f->numerator;

	if (result->denominator < 0)
	{
		result->numerator *= -1;
		result->denominator *= -1;
	}

	return result;
}

Variable* Fraction::operator/(Float* arg)
{
	//const Fraction* f = turnToFraction(arg->getVal());
	//Fraction* result = new Fraction();

	//if (f->numerator == 0)
	//	throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	//result->numerator = numerator * f->denominator;
	//result->denominator = denominator * f->numerator;

	//if (result->denominator < 0)
	//{
	//	result->numerator *= -1;
	//	result->denominator *= -1;
	//}

	//return result;

	if (denominator == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	Variable* result = new Float(((double)numerator / (double)denominator) / arg->getVal());

	return result;
}

Variable* Fraction::toUpDegree(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);

	if (abs(f->numerator) >= f->denominator && abs(f->numerator) % f->denominator == 0)
	{
		int degree = f->numerator / f->denominator;

		Fraction* result = new Fraction();

		if (degree > -1)
		{
			result->numerator = pow(numerator, degree);
			result->denominator = pow(denominator, degree);
		}
		else
		{
			result->numerator = pow(denominator, (-1) * degree);
			result->denominator = pow(numerator, (-1) * degree);
		}

		if (result->denominator < 0)
		{
			result->numerator *= -1;
			result->denominator *= -1;
		}

		return result;
	}
	else
		throw Exceptions(FORMAT::INVALID_POW);

	return this;
}

Variable* Fraction::toUpDegree(Float* arg)
{
	if (arg->getVal() != round(arg->getVal()))
		throw Exceptions(FORMAT::INVALID_POW);

	int degree = arg->getVal();

	Fraction* result = new Fraction();

	if (degree > -1)
	{
		result->numerator = pow(numerator, degree);
		result->denominator = pow(denominator, degree);
	}
	else
	{
		result->numerator = pow(denominator, (-1) * degree);
		result->denominator = pow(numerator, (-1) * degree);
	}

	if (result->denominator < 0)
	{
		result->numerator *= -1;
		result->denominator *= -1;
	}

	return result;
}

void Fraction::print(Variable* arg)
{
	Fraction* f = dynamic_cast<Fraction*>(arg);
	Float* ff = dynamic_cast<Float*>(arg);

	if (ff)
	{
		ff->print();
	}
	else if (f)
	{
		f = minimize(f);
		cout << f->integer << "[" << f->numerator << "/" << f->denominator << "]" << endl;
	}
	else
	{
		minimize();
		cout << integer << "[" << numerator << "/" << denominator << "]" << endl;
	}
}

Fraction* Fraction::minimize(Fraction* f)
{
	Fraction* result = new Fraction();

	if (f)
		if (abs(f->numerator) >= f->denominator)
		{
			int delimer = LCD(f->numerator, f->denominator);
			f->numerator /= delimer;
			f->denominator /= delimer;

			result->integer = f->numerator / f->denominator;
			result->numerator = abs(f->numerator) % f->denominator;
			result->denominator = f->denominator;
		}
		else
		{
			int delimer = LCD(f->numerator, f->denominator);
			result->numerator = f->numerator / delimer;
			result->denominator = f->denominator / delimer;
		}
	else
		if (abs(numerator) >= denominator)
		{
			int delimer = LCD(numerator, denominator);
			numerator /= delimer;
			denominator /= delimer;

			result->integer = numerator / denominator;
			result->numerator = abs(numerator) % denominator;
			result->denominator = denominator;
		}
		else
		{
			int delimer = LCD(numerator, denominator);
			result->numerator = numerator / delimer;
			result->denominator = denominator / delimer;
		}

	return result;
}

int Fraction::LCD(int numerator, int denominator)
{
	int num = abs(numerator);
	while (num * denominator != 0)
		if (num > denominator)
			num %= denominator;
		else
			denominator %= num;

	return num + denominator;
}

Fraction* Fraction::turnToFraction(double val)
{
	Fraction* f = new Fraction();

	int n = val;
	double mult = pow(10, 3);
	double fract = round((val - n) * mult) / mult;

	f->denominator = 1000;

	if (fract == round(fract))
	{
		f->integer = n + fract;
		f->numerator = f->integer * f->denominator;
	}
	else
	{
		f->integer = n;
		f->numerator = f->integer * 1000 + fract * 1000;
	}

	f->integer = 0;

	return f;
}