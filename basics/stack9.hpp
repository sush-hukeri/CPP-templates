// Template with a template argument.
#include <deque>
#include <cassert>

template<typename T, template<typename Elem> class Cont = std::deque>
class Stack
{
private:
	Cont<T> elems;
public:
	void push(T const& t);
	void pop();
	T const& top() const;
	bool empty() const { return elems.empty(); }

	// Assign a stack of elements of type T2.
	template<typename T2, template<typename Elem2> class Cont2>
	Stack<T, Cont>& operator=(Stack<T2, Cont2> const& other);

	template<typename, template<typename> class>
	friend class Stack;
};

template<typename T, template<typename> class Cont>
void Stack<T, Cont>::push(T const& elem)
{
	elems.push_back(elem);
}

template<typename T, template<typename> class Cont>
void Stack<T, Cont>::pop()
{
	assert(!empty());
	elems.pop_back();
}

template<typename T, template<typename> class Cont>
T const& Stack<T, Cont>::top() const
{
	assert(!empty());
	return elems.back();
}

template<typename T, template<typename> class Cont>
  template<typename T2, template<typename> class Cont2>
Stack<T, Cont>& Stack<T, Cont>::operator=(Stack<T2, Cont2> const& other)
{
	elems.clear();
	elems.insert(elems.begin(), other.elems.begin(), other.elems.end());
	return *this;
}