#include <utility>
#include <functional>

template<typename Iter, typename Callable, typename... Args>
void foreach(Iter current, Iter end, Callable op, Args const&... args)
{
	while (current != end)
	{
		std::invoke(op,  // Call passed callable with
			args...,     // any additional args
			*current++); // and the current element.		
	}
}