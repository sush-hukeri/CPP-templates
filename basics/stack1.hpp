#include <vector>
#include <cassert>

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