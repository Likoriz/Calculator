#include "Matrix.h"
#include "Float.h"

using namespace std;

Matrix::Matrix(string name) : Variable(name)
{
	setDataType(dataType::MATRIX);
	cout << "Введите кол-во строк и столбцов: " << endl;
	cin >> rows >> cols;

	if (rows == 0 || cols == 0)
		throw exception("Матрица не может быть нулевого размера!");

	cout << "Введите построчно матрицу: " << endl;

	elements.resize(rows, vector<float>(cols, 0));

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> elements[i][j];

	cout << endl;
}

Matrix::Matrix(int rows_, int cols_)
{
	setDataType(dataType::MATRIX);

	rows = rows_;
	cols = cols_;

	elements.resize(rows, vector<float>(cols, 0));
}

Variable* Matrix::operator+(Variable* arg)
{
	const Matrix* m = dynamic_cast<const Matrix*>(arg);

	if (rows == m->rows && cols == m->cols)
	{
		Matrix* result = new Matrix(m->rows, m->cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result->elements[i][j] = elements[i][j] + m->elements[i][j];

		return result;
	}
	else
		throw exception("Матрицы имеют разные размеры!");
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
		throw exception("У матриц не совпадают число столбцов и строк!");
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
		throw exception("Матрицы имеют разные размеры!");
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
	throw exception("Деления матрицы на матрицу не существует!.");
}

Variable* Matrix::operator/(Float* arg)
{
	double f = arg->getVal();
	if (f == 0)
		throw exception("Делить на нуль нельзя!");

	Variable* result = new Matrix(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			dynamic_cast<Matrix*>(result)->elements[i][j] = elements[i][j] / f;

	return result;
}

Variable* Matrix::toUpDegree(Variable* arg)
{
	throw exception("Нельзя возвести матрицу в степень матрицы!");
}

Variable* Matrix::toUpDegree(Float* arg)
{
	if (arg->getVal() != round(arg->getVal()))
		throw exception("Нельзя возвести матрицу в нецелочисленную степень!");

	int degree = arg->getVal();

	if (degree < 0)
		throw exception("Нельзя возвести матрицу в отрицательную степень!");

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