#include "OperatorToken.hpp"
#include <iostream>

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

void OperatorToken::Print()
{
    std::cout << GetValue();
}