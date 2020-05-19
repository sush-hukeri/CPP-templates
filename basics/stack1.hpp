#pragma once
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <iterator>

template<typename T>
class Stack
{
private:
	std::vector<T> elems;  // Elements of the stack.

public:
	void push(T const& elem);
	void pop();
	T const& top() const;
	bool empty() const { return elems.empty(); }

	/*
	We cannot use T as the template parameter again because this inner T will hide the outer T. Hence, we use U.
	*/
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, Stack<U> const& s);
};

template<typename T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);  // Append a copy of the passed elem.
}

template<typename T>
void Stack<T>::pop()
{
	assert(!empty());
	elems.pop_back();
}

template<typename T>
T const& Stack<T>::top() const
{
	assert(!empty());
	return elems.back();  // Return a copy of the last element.
}

template<typename U>
std::ostream& operator<<(std::ostream& os, Stack<U> const& s)
{
	copy(s.elems.cbegin(), s.elems.cend(),
		std::ostream_iterator<U const&>{os, " "});
	return os;
}