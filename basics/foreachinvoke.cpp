#include <iostream>
#include <vector>
#include <string>
#include "foreachinvoke.hpp"

using std::string;
using std::vector;
using std::cout;

class MyClass
{
public:
	void memfunc(int i) const {
		cout << "MyClass::memfunc() called for " << i << '\n';
	}
};


int main(int argc, char* argv[])
{
	vector<int> primes{ 2, 3, 5, 7, 11, 17, 19 };

	// Pass lambda as callable with an additional argument.
	foreach(primes.begin(), primes.end(), [](const string& prefix,
		string const& suffix,
		int i) { cout << prefix << i << suffix << '\n'; },
		"- prefix ", " - suffix."); // First and second argument of the lambda.

	// Call obj.memfunc() for each element in the vector.
	// If the callable is a pointer-to-member, the first additional argument is used as the "this" object.
	// All remaining additional parameters are just passed as arguments to the callable.
	MyClass obj;
	foreach(primes.begin(), primes.end(),
		&MyClass::memfunc,  // Member function to call.
		obj);  // Object to call memfunc() for.
	return 0;
}