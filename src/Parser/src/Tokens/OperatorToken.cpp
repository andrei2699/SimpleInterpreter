#include "OperatorToken.hpp"

OperatorToken::OperatorToken(char op) : IToken(OPERATOR), _op(op)
{
}

OperatorToken::~OperatorToken()
{
}

char OperatorToken::GetValue()
{
    return _op;
}