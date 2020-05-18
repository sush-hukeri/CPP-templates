#include <iostream>
using namespace std;

// Maximum of two values of any type.
template<typename T>
T max(T a, T b)
{
	cout << "max<T>()\n";
	return a > b ? a : b;
}
// Maximum of three values of any type.
template<typename T>
T max(T a, T b, T c)
{
	return max(max(a, b), c); // Uses the template version even for ints
							  // because the declaration of max for two ints hasn't appeared at this point.
							  // For it to use max(int, int), that function should have been declared before this function.
}

// Maximum of two ints
int max(int a, int b)
{
	cout << "max(int, int)\n";
	return a > b ? a : b;
}

int main(int argc, char* argv[])
{
	::max(47, 11, 33) // Uses max<T>() instead of max(int, int)
	return 0;
}