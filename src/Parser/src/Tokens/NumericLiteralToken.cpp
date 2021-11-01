#include "NumericLiteralToken.hpp"
#include <iostream>

NumericLiteralToken::NumericLiteralToken(double value) : IToken(LITERAL), _value(value)
{
}

NumericLiteralToken::~NumericLiteralToken()
{
}

double NumericLiteralToken::GetValue()
{
    return _value;
}

void NumericLiteralToken::Print()
{
    std::cout << GetValue();
}