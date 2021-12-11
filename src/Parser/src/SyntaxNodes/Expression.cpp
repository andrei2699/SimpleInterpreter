#include "Expression.hpp"

Expression::Expression(ExpressionType type)
{
    this->type = type;
}

Expression::~Expression()
{
}

Expression &Expression::operator=(const Expression &other)
{
    if (this == &other)
    {
        return *this;
    }

    this->type = other.type;

    return *this;
}

void Expression::SetType(ExpressionType type)
{
    this->type = type;
}

ExpressionType Expression::GetType()
{
    return type;
}