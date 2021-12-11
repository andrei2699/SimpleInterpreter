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
    void SetValue(char *value);
    void SetValue(const char *value);

private:
    char *value;
};

#endif // STRING_EXPRESSION_H
