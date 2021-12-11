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
void test_unique();
void test_shared();

int main(int argc, char **argv)
{
    cout << APP_NAME << endl
         << endl;

    // test_unique();
    // return 0;

    test_shared();
    return 0;

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

            unique_ptr<AST> ast(parser.Parse(list));
            // ast.Print();
            // cout << " = ";
            runner.Run(ast.get());
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

void test_unique()
{
    unique_ptr<StringExpression> ex1(new StringExpression());

    ex1->SetValue("Val1");
    cout << ex1.get()->GetValue() << endl;

    // unique_ptr<StringExpression> ex2 = ex1;

    unique_ptr<StringExpression> ex2 = move(ex1);
    cout << ex1.get() << endl;
    ex2->SetValue("V2");
    cout << ex2.get()->GetValue() << endl;
}

void test_shared()
{
    shared_ptr<StringExpression> ex1(new StringExpression());

    ex1->SetValue("Val1");
    cout << ex1.get()->GetValue() << ' ' << ex1.use_count() << endl;

    shared_ptr<StringExpression> ex2 = ex1;
    cout << ex1.get()->GetValue() << ' ' << ex1.use_count() << endl;

    {
        shared_ptr<StringExpression> ex3(ex2);
        cout << ex3.get()->GetValue() << ' ' << ex3.use_count() << endl;
    }
    ex2->SetValue("V2");
    cout << ex2.get()->GetValue() << ' ' << ex2.use_count() << endl;

    ex2->SetValue("Val3");
    ex1.reset();
    cout << ex1.get() << ' ' << ex2.get()->GetValue() << ' ' << ex1.use_count() << ' ' << ex2.use_count() << endl;
}