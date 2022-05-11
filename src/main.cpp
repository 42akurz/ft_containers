#include "../inc/vector.hpp"

#define TESTED_NAMESPACE std
#define TESTED_TYPE int

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

int	main( void )
{
	// insert 1
	#if THIRTYONE
	{
		LOG_RED("TEST1");
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		printSize(vct);

		vct2.insert(vct2.end(), 42);
		vct2.insert(vct2.begin(), 2, 21);
		printSize(vct2);

		vct2.insert(vct2.end() - 2, 42);
		printSize(vct2);

		vct2.insert(vct2.end(), 2, 84);
		printSize(vct2);

		vct2.resize(4);
		printSize(vct2);

		vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		vct.clear();
		printSize(vct2);

		printSize(vct);
	}
	#endif

	// insert 2
	#if THIRTYTWO
	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
		const int cut = 3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 7;
		printSize(vct);

		vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		printSize(vct2);
		vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		printSize(vct2);
		vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
		printSize(vct2);

		std::cout << "insert return:" << std::endl;

		std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
		std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
		std::cout << "----------------------------------------" << std::endl;

		printSize(vct2);
	}
	#endif


	return 0;
}
