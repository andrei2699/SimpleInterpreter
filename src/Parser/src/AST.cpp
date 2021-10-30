#include "AST.hpp"

AST::AST() : Token(nullptr), Left(nullptr), Right(nullptr)
{
}

AST::AST(IToken *token) : Token(token), Left(nullptr), Right(nullptr)
{
}

AST::~AST()
{
    Free(this);
}

void AST::Free(AST *ast)
{
    if (ast == nullptr)
    {
        return;
    }

    Free(ast->Left);
    Free(ast->Right);

    delete ast;
}
