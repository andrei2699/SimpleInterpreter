#include "StringExpression.hpp"
#include <iostream>
#include <cstring>

StringExpression::StringExpression() : Expression(STRING_EXPRESSION)
{
    this->value = NULL;
}

StringExpression::~StringExpression()
{
    if (this->value != NULL)
    {
        delete[] this->value;
    }
}

StringExpression &StringExpression::operator=(const StringExpression &other)
{
    if (this == &other)
    {
        std::cout << "Self assignment" << std::endl;
        return *this;
    }

    Expression::operator=(other);

    SetValue(other.value);
    return *this;
}

StringExpression &StringExpression::operator=(char *value)
{
    SetValue(value);
    return *this;
}

StringExpression &StringExpression::operator=(const char *value)
{
    SetValue((char *)value);
    return *this;
}

char *StringExpression::GetValue()
{
    return value;
}

void StringExpression::SetValue(char *value)
{
    if (this->value != NULL)
    {
        delete[] this->value;
    }

    this->value = new char[strlen(value)];

    strcpy(this->value, value);
}

void StringExpression::SetValue(const char *value)
{
    SetValue((char *)value);
}