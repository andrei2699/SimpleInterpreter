#ifndef OPERATOR_TOKEN_H
#define OPERATOR_TOKEN_H

#include "IToken.hpp"

class OperatorToken : public IToken
{
public:
    OperatorToken(char op);
    virtual ~OperatorToken();

    char GetValue();
    void Print();

private:
    char _op;
};

#endif // OPERATOR_TOKEN_H
