#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Token.h"
#include "JsonReader.h"

class Calculator
{
private:
    dataType workingMode;
    std::vector<Token*> tokens;
    std::string expression;
    JsonReader* reader;
    std::map<std::string, Variable*> variables;
public:
    Calculator(std::string str, dataType mode);
    Calculator(std::string path);
    ~Calculator();
    void Tokenize();
    void turnToRPN();
    void calculateRPN();
    std::vector<Token*> getTokens();
    int getOperatorPrecedence(operatorsType type); // Добавляем здесь
};
