#include "../inc/vector.hpp"

#define TESTED_TYPE			int
#define T_SIZE_TYPE			typename TESTED_NAMESPACE::vector<T>::size_type
#define TESTED_NAMESPACE	ft

#define THIRTYONE		1 // insert 1
#define THIRTYTWO		0 // insert 2

template <typename T>
void	printVectorContent( TESTED_NAMESPACE::vector<T> & vector ) {
	std::cout << std::endl;
	typename TESTED_NAMESPACE::vector<T>::iterator	it;
	for (it = vector.begin(); it != vector.end(); it++) {
		LOG_CYAN(*it);
	}
	std::cout << std::endl;
}

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{

	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

	for (size_t i = 0; i < 10; i++)
		vct[i] = i + 1;

	printVectorContent(vct);

	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator	rit = vct.rbegin();

	LOG_RED("--------- TEST1");
	LOG_RED(*rit);
	LOG_RED(*(++rit));
	LOG_RED(*(++rit));
	LOG_RED(*(++rit));

	LOG_YELLOW(std::endl << "--------- TEST2");
	LOG_YELLOW(*rit);
	LOG_YELLOW(*(rit++));
	LOG_YELLOW(*(rit++));
	LOG_YELLOW(*(rit++));
	LOG_YELLOW(*rit);

	LOG_GREEN(std::endl << "--------- TEST3");
	LOG_GREEN(rit[-1]);
	LOG_GREEN(rit[0]);
	LOG_GREEN(rit[1]);
	LOG_GREEN(rit[2]);

	LOG_PINK(std::endl << "--------- TEST4");
	LOG_PINK(*(rit - 1));
	LOG_PINK(*(rit + 0));
	LOG_PINK(*(rit + 1));
	LOG_PINK(*(rit + 2));

	return 0;
}
