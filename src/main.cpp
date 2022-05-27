#include "../container/vector.hpp"
#include "../container/map.hpp"
#include "../container/stack.hpp"
#include "../container/set.hpp"

#define TESTED_NAMESPACE	ft

int	main()
{
	TESTED_NAMESPACE::set<int>	s;
	
	s.insert(5);
	s.insert(10);
	s.insert(15);
	s.insert(20);
	s.insert(25);

	TESTED_NAMESPACE::set<int>	s2;

	s2.insert(s.begin(), s.end());
	TESTED_NAMESPACE::set<int>::iterator	it = s2.begin();

	s2.insert(++(++s2.begin()), 42);
	for (; it != s2.end(); it++)
		LOG(*it);

	std::cout << std::endl;

	TESTED_NAMESPACE::set<int>	s3(s2.begin(), s2.end());
	for (TESTED_NAMESPACE::set<int>::iterator start = s2.begin(); start != s2.end(); start++)
		LOG_GREEN(*start);
	return 0;
}
