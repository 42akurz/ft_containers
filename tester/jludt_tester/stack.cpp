#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>

#include "../../container/vector.hpp"
#include "../../container/stack.hpp"
#include "../../container/map.hpp"

#include <sys/time.h>
#include <iomanip>
#include <fstream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"

// c++ -Wall -Werror -Wextra stack.cpp -o ft_container
// c++ -Wall -Werror -Wextra -DSTD stack.cpp -o std_container

#define NAMESPACE ft
#ifdef STD
# undef NAMESPACE
# define NAMESPACE std
#endif

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
	struct timespec startStack, endStack;

	clock_gettime(CLOCK_MONOTONIC, &startStack);

	std::cout << GREEN << "\n***************************" << std::endl;
	std::cout          <<   "*          STACK          *" << std::endl;
	std::cout          <<   "***************************" << RESET << std::endl;

	std::cout << YELLOW << "\nstack::stack\n" << RESET;

	#ifdef STD
	std::deque<int> smydeque (3,200);         				// deque with 3 elements
	NAMESPACE::vector<int> smyvector (2,200);         		// vector with 2 elements
	NAMESPACE::stack<int> sfirst;                 		    // empty stack
	NAMESPACE::stack<int> ssecond (smydeque);         		// stack initialized to copy of deque
	NAMESPACE::stack<int,NAMESPACE::vector<int> > sthird;	// empty stack using vector
	NAMESPACE::stack<int,NAMESPACE::vector<int> > sfourth (smyvector);
	#else
	std::deque<int> smydeque (2,200);         				// deque with 3 elements
	NAMESPACE::vector<int> smyvector (3,200);        		// vector with 2 elements
	NAMESPACE::stack<int> sfirst;                    		// empty stack
	NAMESPACE::stack<int> ssecond (smyvector);         		// stack initialized to copy of deque
	NAMESPACE::stack<int,std::deque<int> > sthird;  		// empty stack using vector
	NAMESPACE::stack<int,std::deque<int> > sfourth (smydeque);
	#endif
	std::cout << "size of sfirst: " << sfirst.size() << '\n';
	std::cout << "size of ssecond: " << ssecond.size() << '\n';
	std::cout << "size of sthird: " << sthird.size() << '\n';
	std::cout << "size of sfourth: " << sfourth.size() << '\n';

	std::cout << YELLOW << "\nstack::empty\n" << RESET;

	NAMESPACE::stack<int> mystack;
	int ssum (0);
	for (int i=1;i<=10;i++) mystack.push(i);
	while (!mystack.empty())
	{
		ssum += mystack.top();
		mystack.pop();
	}
	std::cout << "total: " << ssum << '\n';

	std::cout << YELLOW << "\nstack::size\n" << RESET;

	NAMESPACE::stack<int> smyints;
	std::cout << "0. size: " << smyints.size() << '\n';
	for (int i=0; i<5; i++) smyints.push(i);
	std::cout << "1. size: " << smyints.size() << '\n';
	smyints.pop();
	std::cout << "2. size: " << smyints.size() << '\n';

	std::cout << YELLOW << "\nstack::top\n" << RESET;

	NAMESPACE::stack<int> mystack2;
	mystack2.push(10);
	mystack2.push(20);
	mystack2.top() -= 5;
	std::cout << "mystack2.top() is now " << mystack2.top() << '\n';

	std::cout << YELLOW << "\nstack::push | stack::pop\n" << RESET;

	NAMESPACE::stack<int> mystack3;
	for (int i=0; i<5; ++i) mystack3.push(i);
	std::cout << "Popping out elements...";
	while (!mystack3.empty())
	{
		std::cout << ' ' << mystack3.top();
		mystack3.pop();
	}
	std::cout << '\n';

	std::cout << YELLOW << "\nrelational operators (stack)\n" << RESET;

	NAMESPACE::stack<int> mystackA;
	std::cout << "StackA contains: ";
	for (int i=1;i<=10;i++)
	{
		std::cout << i << " ";
		mystackA.push(i);
	}
	std::cout << '\n';

	std::cout << "StackB contains: ";
	NAMESPACE::stack<int> mystackB;
	for (int i=1;i<=10;i++)
	{
		std::cout << i << " ";
		mystackB.push(i);
	}

	std::cout << '\n';
	std::cout << std::boolalpha;
	std::cout << "operator== "<<(mystackA == mystackB) << '\n';
	std::cout << "operator!= "<<(mystackA != mystackB) << '\n';
	std::cout << "operator<  "<<(mystackA < mystackB) << '\n';
	std::cout << "operator<= "<<(mystackA <= mystackB) << '\n';
	std::cout << "operator>  "<<(mystackA > mystackB) << '\n';
	std::cout << "operator>= "<<(mystackA >= mystackB) << '\n';
	std::cout << std::noboolalpha;


	std::cout << YELLOW << "\nperformance stack\n" << RESET;
	std::cout << "inserting and deleting lots of elements\n";

	struct timespec timeStart, timeEnd;
	// start timer
	clock_gettime(CLOCK_MONOTONIC, &timeStart);
	NAMESPACE::stack<int> perfS;
	for (size_t i = 0; i < 10000000; ++i)
			perfS.push(std::rand());
	NAMESPACE::stack<int> perfS2(perfS);
	for (size_t i = 0; i < 10000000; ++i)
			perfS.pop();
	// end timer
	clock_gettime(CLOCK_MONOTONIC, &timeEnd);
	double timePerformance;
	timePerformance = timeStart.tv_sec * 1e9;
	timePerformance = (timeEnd.tv_sec - timeStart.tv_sec) * 1e9;
	timePerformance = (timePerformance + (timeEnd.tv_nsec - timeStart.tv_nsec)) * 1e-9;
	std::cout << "Stack performance test: " <<  timePerformance << "sec.\n";

	std::cout << YELLOW << "\nleaks stack\n" << RESET;

	#ifdef STD
		system("leaks std_container | tail -3");
	#else
		system("leaks ft_container | tail -3");
	#endif

	clock_gettime(CLOCK_MONOTONIC, &endStack);
	return 0;
}