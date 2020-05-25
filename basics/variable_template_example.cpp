#include <iostream>
#include <array>

using namespace std;

template<typename T = long double>
constexpr T pi{ 3.1415926535897932385 };

// Template parameterized by a non-type parameter.
template<int N>
array<int, N> arr{}; // An array with N elements, zero-initialized.

template<auto N>
constexpr decltype(N) dval{ N }; // dval's type depends on the passed value.

int main(int argc, char* argv[])
{
	cout << pi<> << '\n';
	cout << pi<float> << '\n';
	// cout << pi << '\n'; // ERROR. Angle brackets always have to be specified.

	cout << dval<'c'> << '\n';  // N has value 'c' of type char.
	arr<10>[0] = 42;
	for (size_t i = 0; i != arr<10>.size(); ++i) cout << arr<10>[i] << '\n';
	return 0;
}