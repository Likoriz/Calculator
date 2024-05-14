#include "Complex.h"
#include "Float.h"

#include "Exceptions.h"

#define PI 3.14

using namespace std;

Complex::Complex(std::string name) :Variable(name)
{
	setDataType(dataType::COMPLEX);
	cout << "������� �������������� � ������ �����: ";

	cin >> real >> imaginary;
	if (cin.fail())
		throw Exceptions(FORMAT::INVALID_FORMAT);
}

Complex::Complex()
{
	real = 0;
	imaginary = 0;
}

Complex::Complex(string name, double r, double i) : Variable(name, 0)
{
	setDataType(dataType::COMPLEX);
	real = r;
	imaginary = i;
}

Variable* Complex::operator+(Variable* arg)
{
	const Complex* c = dynamic_cast<const Complex*>(arg);

	Complex* result = new Complex();

	if (c)
	{
		result->real = real + c->real;
		result->imaginary = imaginary + c->imaginary;
	}
	else
	{
		Float* f = dynamic_cast<Float*>(arg);

		result->real = real + f->getVal();
		result->imaginary = imaginary;

		return result;
	}

	return result;
}

Variable* Complex::operator+(Float* arg)
{
	Complex* result = new Complex();

	result->real = real + arg->getVal();
	result->imaginary = imaginary;

	return result;
}

Variable* Complex::operator*(Variable* arg)
{
	const Complex* c = dynamic_cast<const Complex*>(arg);

	Complex* result = new Complex();

	if (c)
	{
		result->real = real * c->real - imaginary * c->imaginary;
		result->imaginary = real * c->imaginary + c->real * imaginary;
	}
	else
	{
		Float* f = dynamic_cast<Float*>(arg);
		Complex* tmp = new Complex();
		tmp->real = f->getVal();

		result->real = real * tmp->real - imaginary * tmp->imaginary;
		result->imaginary = real * tmp->imaginary + tmp->real * imaginary;
	}

	return result;
}

Variable* Complex::operator*(Float* arg)
{
	Complex* result = new Complex();

	result->real = real * arg->getVal();
	result->imaginary = imaginary * arg->getVal();

	return result;
}

Variable* Complex::operator-(Variable* arg)
{
	const Complex* c = dynamic_cast<const Complex*>(arg);

	Complex* result = new Complex();

	result->real = real - c->real;
	result->imaginary = imaginary - c->imaginary;

	return result;
}

Variable* Complex::operator-(Float* arg)
{
	Complex* result = new Complex();

	result->real = real - arg->getVal();
	result->imaginary = imaginary;

	return result;
}

Variable* Complex::operator/(Variable* arg)
{
	const Complex* c = dynamic_cast<const Complex*>(arg);

	if (c->real == 0 && c->imaginary == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	Complex* result = new Complex();

	result->real = (real * c->real + imaginary * c->imaginary) / (c->real * c->real + c->imaginary * c->imaginary);
	result->imaginary = (c->real * imaginary - real * c->imaginary) / (c->real * c->real + c->imaginary * c->imaginary);

	return result;
}

Variable* Complex::operator/(Float* arg)
{
	if (arg->getVal() == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	Complex* result = new Complex();

	result->real = real / arg->getVal();
	result->imaginary = imaginary / arg->getVal();

	return result;
}

Variable* Complex::toUpDegree(Variable* arg)
{
	throw Exceptions(COMPUTE::COMPLEX_POW_COMPLEX);
}

Variable* Complex::toUpDegree(Float* arg)
{
	if (arg->getVal() != round(arg->getVal()))
		throw Exceptions(FORMAT::INVALID_POW);

	int degree = arg->getVal();

	Complex* result = new Complex();

	if (degree == 0)
	{
		result->real = 1;
		result->imaginary = 0;
	}
	else if (degree == 1)
		return this;
	else
	{
		if (real == 0)
			throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

		float r = sqrt(real * real + imaginary * imaginary);

		float y;
		if (real > 0)
			y = atan(imaginary / real);
		else if (real < 0 && imaginary >= 0)
			y = PI + atan(imaginary / real);
		else if (real < 0 && imaginary < 0)
			y = -PI + atan(imaginary / real);
		else if (real == 0 && imaginary > 0)
			y = PI / 2;
		else
			y = -PI / 2;

		result->real = pow(r, degree) * cos(degree * y);
		result->imaginary = pow(r, degree) * sin(degree * y);
	}

	return result;
}

void Complex::print(Variable* arg)
{
	const Complex* c = dynamic_cast<Complex*>(arg);

	if (c)
		if (c->imaginary > 0)
			cout << c->real << " + " << c->imaginary << "i" << endl;
		else if (c->imaginary == 0)
			cout << c->real << endl;
		else
			cout << c->real << c->imaginary << "i" << endl;
	else
		if (imaginary > 0)
			cout << real << " + " << imaginary << "i" << endl;
		else if (imaginary == 0)
			cout << real << endl;
		else
			cout << real << imaginary << "i" << endl;
}