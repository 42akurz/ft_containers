#include "../container/map.hpp"

#include <map>
#include <list>

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
#define TEST8	1 /* insert single element */
#define TEST9	1 /* insert range */
#define TEST10	1 /* swap */
#define TEST11	1 /* find and bounds */
#define TEST12	1 /* erase */
#define TEST13	1 /* copy construct / assign */
#define TEST14	1 /* insert hint */
#define TEST15	1 /* count */
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
		std::cout << std::endl;
		LOG_RED("map2 --------------------");
		mp2.print();
		LOG_RED("-------------------------");

		mp.erase(b);

		std::cout << std::endl;
		LOG_GREEN("AFTER ERASE");
		LOG_BLUE("map ---------------------");
		mp.print();
		LOG_BLUE("-------------------------");
		std::cout << std::endl;
		LOG_RED("map2 --------------------");
		mp2.print();
		LOG_RED("-------------------------");

		mp.erase(mp.begin(), mp.end());

		std::cout << std::endl;
		LOG_GREEN("AFTER ERASE");
		LOG_BLUE("map ---------------------");
		mp.print();
		LOG_BLUE("-------------------------");
		std::cout << std::endl;
		LOG_RED("map2 --------------------");
		mp2.print();
		LOG_RED("-------------------------");
	}
	#endif

	/* copy construct / assign */
	#if TEST13
	{
		ft::map<int, char>	mp;

		mp.insert(ft::make_pair<int, char>(42, 'c'));
		mp.insert(ft::make_pair<int, char>(1, 'a'));
		mp.insert(ft::make_pair<int, char>(4, 'b'));
		mp.insert(ft::make_pair<int, char>(88, 'd'));
		mp.insert(ft::make_pair<int, char>(89, 'e'));


		ft::map<int, char>	mp2(mp);

		LOG_GREEN("AFTER clear");
		LOG_BLUE("map ---------------------");
		mp.print();
		LOG_BLUE("-------------------------");
		std::cout << std::endl;
		LOG_RED("map2 --------------------");
		mp2.print();
		LOG_RED("-------------------------");

		mp.clear();

		std::cout << std::endl;
		LOG_GREEN("AFTER clear");
		LOG_BLUE("map ---------------------");
		mp.print();
		LOG_BLUE("-------------------------");
		std::cout << std::endl;
		LOG_RED("map2 --------------------");
		mp2.print();
		LOG_RED("-------------------------");
	}
	#endif

	/* insert hint */
	#if TEST14
	{
		ft::map<int, char>	mp;

		mp.insert(ft::make_pair(1, 'b'));
		mp.insert(ft::make_pair(10, 'g'));
		mp.insert(ft::make_pair(5, 'x'));
		mp.insert(ft::make_pair(20, 'k'));
		mp.insert(ft::make_pair(3, 'b'));
		mp.insert(ft::make_pair(8, 'e'));
		mp.insert(ft::make_pair(15, 'i'));
		mp.insert(ft::make_pair(25, 'm'));
		mp.insert(ft::make_pair(4, 'c'));
		mp.insert(ft::make_pair(6, 'd'));
		mp.insert(ft::make_pair(9, 'f'));
		mp.insert(ft::make_pair(12, 'h'));
		mp.insert(ft::make_pair(17, 'j'));
		mp.insert(ft::make_pair(21, 'l'));
		mp.insert(ft::make_pair(30, 'n'));

		mp.printTree();

		ft::map<int, char>::iterator	it = mp.find(17);
		mp.insert(it, ft::make_pair<int, char>(19, '5'));

		std::cout << std::endl;

		mp.printTree();
	}
	#endif

	/* count */
	#if TEST15
	{
		ft::map<int, char>	mp;

		mp.insert(ft::make_pair(1, 'b'));
		mp.insert(ft::make_pair(10, 'g'));
		mp.insert(ft::make_pair(5, 'x'));
		mp.insert(ft::make_pair(20, 'k'));
		mp.insert(ft::make_pair(3, 'b'));
		mp.insert(ft::make_pair(8, 'e'));
		mp.insert(ft::make_pair(15, 'i'));
		mp.insert(ft::make_pair(25, 'm'));
		mp.insert(ft::make_pair(4, 'c'));
		mp.insert(ft::make_pair(6, 'd'));
		mp.insert(ft::make_pair(9, 'f'));
		mp.insert(ft::make_pair(12, 'h'));
		mp.insert(ft::make_pair(17, 'j'));
		mp.insert(ft::make_pair(21, 'l'));
		mp.insert(ft::make_pair(30, 'n'));

		mp.printTree();

		LOG_GREEN(mp.count(42));
	}
	#endif

	return 0;
}