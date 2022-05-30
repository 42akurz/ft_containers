#include "../container/vector.hpp"
#include "../container/map.hpp"
#include "../container/stack.hpp"
#include "../container/set.hpp"

#include <list>
#include <set>

#define TESTED_NAMESPACE	ft

// #define T1 int
// typedef TESTED_NAMESPACE::set<T1>::iterator ft_iterator;
// typedef TESTED_NAMESPACE::set<T1>::const_iterator ft_const_iterator;

static int iter = 0;

#define _pair TESTED_NAMESPACE::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << *iterator << " | value: " << *iterator;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

#define T1 int

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(lst_size - i);

	TESTED_NAMESPACE::set<T1> st(lst.begin(), lst.end());
	TESTED_NAMESPACE::set<T1>::iterator it = st.begin(), ite = st.end();

	TESTED_NAMESPACE::set<T1> st_range(it, --(--ite));
	for (int i = 0; i < 5; ++i)
		st.insert(i * 5);

	it = st.begin(); ite = --(--st.end());
	TESTED_NAMESPACE::set<T1> st_copy(st);
	for (int i = 0; i < 7; ++i)
		st.insert(i * 7);

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(st);
	printSize(st_range);
	printSize(st_copy);

	st = st_copy;
	st_copy = st_range;
	st_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(st);
	printSize(st_range);
	printSize(st_copy);
	(void)iter;
	return (0);
}
