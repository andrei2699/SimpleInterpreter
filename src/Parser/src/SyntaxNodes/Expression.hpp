#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ExpressionType.hpp"

class Expression
{
public:
    Expression(ExpressionType type);
    virtual ~Expression();

    Expression &operator=(const Expression &other);

    void SetType(ExpressionType type);
    ExpressionType GetType();

private:
    ExpressionType type;
};

#endif // EXPRESSION_H
