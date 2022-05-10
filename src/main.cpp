#include "../inc/vector.hpp"

#define TESTED_NAMESPACE ft

#define THIRTYONE		1 // insert range

template <typename T>
void	printVectorContent( TESTED_NAMESPACE::vector<T> & vector ) {
	std::cout << std::endl;
	typename TESTED_NAMESPACE::vector<T>::iterator	it;
	for (it = vector.begin(); it != vector.end(); it++) {
		LOG_CYAN(*it);
	}
	std::cout << std::endl;
}

int	main( void )
{
	// 
	#if THIRTYONE
	{
		TESTED_NAMESPACE::vector<int>	vec1;
		TESTED_NAMESPACE::vector<int>	vec2;
		vec1.reserve(11);
		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl << std::endl;
		for (size_t i = 100; i <= 110; i++)
			vec2.push_back(i);
		printVectorContent(vec2);
		std::cout << "size:\t\t" << vec2.size() << std::endl;
		std::cout << "capacity:\t" << vec2.capacity() << std::endl << std::endl;

		std::cout << std::endl << "TEST1" << std::endl << std::endl;
	}
	#endif

	return 0;
}
