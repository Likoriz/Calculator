#include "Exceptions.h"

using namespace std;

Exceptions::Exceptions(JSON error)
{
	switch (error)
	{
	case JSON::INVALID_FILENAME:
		message = "Отсутствует файл или неверное имя файла!";
		break;
	case JSON::NOT_STRING_VALUE:
		message = "Значение не является строкой!";
		break;
	case JSON::ABSENT_VALUE:
		message = "Отсутствует значение!";
		break;
	case JSON::INVALID_VALUE:
		message = "Некорректное значение!";
		break;
	case JSON::UNKNOWN_TYPE:
		message = "Неизвестный тип данных!";
		break;
	case JSON::PARSE_ERROR:
		message = "Ошибка чтения файла!";
		break;
	case JSON::VARIABLE_ABSENCE:
		message = "Отсутствует необходимая для вычисления выражения переменная!";
		break;
	default:
		message = "Неизвестная ошибка во время чтения файла!";
		break;
	}
}

Exceptions::Exceptions(COMPUTE error)
{
	switch (error)
	{
	case COMPUTE::DIVISION_BY_ZERO:
		message = "Деление на нуль!";
		break;
	case COMPUTE::INCOMPATIBLE_SIZES:
		message = "Несоответствующие размеры матриц!";
		break;
	case COMPUTE::MATRIX_DIVISION:
		message = "Деление матрицы на матрицу!";
		break;
	case COMPUTE::MATRIX_POW_MATRIX:
		message = "Возведение матрицы в степень матрицы!";
		break;
	case COMPUTE::COMPLEX_POW_COMPLEX:
		message = "Возведение комплексного числа в степень комплексного числа!";
		break;
	default:
		message = "Неизвестная ошибка во время вычисления!";
		break;
	}
}

Exceptions::Exceptions(FORMAT error)
{
	switch (error)
	{	
	case FORMAT::INVALID_SIZE:
		message = "Некорректный размер!";
		break;
	case FORMAT::INVALID_POW:
		message = "Некорректное значение степени!";
		break;
	case FORMAT::INVALID_FORMAT:
		message = "Некорректный формат записи!";
		break;
	default:
		message = "Неизвестная ошибка формата!";
		break;
	}
}

const char* Exceptions::what()
{
	return message.c_str();
}