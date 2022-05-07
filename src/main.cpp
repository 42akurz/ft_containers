#include "../inc/vector.hpp"
#include "../inc/test.hpp"

// void	printRealVector( std::vector<int> &real ) {
// 	LOG_RED(std::endl << "Real Vector -----");
// 	for(std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
// 		LOG_RED(*it);
// 	LOG_RED("-----------------");
// }

// template< typename T >
// void	printVectors( std::vector<T> &real, ft::vector<T> &mine ) {
// 	LOG(std::endl << "\033[1;31m" << "Real Vector -----\t" << "\033[0m" << "\033[1;36m" << "My Vector -------" << "\033[0m");
// 	for(size_t i = 0; ((i < real.size()) && (i < mine.size())); i++) {
// 		LOG("\033[1;31m" << real[i] << "                \t" << "\033[0m" << "\033[1;36m" << mine[i] << "                " << "\033[0m");
// 	}
// 	LOG("\033[1;31m" << "-----------------\t" << "\033[0m" << "\033[1;36m" << "----------------- " << "\033[0m");
// }

#define ONE 0 // push_back
#define TWO 0 // reserve
#define THREE 0 // reserve more tests
#define FOUR 0 // clear
#define FIVE 0 // get_allocator
#define SIX 0 // pop_back
#define SEVEN 0 // resize
#define EIGHT 0 // resize more tests
#define NINE 0 // real swap
#define TEN 0 // my swap
#define ELEVEN 0 // operator[]
#define TWELVE 0 // real operator=
#define THIRTEEN 0 // my operator=
#define FOURTEEN 0 // non member operators
#define FIVETEEN 0 // non member operators part 2
#define SIXTEEN 0 // non member operators part 3
#define SEVENTEEN 0 // non member swap
#define EIGHTEEN 0 // iterator
#define NINETEEN 0 // test at
#define TWENTY 0 // assign range
#define TWENTYONE 1 // assign fill

int	main( void )
{
	#if ONE
	{
		ft::vector<int>		mine(5, 1);

		mine.printVector();

		LOG("");
		LOG_WHITE("size:		" << mine.size());
		LOG_WHITE("max_size:	" << mine.max_size());
		LOG_WHITE("empty:		" << mine.empty());
		LOG_WHITE("capacity:	" << mine.capacity());

		// mine.reserve(10);
		mine.push_back(42);
		mine.push_back(43);
		mine.push_back(44);
		mine.printVector();

		LOG("");
		LOG_WHITE("size:		" << mine.size());
		LOG_WHITE("max_size:	" << mine.max_size());
		LOG_WHITE("empty:		" << mine.empty());
		LOG_WHITE("capacity:	" << mine.capacity());

		std::vector<int>	real(5, 1);

		printRealVector(real);

		LOG("");
		LOG_YELLOW("size:		" << real.size());
		LOG_YELLOW("max_size:	" << real.max_size());
		LOG_YELLOW("empty:		" << real.empty());
		LOG_YELLOW("capacity:	" << real.capacity());

		// real.reserve(10);
		real.push_back(42);
		real.push_back(43);
		real.push_back(44);
		printRealVector(real);

		LOG("");
		LOG_YELLOW("size:		" << real.size());
		LOG_YELLOW("max_size:	" << real.max_size());
		LOG_YELLOW("empty:		" << real.empty());
		LOG_YELLOW("capacity:	" << real.capacity());
	}
	#endif
	#if TWO
	{
		ft::vector<int>		mine(5, 1);
		std::vector<int>	real(5, 1);

		LOG_CYAN("size\t\t" << mine.size());
		LOG_YELLOW("size\t\t" << real.size());
		LOG_CYAN("capacity\t" << mine.capacity());
		LOG_YELLOW("capacity\t" << real.capacity());

		mine.reserve(10);
		real.reserve(10);

		LOG("");

		LOG_CYAN("size\t\t" << mine.size());
		LOG_YELLOW("size\t\t" << real.size());
		LOG_CYAN("capacity\t" << mine.capacity());
		LOG_YELLOW("capacity\t" << real.capacity());
	}
	#endif

	// testing reserve and reserve exceptions TODO: not finished
	#if THREE
	{
		ft::vector<int>		mine;
		std::vector<int>	real;

		for (size_t i = 0; i < 5; i++) {
			real.push_back(i);
			mine.push_back(i);
		}

		mine.printVector();
		printRealVector(real);

		try
		{
			real.reserve(-0);
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
		ft::vector<int>		mine;
		std::vector<int>	real;

		for (size_t i = 0; i < 5; i++) {
			real.push_back(i);
			mine.push_back(i);
		}

		mine.printVector();
		printRealVector(real);

		LOG_YELLOW("size\t\t" << real.size());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("capacity\t" << mine.capacity());

		real.clear();
		mine.clear();

		LOG_YELLOW("size\t\t" << real.size());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("capacity\t" << mine.capacity());

		mine.printVector();
		printRealVector(real);


		LOG_GREEN(std::endl << "PUSH AGAIN" << std::endl);
		for (size_t i = 0; i < 5; i++) {
			real.push_back(i);
			mine.push_back(i);
		}

		mine.printVector();
		printRealVector(real);

		LOG_YELLOW("size\t\t" << real.size());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("capacity\t" << mine.capacity());
	}
	#endif

	// get_allocator
	#if FIVE
	{
		ft::vector<int>		mine;
		std::vector<int>	real;

		for (size_t i = 0; i < 5; i++) {
			real.push_back(i);
			mine.push_back(i);
		}

		mine.printVector();
		printRealVector(real);

		std::allocator<int>	realA = real.get_allocator();
		std::allocator<int>	myA = mine.get_allocator();

		int	*realP = realA.allocate(5);
		int	*myP = myA.allocate(5);

		for (int i = 0; i < 5; i++) {
			realA.construct(&realP[i], i + 10);
			myA.construct(&myP[i], i + 10);
		}
		for (int i = 0; i < 5; i++) {
			LOG_BLACK(realP[i]);
			LOG_WHITE(myP[i]);
		}

		mine.printVector();
		printRealVector(real);
	}
	#endif

	// pop_back
	#if SIX
	{
		ft::vector<int>		mine;
		std::vector<int>	real;

		for (size_t i = 0; i < 5; i++) {
			real.push_back(i);
			mine.push_back(i);
		}

		mine.printVector();
		printRealVector(real);

		LOG_YELLOW("size\t\t" << real.size());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("capacity\t" << mine.capacity());

		real.pop_back();
		mine.pop_back();
		LOG_GREEN(std::endl << "AFTER POP");

		mine.printVector();
		printRealVector(real);

		LOG_YELLOW("size\t\t" << real.size());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("capacity\t" << mine.capacity());
	}
	#endif

	// resize 
	#if SEVEN
	{
		std::vector<int>	real;
		ft::vector<int>		mine;

		for (size_t i = 0; i < 16; i++) {
			real.push_back(i);
			mine.push_back(i);
		}

		mine.printVector();
		printRealVector(real);

		LOG_YELLOW("size\t\t" << real.size());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("capacity\t" << mine.capacity());

		real.resize(44);
		mine.resize(44);

		LOG_GREEN(std::endl << "AFTER RESIZE");

		mine.printVector();
		printRealVector(real);

		LOG_YELLOW("size\t\t" << real.size());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("capacity\t" << mine.capacity());
	}
	#endif

	// resize more tests
	#if EIGHT
	{
		std::vector<int>	real(5);
		ft::vector<int>		mine(5);

		for (size_t i = 0; i < 5; i++) {
			real.at(i) = i;
			mine.at(i) = i;
		}

		mine.printVector();
		printRealVector(real);

		LOG_YELLOW("size\t\t" << real.size());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("capacity\t" << mine.capacity());

		real.resize(18,42);
		mine.resize(18, 42);

		LOG_GREEN(std::endl << "AFTER RESIZE");

		mine.printVector();
		printRealVector(real);

		LOG_YELLOW("size\t\t" << real.size());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("capacity\t" << mine.capacity());
	}
	#endif

	// real swap
	#if NINE
	{
		std::vector<int>	real1;
		std::vector<int>	real2;

		for (size_t i = 0; i < 21; i++) {
			real1.push_back(i);
			if (i < 12)
				real2.push_back(i + 10);
		}

		printRealVector(real1);
		printRealVector(real2);

		LOG_YELLOW("size\t\t" << real1.size());
		LOG_YELLOW("capacity\t" << real1.capacity());
		LOG_BLUE("size\t\t" << real2.size());
		LOG_BLUE("capacity\t" << real2.capacity());

		real1.swap(real2);

		printRealVector(real1);
		printRealVector(real2);

		LOG_YELLOW("size\t\t" << real1.size());
		LOG_YELLOW("capacity\t" << real1.capacity());
		LOG_BLUE("size\t\t" << real2.size());
		LOG_BLUE("capacity\t" << real2.capacity());
	}
	#endif

	// my swap
	#if TEN
	{
		ft::vector<int>	mine1;
		ft::vector<int>	mine2;

		for (size_t i = 0; i < 21; i++) {
			mine1.push_back(i);
			if (i < 12)
				mine2.push_back(i + 10);
		}

		mine1.printVector();
		mine2.printVector();

		LOG_YELLOW("size\t\t" << mine1.size());
		LOG_YELLOW("capacity\t" << mine1.capacity());
		LOG_BLUE("size\t\t" << mine2.size());
		LOG_BLUE("capacity\t" << mine2.capacity());

		mine1.swap(mine2);

		mine1.printVector();
		mine2.printVector();

		LOG_YELLOW("size\t\t" << mine1.size());
		LOG_YELLOW("capacity\t" << mine1.capacity());
		LOG_BLUE("size\t\t" << mine2.size());
		LOG_BLUE("capacity\t" << mine2.capacity());
	}
	#endif

	// operator[]
	#if ELEVEN
	{
		std::vector<int>	real(5);
		ft::vector<int>		mine(5);

		for (size_t i = 0; i < 5; i++) {
			real[i] = i;
			mine[i] = i;
		}

		mine.printVector();
		printRealVector(real);

		LOG_YELLOW("size\t\t" << real.size());
		LOG_YELLOW("capacity\t" << real.capacity());
		LOG_BLUE("size\t\t" << mine.size());
		LOG_BLUE("capacity\t" << mine.capacity());

		LOG_GREEN(std::endl << "PRINT VALUES" << std::endl);

		for (int i = 0; i < 5; i++) {
			LOG_GREEN("real["<< i << "]\t" << real[i] << "\t|\tmine[" << i << "]\t" << mine[i]);
		}
	}
	#endif

	// real operator=
	#if TWELVE
	{
		std::vector<int>	real1;
		std::vector<int>	real2;

		real1.reserve(33);
		real2.reserve(12);

		for (size_t i = 0; i < 21; i++) {
			real1.push_back(i);
			if (i < 12)
				real2.push_back(i + 10);
		}

		printRealVector(real1);
		printRealVector(real2);

		LOG_YELLOW("size\t\t" << real1.size());
		LOG_YELLOW("capacity\t" << real1.capacity());
		LOG_BLUE("size\t\t" << real2.size());
		LOG_BLUE("capacity\t" << real2.capacity());

		real2 = real1;
		// real1 = real2;

		LOG_GREEN(std::endl << "AFTER ASSIGN" << std::endl);
		
		printRealVector(real1);
		printRealVector(real2);

		LOG_YELLOW("size\t\t" << real1.size());
		LOG_YELLOW("capacity\t" << real1.capacity());
		LOG_BLUE("size\t\t" << real2.size());
		LOG_BLUE("capacity\t" << real2.capacity());
	}
	#endif

	// my operator=
	// TODO: test capacity < == >, etc.
	#if THIRTEEN
	{
		ft::vector<int>	mine1;
		ft::vector<int>	mine2;

		mine1.reserve(33);
		mine2.reserve(12);

		for (size_t i = 0; i < 21; i++) {
			mine1.push_back(i);
			if (i < 12)
				mine2.push_back(i + 10);
		}

		mine1.printVector();
		mine2.printVector();

		LOG_YELLOW("size\t\t" << mine1.size());
		LOG_YELLOW("capacity\t" << mine1.capacity());
		LOG_BLUE("size\t\t" << mine2.size());
		LOG_BLUE("capacity\t" << mine2.capacity());

		mine2 = mine1;
		// mine1 = mine2;

		LOG_GREEN(std::endl << "AFTER ASSIGN" << std::endl);
		
		mine1.printVector();
		mine2.printVector();

		LOG_YELLOW("size\t\t" << mine1.size());
		LOG_YELLOW("capacity\t" << mine1.capacity());
		LOG_BLUE("size\t\t" << mine2.size());
		LOG_BLUE("capacity\t" << mine2.capacity());
	}
	#endif

	// non member operators == / !=
	#if FOURTEEN
	{
		non_member_operator_test_1();
	}
	#endif

	// non member operators part 2 < / <=
	#if FIVETEEN
	{
		non_member_operator_test_2();
	}
	#endif

	// non member operators part 3 > / >=
	#if SIXTEEN
	{
		non_member_operator_test_3();
	}
	#endif

	// non member swap
	#if SEVENTEEN
	{
		std::vector<int>	real1;
		std::vector<int>	real2;
		ft::vector<int>		mine1;
		ft::vector<int>		mine2;

		for (size_t i = 0; i < 21; i++) {
			real1.push_back(i);
			mine1.push_back(i);
			if (i < 12) {
				real2.push_back(i + 10);
				mine2.push_back(i + 10);
			}
		}

		printVectors(real1, mine1);
		LOG_YELLOW("size\t\t" << real1.size());
		LOG_YELLOW("capacity\t" << real1.capacity());
		LOG_BLUE("size\t\t" << mine1.size());
		LOG_BLUE("capacity\t" << mine1.capacity());
		printVectors(real2, mine2);
		LOG_YELLOW("size\t\t" << real2.size());
		LOG_YELLOW("capacity\t" << real2.capacity());
		LOG_BLUE("size\t\t" << mine2.size());
		LOG_BLUE("capacity\t" << mine2.capacity());

		swap(real1, real2);
		swap(mine1, mine2);

		LOG_GREEN(std::endl << "AFTER SWAP" << std::endl);

		printVectors(real1, mine1);
		LOG_YELLOW("size\t\t" << real1.size());
		LOG_YELLOW("capacity\t" << real1.capacity());
		LOG_BLUE("size\t\t" << mine1.size());
		LOG_BLUE("capacity\t" << mine1.capacity());
		printVectors(real2, mine2);
		LOG_YELLOW("size\t\t" << real2.size());
		LOG_YELLOW("capacity\t" << real2.capacity());
		LOG_BLUE("size\t\t" << mine2.size());
		LOG_BLUE("capacity\t" << mine2.capacity());
	}
	#endif

	#if EIGHTEEN
	{
		ft::vector<int>	myVec(5, 42);
		std::vector<int>	rVec(5, 42);
	
		rVec.push_back(10);
		myVec.push_back(10);

		ft::vector<int>::iterator	it = myVec.begin();
		std::vector<int>::iterator	it2 = rVec.begin();


		printVectors(rVec, myVec);

		LOG(std::endl << "mine:");

		LOG(*it);
		++it;
		LOG(*it);
		++it;
		LOG(*it);
		++it;
		LOG(*it);
		++it;
		LOG(*it);
		++it;
		LOG(*it);

		LOG(std::endl << "real:");

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

		ft::vector<int>::iterator	itend = myVec.end();
		LOG_RED(*(--itend));

	}
	#endif

	#if NINETEEN
	{
		ft::vector<int> vct(7);
		std::vector<int> real(7);

		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct.at(): " << vct.at(i) << " | ";
			std::cout << "vct[]: " << vct[i] << std::endl;
			real.at(i) = (real.size() - i) * 3;
			std::cout << "real.at(): " << real.at(i) << " | ";
			std::cout << "real[]: " << real[i] << std::endl;
		}
		LOG_GREEN(vct.size());
		LOG_GREEN(real.size());

		ft::vector<int> const vct_c(vct);
		std::vector<int> const real_c(real);

		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;
		std::cout << "front(): " << real.front() << " " << real_c.front() << std::endl;
		std::cout << "back(): " << real.back() << " " <<  real_c.back() << std::endl;

		try {
			vct.at(10) = 42;
			// real.at(10) = 42;
		}
		catch (std::out_of_range &e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Catch exception: " << e.what() << std::endl;
		}

	}
	#endif

	// assign range
	#if TWENTY
	{
		std::vector<int>	real1;
		std::vector<int>	real2(20, 42);

		for (size_t i = 0; i < 30; i += 3) {
			real1.push_back(i);
		}

		printRealVector(real1);
		printRealVector(real2);

		real2.assign((++real1.begin()), (--real1.end()));

		LOG_YELLOW("AFTER ASSIGN");

		printRealVector(real1);
		LOG_YELLOW("capacity\t" << real1.capacity());
		LOG_BLUE("size\t\t" << real1.size());
		printRealVector(real2);
		LOG_YELLOW("capacity\t" << real2.capacity());
		LOG_BLUE("size\t\t" << real2.size());

		ft::vector<int>	mine1;
		ft::vector<int>	mine2(20, 42);

		for (size_t i = 0; i < 30; i += 3) {
			mine1.push_back(i);
		}

		mine1.printVector();
		mine2.printVector();

		mine2.assign((++mine1.begin()), (--mine1.end()));

		LOG_YELLOW("AFTER ASSIGN");

		mine1.printVector();
		LOG_YELLOW("capacity\t" << mine1.capacity());
		LOG_BLUE("size\t\t" << mine1.size());
		mine2.printVector();
		LOG_YELLOW("capacity\t" << mine2.capacity());
		LOG_BLUE("size\t\t" << mine2.size());
	}
	#endif

	// assign fill
	#if TWENTYONE
	{
		std::vector<int>	real1(5, 42);
		ft::vector<int>		mine1(5, 42);

		printVectors(real1, mine1);

		LOG_YELLOW("capacity\t" << real1.capacity());
		LOG_YELLOW("size\t\t" << real1.size());
		LOG_BLUE("capacity\t" << mine1.capacity());
		LOG_BLUE("size\t\t" << mine1.size());

		real1.assign((ft::vector<int>::size_type)0, (ft::vector<int>::value_type)69);
		mine1.assign((ft::vector<int>::size_type)0, (ft::vector<int>::value_type)69);

		LOG_YELLOW("AFTER ASSIGN");

		printVectors(real1, mine1);

		LOG_YELLOW("capacity\t" << real1.capacity());
		LOG_YELLOW("size\t\t" << real1.size());
		LOG_BLUE("capacity\t" << mine1.capacity());
		LOG_BLUE("size\t\t" << mine1.size());
	}
	#endif


	return 0;
}
