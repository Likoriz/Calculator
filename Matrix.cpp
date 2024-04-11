#include "Matrix.h"

using namespace std;

Matrix::Matrix(string name) : Variable(name)
{
	setDataType(dataType::MATRIX);

	cin >> rows >> cols;
	cout << endl;

	elements.resize(rows, std::vector<float>(cols, 0));

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> elements[i][j];

	cout << endl;
}

Matrix::Matrix(string name, int rows_, int cols_) : Variable(name)
{
	setDataType(dataType::MATRIX);

	rows = rows_;
	cols = cols_;

	elements.resize(rows, std::vector<float>(cols, 0));
}

Variable* Matrix::operator+(Variable* arg)
{
	const Matrix* m = dynamic_cast<const Matrix*>(arg);

	if (rows == m->rows && cols == m->cols)
	{
		Variable* result = new Matrix("res", m->rows, m->cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				dynamic_cast<Matrix*>(result)->elements[i][j] = elements[i][j] + m->elements[i][j];

		return result;
	}

	return nullptr;
}

Variable* Matrix::operator*(Variable* arg)
{
	const Matrix* m = dynamic_cast<const Matrix*>(arg);

	if (cols == m->rows)
	{
		Variable* result = new Matrix("res", rows, m->cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < m->cols; j++)
				for (int k = 0; k < cols; k++)
					dynamic_cast<Matrix*>(result)->elements[i][j] += elements[i][k] * m->elements[k][j];

		return result;
	}

	return nullptr;
}

Variable* Matrix::operator-(Variable* arg)
{
	const Matrix* m = dynamic_cast<const Matrix*>(arg);

	if (rows == m->rows && cols == m->cols)
	{
		Variable* result = new Matrix("res", m->rows, m->cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				dynamic_cast<Matrix*>(result)->elements[i][j] = elements[i][j] - m->elements[i][j];

		return result;
	}

	return nullptr;
}

void Matrix::operator/(Variable* arg)
{

}

Variable* Matrix::toUpDegree(int degree)
{
	if (degree == 0)
	{
		Variable* result = new Matrix("res", rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				dynamic_cast<Matrix*>(result)->elements[i][j] = (i == j) ? 1 : 0;

		return result;
	}
	else if (degree == 1)
	{
		Variable* result = new Matrix("res", rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				dynamic_cast<Matrix*>(result)->elements[i][j] = elements[i][j];

		return result;
	}
	else
	{
		Variable* result = new Matrix("res", rows, cols);
		Variable* temp = new Matrix("temp", rows, cols);
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
				dynamic_cast<Matrix*>(result)->elements[i][j] = dynamic_cast<Matrix*>(temp)->elements[i][j];

		delete temp;
		return result;
	}
}

ostream& operator<<(std::ostream& os, const Variable* arg)
{
	const Matrix* m = dynamic_cast<const Matrix*>(arg);

	if (m)
		for (int i = 0; i < m->rows; i++)
		{
			for (int j = 0; j < m->cols; j++)
				os << m->elements[i][j] << " ";
			os << endl;
		}

	return os;
}