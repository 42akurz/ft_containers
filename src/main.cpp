#include "../container/vector.hpp"
#include "../container/map.hpp"
#include "../container/stack.hpp"
#include "../container/set.hpp"

#include <map>
#include <set>

#define T1 int
#define T2 int

#define TESTED_NAMESPACE	std

int	main()
{
	TESTED_NAMESPACE::set<T1> const mp;
	TESTED_NAMESPACE::set<T1>::iterator it = mp.begin(); // <-- error expected

	(void)it;
	return 0;
}
