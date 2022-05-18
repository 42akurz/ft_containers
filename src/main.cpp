#include "../container/vector.hpp"
#include "../container/map.hpp"
#include "../utils/red_black_tree.hpp"

#define TESTED_TYPE			std::string
#define TESTED_NAMESPACE	ft

#define TEST1	0
#define TEST2	0
#define TEST3	1

int	main()
{
	ft::RBTree<ft::pair<int, char> > tree;
	
	tree.insert(ft::make_pair(0, 'b'));
	tree.insert(ft::make_pair(10, 'g'));
	tree.insert(ft::make_pair(5, 'x'));
	tree.insert(ft::make_pair(20, 'k'));
	tree.insert(ft::make_pair(3, 'b'));
	tree.insert(ft::make_pair(8, 'e'));
	tree.insert(ft::make_pair(15, 'i'));
	tree.insert(ft::make_pair(25, 'm'));
	tree.insert(ft::make_pair(4, 'c'));
	tree.insert(ft::make_pair(7, 'd'));
	tree.insert(ft::make_pair(9, 'f'));
	tree.insert(ft::make_pair(12, 'h'));
	tree.insert(ft::make_pair(17, 'j'));
	tree.insert(ft::make_pair(21, 'l'));
	tree.insert(ft::make_pair(30, 'n'));

	#if TEST1
	{
		ft::RBTree<ft::pair<int, char> >::iterator	it = tree.begin();

		std::cout << it->first << "\t|\t" << it->second << std::endl;
		std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (++it)->first << "\t|\t" << it->second << std::endl;

		std::cout << std::endl;

		std::cout << it->first << "\t|\t" << it->second << std::endl;
		std::cout << (--it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (--it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (--it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (--it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (--it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (--it)->first << "\t|\t" << it->second << std::endl;
		std::cout << (--it)->first << "\t|\t" << it->second << std::endl;
	}
	#endif

	#if TEST2
	{
		ft::RBTree<ft::pair<int, char> >::iterator	start = tree.begin();
		ft::RBTree<ft::pair<int, char> >::iterator	end = tree.end();

		for ( ; start != end; start++)
			LOG_BLUE(start->first << "\t|\t" << start->second);
		
		start = tree.begin();
		std::cout << std::endl;

		for ( ; end != start; end--)
			LOG_RED(end->first << "\t|\t" << end->second);
		LOG_RED(end->first << "\t|\t" << end->second);
	}
	#endif

	#if TEST3
	{
		ft::RBTree<ft::pair<int, char> >::reverse_iterator	rbegin = tree.rbegin();

		LOG_CYAN(rbegin->first << "\t|\t" << rbegin->second);
		rbegin++;
		LOG_CYAN(rbegin->first << "\t|\t" << rbegin->second);
		rbegin++;
		LOG_CYAN(rbegin->first << "\t|\t" << rbegin->second);
		rbegin++;
		LOG_CYAN(rbegin->first << "\t|\t" << rbegin->second);
		rbegin++;
		LOG_CYAN(rbegin->first << "\t|\t" << rbegin->second);
		rbegin++;
		LOG_CYAN(rbegin->first << "\t|\t" << rbegin->second);
	}
	#endif

	return 0;
}
