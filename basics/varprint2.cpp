#include <iostream>
#include <string>
using namespace std;

template<typename T>
void print(T arg)
{
    cout << arg << '\n';  // Print passed argument.
}

template<typename T, typename... Types>
void print(T firstArg, Types... args)
{
    print(firstArg);
    // cout << sizeof...(Types) << '\n';
    cout << "Number of arguments remaining " << sizeof...(args) << '\n';
    print(args...);
}


int main(int argc, char* argv[])
{
    print(1.00, "Hello, world!", 2);
    cout << endl;
    return 0;
}