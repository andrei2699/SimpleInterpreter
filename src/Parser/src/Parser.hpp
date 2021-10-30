#ifndef PARSER_H
#define PARSER_H

#include "AST.hpp"
#include "List.hpp"
#include "Tokens/IToken.hpp"

class Parser
{
public:
    Parser();
    ~Parser();

    AST *Parse(List<IToken *> tokens);

private:
    AST *Parse(List<IToken *> tokens, int index);
    int IndexOfToken(List<IToken *> tokens, TokenType type, int startIndex = 0);
    int IndexOfOperator(List<IToken *> tokens, char op, int startIndex = 0);
};

#endif // PARSER_H
