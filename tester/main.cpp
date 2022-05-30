/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:47:05 by julian            #+#    #+#             */
/*   Updated: 2022/05/30 12:16:52 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>

#include "../container/vector.hpp"
#include "../container/stack.hpp"
#include "../container/map.hpp"

#include <sys/time.h>
#include <iomanip>
#include <fstream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"

#define NAMESPACE ft
// #ifdef STD
// # undef NAMESPACE
// # define NAMESPACE std
// #endif

// functions for map & set
bool fncomp (char lhs, char rhs) {return lhs<rhs;}
bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp
{
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

struct classcomp2
{
	bool operator() (const int& lhs, const int& rhs) const
	{return lhs<rhs;}
};

int main()
{
	struct timespec startMap, endMap;
	struct timespec timeStart, timeEnd;
	double timePerformance = timeStart.tv_sec * 1e9;

		// start timer.
	clock_gettime(CLOCK_MONOTONIC, &startMap);

	std::cout << GREEN << "\n***************************" << std::endl;
	std::cout          <<   "*           MAP           *" << std::endl;
	std::cout          <<   "***************************" << RESET << std::endl;

	std::cout << YELLOW << "\nmap::map\n" << RESET;

	NAMESPACE::map<char,int> mfirst;
	mfirst['a']=10;
	mfirst['b']=30;
	mfirst['c']=50;
	mfirst['d']=70;
	NAMESPACE::map<char,int> msecond (mfirst.begin(),mfirst.end());
	NAMESPACE::map<char,int> mthird (msecond);
	NAMESPACE::map<char,int,classcomp> mfourth;                 // class as Compare
	bool(*fn_pt)(char,char) = fncomp;
	NAMESPACE::map<char,int,bool(*)(char,char)> mfifth (fn_pt);
	for (NAMESPACE::map<char, int>::iterator mit = mthird.begin(); mit != mthird.end(); ++mit)
		std::cout << mit->first << " => " << mit->second << '\n';

	std::cout << YELLOW << "\nmap::operator=\n" << RESET;

	NAMESPACE::map<char,int> mfirst2;
	NAMESPACE::map<char,int> msecond2;
	mfirst2['x']=8;
	mfirst2['y']=16;
	mfirst2['z']=32;
	msecond2=mfirst2;                // second now contains 3 ints
	mfirst2=NAMESPACE::map<char,int>();    // and first is now empty
	std::cout << "Size of mfirst2: " << mfirst2.size() << '\n';
	std::cout << "Size of msecond2: " << msecond2.size() << '\n';

	std::cout << YELLOW << "\nmap::begin | map::end\n" << RESET;

	NAMESPACE::map<char,int> mymap;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	// show content:
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << YELLOW << "\nmap::rbegin | map::rend\n" << RESET;

	NAMESPACE::map<char,int> mymap2;
	mymap2['x'] = 100;
	mymap2['y'] = 200;
	mymap2['z'] = 300;
	// show content:
	NAMESPACE::map<char,int>::reverse_iterator mrit;
	for (mrit=mymap2.rbegin(); mrit!=mymap2.rend(); ++mrit)
		std::cout << mrit->first << " => " << mrit->second << '\n';

	std::cout << YELLOW << "\nmap::empty\n" << RESET;

	NAMESPACE::map<char,int> mymap3;
	mymap3['a']=10;
	mymap3['b']=20;
	mymap3['c']=30;
	while (!mymap3.empty())
	{
		std::cout << mymap3.begin()->first << " => " << mymap3.begin()->second << '\n';
		mymap3.erase(mymap3.begin());
	}

	std::cout << YELLOW << "\nmap::size\n" << RESET;

	NAMESPACE::map<char,int> mymap4;
	mymap4['a']=101;
	mymap4['b']=202;
	mymap4['c']=302;
	std::cout << "mymap4.size() is " << mymap4.size() << '\n';

	std::cout << YELLOW << "\nmap::max_size\n" << RESET;

	NAMESPACE::map<int,int> mymap5;
	if (mymap5.max_size()>1000)
	{
		for (int i=0; i<1000; i++) mymap5[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";

	std::cout << YELLOW << "\nmap::operator[]\n" << RESET;

	NAMESPACE::map<char,std::string> mymap6;
	mymap6['a']="an element";
	mymap6['b']="another element";
	mymap6['c']=mymap6['b'];
	std::cout << "mymap6['a'] is " << mymap6['a'] << '\n';
	std::cout << "mymap6['b'] is " << mymap6['b'] << '\n';
	std::cout << "mymap6['c'] is " << mymap6['c'] << '\n';
	std::cout << "mymap6['d'] is " << mymap6['d'] << '\n';
	std::cout << "mymap6 now contains " << mymap6.size() << " elements.\n";

	std::cout << YELLOW << "\nmap::insert\n" << RESET;

	NAMESPACE::map<char,int> mymap7;
	// first insert function version (single parameter):
	mymap7.insert ( NAMESPACE::pair<char,int>('a',100) );
	mymap7.insert ( NAMESPACE::pair<char,int>('z',200) );
	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,bool> ret;
	ret = mymap7.insert ( NAMESPACE::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}
	// second insert function version (with hint position):
	NAMESPACE::map<char,int>::iterator mit7 = mymap7.begin();
	mymap7.insert (mit7, NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
	mymap7.insert (mit7, NAMESPACE::pair<char,int>('c',400));  // no max efficiency inserting
	// third insert function version (range insertion):
	NAMESPACE::map<char,int> anothermap;
	anothermap.insert(mymap7.begin(),mymap7.find('c'));
	// showing contents:
	std::cout << "mymap7 contains:\n";
	for (mit7=mymap7.begin(); mit7!=mymap7.end(); ++mit7)
		std::cout << mit7->first << " => " << mit7->second << '\n';
	std::cout << "anothermap contains:\n";
	for (mit7=anothermap.begin(); mit7!=anothermap.end(); ++mit7)
		std::cout << mit7->first << " => " << mit7->second << '\n';

	std::cout << YELLOW << "\nmap::erase\n" << RESET;

	NAMESPACE::map<char,int> mymap8;
	NAMESPACE::map<char,int>::iterator mit8;
	// insert some values:
	mymap8['a']=10;
	mymap8['b']=20;
	mymap8['c']=30;
	mymap8['d']=40;
	mymap8['e']=50;
	mymap8['f']=60;
	mit8=mymap8.find('b');
	mymap8.erase (mit8);                   // erasing by iterator
	mymap8.erase ('c');                  // erasing by key
	mit8=mymap8.find ('e');
	mymap8.erase ( mit8, mymap8.end() );    // erasing by range
	// show content:
	for (mit8=mymap8.begin(); mit8!=mymap8.end(); ++mit8)
		std::cout << mit8->first << " => " << mit8->second << '\n';

	std::cout << YELLOW << "\nmap::swap\n" << RESET;

	NAMESPACE::map<char,int> mfoo;
	NAMESPACE::map<char,int> mbar;
	mfoo['x']=100;
	mfoo['y']=200;
	mbar['a']=11;
	mbar['b']=22;
	mbar['c']=33;
	std::cout << "mfoo contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=mfoo.begin(); it!=mfoo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "mbar contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=mbar.begin(); it!=mbar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\nswapping\n\n";
	mfoo.swap(mbar);
	std::cout << "mfoo contains:\n";
	LOG("END");
	for (NAMESPACE::map<char,int>::iterator it=mfoo.begin(); it!=mfoo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	LOG("END");
	std::cout << "mbar contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=mbar.begin(); it!=mbar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << YELLOW << "\nmap::clear\n" << RESET;

	NAMESPACE::map<char,int> mymap9;
	mymap9['x']=100;
	mymap9['y']=200;
	mymap9['z']=300;
	std::cout << "mymap9 contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=mymap9.begin(); it!=mymap9.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	mymap9.clear();
	mymap9['a']=1101;
	mymap9['b']=2202;
	std::cout << "mymap9 contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=mymap9.begin(); it!=mymap9.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << YELLOW << "\nmap::key_comp\n" << RESET;

	NAMESPACE::map<char,int> mymap10;
	NAMESPACE::map<char,int>::key_compare mycomp = mymap10.key_comp();
	mymap10['a']=100;
	mymap10['b']=200;
	mymap10['c']=300;
	std::cout << "mymap10 contains:\n";
	char highest = mymap10.rbegin()->first;     // key value of last element
	NAMESPACE::map<char,int>::iterator mit10 = mymap10.begin();
	do {
		std::cout << mit10->first << " => " << mit10->second << '\n';
	} while ( mycomp((*mit10++).first, highest) );
	std::cout << '\n';

	std::cout << YELLOW << "\nmap::value_comp\n" << RESET;

	NAMESPACE::map<char,int> mymap11;
	mymap11['x']=1001;
	mymap11['y']=2002;
	mymap11['z']=3003;
	std::cout << "mymap11 contains:\n";
	NAMESPACE::pair<char,int> highest2 = *mymap11.rbegin();          // last element
	NAMESPACE::map<char,int>::iterator mit11 = mymap11.begin();
	do {
		std::cout << mit11->first << " => " << mit11->second << '\n';
	} while ( mymap11.value_comp()(*mit11++, highest2) );

	std::cout << YELLOW << "\nmap::find\n" << RESET;

	NAMESPACE::map<char,int> mymap12;
	NAMESPACE::map<char,int>::iterator mit12;
	mymap12['a']=50;
	mymap12['b']=100;
	mymap12['c']=150;
	mymap12['d']=200;
	mit12 = mymap12.find('b');
	if (mit12 != mymap12.end())
		mymap12.erase (mit12);
	// print content:
	std::cout << "elements in mymap12:" << '\n';
	std::cout << "a => " << mymap12.find('a')->second << '\n';
	std::cout << "c => " << mymap12.find('c')->second << '\n';
	std::cout << "d => " << mymap12.find('d')->second << '\n';

	std::cout << YELLOW << "\nmap::count\n" << RESET;

	NAMESPACE::map<char,int> mymap13;
	char c;
	mymap13 ['a']=101;
	mymap13 ['c']=202;
	mymap13 ['f']=303;
	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap13.count(c)>0)
			std::cout << " is an element of mymap13.\n";
		else
			std::cout << " is not an element of mymap13.\n";
	}

	std::cout << YELLOW << "\nmap::lower_bound | map::upper_bound\n" << RESET;

	NAMESPACE::map<char,int> mymap14;
	NAMESPACE::map<char,int>::iterator itlow;
	NAMESPACE::map<char,int>::iterator itup;
	mymap14['a']=20;
	mymap14['b']=40;
	mymap14['c']=60;
	mymap14['d']=80;
	mymap14['e']=100;
	itlow=mymap14.lower_bound ('b');  // itlow points to b
	itup=mymap14.upper_bound ('d');   // itup points to e (not d!)
	mymap14.erase(itlow,itup);        // erases [itlow,itup)
	// print content:
	for (NAMESPACE::map<char,int>::iterator it=mymap14.begin(); it!=mymap14.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << YELLOW << "\nmap::equal_range\n" << RESET;

	NAMESPACE::map<char,int> mymap15;
	mymap15['a']=10;
	mymap15['b']=20;
	mymap15['c']=30;
	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> mret2;
	mret2 = mymap15.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << mret2.first->first << " => " << mret2.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << mret2.second->first << " => " << mret2.second->second << '\n';

	std::cout << YELLOW << "\nmap::get_allocator\n" << RESET;

	int psize;
	NAMESPACE::map<char,int> mymap16;
	NAMESPACE::pair<const char,int>* p;
	// allocate an array of 5 elements using mymap16's allocator:
	p=mymap16.get_allocator().allocate(5);
	// assign some values to array
	psize = sizeof(NAMESPACE::map<char,int>::value_type)*5;
	std::cout << "The allocated array has a size of " << psize << " bytes.\n";
	mymap16.get_allocator().deallocate(p,5);

	std::cout << YELLOW << "\nrelational operators (map)\n" << RESET;

	NAMESPACE::map<int, char> malice;
	malice.insert ( NAMESPACE::pair<int,char>(1,'a') );
	malice.insert ( NAMESPACE::pair<int,char>(2,'b') );
	malice.insert ( NAMESPACE::pair<int,char>(3,'c') );
	NAMESPACE::map<int, char> mbob;
	mbob.insert ( NAMESPACE::pair<int,char>(7,'Z') );
	mbob.insert ( NAMESPACE::pair<int,char>(8,'Y') );
	mbob.insert ( NAMESPACE::pair<int,char>(9,'X') );
	mbob.insert ( NAMESPACE::pair<int,char>(10,'W') );
	NAMESPACE::map<int, char> meve;
	meve.insert ( NAMESPACE::pair<int,char>(1,'a') );
	meve.insert ( NAMESPACE::pair<int,char>(2,'b') );
	meve.insert ( NAMESPACE::pair<int,char>(3,'c') );
	std::cout << std::boolalpha;
	// Compare non equal containers
	std::cout << "malice == mbob returns " << (malice == mbob) << '\n';
	std::cout << "malice != mbob returns " << (malice != mbob) << '\n';
	std::cout << "malice <  mbob returns " << (malice < mbob) << '\n';
	std::cout << "malice <= mbob returns " << (malice <= mbob) << '\n';
	std::cout << "malice >  mbob returns " << (malice > mbob) << '\n';
	std::cout << "malice >= mbob returns " << (malice >= mbob) << '\n';
	std::cout << '\n';
	// Compare equal containers
	std::cout << "malice == meve returns " << (malice == meve) << '\n';
	std::cout << "malice != meve returns " << (malice != meve) << '\n';
	std::cout << "malice <  meve returns " << (malice < meve) << '\n';
	std::cout << "malice <= meve returns " << (malice <= meve) << '\n';
	std::cout << "malice >  meve returns " << (malice > meve) << '\n';
	std::cout << "malice >= meve returns " << (malice >= meve) << '\n';
	std::cout << std::noboolalpha;

	std::cout << YELLOW << "\nswap (map)\n" << RESET;

	NAMESPACE::map<int, char> malice2;
	malice2.insert ( NAMESPACE::pair<int,char>(1,'a') );
	malice2.insert ( NAMESPACE::pair<int,char>(2,'b') );
	malice2.insert ( NAMESPACE::pair<int,char>(3,'c') );
	NAMESPACE::map<int, char> mbob2;
	mbob2.insert ( NAMESPACE::pair<int,char>(7,'Z') );
	mbob2.insert ( NAMESPACE::pair<int,char>(8,'Y') );
	mbob2.insert ( NAMESPACE::pair<int,char>(9,'X') );
	mbob2.insert ( NAMESPACE::pair<int,char>(10,'W') );
	// Print state before swap
	std::cout << "malice2:\n";
	for (NAMESPACE::map<int,char>::iterator it=malice2.begin(); it!=malice2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n" "mbob2:\n";
	for (NAMESPACE::map<int,char>::iterator it=mbob2.begin(); it!=mbob2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n-- SWAP\n\n";
	std::swap(malice2, mbob2);
	// Print state after swap
	std::cout << "malice2:\n";
	for (NAMESPACE::map<int,char>::iterator it=malice2.begin(); it!=malice2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n" "mbob2:\n";
	for (NAMESPACE::map<int,char>::iterator it=mbob2.begin(); it!=mbob2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << YELLOW << "\nperformance map\n" << RESET;
	std::cout << "inserting and deleting lots of elements\n";

	// start timer
	clock_gettime(CLOCK_MONOTONIC, &timeStart);
	NAMESPACE::map<int, std::string> perfM;
	for (size_t i = 0; i < 10000000; ++i)
			perfM.insert(NAMESPACE::make_pair<int, std::string>(std::rand() % 1000000, "performance: " + std::to_string(i)));
	// std::cout << "Map perfM.size() = " << perfM.size() << std::endl;
	NAMESPACE::map<int, std::string> perfM2(perfM);
	// std::cout << "Map perfM2.size() = " << perfM2.size() << std::endl;
	NAMESPACE::map<int, std::string> perfM3(perfM2.begin(), perfM2.end());
	// std::cout << "Map perfM3.size() = " << perfM3.size() << std::endl;
	perfM.erase(perfM.begin(), perfM.end());
	// std::cout << "Map perfM.size() = " << perfM.size() << std::endl;

	// end timer
	clock_gettime(CLOCK_MONOTONIC, &timeEnd);
	timePerformance = timeStart.tv_sec * 1e9;
	timePerformance = (timeEnd.tv_sec - timeStart.tv_sec) * 1e9;
	timePerformance = (timePerformance + (timeEnd.tv_nsec - timeStart.tv_nsec)) * 1e-9;
	std::cout << "Map performance test: " <<  timePerformance << "sec.\n";

	std::cout << YELLOW << "\nleaks map\n" << RESET;

	#ifdef STD
		system("leaks std_container | tail -3");
	#else
		system("leaks ft_container | tail -3");
	#endif

	clock_gettime(CLOCK_MONOTONIC, &endMap);


/* ------------------------------------------------------------------------------------------------------------------ */

	double time_takenMap;
	time_takenMap = (endMap.tv_sec - startMap.tv_sec) * 1e9;
	time_takenMap = (time_takenMap + (endMap.tv_nsec - startMap.tv_nsec)) * 1e-9;
	#ifdef STD
	std::cout << CYAN << "Time taken by program for STD_MAP    is " << std::fixed << std::setprecision(9) << time_takenMap;
	#else
	std::cout << CYAN << "Time taken by program for FT_MAP    is " << std::fixed << std::setprecision(9) << time_takenMap;
	#endif
	std::cout << " sec" << std::endl << RESET;

	return (0);
}