#include "../inc/vector.hpp"

#define TESTED_NAMESPACE ft

#define ASSIGN	0
#define ERASE	0
#define ERASE_2	1

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
	#if ASSIGN
	{
		TESTED_NAMESPACE::vector<int>	vec1;

		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);

		TESTED_NAMESPACE::vector<int>	vec2;
		TESTED_NAMESPACE::vector<int>::iterator	it1 = vec1.begin();
		TESTED_NAMESPACE::vector<int>::iterator	it2 = vec1.end();

		it2--;
		it2--;
		it2--;

		vec2.assign(it1, it2);
		printVectorContent(vec2);

		vec2.assign(10, 42);
		printVectorContent(vec2);
	}
	#endif

	#if ERASE
	{
		TESTED_NAMESPACE::vector<int>	vec1;

		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		LOG_YELLOW("capacity:\t" << vec1.capacity());
		LOG_YELLOW("size:\t\t" << vec1.size());

		TESTED_NAMESPACE::vector<int>::iterator	pos = vec1.end();

		pos--;

		LOG_RED("pos:\t\t" << *pos);

		TESTED_NAMESPACE::vector<int>::iterator	ret = vec1.erase(pos);

		LOG_BLACK(std::endl << "AFTER ERASE");

		printVectorContent(vec1);
		LOG_YELLOW("capacity:\t" << vec1.capacity());
		LOG_YELLOW("size:\t\t" << vec1.size());

		LOG_GREEN("return:\t\t" << (*ret));
	}
	#endif

	#if ERASE_2
	{
		TESTED_NAMESPACE::vector<int>	vec1;

		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		LOG_YELLOW("capacity:\t" << vec1.capacity());
		LOG_YELLOW("size:\t\t" << vec1.size());

		TESTED_NAMESPACE::vector<int>::iterator	pos1 = vec1.begin();
		TESTED_NAMESPACE::vector<int>::iterator	pos2 = vec1.end();

		pos1++;
		pos2--;
		pos2--;
		pos2--;

		LOG_RED("pos1:\t\t" << *pos1);
		LOG_RED("pos2:\t\t" << *pos2);

		TESTED_NAMESPACE::vector<int>::iterator	ret = vec1.erase(pos1, pos2);

		// LOG_BLACK(std::endl << "AFTER ERASE");

		// printVectorContent(vec1);
		// LOG_YELLOW("capacity:\t" << vec1.capacity());
		// LOG_YELLOW("size:\t\t" << vec1.size());
		// LOG_GREEN("return:\t\t" << (*ret));

		system("leaks containers");
	}
	#endif
	
	return 0;
}
