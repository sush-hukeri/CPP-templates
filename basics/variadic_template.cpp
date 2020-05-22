#include <iostream>
using namespace std;

template<typename T>
void g(T x)
{
    cout << x << '\n';
}
void f() {}

template<typename T, typename... Tail>
void f(T head, Tail... tail)
{
    g(head);
    f(tail...);
}

int main(int argc, char* argv[])
{
    cout << "First:\n";
    /* The following first calls f(1, 2.2, "hello")
     * which, after calling g(1), calls f(2.2, "hello")
     * which calls f("hello"), which then calls f()
     * */
    f(1, 2.2, "hello");

    cout << "\nSecond:\n";
    f(0.2, 'c', "yuck!", 0, 1, 2);
    cout << endl;
    return 0;
}
