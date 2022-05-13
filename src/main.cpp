#include "../inc/vector.hpp"

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

#define TESTED_TYPE			int
#define T_SIZE_TYPE			typename TESTED_NAMESPACE::vector<T>::size_type
#define TESTED_NAMESPACE	ft

#define THIRTYONE		1
#define THIRTYTWO		0
#define THIRTYTHREE		0

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
	#if THIRTYONE
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
	}
	#endif

	#if THIRTYTWO
	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);

		for (int i = 0; i < size; ++i)
			vct[i] = (i + 1) * 5;
		printSize(vct);

		std::cout << (it_ == it.base()) << std::endl;
		std::cout << (it_ == (it + 3).base()) << std::endl;

		// LOG_RED("it_:\t" << *it_);
		// LOG_RED("it:\t" << *it);
		// LOG_RED("it:\t" << *(it - 1));
		std::cout << *(it.base() + 1) << std::endl;
		std::cout << *(it - 3) << std::endl;
		std::cout << *(it - 3).base() << std::endl;
		it -= 3;
		std::cout << *it.base() << std::endl;

		std::cout << "TEST OFFSET" << std::endl;
		std::cout << *(it) << std::endl;
		std::cout << *(it).base() << std::endl;
		std::cout << *(it - 0) << std::endl;
		std::cout << *(it - 0).base() << std::endl;
		std::cout << *(it - 1).base() << std::endl;
	}
	#endif

	#if THIRTYTHREE
	{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(vct.rbegin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite(vct.rend());

	for (int i = 1; it != ite; ++i)
		*it++ = (i * 7);
	printSize(vct, 1);

	it = vct.rbegin();
	ite = vct.rbegin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	it->m();
	ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	(*it).m();
	(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;

	}
	#endif
	return 0;
}
