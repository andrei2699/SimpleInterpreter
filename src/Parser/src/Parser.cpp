#include "Parser.hpp"

#include <stdexcept>
#include "Tokens/NumericLiteralToken.hpp"
#include "Tokens/OperatorToken.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

AST *Parser::Parse(List<IToken *> tokens)
{
    if (tokens.Length() == 0)
    {
        return nullptr;
    }

    AST *ast = new AST();

    int operatorIndex = IndexOfOperator(tokens, '*');
    if (operatorIndex < 0)
    {
        operatorIndex = IndexOfOperator(tokens, '/');
    }
    if (operatorIndex < 0)
    {
        operatorIndex = IndexOfOperator(tokens, '+');
    }
    if (operatorIndex < 0)
    {
        operatorIndex = IndexOfOperator(tokens, '-');
    }
    if (operatorIndex < 0)
    {
        if (tokens.Length() != 1)
        {
            throw new std::invalid_argument("Missing Operator");
        }

        ast->Token = tokens[0];
        return ast;
    }

    ast->Token = tokens[operatorIndex];
    ast->Left = new AST(tokens[operatorIndex - 1]);
    ast->Right = new AST(tokens[operatorIndex + 1]);

    return ast;
}

AST *Parser::Parse(List<IToken *> tokens, int index)
{
    return nullptr;
}

int Parser::IndexOfToken(List<IToken *> tokens, TokenType type, int startIndex)
{
    for (int i = startIndex; i < tokens.Length(); i++)
    {
        if (tokens[i]->GetType() == type)
        {
            return i;
        }
    }

    return -1;
}

int Parser::IndexOfOperator(List<IToken *> tokens, char op, int startIndex)
{
    for (int i = startIndex; i < tokens.Length(); i++)
    {
        if (tokens[i]->GetType() == OPERATOR)
        {
            OperatorToken *operatorToken = (OperatorToken *)tokens[i];
            if (operatorToken->GetValue() == op)
            {
                return i;
            }
        }
    }

    return -1;
}