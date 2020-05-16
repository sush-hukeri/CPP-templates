/*
For historical reasons, the keyword "class" can 
be used instead of "typename" to define the type parameter.
*/
template<typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}