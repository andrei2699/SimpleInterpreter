#ifndef AST_H
#define AST_H

#include "Tokens/IToken.hpp"

class AST
{
public:
    AST();
    AST(IToken *token);
    ~AST();

    IToken *Token;
    AST *Left;
    AST *Right;

private:
    void Free(AST *ast);
};

#endif // AST_H
