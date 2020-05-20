#include <iostream>
#include <string>
#include <utility>
#include "stack1.hpp"
#include "stack2.hpp"

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

	stringStack.push("Welcome");
	stringStack.push("to");
	stringStack.push("C++.");
	cout << stringStack << '\n';
	
	Stack<pair<int, int>> pairStack;
	pairStack.push({ 4, 5 });
	pairStack.push({ 6, 7 });

	// The following will throw an error because
	// operator<< is not defined for element type std::pair<>.
	// cout << pairStack;

	cout << pairStack.top().first << ", ";
	cout << pairStack.top().second << '\n';

	// Alias declaration
	using DoubleStack = Stack<double>;
	DoubleStack double_stack;
	double_stack.push(7.10);
	double_stack.push(27.44);
	double_stack.push(3.05);
	cout << double_stack << endl;

	return 0;
}