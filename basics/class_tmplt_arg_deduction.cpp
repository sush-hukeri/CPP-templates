//Compile as
// cl /EHsc /O2 /std:c++17 class_tmplt_arg_deduction.cpp
#include "stack4.hpp"
#include <typeinfo>
#include <type_traits>
#include <cassert>

using namespace std;

int main(int argc, char* argv[])
{
	Stack intStack{ 0 };  // Deduced as Stack<int>.
	cout << "intStack:\n";
	cout << intStack;
	cout << "\nType: " << typeid(intStack).name();
	
	Stack doubleStack{ 1.05 };
	cout << "\ndoubleStack:\n";
	cout << doubleStack;
	cout << "\nType: " << typeid(doubleStack).name();
	cout << endl;

	return 0;
}