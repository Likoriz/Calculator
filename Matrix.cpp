#include "Matrix.h"
#include "Float.h"

#include "Exceptions.h"

using namespace std;

Matrix::Matrix(string name) : Variable(name)
{
	setDataType(dataType::MATRIX);
	cout << "¬ведите кол-во строк и столбцов: " << endl;

	cin >> rows >> cols;
	if (cin.fail())
		throw Exceptions(FORMAT::INVALID_FORMAT);

	if (rows <= 0 || cols <= 0)
		throw Exceptions(FORMAT::INVALID_SIZE);

	cout << "¬ведите построчно матрицу: " << endl;

	elements.resize(rows, vector<double>(cols, 0));

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			cin >> elements[i][j];
			if (cin.fail())
				throw Exceptions(FORMAT::INVALID_FORMAT);
		}

	cout << endl;
}

Matrix::Matrix(int rows_, int cols_)
{
	setDataType(dataType::MATRIX);

	rows = rows_;
	cols = cols_;

	if (rows <= 0 || cols <= 0)
		throw Exceptions(FORMAT::INVALID_SIZE);

	elements.resize(rows, vector<double>(cols, 0));
}

Matrix::Matrix(int rows_, int cols_, double val)
{
	setDataType(dataType::MATRIX);

	rows = rows_;
	cols = cols_;

	if (rows <= 0 || cols <= 0)
		throw Exceptions(FORMAT::INVALID_SIZE);

	elements.resize(rows, vector<double>(cols, 0));

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			elements[i][j] = val;
}

Matrix::Matrix(string name, int r, int c, vector<double> e) : Variable(name, 0)
{
	setDataType(dataType::MATRIX);

	rows = r;
	cols = c;

	if (rows <= 0 || cols <= 0)
		throw Exceptions(FORMAT::INVALID_SIZE);

	elements.resize(rows, vector<double>(cols, 0));

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			elements[i][j] = e[i * cols + j];
}

Variable* Matrix::operator+(Variable* arg)
{
	const Matrix* m = dynamic_cast<const Matrix*>(arg);

	if (m)
	{
		if (rows == m->rows && cols == m->cols)
		{
			Matrix* result = new Matrix(m->rows, m->cols);
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					result->elements[i][j] = elements[i][j] + m->elements[i][j];

			return result;
		}
		else
			throw Exceptions(COMPUTE::INCOMPATIBLE_SIZES);
	}
	else
	{
		Float* f = dynamic_cast<Float*>(arg);

		Matrix* result = new Matrix(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result->elements[i][j] = elements[i][j] + f->getVal();

		return result;
	}
}

Variable* Matrix::operator+(Float* arg)
{
	double f = arg->getVal();
	Matrix* result = new Matrix(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result->elements[i][j] = elements[i][j] + f;

	return result;
}

Variable* Matrix::operator*(Variable* arg)
{
	const Matrix* m = dynamic_cast<const Matrix*>(arg);

	if (m)
	{
		if (cols == m->rows)
		{
			Matrix* result = new Matrix(rows, m->cols);
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < m->cols; j++)
					for (int k = 0; k < cols; k++)
						result->elements[i][j] += elements[i][k] * m->elements[k][j];

			return result;
		}
		else
			throw Exceptions(COMPUTE::INCOMPATIBLE_SIZES);
	}
	else
	{
		Float* f = dynamic_cast<Float*>(arg);

		Matrix* result = new Matrix(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result->elements[i][j] = elements[i][j] * f->getVal();

		return result;
	}
}

Variable* Matrix::operator*(Float* arg)
{
	double f = arg->getVal();
	Matrix* result = new Matrix(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result->elements[i][j] = elements[i][j] * f;

	return result;
}

Variable* Matrix::operator-(Variable* arg)
{
	const Matrix* m = dynamic_cast<const Matrix*>(arg);

	if (rows == m->rows && cols == m->cols)
	{
		Variable* result = new Matrix(m->rows, m->cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				dynamic_cast<Matrix*>(result)->elements[i][j] = elements[i][j] - m->elements[i][j];

		return result;
	}
	else
		throw Exceptions(COMPUTE::INCOMPATIBLE_SIZES);
}

Variable* Matrix::operator-(Float* arg)
{
	double f = arg->getVal();
	Variable* result = new Matrix(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			dynamic_cast<Matrix*>(result)->elements[i][j] = elements[i][j] - f;

	return result;
}

Variable* Matrix::operator/(Variable* arg)
{
	throw Exceptions(COMPUTE::MATRIX_DIVISION);
}

Variable* Matrix::operator/(Float* arg)
{
	double f = arg->getVal();
	if (f == 0)
		throw Exceptions(COMPUTE::DIVISION_BY_ZERO);

	Variable* result = new Matrix(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			dynamic_cast<Matrix*>(result)->elements[i][j] = elements[i][j] / f;

	return result;
}

Variable* Matrix::toUpDegree(Variable* arg)
{
	throw Exceptions(FORMAT::INVALID_POW);
}

Variable* Matrix::toUpDegree(Float* arg)
{
	if (arg->getVal() != round(arg->getVal()))
		throw Exceptions(FORMAT::INVALID_POW);

	int degree = arg->getVal();

	if (degree < 0)
		throw Exceptions(FORMAT::INVALID_POW);

	Matrix* result = new Matrix(rows, cols);

	if (degree == 0)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result->elements[i][j] = (i == j) ? 1 : 0;

		return result;
	}
	else if (degree == 1)
		return this;
	else
	{
		Variable* temp = new Matrix(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				dynamic_cast<Matrix*>(temp)->elements[i][j] = elements[i][j];

		for (int i = 1; i < degree; i++)
		{
			Variable* newTemp = *temp * this;
			delete temp;
			temp = newTemp;
		}

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result->elements[i][j] = dynamic_cast<Matrix*>(temp)->elements[i][j];

		delete temp;
		return result;
	}
}

void Matrix::print(Variable* arg)
{
	const Matrix* m = dynamic_cast<Matrix*>(arg);

	if (m)
		for (int i = 0; i < m->rows; i++)
		{
			for (int j = 0; j < m->cols; j++)
				cout << m->elements[i][j] << " ";
			cout << endl;
		}
	else
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				cout << elements[i][j] << " ";
			cout << endl;
		}
}