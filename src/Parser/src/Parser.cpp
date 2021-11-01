#include "Parser.hpp"
#include <iostream>
#include <stdexcept>
#include "Tokens/NumericLiteralToken.hpp"
#include "Tokens/OperatorToken.hpp"
#include "Stack.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

AST *Parser::Parse(List<IToken *> tokens)
{
    if (tokens.Length() == 0)
    {
        return nullptr;
    }

    Stack<IToken *> stack;
    List<IToken *> outputlist;

    for (int i = 0; i < tokens.Length(); i++)
    {
        switch (tokens[i]->GetType())
        {
        case LITERAL:
        {
            outputlist.Add(tokens[i]);
        }
        break;

        case OPERATOR:
        {
            while (!stack.IsEmpty() && Priority((OperatorToken *)stack.Top()) >= Priority((OperatorToken *)tokens[i]))
            {
                outputlist.Add(stack.Pop());
            }
            stack.Push(tokens[i]);
        }
        break;

        default:
            break;
        }
    }

    while (!stack.IsEmpty())
    {
        outputlist.Add(stack.Pop());
    }

    // for (int i = 0; i < outputlist.Length(); i++)
    // {
    //     if (outputlist[i]->GetType() == LITERAL)
    //     {
    //         std::cout << ((NumericLiteralToken *)outputlist[i])->GetValue() << " ";
    //     }
    //     else
    //     {
    //         std::cout << ((OperatorToken *)outputlist[i])->GetValue() << " ";
    //     }
    // }

    for (int i = 0; i < tokens.Length(); i++)
    {
        if (tokens[i]->GetType() == OPERATOR)
        {
            if (i - 1 < 0 || i + 1 >= tokens.Length())
            {
                throw new std::invalid_argument("Parsing error");
            }
            if (tokens[i - 1]->GetType() != LITERAL && tokens[i + 1]->GetType() != LITERAL)
            {
                throw new std::invalid_argument("Parsing error");
            }
        }
    }

    int x = 0;
    AST *ast = CovertListToAST(outputlist, outputlist.Length() - 1, &x);

    if (ast->NodeCount() != outputlist.Length())
    {
        throw new std::invalid_argument("Parsing error");
    }

    return ast;
}

int Parser::Priority(OperatorToken *token)
{
    switch (token->GetValue())
    {
        //case '^': return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;

    default:
        return 0;
    }
}

AST *Parser::CovertListToAST(List<IToken *> tokens, int index, int *offset)
{
    AST *ast = new AST(tokens[index]);

    (*offset)++;

    if (tokens[index]->GetType() == LITERAL)
    {
        return ast;
    }

    if (index - 1 < 0)
    {
        throw new std::out_of_range("Missing Right Operand");
    }

    int rightOffset = 0;
    ast->Right = CovertListToAST(tokens, index - 1, &rightOffset);

    if (index - rightOffset - 1 < 0)
    {
        throw new std::out_of_range("Missing Left Operand");
    }

    int leftOffset = 0;
    ast->Left = CovertListToAST(tokens, index - rightOffset - 1, &leftOffset);

    *offset += leftOffset + rightOffset;

    return ast;
}
