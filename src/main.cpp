#include "../inc/vector.hpp"

void	printRealVector( std::vector<int> &real ) {
	LOG_RED(std::endl << "Real Vector -----");
	for(std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		LOG_RED(*it);
	LOG_RED("-----------------");
}

#define ONE 0
#define TWO 0
#define THREE 0
#define FOUR 0
#define FIVE 0
#define SIX 0
#define SEVEN 0
#define EIGHT 1

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

	// added clear
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

	// test get_allocator
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

	// pop_back added
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

	// resize added
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
	return 0;
}

// int	main( void )
// {
// 	std::vector<int>	real(100000000, 42);

// 	LOG_GREEN("capacity:	" << real.capacity());
// 	LOG_GREEN("size:		" << real.size());
	

// 	std::cout << std::endl;

// 	LOG_GREEN("capacity:	" << real.capacity());
// 	LOG_GREEN("size:		" << real.size());
// }