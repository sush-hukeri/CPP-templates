#include <iostream>
using namespace std;

template<typename... Types>
class Tuple {
public:
	static constexpr size_t length{ sizeof...(Types) };
};

int main(int argc, char* argv[])
{
	cout << Tuple<>::length << '\n';
	cout << Tuple<int>::length << '\n';
	cout << Tuple<short, int, long>::length << endl;
	return 0;
}