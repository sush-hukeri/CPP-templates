#include "max1.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
	int const i{ 42 };
	cout << "i = " << i << ", max(7, i): " << ::max(7, i) << '\n';

	double const f1{ 3.4 };
	double const f2{ -6.7 };
	cout << "f1 = " << f1 << ", f2 = " << f2
		 << ", max(f1, f2): " << ::max(f1, f2) << '\n';

	string const s1{ "mathematics" };
	string const s2{ "math" };
	cout << "s1 = " << s1 << ", s2 = " << s2
		 << ", max(s1, s2): " << max(s1, s2) << endl;

	/* int 4 is cast to a double so that the deduced type of the template parameter T can be "double."
	Without the cast, this will be an error because T can be deduced as	either int or double.
	*/
	cout << max(static_cast<double>(4), 7.2) << '\n';

	// Explicitly specify the type of T to prevent the compiler from attempting type deduction.
	cout << max<double>(4, 7.2) << '\n';

	cout << endl;
	return 0;
}