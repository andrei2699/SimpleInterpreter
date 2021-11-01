#include "AST.hpp"
#include "Tokens/OperatorToken.hpp"
#include "Tokens/NumericLiteralToken.hpp"

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

    Free(ast->Left);
    Free(ast->Right);

    if (ast != this)
    {
        delete ast;
    }
}

int AST::NodeCount(AST *ast)
{
    if (ast == nullptr)
    {
        return 0;
    }

    return 1 + NodeCount(ast->Left) + NodeCount(ast->Right);
}