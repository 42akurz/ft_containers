#include "../container/vector.hpp"
#include "../container/map.hpp"
#include "../utils/red_black_tree.hpp"
#include "../containers_test/srcs/base.hpp"

#include <map>
#include <list>

#define TESTED_NAMESPACE	ft


#define _pair TESTED_NAMESPACE::pair


#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

// static int iter = 0;

TESTED_NAMESPACE::map<T1, T2> mp;
TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.end();

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
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

void	ft_find(T1 const &k)
{
	TESTED_NAMESPACE::map<T1, T2>::iterator ret = mp.find(k);

	if (ret != it)
		printPair(ret);
	else
		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
}


int	main()
{
	// TESTED_NAMESPACE::map<T1, T2> mp1;
	// TESTED_NAMESPACE::map<T1, T2> mp2;

	// mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	// mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	// cmp(mp1, mp1); // 0
	// cmp(mp1, mp2); // 1

	// mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	// cmp(mp1, mp2); // 2
	// cmp(mp2, mp1); // 3

	// (++(++mp1.begin()))->second = 42;

	// for (TESTED_NAMESPACE::map<T1, T2>::iterator it = mp1.begin(); it != mp1.end(); it++)
	// 	LOG_RED(it->first << " | " << it->second);
	// LOG_RED("size: " << mp1.size() << std::endl);

	// for (TESTED_NAMESPACE::map<T1, T2>::iterator it = mp2.begin(); it != mp2.end(); it++)
	// 	LOG_GREEN(it->first << " | " << it->second);
	// LOG_GREEN("size: " << mp2.size() << std::endl);

	// cmp(mp1, mp2); // 4
	// cmp(mp2, mp1); // 5

	// swap(mp1, mp2);

	// cmp(mp1, mp2); // 6
	// cmp(mp2, mp1); // 7

	ft::map<int, int>	og1;
	ft::map<int, int>	og2;

	og1[1] = 10;
	og1[2] = 20;
	og1[3] = 30;
	og1[4] = 40;

	og2[1] = 10;
	og2[2] = 20;
	og2[3] = 30;
	og2[4] = 40;

	LOG_GREEN((og1 == og2));
	LOG_GREEN((og1 != og2));
	
	return 0;
}
