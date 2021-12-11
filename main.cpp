#include <iostream>
#include <cstring>
#include <memory>
#include "FileReader.hpp"
#include "List.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "AST.hpp"
#include "Runner.hpp"
#include "SyntaxNodes/Expression.hpp"
#include "SyntaxNodes/StringExpression.hpp"

using namespace std;

#ifndef APP_NAME
#define APP_NAME "SimpleInterpreter"
#endif

void test_list();
void test_expression();

int main(int argc, char **argv)
{
    cout << APP_NAME << endl
         << endl;

    if (argc != 2)
    {
        cout << "Usage " << argv[0] << " <path_to_file>" << endl;
        return 1;
    }

    FileReader reader;
    // FileReader reader2 = reader;

    // FileReader reader3;
    // reader3 = reader;

    if (!reader.Open(argv[1]))
    {
        cout << "Could not open file " << argv[1] << endl;

        return 2;
    }

    Lexer lexer;
    Parser parser;
    Runner runner;
    char line[100];
    while (reader.ReadLine(line, 100))
    {
        try
        {
            shared_ptr<List<IToken *>> list = lexer.Parse(line);

            AST ast(*parser.Parse(list));
            // ast.Print();
            // cout << " = ";
            runner.Run(&ast);
        }
        catch (...)
        {
            int len = strlen(line);
            cout << "An exception occured while interpreting!" << endl;
            cout << "Could not parse line " << line;
            cout << endl;
            break;
        }
    }

    reader.Close();

    cout << endl;

    return 0;
}

void test_expression()
{
    StringExpression exp;
    exp = "Value";

    StringExpression ex1, ex2;

    cout << exp.GetValue() << " | " << exp.GetType() << endl
         << endl;

    exp.SetType(NUMBER_EXPRESSION);

    ex1 = ex2 = exp;

    // ex2 = "val";

    cout << exp.GetValue() << " | " << exp.GetType() << endl;
    cout << ex1.GetValue() << " | " << ex1.GetType() << endl;
    cout << ex2.GetValue() << " | " << ex2.GetType() << endl;

    // self assignment
    exp = exp;

    ex1 = ex2 = exp = "Other";

    cout << exp.GetValue() << " | " << exp.GetType() << endl;
    cout << ex1.GetValue() << " | " << ex1.GetType() << endl;
    cout << ex2.GetValue() << " | " << ex2.GetType() << endl;
}