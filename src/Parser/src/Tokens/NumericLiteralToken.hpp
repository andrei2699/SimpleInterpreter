#ifndef NUMERIC_LITERAL_TOKEN_H
#define NUMERIC_LITERAL_TOKEN_H

#include "IToken.hpp"

class NumericLiteralToken : public IToken
{
public:
    NumericLiteralToken(double value);
    virtual ~NumericLiteralToken();

    double GetValue();

private:
    double _value;
};

#endif // NUMERIC_LITERAL_TOKEN_H
