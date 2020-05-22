#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T>
void printcoll(T const& coll)
{
	typename T::const_iterator start{ coll.cbegin() };
	typename T::const_iterator end{ coll.cend() };
	using value_type = typename T::value_type;
	copy(start, end, ostream_iterator<value_type const&>{cout, " "});
	cout << '\n';
}

int main(int argc, char* argv[])
{
	vector<string> stringVec{ "Welcome" , "to" , "C++" };
	vector<int> intVec{ 5, 10, 15, 20 };
	printcoll(stringVec);
	printcoll(intVec);
	cout << endl;
	return 0;
}