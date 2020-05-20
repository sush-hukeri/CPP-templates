#pragma once
#include <vector>
#include <iterator>
#include <iostream>

template<typename T>
class Stack
{
private:
	std::vector<T> elems;
public:
	Stack() = default;
	Stack(T const& elem) : elems{ elem } {} // Initialize stack with one element.
	bool empty() const { return elems.empty(); }

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, Stack<U> const& s);
};

template<typename U>
std::ostream& operator<<(std::ostream& os, Stack<U> const& s)
{
	copy(s.elems.cbegin(), s.elems.cend(),
		std::ostream_iterator<U const&>{os, " "});
	return os;
}