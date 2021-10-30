#include "NumericLiteralToken.hpp"

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