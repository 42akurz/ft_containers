#include "../container/vector.hpp"
#include "../container/map.hpp"
#include "../utils/red_black_tree.hpp"

#include <map>

#define TESTED_TYPE			std::string
#define TESTED_NAMESPACE	ft

/* START tree tests --------------- */
#define TEST1	0
#define TEST2	0
#define TEST3	0
#define TEST4	0
#define TEST5	0
#define TEST6	0
#define TEST7	0
/* END tree tests ----------------- */

/* START map tests ---------------- */
#define TEST8	0 /* insert single element */
#define TEST9	0 /* insert range */
#define TEST10	0 /* swap */
#define TEST11	0 /* find and bounds */
#define TEST12	1 /* erase */
/* END map tests ------------------ */

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

	/* insert single element */
	#if TEST8
	{
		ft::map<int, char>	mp;

		mp.insert(ft::make_pair<int, char>(42, 'a'));
		mp.insert(ft::make_pair<int, char>(1, 'a'));
		mp.insert(ft::make_pair<int, char>(4, 'a'));
		mp.insert(ft::make_pair<int, char>(88, 'a'));
		mp.insert(ft::make_pair<int, char>(89, 'a'));
		mp.print();

		ft::pair<ft::map<int, char>::iterator, bool>	ret1 = mp.insert(ft::make_pair<int, char>(42, 'b'));
		ft::pair<ft::map<int, char>::iterator, bool>	ret2 = mp.insert(ft::make_pair<int, char>(43, 'x'));
		LOG_RED("[" << ret1.first->first << ", " << ret1.first->second << "] | " << ret1.second);
		LOG_GREEN("[" << ret2.first->first << ", " << ret2.first->second << "] | " << ret2.second);
		mp.print();
	}
	#endif

	/* insert range */
	#if TEST9
	{
		ft::map<int, char>	mp;
		ft::map<int, char>	mp2;

		mp.insert(ft::make_pair<int, char>(42, 'a'));
		mp.insert(ft::make_pair<int, char>(1, 'a'));
		mp.insert(ft::make_pair<int, char>(4, 'a'));
		mp.insert(ft::make_pair<int, char>(88, 'a'));
		mp.insert(ft::make_pair<int, char>(89, 'a'));
		mp.print();

		std::cout << std::endl;

		mp2.insert(mp.begin(), mp.end());
		mp2.print();

		const ft::map<int, char>	mp3;
		ft::map<int, char>			mp4;

		ft::map<int, char>::const_iterator				citb = mp3.begin();
		ft::map<int, char>::const_iterator				cite = mp3.end();
		ft::map<int, char>::const_reverse_iterator		critb = mp3.rbegin();
		ft::map<int, char>::const_reverse_iterator		crite = mp3.rend();
		ft::map<int, char>::const_iterator				citb2 = mp4.begin();
		ft::map<int, char>::const_iterator				cite2 = mp4.end();
		ft::map<int, char>::const_reverse_iterator		critb2 = mp4.rbegin();
		ft::map<int, char>::const_reverse_iterator		crite2 = mp4.rend();
	}
	#endif

	/* swap */
	#if TEST10
	{
		ft::map<int, char>	mp;
		ft::map<int, char>	mp2;

		mp.insert(ft::make_pair<int, char>(42, 'a'));
		mp.insert(ft::make_pair<int, char>(1, 'a'));
		mp.insert(ft::make_pair<int, char>(4, 'a'));
		mp.insert(ft::make_pair<int, char>(88, 'a'));
		mp.insert(ft::make_pair<int, char>(89, 'a'));
		mp.print();

		std::cout << std::endl;

		ft::map<int, char>::iterator end = mp.end();
		end--;
		end--;
		end--;

		mp2.insert(mp.begin(), end);
		mp2.print();

		mp.swap(mp2);

		std::cout << std::endl;
		mp.print();
		std::cout << std::endl;
		mp2.print();
	}
	#endif

	/* find and bounds */
	#if TEST11
	{
		ft::map<int, char>	mp;

		mp.insert(ft::make_pair<int, char>(42, 'c'));
		mp.insert(ft::make_pair<int, char>(1, 'a'));
		mp.insert(ft::make_pair<int, char>(4, 'b'));
		mp.insert(ft::make_pair<int, char>(88, 'd'));
		mp.insert(ft::make_pair<int, char>(89, 'e'));

		ft::map<int, char>::iterator	it1 = mp.find(4);
		LOG_CYAN(it1->first << " | " << it1->second);

		ft::map<int, char>::iterator	it2 = mp.find(89);
		LOG_CYAN(it2->first << " | " << it2->second);

		ft::map<int, char>::iterator	it3 = mp.find(102);
		LOG_CYAN((it3 == mp.end()));

		ft::map<int, char>::iterator	it4 = mp.upper_bound(86);
		LOG_RED(it4->first << " | " << it4->second);

		ft::map<int, char>::iterator	it5 = mp.lower_bound(1);
		LOG_RED(it5->first << " | " << it5->second);

		LOG_PINK(mp[42]);


	}
	#endif

	/* erase */
	#if TEST12
	{
		ft::map<int, char>	mp;

		mp.insert(ft::make_pair<int, char>(42, 'c'));
		mp.insert(ft::make_pair<int, char>(1, 'a'));
		mp.insert(ft::make_pair<int, char>(4, 'b'));
		mp.insert(ft::make_pair<int, char>(88, 'd'));
		mp.insert(ft::make_pair<int, char>(89, 'e'));

		ft::map<int, char>::iterator b = mp.begin();
		ft::map<int, char>::iterator e = mp.end();

		b++;
		e--;

		ft::map<int, char>	mp2(b, e);

		LOG_BLUE("map ---------------------");
		mp.print();
		LOG_BLUE("-------------------------");
		// std::cout << std::endl;
		// LOG_RED("map2 --------------------");
		// mp2.print();
		// LOG_RED("-------------------------");

		// mp.swap(mp2);

		// LOG_GREEN("AFTER SWAP");
		// std::cout << std::endl;
		// LOG_BLUE("map ---------------------");
		// mp.print();
		// LOG_BLUE("-------------------------");
		// std::cout << std::endl;
		// LOG_RED("map2 --------------------");
		// mp2.print();
		// LOG_RED("-------------------------");

		// mp.erase(b);

		// mp.erase(mp.begin(), mp.end());

		mp.erase(43);

		std::cout << std::endl;
		LOG_GREEN("AFTER ERASE");
		LOG_BLUE("map ---------------------");
		mp.print();
		LOG_BLUE("-------------------------");
		// std::cout << std::endl;
		// LOG_RED("map2 --------------------");
		// mp2.print();
		// LOG_RED("-------------------------");
	}
	#endif
	return 0;
}
