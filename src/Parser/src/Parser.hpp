#ifndef PARSER_H
#define PARSER_H

#include "AST.hpp"
#include "List.hpp"
#include "Tokens/IToken.hpp"
#include "Tokens/OperatorToken.hpp"

class Parser
{
public:
    Parser();
    ~Parser();

    AST *Parse(List<IToken *> tokens);

private:
    int Priority(OperatorToken *token);
    AST *CovertListToAST(List<IToken *> tokens, int index, int *offset);
};

#endif // PARSER_H
