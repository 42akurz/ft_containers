#include "../inc/test.hpp"

void	printRealVector( std::vector<int> &real ) {
	LOG_RED(std::endl << "Real Vector -----");
	for(std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		LOG_RED(*it);
	LOG_RED("-----------------");
}

void	non_member_operator_test_1() {
		std::vector<int>	real1;
		std::vector<int>	real2;

		ft::vector<int>		mine1;
		ft::vector<int>		mine2;

		// TEST1
		for (size_t i = 0; i < 10; i++) {
			real1.push_back(i);
			mine1.push_back(i);
		}
		for (size_t i = 0; i < 10; i++) {
			real2.push_back(i + 10);
			mine2.push_back(i + 10);
		}
		LOG_GREEN(std::endl << "TEST1");
		LOG_YELLOW((real1 == real2));
		LOG_CYAN((mine1 == mine2));
		LOG_YELLOW((real1 != real2));
		LOG_CYAN((mine1 != mine2));

		// TEST2
		real1.clear();
		mine1.clear();
		real2.clear();
		mine2.clear();
		for (size_t i = 0; i < 10; i++) {
			real1.push_back(i);
			mine1.push_back(i);
		}
		for (size_t i = 0; i < 10; i++) {
			real2.push_back(i);
			mine2.push_back(i);
		}
		// printVectors(real1, mine1);
		// printVectors(real2, mine2);
		// LOG_YELLOW("size1\t\t" << real1.size());
		// LOG_YELLOW("capacity1\t" << real1.capacity());
		// LOG_YELLOW("size2\t\t" << real2.size());
		// LOG_YELLOW("capacity2\t" << real2.capacity());
		// LOG_CYAN("size1\t\t" << mine1.size());
		// LOG_CYAN("capacity1\t" << mine1.capacity());
		// LOG_CYAN("size2\t\t" << mine2.size());
		// LOG_CYAN("capacity2\t" << mine2.capacity());
		LOG_GREEN(std::endl << "TEST2");
		LOG_YELLOW((real1 == real2));
		LOG_CYAN((mine1 == mine2));
		LOG_YELLOW((real1 != real2));
		LOG_CYAN((mine1 != mine2));

		// TEST3
		real1.resize(9);
		mine1.resize(9);
		LOG_GREEN(std::endl << "TEST3");
		LOG_YELLOW((real1 == real2));
		LOG_CYAN((mine1 == mine2));
		LOG_YELLOW((real1 != real2));
		LOG_CYAN((mine1 != mine2));

		// TEST4
		real2.resize(9);
		mine2.resize(9);
		LOG_GREEN(std::endl << "TEST4");
		LOG_YELLOW((real1 == real2));
		LOG_CYAN((mine1 == mine2));
		LOG_YELLOW((real1 != real2));
		LOG_CYAN((mine1 != mine2));

		// TEST5
		real2.resize(15);
		mine2.resize(15);
		LOG_GREEN(std::endl << "TEST5");
		LOG_YELLOW((real1 == real2));
		LOG_CYAN((mine1 == mine2));
		LOG_YELLOW((real1 != real2));
		LOG_CYAN((mine1 != mine2));

		// TEST6
		real1.resize(15);
		mine1.resize(15);
		LOG_GREEN(std::endl << "TEST6");
		LOG_YELLOW((real1 == real2));
		LOG_CYAN((mine1 == mine2));
		LOG_YELLOW((real1 != real2));
		LOG_CYAN((mine1 != mine2));
}

void	non_member_operator_test_2() {
		std::vector<std::string>	real1;
		std::vector<std::string>	real2;

		ft::vector<std::string>		mine1;
		ft::vector<std::string>		mine2;

		// TEST1
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

		mine1.push_back("a");
		mine1.push_back("b");
		mine1.push_back("cdfvdf");
		mine1.push_back("ddvdfv");
		mine1.push_back("c");

		mine2.push_back("a");
		mine2.push_back("b");
		mine2.push_back("cdfvdf");
		mine2.push_back("ddvdfv");
		mine2.push_back("c");

		// TEST1
		printVectors(real1, mine1);
		printVectors(real2, mine2);

		LOG_GREEN((real1 <= real2));
		LOG_GREEN((mine1 <= mine2));
		LOG_GREEN((real1 < real2));
		LOG_GREEN((mine1 < mine2));

		// TEST2
		real1.pop_back();
		mine1.pop_back();

		printVectors(real1, mine1);
		printVectors(real2, mine2);

		LOG_GREEN((real1 <= real2));
		LOG_GREEN((mine1 <= mine2));
		LOG_GREEN((real1 < real2));
		LOG_GREEN((mine1 < mine2));

		// TEST3
		real1.push_back("b");
		mine1.push_back("b");

		printVectors(real1, mine1);
		printVectors(real2, mine2);

		LOG_GREEN((real1 <= real2));
		LOG_GREEN((mine1 <= mine2));
		LOG_GREEN((real1 < real2));
		LOG_GREEN((mine1 < mine2));

		// TEST4
		real1.pop_back();
		mine1.pop_back();
		real1.push_back("d");
		mine1.push_back("d");

		printVectors(real1, mine1);
		printVectors(real2, mine2);

		LOG_GREEN((real1 <= real2));
		LOG_GREEN((mine1 <= mine2));
		LOG_GREEN((real1 < real2));
		LOG_GREEN((mine1 < mine2));
}

void	non_member_operator_test_3() {
		std::vector<std::string>	real1;
		std::vector<std::string>	real2;

		ft::vector<std::string>		mine1;
		ft::vector<std::string>		mine2;

		// TEST1
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

		mine1.push_back("a");
		mine1.push_back("b");
		mine1.push_back("cdfvdf");
		mine1.push_back("ddvdfv");
		mine1.push_back("c");

		mine2.push_back("a");
		mine2.push_back("b");
		mine2.push_back("cdfvdf");
		mine2.push_back("ddvdfv");
		mine2.push_back("c");

		// TEST1
		printVectors(real1, mine1);
		printVectors(real2, mine2);

		LOG_GREEN((real1 >= real2));
		LOG_GREEN((mine1 >= mine2));
		LOG_GREEN((real1 > real2));
		LOG_GREEN((mine1 > mine2));

		// TEST2
		real1.pop_back();
		mine1.pop_back();

		printVectors(real1, mine1);
		printVectors(real2, mine2);

		LOG_GREEN((real1 >= real2));
		LOG_GREEN((mine1 >= mine2));
		LOG_GREEN((real1 > real2));
		LOG_GREEN((mine1 > mine2));

		// TEST3
		real1.push_back("b");
		mine1.push_back("b");

		printVectors(real1, mine1);
		printVectors(real2, mine2);

		LOG_GREEN((real1 >= real2));
		LOG_GREEN((mine1 >= mine2));
		LOG_GREEN((real1 > real2));
		LOG_GREEN((mine1 > mine2));

		// TEST4
		real1.pop_back();
		mine1.pop_back();
		real1.push_back("d");
		mine1.push_back("d");

		printVectors(real1, mine1);
		printVectors(real2, mine2);

		LOG_GREEN((real1 >= real2));
		LOG_GREEN((mine1 >= mine2));
		LOG_GREEN((real1 > real2));
		LOG_GREEN((mine1 > mine2));
}