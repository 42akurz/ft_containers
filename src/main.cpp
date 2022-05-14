#include "../container/vector.hpp"

#define TESTED_TYPE			std::string
#define TESTED_NAMESPACE	ft

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

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

void	printVectorContent( TESTED_NAMESPACE::vector<TESTED_TYPE> vct ) {
	LOG_CYAN(std::endl << "My Vector -------");
	for (TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(); it != vct.end(); it++)
		LOG_CYAN(*it);
	LOG_CYAN("-----------------");
}

void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

int	main()
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printSize(vct);

	vct.erase(vct.begin() + 2);
	vct.erase(vct.begin());
	vct.erase(vct.end() - 1);

	printVectorContent(vct);

	LOG_RED("--------------------------");
	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	LOG_RED("--------------------------");
	// checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	// vct.push_back("Hello");
	// vct.push_back("Hi there");
	// printSize(vct);
	// checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	// vct.push_back("ONE");
	// vct.push_back("TWO");
	// vct.push_back("THREE");
	// vct.push_back("FOUR");
	// printSize(vct);
	// checkErase(vct, vct.erase(vct.begin(), vct.end()));


	// TESTED_NAMESPACE::vector<TESTED_TYPE>	vct;
	// for (int i = 0; i < 10; i++)
	// 	vct.push_back(i + 1);

	// TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator	first = (vct.begin() + 3);
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator	last = (vct.end() - 2);

	// LOG_GREEN("*first:\t" << *first);
	// LOG_GREEN("*last:\t" << *last);

	// printVectorContent(vct);
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator	ret = vct.erase(first, last);
	// printVectorContent(vct);
	// LOG_RED(*ret);

	return 0;
}
