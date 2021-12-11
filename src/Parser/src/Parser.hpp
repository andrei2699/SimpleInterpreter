#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include "AST.hpp"
#include "List.hpp"
#include "Tokens/IToken.hpp"
#include "Tokens/OperatorToken.hpp"

class Parser
{
public:
    Parser();
    ~Parser();

    AST *Parse(std::shared_ptr<List<IToken *>> tokens);

private:
    int Priority(OperatorToken *token);
    AST *CovertListToAST(List<IToken *> tokens, int index, int *offset);
};

#endif // PARSER_H
