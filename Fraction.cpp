#include "Fraction.h"
#include "Float.h"

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

	return result;
}

Variable* Fraction::operator+(Float* arg)
{
	const Fraction* f = turnToFraction(arg->getVal());
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

	return result;
}

Variable* Fraction::operator*(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Fraction* result = new Fraction();

	result->numerator = numerator * f->numerator;
	result->denominator = denominator * f->denominator;

	return result;
}

Variable* Fraction::operator*(Float* arg)
{
	const Fraction* f = turnToFraction(arg->getVal());
	Fraction* result = new Fraction();

	result->numerator = numerator * f->numerator;
	result->denominator = denominator * f->denominator;

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

	return result;
}

Variable* Fraction::operator-(Float* arg)
{
	const Fraction* f = turnToFraction(arg->getVal());
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

	return result;
}

Variable* Fraction::operator/(Variable* arg)
{
	const Fraction* f = dynamic_cast<const Fraction*>(arg);
	Fraction* result = new Fraction();

	if (f->numerator == 0)
		throw exception("Делить на нуль нельзя!");

	result->numerator = numerator * f->denominator;
	result->denominator = denominator * f->numerator;

	return result;
}

Variable* Fraction::operator/(Float* arg)
{
	const Fraction* f = turnToFraction(arg->getVal());
	Fraction* result = new Fraction();

	if (f->numerator == 0)
		throw exception("Делить на нуль нельзя!");

	result->numerator = numerator * f->denominator;
	result->denominator = denominator * f->numerator;

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

		return result;
	}
	else
		throw exception("Нельзя возвести дробь в нецелочисленную степень!");

	return this;
}

Variable* Fraction::toUpDegree(Float* arg)
{
	if (arg->getVal() != round(arg->getVal()))
		throw exception("Нельзя возвести дробь в нецелочисленную степень!");

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
	while (num != denominator)
		if (num > denominator)
			num -= denominator;
		else
			denominator -= num;

	return num;
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