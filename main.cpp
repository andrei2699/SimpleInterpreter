#include <iostream>
#include "FileReader.hpp"

using namespace std;

#ifndef APP_NAME
#define APP_NAME "SimpleInterpreter"
#endif

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

    char line[100];
    while (reader.ReadLine(line, 100))
    {
        cout << line;
    }

    reader.Close();

    return 0;
}