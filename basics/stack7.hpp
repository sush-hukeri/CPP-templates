#pragma once
#include <deque>
#include <iostream>

using std::deque;
using std::cout;

template<typename T, typename Cont = std::deque<T>>
class Stack
{
private:
	Cont elems;
public:
	void push(T const&);
	void pop();
	T const& top() const;
	bool empty() const return { elems.empty(); }

	template<typename T2, typename Cont2>
	Stack& operator=(Stack<T2, Cont2> other);

	template<typename, typename> friend class Stack;
};

template<typename T, typename Cont>
void Stack<T, Cont>::push(const T& t)
{
	elems.push_back(t);
}