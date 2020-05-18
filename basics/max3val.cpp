#include <cstring>
#include <string>
#include <iostream>
using namespace std;

// Maximum of two values of any type.
template<typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

// Maximum of two pointers.
template<typename T>
T* max(T* a, T* b)
{
	return *a > * b ? a : b;
}

// Maximum of two C-strings
char const* max(char const* a, char const* b)
{
	return strcmp(b, a) < 0 ? a : b;
}

int main(int argc, char* argv[])
{
	int a{ 7 };
	int b{ 42 };
	auto m1{ ::max(a, b) }; // max() for two values of type int.
	cout << m1 << '\n';

	string s1{ "hey" };
	string s2{ "you" };
	auto m2{ ::max(s1, s2) }; // max() for two values of type string.
	cout << m2 << '\n';

	int* p1{ &b };
	int* p2{ &a };
	auto m3{ ::max(p1, p2) }; // max() for two pointers.
	cout << m3 << '\n';

	char const* x{ "hello" };
	char const* y{ "world!" };
	auto m4{ ::max(x, y) }; // max() for two C-strings.
	cout << m4 << endl;

	return 0;
}
