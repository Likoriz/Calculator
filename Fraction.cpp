#include "Fraction.h"

using namespace std;

Fraction::Fraction(std::string name) :Variable(name)
{
	setDataType(dataType::FRACTION);
	cout << "Введите сначала числитель, затем знаменатель:" << endl;
	cin >> numerator >> denominator;

	if (denominator == 0)
		throw exception("Делить на нуль нельзя!");
}

Fraction::Fraction()
{
	numerator = 0;
	denominator = 0;
}

Variable* Fraction::operator+(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Variable* result = new Fraction();

	if (denominator == f->denominator)
	{
		dynamic_cast<Fraction*>(result)->numerator = numerator + f->numerator;
		dynamic_cast<Fraction*>(result)->denominator = denominator;
	}
	else
	{
		dynamic_cast<Fraction*>(result)->numerator = numerator * f->denominator + f->numerator * denominator;
		dynamic_cast<Fraction*>(result)->denominator = denominator * f->denominator;
	}

	return result;
}

Variable* Fraction::operator*(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Variable* result = new Fraction();

	dynamic_cast<Fraction*>(result)->numerator = numerator * f->numerator;
	dynamic_cast<Fraction*>(result)->denominator = denominator * f->denominator;

	return result;
}

Variable* Fraction::operator-(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Variable* result = new Fraction();

	if (denominator == f->denominator)
	{
		dynamic_cast<Fraction*>(result)->numerator = numerator - f->numerator;
		dynamic_cast<Fraction*>(result)->denominator = denominator;
	}
	else
	{
		dynamic_cast<Fraction*>(result)->numerator = numerator * f->denominator - f->numerator * denominator;
		dynamic_cast<Fraction*>(result)->denominator = denominator * f->denominator;
	}

	return result;
}

Variable* Fraction::operator/(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Variable* result = new Fraction();

	if (f->numerator == 0)
		throw exception("Делить на нуль нельзя!");

	dynamic_cast<Fraction*>(result)->numerator = numerator * f->denominator;
	dynamic_cast<Fraction*>(result)->denominator = denominator * f->numerator;

	return result;
}

Variable* Fraction::toUpDegree(int degree)
{
	Variable* result = new Fraction();

	if (degree > -1)
	{
		dynamic_cast<Fraction*>(result)->numerator = pow(numerator, degree);
		dynamic_cast<Fraction*>(result)->denominator = pow(denominator, degree);
	}
	else
	{
		dynamic_cast<Fraction*>(result)->numerator = pow(denominator, (-1) * degree);
		dynamic_cast<Fraction*>(result)->denominator = pow(numerator, (-1) * degree);
	}

	return result;
}

void Fraction::print(Variable* arg)
{
	Fraction* f = dynamic_cast<Fraction*>(arg);

	if (f)
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
		if (f->numerator >= f->denominator)
		{
			result->integer = f->numerator / f->denominator;
			result->numerator = f->numerator % f->denominator;
			result->denominator = f->denominator;
		}
		else
		{
			int delimer = LCD(f->numerator, f->denominator);
			result->numerator = f->numerator / delimer;
			result->denominator = f->denominator / delimer;
		}
	else
		if (numerator >= denominator)
		{
			result->integer = numerator / denominator;
			result->numerator = numerator % denominator;
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
	while (numerator != denominator)
		if (numerator > denominator)
			numerator -= denominator;
		else
			denominator -= numerator;

	return numerator;
}