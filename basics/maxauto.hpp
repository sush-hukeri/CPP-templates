// The actual return type is deduced from the return statement(s).
template<typename T1, typename T2>
auto max(T1 a, T2 b)
{
	return b < a ? a : b;
}