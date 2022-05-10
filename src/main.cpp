#include "../inc/vector.hpp"

#define TESTED_NAMESPACE ft

#define INSERT	1

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
	// insert single element
	#if INSERT
	{
		TESTED_NAMESPACE::vector<int>	vec1;

		vec1.reserve(11);

		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl << std::endl;

		std::cout << std::endl << "TEST1" << std::endl << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	pos = vec1.end();
		pos -= 4;
		LOG_RED("pos:\t" << *pos);
		LOG_GREEN("ret:\t" << *(vec1.insert(pos, 69)));
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;

		std::cout << std::endl << "TEST2	" << std::endl << std::endl;
		LOG_GREEN("ret:\t" << *(vec1.insert(vec1.end(), 42)));
		LOG_GREEN("ret:\t" << *(vec1.insert(vec1.end(), 99)));
		LOG_GREEN("ret:\t" << *(vec1.insert(--vec1.end(), 102)));
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;

	}
	#endif
	return 0;
}
