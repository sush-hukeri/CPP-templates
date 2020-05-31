// Example of perfect forwarding with std::invoke()
#include <utility>		// for std::invoke()
#include <functional>   // for std::forward()
#include <type_traits>  // for std::is_same<> and std::invoke_result<>

template<typename Callable, typename... Args>
decltype(auto) call(Callable&& op, Args&&... args)
{
	if constexpr(std::is_same_v<std::invoke_result_t<Callable, Args...>, void>) {
		// Return type is void.
		std::invoke(std::forward<Callable>(op), std::forward<Args>(args)...);
		return;
	}
	else {
		decltype(auto) ret{ std::invoke(std::forward<Callable>(op),
			std::forward<Args>(args)...) };
		return ret;
	}
}