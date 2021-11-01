#ifndef ITOKEN_H
#define ITOKEN_H

#include "TokenType.hpp"

class IToken
{
public:
    IToken(TokenType type);
    virtual ~IToken();

    virtual void Print() = 0;

    TokenType GetType();

private:
    TokenType _type;
};

#endif // ITOKEN_H
