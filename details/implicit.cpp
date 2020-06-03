// Function template argument deduction example
#include <iostream>

using std::cout;
using std::endl;

template<typename RT, typename SrcT>
RT implicit_cast(SrcT const& x)  // SrcT can be deduced, but RT cannot.
{
	return x;
}

int main(int argc, char* argv[])
{
	double const value{ implicit_cast<double>(-1) };
	cout << value << endl;
	return 0;
}