#ifndef LEXER_H
#define LEXER_H

#include "List.hpp"
#include "Tokens/IToken.hpp"

class Lexer
{
public:
    Lexer();
    ~Lexer();

    List<IToken *> Parse(char *line);

private:
    bool IsOperator(char *c);
    bool IsOperator(char c);
};

#endif // LEXER_H
