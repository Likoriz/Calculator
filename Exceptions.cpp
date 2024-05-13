#include "Exceptions.h"

using namespace std;

Exceptions::Exceptions(JSON error)
{
	switch (error)
	{
	case JSON::INVALID_FILENAME:
		message = "����������� ���� ��� �������� ��� �����!";
		break;
	case JSON::NOT_STRING_VALUE:
		message = "�������� �� �������� �������!";
		break;
	case JSON::ABSENT_VALUE:
		message = "����������� ��������!";
		break;
	case JSON::INVALID_VALUE:
		message = "������������ ��������!";
		break;
	case JSON::UNKNOWN_TYPE:
		message = "����������� ��� ������!";
		break;
	case JSON::PARSE_ERROR:
		message = "������ ������ �����!";
		break;
	case JSON::VARIABLE_ABSENCE:
		message = "����������� ����������� ��� ���������� ��������� ����������!";
		break;
	default:
		message = "����������� ������ �� ����� ������ �����!";
		break;
	}
}

Exceptions::Exceptions(COMPUTE error)
{
	switch (error)
	{
	case COMPUTE::DIVISION_BY_ZERO:
		message = "������� �� ����!";
		break;
	case COMPUTE::INCOMPATIBLE_SIZES:
		message = "����������������� ������� ������!";
		break;
	case COMPUTE::MATRIX_DIVISION:
		message = "������� ������� �� �������!";
		break;
	case COMPUTE::MATRIX_POW_MATRIX:
		message = "���������� ������� � ������� �������!";
		break;
	case COMPUTE::COMPLEX_POW_COMPLEX:
		message = "���������� ������������ ����� � ������� ������������ �����!";
		break;
	default:
		message = "����������� ������ �� ����� ����������!";
		break;
	}
}

Exceptions::Exceptions(FORMAT error)
{
	switch (error)
	{	
	case FORMAT::INVALID_SIZE:
		message = "������������ ������!";
		break;
	case FORMAT::INVALID_POW:
		message = "������������ �������� �������!";
		break;
	case FORMAT::INVALID_FORMAT:
		message = "������������ ������ ������!";
		break;
	default:
		message = "����������� ������ �������!";
		break;
	}
}

const char* Exceptions::what()
{
	return message.c_str();
}