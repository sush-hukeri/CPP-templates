#include <iostream>
#include <string>
#include "stack1.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	Stack<int> intStack;
	Stack<string> stringStack;

	intStack.push(7);
	int topmost_int{ intStack.top() };
	cout << "The topmost int in intStack is " << topmost_int << '\n';

	stringStack.push("hello");
	string topmost_string{ stringStack.top() };
	cout << "The topmost string in stringStack is " << topmost_string << '\n';

	stringStack.pop();
	cout << "Is stringStack empty? " << stringStack.empty() << endl;

	return 0;
}