#ifndef STRING_EXPRESSION_H
#define STRING_EXPRESSION_H

#include "Expression.hpp"

class StringExpression : public Expression
{
public:
    StringExpression();
    virtual ~StringExpression();

    StringExpression &operator=(const StringExpression &other);
    StringExpression &operator=(char *value);
    StringExpression &operator=(const char *value);

    char *GetValue();

private:
    char *value;

    void SetValue(char *value);
};

#endif // STRING_EXPRESSION_H
