#include "vector_tests.hpp"

#define ONE			1 // push_back
#define TWO			1 // reserve
#define THREE		1 // reserve more tests
#define FOUR		1 // clear
#define FIVE		1 // get_allocator
#define SIX			1 // pop_back
#define SEVEN		1 // resize
#define EIGHT		1 // resize more tests
#define NINE		1 // member swap
#define ELEVEN		1 // operator[]
#define TWELVE		1 // operator=
#define FOURTEEN	1 // non member operators (==) (!=)
#define FIVETEEN	1 // non member operators (<) (<=)
#define SIXTEEN		1 // non member operators (>) (>=)
#define SEVENTEEN	1 // non member swap
#define EIGHTEEN	1 // it operators
#define TWENTY		1 // assign range
#define TWENTYONE	1 // assign fill
#define TWENTYTWO	1 // iterator tests
#define TWENTYTHREE	1 // more iterator tests
#define TWENTYFOUR	1 // assign
#define TWENTYFIVE	1 // erase
#define TWENTYSIX	1 // erase 2
#define TWENTYSEVEN	1 // erase 3
#define TWENTYEIGHT	1 // insert single element
#define TWENTYNINE	1 // insert fill
#define THIRTY		1 // insert range

int	main( void )
{
	// push_back
	#if ONE
	{
		std::cout << std::endl << "ONE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec(5, 1);

		printVectorContent(vec);

		std::cout << std::endl;
		std::cout << "size:		" << vec.size() << std::endl;
		std::cout << "max_size:	" << vec.max_size() << std::endl;
		std::cout << "empty:		" << vec.empty() << std::endl;
		std::cout << "capacity:	" << vec.capacity() << std::endl;

		vec.push_back(42);
		vec.push_back(43);
		vec.push_back(44);

		printVectorContent(vec);

		std::cout << std::endl;
		std::cout << "size:		" << vec.size() << std::endl;
		std::cout << "max_size:	" << vec.max_size() << std::endl;
		std::cout << "empty:		" << vec.empty() << std::endl;
		std::cout << "capacity:	" << vec.capacity() << std::endl;
	}
	#endif

	// reserve
	#if TWO
	{
		std::cout << std::endl << "TWO" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec(5, 1);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;

		vec.reserve(10);

		std::cout << std::endl;

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;
	}
	#endif

	// testing reserve and reserve exceptions TODO: not finished
	#if THREE
	{
		std::cout << std::endl << "THREE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec;

		for (size_t i = 0; i < 5; i++)
			vec.push_back(i);

		printVectorContent(vec);

		try
		{
			vec.reserve(-0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	#endif

	// clear
	#if FOUR
	{
		std::cout << std::endl << "FOUR" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec;

		for (size_t i = 0; i < 5; i++)
			vec.push_back(i);

		printVectorContent(vec);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;

		vec.clear();

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;

		for (size_t i = 0; i < 5; i++)
			vec.push_back(i);

		printVectorContent(vec);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;
	}
	#endif

	// get_allocator
	#if FIVE
	{
		std::cout << std::endl << "FIVE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec;

		for (size_t i = 0; i < 5; i++)
			vec.push_back(i);

		printVectorContent(vec);

		std::allocator<int>	vecA = vec.get_allocator();

		int	*vecP = vecA.allocate(5);

		for (int i = 0; i < 5; i++)
			vecA.construct(&vecP[i], i + 10);
		for (int i = 0; i < 5; i++)
			std::cout << vecP[i] << std::endl;
		printVectorContent(vec);
	}
	#endif

	// pop_back
	#if SIX
	{
		std::cout << std::endl << "SIX" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec;

		for (size_t i = 0; i < 5; i++)
			vec.push_back(i);

		printVectorContent(vec);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;

		vec.pop_back();
		std::cout << std::endl << "AFTER POP" << std::endl;

		printVectorContent(vec);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;
	}
	#endif

	// resize 
	#if SEVEN
	{
		std::cout << std::endl << "SEVEN" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec;

		for (size_t i = 0; i < 16; i++)
			vec.push_back(i);

		printVectorContent(vec);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;

		vec.resize(44);

		std::cout << std::endl << "AFTER RESIZE" << std::endl;

		printVectorContent(vec);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;
	}
	#endif

	// resize more tests
	#if EIGHT
	{
		std::cout << std::endl << "EIGHT" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec(5);

		for (size_t i = 0; i < 5; i++)
			vec.at(i) = i;

		printVectorContent(vec);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;

		vec.resize(18, 42);

		std::cout << std::endl << "AFTER RESIZE" << std::endl;

		printVectorContent(vec);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;
	}
	#endif

	// member swap
	#if NINE
	{
		std::cout << std::endl << "NINE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;
		TESTED_NAMESPACE::vector<int>	vec2;

		for (size_t i = 0; i < 21; i++) {
			vec1.push_back(i);
			if (i < 12)
				vec2.push_back(i + 10);
		}

		printVectorContent(vec1);
		printVectorContent(vec2);

		std::cout << "size\t\t" << vec1.size() << std::endl;
		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		std::cout << "size\t\t" << vec2.size() << std::endl;
		std::cout << "capacity\t" << vec2.capacity() << std::endl;

		vec1.swap(vec2);

		printVectorContent(vec1);
		printVectorContent(vec2);

		std::cout << "size\t\t" << vec1.size() << std::endl;
		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		std::cout << "size\t\t" << vec2.size() << std::endl;
		std::cout << "capacity\t" << vec2.capacity() << std::endl;
	}
	#endif

	// operator[]
	#if ELEVEN
	{
		std::cout << std::endl << "ELEVEN" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec(5);

		for (size_t i = 0; i < 5; i++)
			vec[i] = i;

		printVectorContent(vec);

		std::cout << "size\t\t" << vec.size() << std::endl;
		std::cout << "capacity\t" << vec.capacity() << std::endl;

		std::cout << std::endl << "PRINT VALUES" << std::endl << std::endl;

		for (int i = 0; i < 5; i++)
			std::cout << "vec["<< i << "]\t" << vec[i] << std::endl;
	}
	#endif

	// operator=
	#if TWELVE
	{
		std::cout << std::endl << "TWELVE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;
		TESTED_NAMESPACE::vector<int>	vec2;

		vec1.reserve(33);
		vec2.reserve(12);

		for (size_t i = 0; i < 21; i++) {
			vec1.push_back(i);
			if (i < 12)
				vec2.push_back(i + 10);
		}

		printVectorContent(vec1);
		printVectorContent(vec2);

		std::cout << "size\t\t" << vec1.size() << std::endl;
		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		std::cout << "size\t\t" << vec2.size() << std::endl;
		std::cout << "capacity\t" << vec2.capacity() << std::endl;

		vec2 = vec1;
		// vec1 = vec2;

		std::cout << std::endl << "AFTER ASSIGN" << std::endl << std::endl;
		
		printVectorContent(vec1);
		printVectorContent(vec2);

		std::cout << "size\t\t" << vec1.size() << std::endl;
		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		std::cout << "size\t\t" << vec2.size() << std::endl;
		std::cout << "capacity\t" << vec2.capacity() << std::endl;
	}
	#endif

	// non member operators (==) (!=)
	#if FOURTEEN
	{
		std::cout << std::endl << "FOURTEEN" << std::endl;
		TESTED_NAMESPACE::vector<int>	real1;
		TESTED_NAMESPACE::vector<int>	real2;

		// TEST1
		std::cout << std::endl << "TEST1" << std::endl;
		for (size_t i = 0; i < 10; i++)
			real1.push_back(i);
		for (size_t i = 0; i < 10; i++)
			real2.push_back(i + 10);
		std::cout << (real1 == real2) << std::endl;
		std::cout << (real1 != real2) << std::endl;

		// TEST2
		std::cout << std::endl << "TEST2" << std::endl;
		real1.clear();
		real2.clear();
		for (size_t i = 0; i < 10; i++)
			real1.push_back(i);
		for (size_t i = 0; i < 10; i++)
			real2.push_back(i);
		printVectorContent(real1);
		printVectorContent(real2);
		std::cout << "size1\t\t" << real1.size() << std::endl;
		std::cout << "capacity1\t" << real1.capacity() << std::endl;
		std::cout << "size2\t\t" << real2.size() << std::endl;
		std::cout << "capacity2\t" << real2.capacity() << std::endl;
		std::cout << (real1 == real2) << std::endl;
		std::cout << (real1 != real2) << std::endl;

		// TEST3
		std::cout << std::endl << "TEST3" << std::endl;
		real1.resize(9);
		std::cout << (real1 == real2) << std::endl;
		std::cout << (real1 != real2) << std::endl;

		// TEST4
		std::cout << std::endl << "TEST4" << std::endl;
		real2.resize(9);
		std::cout << (real1 == real2) << std::endl;
		std::cout << (real1 != real2) << std::endl;

		// TEST5
		std::cout << std::endl << "TEST5" << std::endl;
		real2.resize(15);
		std::cout << (real1 == real2) << std::endl;
		std::cout << (real1 != real2) << std::endl;

		// TEST6
		std::cout << std::endl << "TEST6" << std::endl;
		real1.resize(15);
		std::cout << (real1 == real2) << std::endl;
		std::cout << (real1 != real2) << std::endl;
	}
	#endif

	// non member operators (<) (<=)
	#if FIVETEEN
	{
		std::cout << std::endl << "FIVETEEN" << std::endl;
		TESTED_NAMESPACE::vector<std::string>	real1;
		TESTED_NAMESPACE::vector<std::string>	real2;

		real1.push_back("a");
		real1.push_back("b");
		real1.push_back("cdfvdf");
		real1.push_back("ddvdfv");
		real1.push_back("c");

		real2.push_back("a");
		real2.push_back("b");
		real2.push_back("cdfvdf");
		real2.push_back("ddvdfv");
		real2.push_back("c");

		// TEST1
		std::cout << std::endl << "TEST1" << std::endl;
		printVectorContent(real1);
		printVectorContent(real2);
		std::cout << (real1 <= real2) << std::endl;
		std::cout << (real1 < real2) << std::endl;

		// TEST2
		std::cout << std::endl << "TEST2" << std::endl;
		real1.pop_back();
		printVectorContent(real1);
		printVectorContent(real2);
		std::cout << (real1 <= real2) << std::endl;
		std::cout << (real1 < real2) << std::endl;

		// TEST3
		std::cout << std::endl << "TEST3" << std::endl;
		real1.push_back("b");
		printVectorContent(real1);
		printVectorContent(real2);
		std::cout << (real1 <= real2) << std::endl;
		std::cout << (real1 < real2) << std::endl;

		// TEST4
		std::cout << std::endl << "TEST4" << std::endl;
		real1.pop_back();
		real1.push_back("d");
		printVectorContent(real1);
		printVectorContent(real2);
		std::cout << (real1 <= real2) << std::endl;
		std::cout << (real1 < real2) << std::endl;
	}
	#endif

	// non member operators (>) (>=)
	#if SIXTEEN
	{
		std::cout << std::endl << "SIXTEEN" << std::endl;
		TESTED_NAMESPACE::vector<std::string>	real1;
		TESTED_NAMESPACE::vector<std::string>	real2;

		real1.push_back("a");
		real1.push_back("b");
		real1.push_back("cdfvdf");
		real1.push_back("ddvdfv");
		real1.push_back("c");

		real2.push_back("a");
		real2.push_back("b");
		real2.push_back("cdfvdf");
		real2.push_back("ddvdfv");
		real2.push_back("c");

		// TEST1
		std::cout << std::endl << "TEST1" << std::endl;
		printVectorContent(real1);
		printVectorContent(real2);
		std::cout << (real1 >= real2) << std::endl;
		std::cout << (real1 > real2) << std::endl;

		// TEST2
		std::cout << std::endl << "TEST2" << std::endl;
		real1.pop_back();
		printVectorContent(real1);
		printVectorContent(real2);
		std::cout << (real1 >= real2) << std::endl;
		std::cout << (real1 > real2) << std::endl;

		// TEST3
		std::cout << std::endl << "TEST3" << std::endl;
		real1.push_back("b");
		printVectorContent(real1);
		printVectorContent(real2);
		std::cout << (real1 >= real2) << std::endl;
		std::cout << (real1 > real2) << std::endl;

		// TEST4
		std::cout << std::endl << "TEST4" << std::endl;
		real1.pop_back();
		real1.push_back("d");
		printVectorContent(real1);
		printVectorContent(real2);
		std::cout << (real1 >= real2) << std::endl;
		std::cout << (real1 > real2) << std::endl;
	}
	#endif

	// non member swap
	#if SEVENTEEN
	{
		std::cout << std::endl << "SEVENTEEN" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;
		TESTED_NAMESPACE::vector<int>	vec2;

		for (size_t i = 0; i < 21; i++) {
			vec1.push_back(i);
			if (i < 12) {
				vec2.push_back(i + 10);
			}
		}

		printVectorContent(vec1);
		std::cout << "size\t\t" << vec1.size() << std::endl;
		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		printVectorContent(vec2);
		std::cout << "size\t\t" << vec2.size() << std::endl;
		std::cout << "capacity\t" << vec2.capacity() << std::endl;

		swap(vec1, vec2);

		std::cout << std::endl << "AFTER SWAP" << std::endl << std::endl;

		printVectorContent(vec1);
		std::cout << "size\t\t" << vec1.size() << std::endl;
		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		printVectorContent(vec2);
		std::cout << "size\t\t" << vec2.size() << std::endl;
		std::cout << "capacity\t" << vec2.capacity() << std::endl;
	}
	#endif

	// it operators
	#if EIGHTEEN
	{
		std::cout << std::endl << "EIGHTEEN" << std::endl;
		TESTED_NAMESPACE::vector<int>	rVec(5, 42);
	
		rVec.push_back(10);

		printVectorContent(rVec);

		TESTED_NAMESPACE::vector<int>::iterator	it2 = rVec.begin();

		std::cout << *it2 << std::endl;
		++it2;
		std::cout << *it2 << std::endl;
		++it2;
		std::cout << *it2 << std::endl;
		++it2;
		std::cout << *it2 << std::endl;
		++it2;
		std::cout << *it2 << std::endl;
		++it2;
		std::cout << *it2 << std::endl;

		TESTED_NAMESPACE::vector<int>::iterator	itend = rVec.end();
		std::cout << *(--itend) << std::endl;

	}
	#endif

	// assign range
	#if TWENTY
	{
		std::cout << std::endl << "TWENTY" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;
		TESTED_NAMESPACE::vector<int>	vec2(20, 42);

		for (size_t i = 0; i < 30; i += 3)
			vec1.push_back(i);

		printVectorContent(vec1);
		printVectorContent(vec2);

		vec2.assign((++vec1.begin()), (--vec1.end()));

		std::cout << "AFTER ASSIGN" << std::endl;

		printVectorContent(vec1);
		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		std::cout << "size\t\t" << vec1.size() << std::endl;
		printVectorContent(vec2);
		std::cout << "capacity\t" << vec2.capacity() << std::endl;
		std::cout << "size\t\t" << vec2.size() << std::endl;
	}
	#endif

	// assign fill
	#if TWENTYONE
	{
		std::cout << std::endl << "TWENTYONE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1(5, 42);

		printVectorContent(vec1);

		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		std::cout << "size\t\t" << vec1.size() << std::endl;

		vec1.assign((TESTED_NAMESPACE::vector<int>::size_type)0, (TESTED_NAMESPACE::vector<int>::value_type)69); // TODO: fix this issue

		std::cout << "AFTER ASSIGN" << std::endl;

		printVectorContent(vec1);

		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		std::cout << "size\t\t" << vec1.size() << std::endl;
	}
	#endif

	// iterator tests
	#if TWENTYTWO
	{
		std::cout << std::endl << "TWENTYTWO" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;

		for (size_t i = 0; i < 33; i++) {
			vec1.push_back(i);
		}

		printVectorContent(vec1);
		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		std::cout << "size\t\t" << vec1.size() << std::endl;
		

		TESTED_NAMESPACE::vector<int>::iterator	it1 = vec1.begin();
		TESTED_NAMESPACE::vector<int>::iterator	it2 = vec1.begin();

		std::cout << std::endl << "TEST1" << std::endl;
		std::cout << (it1 == it2) << std::endl;
		std::cout << (it1 != it2) << std::endl;
		std::cout << (it1 <= it2) << std::endl;
		std::cout << (it1 >= it2) << std::endl;
		std::cout << (it1 < it2) << std::endl;
		std::cout << (it1 > it2) << std::endl;

		it1 += 1;
		it2++;

		std::cout << std::endl << "TEST2" << std::endl;
		std::cout << (it1 == it2) << std::endl;
		std::cout << (it1 != it2) << std::endl;
		std::cout << (it1 <= it2) << std::endl;
		std::cout << (it1 >= it2) << std::endl;
		std::cout << (it1 < it2) << std::endl;
		std::cout << (it1 > it2) << std::endl;

		it2 += 1;

		std::cout << std::endl << "TEST3" << std::endl;
		std::cout << (it1 == it2) << std::endl;
		std::cout << (it1 != it2) << std::endl;
		std::cout << (it1 <= it2) << std::endl;
		std::cout << (it1 >= it2) << std::endl;
		std::cout << (it1 < it2) << std::endl;
		std::cout << (it1 > it2) << std::endl;

		std::cout << std::endl << "TEST4" << std::endl;
		std::cout << it2 - it1 << std::endl;
		std::cout << *(it2 + 5) << std::endl;
		std::cout << *(it2 - 1) << std::endl;

		std::cout << std::endl << "TEST5" << std::endl;
		std::cout << *(++it1) << std::endl;
		std::cout << *(it1++) << std::endl;
		std::cout << *(it1) << std::endl;
		std::cout << (it1 == it2) << std::endl;
		std::cout << (it1 != it2) << std::endl;
		std::cout << (it1 <= it2) << std::endl;
		std::cout << (it1 >= it2) << std::endl;
		std::cout << (it1 < it2) << std::endl;
		std::cout << (it1 > it2) << std::endl;

		std::cout << std::endl << "TEST6" << std::endl;
		it2 += 5;
		std::cout << *(--it2) << std::endl;
		std::cout << *(it2--) << std::endl;
		std::cout << *(it2) << std::endl;
		std::cout << *(--it2) << std::endl;
		std::cout << *(--it2) << std::endl;
		
		std::cout << std::endl << "TEST7" << std::endl;
		std::cout << (it1 == it2) << std::endl;
		std::cout << (it1 != it2) << std::endl;
		std::cout << (it1 <= it2) << std::endl;
		std::cout << (it1 >= it2) << std::endl;
		std::cout << (it1 < it2) << std::endl;
		std::cout << (it1 > it2) << std::endl;

		std::cout << std::endl << "TEST8" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec2(18, 42);
		TESTED_NAMESPACE::vector<int>::iterator	it3 = vec2.begin();
		std::cout << (it1 == it3) << std::endl;
		std::cout << (it1 != it3) << std::endl;
		std::cout << (it1 <= it3) << std::endl;
		std::cout << (it1 >= it3) << std::endl;
		std::cout << (it1 < it3) << std::endl;
		std::cout << (it1 > it3) << std::endl;

		std::cout << std::endl << "TEST9" << std::endl;
		it3 = vec2.end();
		std::cout << (it1 == it3) << std::endl;
		std::cout << (it1 != it3) << std::endl;
		std::cout << (it1 <= it3) << std::endl;
		std::cout << (it1 >= it3) << std::endl;
		std::cout << (it1 < it3) << std::endl;
		std::cout << (it1 > it3) << std::endl;

		std::cout << std::endl << "TEST10" << std::endl;
		std::cout << *(--(vec1.end())) << std::endl;
	}
	#endif

	// more iterator tests
	#if TWENTYTHREE
	{
		std::cout << std::endl << "TWENTYTHREE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;

		for (size_t i = 0; i < 33; i++) {
			vec1.push_back(i);
		}

		printVectorContent(vec1);
		std::cout << "capacity\t" << vec1.capacity() << std::endl;
		std::cout << "size\t\t" << vec1.size() << std::endl;
		

		TESTED_NAMESPACE::vector<int>::iterator	it1 = vec1.begin();
		TESTED_NAMESPACE::vector<int>::iterator	it2 = vec1.end();

		std::cout << std::endl << "TEST1" << std::endl;
		std::cout << *(it1) << std::endl;
		std::cout << *(--it2) << std::endl;

		std::cout << std::endl << "TEST2" << std::endl;
		std::cout << it1[9] << std::endl;
		std::cout << it1[32] << std::endl;
		it1[0] = 42;
		std::cout << it1[0] << std::endl;
		std::cout << *it1 << std::endl;
		std::cout << *(it1 += 1) << std::endl;
	}
	#endif

	// assign
	#if TWENTYFOUR
	{
		std::cout << std::endl << "TWENTYFOUR" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;

		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);

		TESTED_NAMESPACE::vector<int>	vec2;
		TESTED_NAMESPACE::vector<int>::iterator	it1 = vec1.begin();
		TESTED_NAMESPACE::vector<int>::iterator	it2 = vec1.end();

		it2--;
		it2--;
		it2--;

		vec2.assign(it1, it2);
		printVectorContent(vec2);

		vec2.assign(10, 42);
		printVectorContent(vec2);
	}
	#endif

	// erase
	#if TWENTYFIVE
	{
		std::cout << std::endl << "TWENTYFIVE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;
		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	pos = vec1.end();
		pos--;
		std::cout << "pos:\t\t" << *pos << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	ret = vec1.erase(pos);
		std::cout << std::endl << "AFTER ERASE" << std::endl;
		printVectorContent(vec1);
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "return:\t\t" << (*(--ret)) << std::endl;
	}
	#endif

	// erase 2
	#if TWENTYSIX
	{
		std::cout << std::endl << "TWENTYSIX" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;

		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	pos1 = vec1.begin();
		TESTED_NAMESPACE::vector<int>::iterator	pos2 = vec1.end();
		pos1++;
		pos2--;
		pos2--;
		pos2--;
		std::cout << "pos1:\t\t" << *pos1 << std::endl;
		std::cout << "pos2:\t\t" << *pos2 << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	ret = vec1.erase(pos1, pos2);
		std::cout << std::endl << "AFTER ERASE" << std::endl;
		printVectorContent(vec1);
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "return:\t\t" << (*ret) << std::endl;
	}
	#endif
	
	// erase 3
	#if TWENTYSEVEN
	{
		std::cout << std::endl << "TWENTYSEVEN" << std::endl;
		std::cout << std::endl << "TEST1" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;
		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	pos1 = vec1.end();
		TESTED_NAMESPACE::vector<int>::iterator	pos2 = vec1.end();
		pos2--;
		pos2--;
		pos2--;
		std::cout << "pos1:\t" << *(pos1 - 1) << std::endl;
		std::cout << "pos2:\t" << *pos2 << std::endl;
		std::cout << "ret:\t" << ((vec1.erase(pos2, pos1)) == vec1.end()) << std::endl;
		std::cout << std::endl << "AFTER ERASE:" << std::endl;
		printVectorContent(vec1);
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;
		std::cout << "size:\t\t" << vec1.size() << std::endl;


		std::cout << std::endl << "TEST2" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec2;
		for (size_t i = 0; i <= 30; i += 3)
			vec2.push_back(i);
		printVectorContent(vec2);
		std::cout << "capacity:\t" << vec2.capacity() << std::endl;
		std::cout << "size:\t\t" << vec2.size() << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	pos3 = vec2.end();
		TESTED_NAMESPACE::vector<int>::iterator	pos4 = vec2.end();
		pos4--;
		pos4--;
		pos4--;
		pos3--;
		std::cout << "pos3:\t" << *pos3 << std::endl;
		std::cout << "pos4:\t" << *pos4 << std::endl;
		std::cout << "ret:\t" << *(vec2.erase(pos4, pos3)) << std::endl;
		std::cout << std::endl << "AFTER ERASE:" << std::endl;
		printVectorContent(vec2);
		std::cout << "capacity:\t" << vec2.capacity() << std::endl;
		std::cout << "size:\t\t" << vec2.size() << std::endl;


		std::cout << std::endl << "TEST3" << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	sheesh1 = vec2.begin();
		TESTED_NAMESPACE::vector<int>::iterator	sheesh2 = vec2.end();
		std::cout << "ret:\t" << *(vec2.erase(sheesh1, sheesh2)) << std::endl;
		std::cout << std::endl << "AFTER ERASE:" << std::endl;
		printVectorContent(vec2);
		std::cout << "capacity:\t" << vec2.capacity() << std::endl;
		std::cout << "size:\t\t" << vec2.size() << std::endl;


		std::cout << std::endl << "TEST4" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec3;
		for (size_t i = 0; i <= 30; i += 3)
			vec3.push_back(i);
		printVectorContent(vec3);
		std::cout << "capacity:\t" << vec3.capacity() << std::endl;
		std::cout << "size:\t\t" << vec3.size() << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	pos5 = vec3.begin();
		TESTED_NAMESPACE::vector<int>::iterator	pos6 = vec3.end();
		--pos6;
		--pos6;
		std::cout << "pos5:\t" << *pos5 << std::endl;
		std::cout << "pos6:\t" << *pos6 << std::endl;
		std::cout << "ret:\t" << *(vec3.erase(pos5, pos6)) << std::endl;
		std::cout << std::endl << "AFTER ERASE:" << std::endl;
		printVectorContent(vec3);
		std::cout << "capacity:\t" << vec3.capacity() << std::endl;
		std::cout << "size:\t\t" << vec3.size() << std::endl;
	}
	#endif

	// insert single element
	#if TWENTYEIGHT
	{
		std::cout << std::endl << "TWENTYEIGHT" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;
		vec1.reserve(11);
		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl << std::endl;

		std::cout << std::endl << "TEST1" << std::endl << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	pos = vec1.end();
		pos -= 4;
		std::cout << "pos:\t" << *pos << std::endl;
		std::cout << "ret:\t" << *(vec1.insert(pos, 69)) << std::endl;
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;

		std::cout << std::endl << "TEST2	" << std::endl << std::endl;
		std::cout << "ret:\t" << *(vec1.insert(vec1.end(), 42)) << std::endl;
		std::cout << "ret:\t" << *(vec1.insert(vec1.end(), 99)) << std::endl;
		std::cout << "ret:\t" << *(vec1.insert(--vec1.end(), 102)) << std::endl;
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;
	}
	#endif

	// insert fill
	#if TWENTYNINE
	{
		std::cout << std::endl << "TWENTYNINE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;
		vec1.reserve(11);
		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl << std::endl;

		std::cout << std::endl << "TEST1" << std::endl << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	pos = vec1.end();
		--pos;
		--pos;
		--pos;
		std::cout << "pos:\t" << *pos << std::endl;
		vec1.insert(pos, 5, 69);
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;

		std::cout << std::endl << "TEST2" << std::endl << std::endl;
		vec1.insert(vec1.begin(), 5, 69);
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;

		std::cout << std::endl << "TEST3" << std::endl << std::endl;
		vec1.insert(vec1.end(), 3, 102);
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;

		std::cout << std::endl << "TEST4" << std::endl << std::endl;
		vec1.insert(--(vec1.end()), 2, 99);
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;
	}
	#endif

	// insert range
	#if THIRTY
	{
		std::cout << std::endl << "THIRTY" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1;
		TESTED_NAMESPACE::vector<int>	vec2;
		vec1.reserve(11);
		for (size_t i = 0; i <= 30; i += 3)
			vec1.push_back(i);
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl << std::endl;
		for (size_t i = 100; i <= 110; i++)
			vec2.push_back(i);
		printVectorContent(vec2);
		std::cout << "size:\t\t" << vec2.size() << std::endl;
		std::cout << "capacity:\t" << vec2.capacity() << std::endl << std::endl;

		std::cout << std::endl << "TEST1" << std::endl << std::endl;
		TESTED_NAMESPACE::vector<int>::iterator	where = (vec1.end() - 4);
		std::cout << "where:\t" << *where << std::endl;
		vec1.insert(where, vec2.begin(), vec2.end());
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;

		std::cout << std::endl << "TEST2" << std::endl << std::endl;
		std::cout << "where:\t" << *where << std::endl;
		vec1.insert(vec1.end(), vec2.begin(), vec2.end());
		vec1.insert(vec1.begin(), vec2.begin(), vec2.end());
		std::cout << std::endl << "AFTER INSERT" << std::endl;
		printVectorContent(vec1);
		std::cout << "size:\t\t" << vec1.size() << std::endl;
		std::cout << "capacity:\t" << vec1.capacity() << std::endl;
	}
	#endif

	return 0;
}
