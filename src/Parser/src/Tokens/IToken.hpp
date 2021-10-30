#ifndef ITOKEN_H
#define ITOKEN_H

#include "TokenType.hpp"

class IToken
{
public:
    IToken(TokenType type);
    virtual ~IToken();

    TokenType GetType();

private:
    TokenType _type;
};

#endif // ITOKEN_H
