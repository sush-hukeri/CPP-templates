#include "stack7.hpp"
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	Stack<int, vector<int>> intStack;	
	intStack.push(1);
	intStack.push(5);
	intStack.push(10);
	intStack.push(100);
	cout << intStack << '\n';

	Stack<float, vector<float>> floatStack;
	floatStack = intStack; // The stacks hev different types but int converts to float.
	cout << floatStack << endl;
	return 0;
}