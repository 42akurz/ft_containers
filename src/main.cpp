#include "../container/vector.hpp"
#include "../container/map.hpp"
#include "../utils/red_black_tree.hpp"

#define TESTED_TYPE			std::string
#define TESTED_NAMESPACE	ft

#define TEST1	0
#define TEST2	0
#define TEST3	0
#define TEST4	1
#define TEST5	0

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

	tree.print_rb_tree("", tree.getRoot(), false);
	std::cout << std::endl;

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

		std::cout << std::endl;

		LOG_CYAN((rbegin++)->first << "\t|\t" << rbegin->second);
		LOG_CYAN((rbegin)->first << "\t|\t" << rbegin->second);
		LOG_CYAN((++rbegin)->first << "\t|\t" << rbegin->second);

		std::cout << std::endl;

		LOG_CYAN((rbegin--)->first << "\t|\t" << rbegin->second);
		LOG_CYAN((rbegin)->first << "\t|\t" << rbegin->second);
		LOG_CYAN((--rbegin)->first << "\t|\t" << rbegin->second);


		ft::RBTree<ft::pair<int, char> >::reverse_iterator	copy = rbegin;
		LOG_RED(std::endl << copy->first << "\t|\t" << copy->second);
		LOG_RED(rbegin->first << "\t|\t" << rbegin->second);
	}
	#endif

	#if TEST4
	{
		ft::RBTree<ft::pair<int, char> >::reverse_iterator	rbegin = tree.rbegin();
		ft::RBTree<ft::pair<int, char> >::reverse_iterator	rend = tree.rend();

		for ( ; rbegin != rend; rbegin++)
			LOG_RED(rbegin->first << "\t|\t" << rbegin->second);

		rbegin = tree.rbegin();
		std::cout << std::endl;

		--rend;
		for ( ; rend != rbegin; rend--)
			LOG_BLUE(rend->first << "\t|\t" << rend->second);
		LOG_BLUE(rend->first << "\t|\t" << rend->second);
	}
	#endif

	#if TEST5
	{
		ft::RBTree<const ft::pair<int, char> >::const_iterator	begin = tree.begin();
		ft::RBTree<const ft::pair<int, char> >::const_iterator	end = tree.end();

		for ( ; begin != end; begin++)
			LOG_RED(begin->first << "\t|\t" << begin->second);

		begin = tree.begin();
		std::cout << std::endl;

		--end;
		for ( ; end != begin; end--)
			LOG_BLUE(end->first << "\t|\t" << end->second);
		LOG_BLUE(end->first << "\t|\t" << end->second);

		end->first = 42;

		LOG_BLUE(end->first << "\t|\t" << end->second);
	}
	#endif

	return 0;
}
