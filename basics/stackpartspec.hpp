#include "stack1.hpp"

using std::vector;

template<typename T>
class Stack<T*>
{
private:
	vector<T*> elems;
public:
	void push(T*);
	T* pop();
	T* top() const;
	bool empty() const { return elems.empty(); }
};

void Stack<T>::push(T* elem)
{
	elems.push_back(elem);
}

T* Stack<T*>::pop()
{
	assert(!empty());
	T* p = elems.back();
	elems.pop_back(); // Remove last element.
	return p; // Return the last element(unlike in the general case).
}

T* Stack<T*>::top() const
{
	assert(!empty());
	return elems.back();
}