#include "stacknontype.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    Stack<int, 20> int20Stack;
    Stack<int, 40> int40Stack;
    Stack<string, 10> stringStack;

    int20Stack.push(7);
    cout << int20Stack.top() << '\n';
    int20Stack.pop();
    cout << int20Stack.empty() << '\n';

    stringStack.push("Hello,");
    stringStack.push("World!");
    cout << stringStack.top()   << '\n'
         << stringStack.empty() << '\n';
    return 0;
}