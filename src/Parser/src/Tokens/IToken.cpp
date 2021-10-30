#include "IToken.hpp"

IToken::IToken(TokenType type) : _type(type)
{
}

IToken::~IToken()
{
}

TokenType IToken::GetType()
{
    return _type;
}