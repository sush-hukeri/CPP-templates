#pragma once
#include <vector>

// Class template with default value for a parameter.
template<typename T, typename Cont = std::vector<T>>
class Stack
{
private:
	Cont elems;
public:
	void push(T const& elem);
	void pop();
	T const& top() const;
	bool empty() const { return elems.empty(); }
};

template<typename T, typename Cont>
void Stack<T, Cont>::push(T const& elem)
{
	Cont.push_back(elem);  // Append a copy of the passed elem
}

// Definition of the remaining methods similar to that in stack1.hpp.