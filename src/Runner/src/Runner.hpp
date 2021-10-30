#ifndef RUNNER_H
#define RUNNER_H

#include "AST.hpp"

class Runner
{
public:
    Runner();
    ~Runner();

    void Run(AST *ast);

private:
    double Evaluate(AST *ast);
};

#endif // RUNNER_H
