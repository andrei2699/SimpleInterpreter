#include <iostream>

using namespace std;

#ifndef APP_NAME
#define APP_NAME "SimpleInterpreter"
#endif

int main()
{
    cout << "Hello, world!" << endl
         << APP_NAME << endl;

    return 0;
}