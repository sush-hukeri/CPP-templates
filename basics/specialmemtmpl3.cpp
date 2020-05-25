// Example of a template that uses enable_if and is_convertible.
#include <iostream>
#include <string>
#include <utility>
#include <type_traits>

using namespace std;

class Person
{
private:
	string name;
public:
	// Generic constructor for pased initial name:
	template<typename T, typename = enable_if_t<is_convertible_v<T, string>>>
	Person(T&& n) : name{ forward<T>(n) } {
		cout << "TMPL-CONSTR for " << name << '\n';
	}
	// The above template is called only if the passed template argument T
	// is a std::string or a type convertible to std::string.
	// The template is ignored if T is not convertible to type std::string.

	// Copy constructor
	Person(Person const& p) : name{ p.name } {
		cout << "COPY-CONSTR Person " << name << '\n';
	}
	
	// Move constructor
	Person(Person&& p) : name{ move(p.name) } {
		cout << "MOVE-CONSTR Person " << name << '\n';
	}
};

int main(int argc, char* argv[])
{
	string s{ "sname" };
	Person p1{ s };       // Calls TMPL-CONSTR
	Person p2{ "tmp" };	  // Calls TMPL-CONSTR
	Person p3{ p1 };      // Calls COPY-CONSTR. Fixes the error in specialmemtmpl2.cpp
	Person p4{ move(p1) }; // Calls MOVE-CONSTR
	return 0;
}