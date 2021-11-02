#include "AST.hpp"
#include "Tokens/OperatorToken.hpp"
#include "Tokens/NumericLiteralToken.hpp"
#include <iostream>

AST::AST() : Token(nullptr), Left(nullptr), Right(nullptr)
{
}

AST::AST(IToken *token) : Token(token), Left(nullptr), Right(nullptr)
{
}

AST::~AST()
{
    Free();
}

void AST::Print()
{
    Print(this);
}

void AST::Free()
{
    Free(this);
}

int AST::NodeCount()
{
    return NodeCount(this);
}

void AST::Free(AST *ast)
{
    if (ast == nullptr)
    {
        return;
    }

    delete ast->Token;

    Free(ast->Left);
    Free(ast->Right);
}

int AST::NodeCount(AST *ast)
{
    if (ast == nullptr)
    {
        return 0;
    }

    return 1 + NodeCount(ast->Left) + NodeCount(ast->Right);
}

void AST::Print(AST *ast)
{
    if (ast == nullptr)
    {
        return;
    }
    Print(ast->Left);
    ast->Token->Print();
    Print(ast->Right);
}