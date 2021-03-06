#ifndef AST_H
#define AST_H

#include "Tokens/IToken.hpp"

class AST
{
public:
    AST();
    AST(IToken *token);
    ~AST();

    void Print();
    void Free();
    int NodeCount();
    AST *Left;
    AST *Right;

    IToken *Token;

private:
    void Free(AST *ast);
    void Print(AST *ast);

    int NodeCount(AST *ast);
};

#endif // AST_H
