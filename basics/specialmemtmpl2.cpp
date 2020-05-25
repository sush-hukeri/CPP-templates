#include <utility>
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string name;
public:
	// Generic constructor for passed inline name:
	template<typename T>
	explicit Person(T&& n) : name{ forward<T>(n) } {
		cout << "TMPL-CONSTR Person " << name << '\n';
	}

	// Copy Constructor
	Person(Person& const p) : name{ p.name } {
		cout << "COPY-CONSTR Person " << name << '\n';
	}

	// Move Constructor
	Person(Person&& p) : name{ move(p.name) } {
		cout << "MOVE-CONSTR Person " << name << '\n';
	}
};

int main(int argc, char* argv[])
{
	string s{ "sname" };
	Person p1{ s }; // Calls TMPL-CONSTR
	Person p2{ "tmp" }; // Calls TMPL-CONSTR

	// Person p3{ p1 };  // ERROR because according to the overload resolution
						 // rules of C++, for a non-constant lvalue Person p, 
						 // the member template is a better match than the
						 // copy constructor.

	Person p4{ move(p1) };

	Person const p2c{ "ctmp" }; // A const Person object.
	Person p3c{ p2c }; // Correctly calls the COPY_CONSTR
	return 0;
}