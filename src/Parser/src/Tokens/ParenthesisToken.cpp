#include "ParenthesisToken.hpp"
#include <iostream>

ParenthesisToken::ParenthesisToken(TokenType type, char _parenthesis) : IToken(type), _parenthesis(_parenthesis)
{
}

ParenthesisToken::~ParenthesisToken()
{
}

char ParenthesisToken::GetValue()
{
    return _parenthesis;
}

void ParenthesisToken::Print()
{
    std::cout << GetValue();
}