#ifndef PARENTHESIS_TOKEN_H
#define PARENTHESIS_TOKEN_H

#include "IToken.hpp"

class ParenthesisToken : public IToken
{
public:
    ParenthesisToken(TokenType, char _parenthesis);
    virtual ~ParenthesisToken();

    char GetValue();
    void Print();

private:
    char _parenthesis;
};

#endif // PARENTHESIS_TOKEN_H
