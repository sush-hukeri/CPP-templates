#include "stack9.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	Stack<int>   iStack;
	Stack<float> fStack;

	// Manipulate int stack.
	iStack.push(1);
	iStack.push(2);
	cout << "iStack.top() " << iStack.top() << '\n';

	// Manipulate float stack.
	fStack.push(3.3);
	cout << "fStack.top() " << fStack.top() << '\n';

	// Assign stack of different type and manipulate again.
	fStack = iStack;
	fStack.push(4.4);
	cout << "fStack.top() " << fStack.top() << '\n';

	// A stack if doubles using a vector as an internal container.
	Stack<double, vector> vStack;
	vStack.push(5.5);
	vStack.push(6.6);
	cout << "vStack.top() " << vStack.top() << '\n';

	vStack = fStack;
	cout << "vStack: ";
	while (!vStack.empty()) {
		cout << vStack.top() << ' ';
		vStack.pop();
	}
	cout << endl;
	return 0;
}