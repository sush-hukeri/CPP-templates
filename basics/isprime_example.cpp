#include <vector>
#include <iostream>
#include "isprime.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	cout << boolalpha;
	cout << IsPrime<1>::value << '\n';
	cout << IsPrime<11>::value << '\n';
	cout << IsPrime<57>::value << '\n';
	cout << IsPrime<59>::value << '\n';
	return 0;
}