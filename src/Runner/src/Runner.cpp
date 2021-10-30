#include "Runner.hpp"
#include <iostream>
#include <stdexcept>
#include "Tokens/NumericLiteralToken.hpp"
#include "Tokens/OperatorToken.hpp"

Runner::Runner()
{
}

Runner::~Runner()
{
}

void Runner::Run(AST *ast)
{
    std::cout << Evaluate(ast) << std::endl;
}

double Runner::Evaluate(AST *ast)
{
    if (ast->Token->GetType() == LITERAL)
    {
        NumericLiteralToken *literal = (NumericLiteralToken *)ast->Token;
        return literal->GetValue();
    }

    double left = Evaluate(ast->Left);
    double right = Evaluate(ast->Right);

    OperatorToken *operatorToken = (OperatorToken *)ast->Token;

    switch (operatorToken->GetValue())
    {
    case '+':
        return left + right;

    case '-':
        return left - right;

    case '*':
        return left * right;

    case '/':
        return left / right;

    default:
        throw new std::invalid_argument("Unknown Operator");
    }
}