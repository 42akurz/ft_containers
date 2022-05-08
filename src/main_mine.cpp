#include "../inc/vector.hpp"

#define TESTED_NAMESPACE ft

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

template <typename T>
void	printVectorContent( TESTED_NAMESPACE::vector<T> & vector ) {
	std::cout << std::endl;
	typename TESTED_NAMESPACE::vector<T>::iterator	it;
	for (it = vector.begin(); it != vector.end(); it++)
		std::cout << (*it) << std::endl;
	std::cout << std::endl;
}

int	main( void )
{
	// push_back
	#if ONE
	{
		std::cout << std::endl << "ONE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec(5, 1);

		printVectorContent(vec);

		LOG("");
		LOG_YELLOW("size:		" << vec.size());
		LOG_YELLOW("max_size:	" << vec.max_size());
		LOG_YELLOW("empty:		" << vec.empty());
		LOG_YELLOW("capacity:	" << vec.capacity());

		vec.push_back(42);
		vec.push_back(43);
		vec.push_back(44);

		printVectorContent(vec);

		LOG("");
		LOG_YELLOW("size:		" << vec.size());
		LOG_YELLOW("max_size:	" << vec.max_size());
		LOG_YELLOW("empty:		" << vec.empty());
		LOG_YELLOW("capacity:	" << vec.capacity());
	}
	#endif

	// reserve
	#if TWO
	{
		std::cout << std::endl << "TWO" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec(5, 1);

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());

		vec.reserve(10);

		LOG("");

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());
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

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());

		vec.clear();

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());

		printVectorContent(vec);

		for (size_t i = 0; i < 5; i++)
			vec.push_back(i);

		printVectorContent(vec);

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());
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
			LOG_BLACK(vecP[i]);
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

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());

		vec.pop_back();
		LOG_GREEN(std::endl << "AFTER POP");

		printVectorContent(vec);

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());
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

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());

		vec.resize(44);

		LOG_GREEN(std::endl << "AFTER RESIZE");

		printVectorContent(vec);

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());
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

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());

		vec.resize(18, 42);

		LOG_GREEN(std::endl << "AFTER RESIZE");

		printVectorContent(vec);

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());
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

		LOG_YELLOW("size\t\t" << vec1.size());
		LOG_YELLOW("capacity\t" << vec1.capacity());
		LOG_BLUE("size\t\t" << vec2.size());
		LOG_BLUE("capacity\t" << vec2.capacity());

		vec1.swap(vec2);

		printVectorContent(vec1);
		printVectorContent(vec2);

		LOG_YELLOW("size\t\t" << vec1.size());
		LOG_YELLOW("capacity\t" << vec1.capacity());
		LOG_BLUE("size\t\t" << vec2.size());
		LOG_BLUE("capacity\t" << vec2.capacity());
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

		LOG_YELLOW("size\t\t" << vec.size());
		LOG_YELLOW("capacity\t" << vec.capacity());

		LOG_GREEN(std::endl << "PRINT VALUES" << std::endl);

		for (int i = 0; i < 5; i++)
			LOG_GREEN("vec["<< i << "]\t" << vec[i]);
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

		LOG_YELLOW("size\t\t" << vec1.size());
		LOG_YELLOW("capacity\t" << vec1.capacity());
		LOG_BLUE("size\t\t" << vec2.size());
		LOG_BLUE("capacity\t" << vec2.capacity());

		vec2 = vec1;
		// vec1 = vec2;

		LOG_GREEN(std::endl << "AFTER ASSIGN" << std::endl);
		
		printVectorContent(vec1);
		printVectorContent(vec2);

		LOG_YELLOW("size\t\t" << vec1.size());
		LOG_YELLOW("capacity\t" << vec1.capacity());
		LOG_BLUE("size\t\t" << vec2.size());
		LOG_BLUE("capacity\t" << vec2.capacity());
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
		LOG_YELLOW((real1 == real2));
		LOG_YELLOW((real1 != real2));

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
		LOG_YELLOW("size1\t\t" << real1.size());
		LOG_YELLOW("capacity1\t" << real1.capacity());
		LOG_YELLOW("size2\t\t" << real2.size());
		LOG_YELLOW("capacity2\t" << real2.capacity());
		LOG_YELLOW((real1 == real2));
		LOG_YELLOW((real1 != real2));

		// TEST3
		std::cout << std::endl << "TEST3" << std::endl;
		real1.resize(9);
		LOG_YELLOW((real1 == real2));
		LOG_YELLOW((real1 != real2));

		// TEST4
		std::cout << std::endl << "TEST4" << std::endl;
		real2.resize(9);
		LOG_YELLOW((real1 == real2));
		LOG_YELLOW((real1 != real2));

		// TEST5
		std::cout << std::endl << "TEST5" << std::endl;
		real2.resize(15);
		LOG_YELLOW((real1 == real2));
		LOG_YELLOW((real1 != real2));

		// TEST6
		std::cout << std::endl << "TEST6" << std::endl;
		real1.resize(15);
		LOG_YELLOW((real1 == real2));
		LOG_YELLOW((real1 != real2));
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
		LOG_GREEN((real1 <= real2));
		LOG_GREEN((real1 < real2));

		// TEST2
		std::cout << std::endl << "TEST2" << std::endl;
		real1.pop_back();
		printVectorContent(real1);
		printVectorContent(real2);
		LOG_GREEN((real1 <= real2));
		LOG_GREEN((real1 < real2));

		// TEST3
		std::cout << std::endl << "TEST3" << std::endl;
		real1.push_back("b");
		printVectorContent(real1);
		printVectorContent(real2);
		LOG_GREEN((real1 <= real2));
		LOG_GREEN((real1 < real2));

		// TEST4
		std::cout << std::endl << "TEST4" << std::endl;
		real1.pop_back();
		real1.push_back("d");
		printVectorContent(real1);
		printVectorContent(real2);
		LOG_GREEN((real1 <= real2));
		LOG_GREEN((real1 < real2));
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
		LOG_GREEN((real1 >= real2));
		LOG_GREEN((real1 > real2));

		// TEST2
		std::cout << std::endl << "TEST2" << std::endl;
		real1.pop_back();
		printVectorContent(real1);
		printVectorContent(real2);
		LOG_GREEN((real1 >= real2));
		LOG_GREEN((real1 > real2));

		// TEST3
		std::cout << std::endl << "TEST3" << std::endl;
		real1.push_back("b");
		printVectorContent(real1);
		printVectorContent(real2);
		LOG_GREEN((real1 >= real2));
		LOG_GREEN((real1 > real2));

		// TEST4
		std::cout << std::endl << "TEST4" << std::endl;
		real1.pop_back();
		real1.push_back("d");
		printVectorContent(real1);
		printVectorContent(real2);
		LOG_GREEN((real1 >= real2));
		LOG_GREEN((real1 > real2));
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
		LOG_YELLOW("size\t\t" << vec1.size());
		LOG_YELLOW("capacity\t" << vec1.capacity());
		printVectorContent(vec2);
		LOG_YELLOW("size\t\t" << vec2.size());
		LOG_YELLOW("capacity\t" << vec2.capacity());

		swap(vec1, vec2);

		LOG_GREEN(std::endl << "AFTER SWAP" << std::endl);

		printVectorContent(vec1);
		LOG_YELLOW("size\t\t" << vec1.size());
		LOG_YELLOW("capacity\t" << vec1.capacity());
		printVectorContent(vec2);
		LOG_YELLOW("size\t\t" << vec2.size());
		LOG_YELLOW("capacity\t" << vec2.capacity());
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

		LOG(*it2);
		++it2;
		LOG(*it2);
		++it2;
		LOG(*it2);
		++it2;
		LOG(*it2);
		++it2;
		LOG(*it2);
		++it2;
		LOG(*it2);

		TESTED_NAMESPACE::vector<int>::iterator	itend = rVec.end();
		LOG_RED(*(--itend));

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

		LOG_YELLOW("AFTER ASSIGN");

		printVectorContent(vec1);
		LOG_YELLOW("capacity\t" << vec1.capacity());
		LOG_BLUE("size\t\t" << vec1.size());
		printVectorContent(vec2);
		LOG_YELLOW("capacity\t" << vec2.capacity());
		LOG_BLUE("size\t\t" << vec2.size());
	}
	#endif

	// assign fill
	#if TWENTYONE
	{
		std::cout << std::endl << "TWENTYONE" << std::endl;
		TESTED_NAMESPACE::vector<int>	vec1(5, 42);

		printVectorContent(vec1);

		LOG_YELLOW("capacity\t" << vec1.capacity());
		LOG_YELLOW("size\t\t" << vec1.size());

		vec1.assign((TESTED_NAMESPACE::vector<int>::size_type)0, (TESTED_NAMESPACE::vector<int>::value_type)69); // TODO: fix this issue

		LOG_YELLOW("AFTER ASSIGN");

		printVectorContent(vec1);

		LOG_YELLOW("capacity\t" << vec1.capacity());
		LOG_YELLOW("size\t\t" << vec1.size());
	}
	#endif

	return 0;
}
