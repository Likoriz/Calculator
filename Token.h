#pragma once
enum class tokenType {CONST, VARIABLE, BRACKET, OPERATOR};
enum class dataType { FLOAT, FRACTION, MATRIX, BIGINT, IMAGINARY };
enum class operatorsType { PLUS, MINUS, DIV, MULT, EXP };
class Token
{
private:
	tokenType typeOfToken;
public:
	tokenType getTokenType();
	void setTokenType(tokenType type);
	void printYourType();
};

