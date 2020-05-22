#pragma once
#include <deque>
#include <iterator>
#include <iostream>
#include <algorithm>

template<typename T, typename Cont = std::deque<T>>
class Stack
{
private:
	Cont elems;
public:
	void push(T const&);
	void pop();
	T const& top() const;
	bool empty() const { return elems.empty(); }

	// Assign a stack of elements of type T2
	template<typename T2, typename Cont2>
	Stack& operator=(Stack<T2, Cont2> const&);
	// To get access to the private members of Stack<T, Cont> for any type T2.
	template<typename, typename> friend class Stack;

	template<typename U, typename Cont2>
	friend std::ostream& operator<<(std::ostream& os, Stack<U, Cont2> const& s);
};

template<typename T, typename Cont>
void Stack<T, Cont>::push(const T& t)
{
	elems.push_back(t);
}

template<typename T, typename Cont>
void Stack<T, Cont>::pop()
{
	assert(!empty());
	elems.pop_back();
}

template<typename T, typename Cont>
T const& Stack<T, Cont>::top() const
{
	assert(!empty());
	return elems.back();  // Return a copy of the last element.
}

template<typename T, typename Cont>
 template<typename T2, typename Cont2>
 Stack<T, Cont>& Stack<T, Cont>::operator=(Stack<T2, Cont2> const& other)
 {
	 elems.clear();
	 elems.insert(elems.begin(), other.elems.cbegin(), other.elems.cend());
	 return *this;
}

template<typename U, typename Cont2>
std::ostream& operator<<(std::ostream& os, Stack<U, Cont2> const& s)
{
	std::copy(s.elems.cbegin(), s.elems.cend(),
		std::ostream_iterator<U const&>{os, " "});
	return os;
}