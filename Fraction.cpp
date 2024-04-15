#include "Fraction.h"

using namespace std;

Fraction::Fraction(std::string name) :Variable(name)
{
	setDataType(dataType::FRACTION);
	cout << "¬ведите сначала числитель, затем знаменатель:" << endl;
	cin >> numerator >> denominator;

	if (denominator == 0)
		throw exception("ƒелить на нуль нельз€!");
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
		cout << f->integer << "[" << f->numerator << "/" << f->denominator << "]" << endl;
	else
		cout << integer << "[" << numerator << "/" << denominator << "]" << endl;
}