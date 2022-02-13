#include <iostream>
#include <vector>
#include "foreach.hpp"

using namespace std;

void func(int i)
{
	cout << "func() called for " << i << '\n';
}

// A function object type (for objects that can be used as functions)
class FuncObj
{
public:
	void operator()(int i) const
	{
		cout << "FuncObj::op() called for " << i << '\n';
	}
};

int main(int argc, char* argv[])
{
	vector<int> primes{ 2, 3, 5, 7, 11, 17, 19 };

	foreach(primes.begin(), primes.end(), func); // Function as callable (decays to pointer)
	foreach(primes.begin(), primes.end(), &func); // Function pointer as callable
	foreach(primes.begin(), primes.end(), FuncObj()); // Function object as callable
	foreach(primes.begin(), primes.end(), [](int i) { cout << "Lambda called for " << i << '\n'; });  // Lambda as callable
	return 0;
}
