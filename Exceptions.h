#pragma once

#include <iostream>
#include <stdexcept>

enum class JSON { INVALID_FILENAME, NOT_STRING_VALUE, ABSENT_VALUE, INVALID_VALUE, UNKNOWN_TYPE, PARSE_ERROR };
enum class COMPUTE { DIVISION_BY_ZERO, INCOMPATIBLE_SIZES, MATRIX_DIVISION, MATRIX_POW_MATRIX, COMPLEX_POW_COMPLEX };
enum class FORMAT { INVALID_SIZE, INVALID_POW, IVALID_FORMAT };

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
