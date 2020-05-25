#include <utility>
#include <string>
#include <iostream>

using namespace std;

class Person
{
private:
	string name;
public:
	explicit Person(string const& n) : name{ n } {
		cout << "Copying string-CONSTR for " << name << '\n';
	}

	explicit Person(string&& n) :name{ n } {
		cout << "Moving string-CONSTR for " << name << '\n';
	}

	//Copy constructor
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
	Person p1{ s };				 // Calls Copying string-CONSTR.
	Person p2{ "tmp" };			 // Calls Moving string-CONSTR.
	Person p3{ p1 };			 // Calls COPY-CONSTR.
	Person p4{ move(p1) };		 // Calls MOVE-CONSTR.
	Person p5{ Person{"temp"} }; // Same as p2.
	return 0;
}