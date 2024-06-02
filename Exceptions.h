#pragma once

#include <iostream>
#include <stdexcept>

enum class JSON { INVALID_FILENAME, NOT_STRING_VALUE, ABSENT_VALUE, INVALID_VALUE, UNKNOWN_TYPE, PARSE_ERROR, VARIABLE_ABSENCE };
enum class COMPUTE { DIVISION_BY_ZERO, INCOMPATIBLE_SIZES, MATRIX_DIVISION };
enum class FORMAT { INVALID_SIZE, INVALID_POW, INVALID_FORMAT, INVALID_OPERAND, INVALID_EXPRESSION};

class Exceptions : public std::exception
{
private:
	std::string message;
public:
	Exceptions(JSON error);
	Exceptions(COMPUTE error);
	Exceptions(FORMAT error);
	const char* what();
};
