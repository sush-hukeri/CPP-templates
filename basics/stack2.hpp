#pragma once
#include "stack1.hpp"
#include <cassert>
#include <deque>
#include <string>
#include <iterator>
#include <algorithm>

using std::string;
using std::deque;
using std::ostream;
using std::ostream_iterator;

template<>
class Stack<string>
{
private:
	deque<string> elems;
public:
	void push(string const&);
	void pop();
	string const& top() const;
	bool empty() const { return elems.empty(); }
	friend ostream& operator<<(ostream&, Stack<string> const&);
};

void Stack<string>::push(string const& elem)
{
	std::cout << "In stack2.hpp.\n";
	elems.push_back(elem);
}

void Stack<string>::pop()
{
	assert(!empty());
	elems.pop_back();
}

string const& Stack<string>::top() const
{
	assert(!empty());
	return elems.back();
}

ostream& operator<<(ostream& os, Stack<string> const& s)
{
	os << "In stack2.hpp.\n";
	copy(s.elems.cbegin(), s.elems.cend(),
		ostream_iterator<string const&>{os, " "});
	return os;
}