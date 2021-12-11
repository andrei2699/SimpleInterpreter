#ifndef LEXER_H
#define LEXER_H

#include <memory>
#include "List.hpp"
#include "Tokens/IToken.hpp"

class Lexer
{
public:
    Lexer();
    ~Lexer();

    std::shared_ptr<List<IToken *>> Parse(char *line);

private:
    bool IsOperator(char *c);
    bool IsOperator(char c);
    bool IsParenthesis(char c);
};

#endif // LEXER_H
