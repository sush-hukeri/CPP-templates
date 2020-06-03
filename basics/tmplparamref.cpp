#include <iostream>

template<typename T>
void tmplParamIsReference(T)
{
	std::cout << "T is reference: " << std::is_reference_v<T> << '\n';
}

int main()
{
	std::cout << std::boolalpha;
	int i{ 3 };
	int& r{ i };
	
	tmplParamIsReference(i);
	tmplParamIsReference(r);  // False. Even if a reference variable is passed to the template,
							  // the template parameter T is deduced to the type of the referenced type.
							  // This is because, for a reference variable v, the expression v has the referenced type;
							  // the type of an epxression is never a reference.
	
	tmplParamIsReference<int&>(i);
	tmplParamIsReference<int&>(r);
	
	std::cout << std::endl;
}