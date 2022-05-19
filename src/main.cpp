#include "../container/vector.hpp"
#include "../container/map.hpp"
#include "../utils/red_black_tree.hpp"

#include <map>

#define TESTED_TYPE			std::string
#define TESTED_NAMESPACE	ft

#define TEST1	0
#define TEST2	0
#define TEST3	0
#define TEST4	0
#define TEST5	0
#define TEST6	0
#define TEST7	0
#define TEST8	1

int	main()
{
	// ft::RBTree<int, char> tree;
	
	// tree.insert(ft::make_pair(0, 'b'));
	// tree.insert(ft::make_pair(10, 'g'));
	// tree.insert(ft::make_pair(5, 'x'));
	// tree.insert(ft::make_pair(20, 'k'));
	// tree.insert(ft::make_pair(3, 'b'));
	// tree.insert(ft::make_pair(8, 'e'));
	// tree.insert(ft::make_pair(15, 'i'));
	// tree.insert(ft::make_pair(25, 'm'));
	// tree.insert(ft::make_pair(4, 'c'));
	// tree.insert(ft::make_pair(7, 'd'));
	// tree.insert(ft::make_pair(9, 'f'));
	// tree.insert(ft::make_pair(12, 'h'));
	// tree.insert(ft::make_pair(17, 'j'));
	// tree.insert(ft::make_pair(21, 'l'));
	// tree.insert(ft::make_pair(30, 'n'));

	// tree.print_rb_tree("", tree.getRoot(), false);
	// std::cout << std::endl;

	#if TEST1
	{
		ft::RBTree<int, char>::iterator	it = tree.begin();

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
		ft::RBTree<int, char>::iterator	start = tree.begin();
		ft::RBTree<int, char>::iterator	end = tree.end();

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
		ft::RBTree<int, char>::reverse_iterator	rbegin = tree.rbegin();

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


		ft::RBTree<int, char>::reverse_iterator	copy = rbegin;
		LOG_RED(std::endl << copy->first << "\t|\t" << copy->second);
		LOG_RED(rbegin->first << "\t|\t" << rbegin->second);
	}
	#endif

	#if TEST4
	{
		ft::RBTree<int, char>::reverse_iterator	rbegin = tree.rbegin();
		ft::RBTree<int, char>::reverse_iterator	rend = tree.rend();

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
		ft::RBTree<int, char>::const_iterator	begin = tree.begin();
		ft::RBTree<int, char>::const_iterator	end = tree.end();

		for ( ; begin != end; begin++)
			LOG_RED(begin->first << " | " << begin->second);

		begin = tree.begin();
		std::cout << std::endl;

		--end;
		for ( ; end != begin; end--)
			LOG_BLUE(end->first << " | " << end->second);
		LOG_BLUE(end->first << " | " << end->second);

		// end->first = 42;

	}
	#endif

	#if TEST6
	{
		ft::RBTree<int, char>::const_reverse_iterator	rbegin = tree.rbegin();
		ft::RBTree<int, char>::const_reverse_iterator	rend = tree.rend();

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

	#if TEST7
	{
		const ft::RBTree<int, char> test2(tree);

		ft::RBTree<int,char>::const_iterator start_const = test2.begin();
		ft::RBTree<int,char>::const_iterator end_const = test2.end();


		for ( ; start_const != end_const; start_const++) {
			LOG_RED(start_const->first << " | " << start_const->second);
		}

		start_const = test2.begin();
		std::cout << std::endl;

		--end_const;
		for ( ; end_const != start_const; end_const--)
			LOG_BLUE(end_const->first << " | " << end_const->second);
		LOG_BLUE(end_const->first << " | " << end_const->second);

	}
	#endif

	#if TEST8
	{
		ft::map<int, char>	mp;

		mp.insert(ft::make_pair<int, char>(42, 'a'));
		mp.insert(ft::make_pair<int, char>(1, 'a'));
		mp.insert(ft::make_pair<int, char>(4, 'a'));
		mp.insert(ft::make_pair<int, char>(88, 'a'));
		mp.insert(ft::make_pair<int, char>(89, 'a'));
		mp.print();

		ft::map<int, char>::iterator	it = mp.begin();
		LOG_RED(it->first);
		LOG_RED(it->second);
		LOG_RED((++it)->first);
		LOG_RED(it->second);
		LOG_RED((++it)->first);
		LOG_RED(it->second);
		LOG_RED((++it)->first);
		LOG_RED(it->second);
		LOG_RED((++it)->first);
		LOG_RED(it->second);
	}
	#endif

	return 0;
}
