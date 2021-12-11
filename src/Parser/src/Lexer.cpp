#include "Lexer.hpp"
#include <cstring>
#include <iostream>
#include "Tokens/NumericLiteralToken.hpp"
#include "Tokens/OperatorToken.hpp"
#include "Tokens/ParenthesisToken.hpp"

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
}

std::shared_ptr<List<IToken *>> Lexer::Parse(char *line)
{
    std::shared_ptr<List<IToken *>> list = std::make_shared<List<IToken *>>();

    int len = strlen(line);

    char *temp = new char[len + 1];
    int tempIndex = 0;

    int index = 0;
    while (isspace(line[index]))
    {
        index++;
    }

    for (; index < len; index++)
    {
        if (isdigit(line[index]))
        {
            temp[tempIndex] = line[index];
            tempIndex++;
        }
        else if (IsOperator(line[index]))
        {
            temp[tempIndex] = '\0';

            if (tempIndex > 0)
            {
                double value = strtod(temp, NULL);

                list->Add(new NumericLiteralToken(value));
            }

            list->Add(new OperatorToken(line[index]));

            tempIndex = 0;
        }
        else if (isspace(line[index]))
        {
            if (tempIndex > 0)
            {
                temp[tempIndex] = '\0';
                double value = strtod(temp, NULL);

                list->Add(new NumericLiteralToken(value));
                tempIndex = 0;
            }
            continue;
        }
        else if (IsParenthesis(line[index]))
        {
            temp[tempIndex] = '\0';

            if (tempIndex > 0)
            {
                double value = strtod(temp, NULL);

                list->Add(new NumericLiteralToken(value));
            }

            TokenType type = line[index] == '(' ? OPEN_PARENTHESIS : CLOSED_PARENTHESIS;

            list->Add(new ParenthesisToken(type, line[index]));

            tempIndex = 0;
        }
    }

    temp[tempIndex] = '\0';

    if (tempIndex > 0)
    {
        double value = strtod(temp, NULL);

        list->Add(new NumericLiteralToken(value));
    }

    delete[] temp;

    return list;
}

bool Lexer::IsOperator(char *c)
{
    return strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0;
}

bool Lexer::IsOperator(char c)
{
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

bool Lexer::IsParenthesis(char c)
{
    return (c == '(') || (c == ')');
}