#ifndef TEST_HPP
# define TEST_HPP

# include "vector.hpp"

void	printRealVector( std::vector<int> &real );

template< typename T >
void	printVectors( std::vector<T> &real, ft::vector<T> &mine ) {
	LOG(std::endl << "\033[1;31m" << "Real Vector -----\t" << "\033[0m" << "\033[1;36m" << "My Vector -------" << "\033[0m");
	for(size_t i = 0; ((i < real.size()) && (i < mine.size())); i++) {
		LOG("\033[1;31m" << real[i] << "                \t" << "\033[0m" << "\033[1;36m" << mine[i] << "                " << "\033[0m");
	}
	LOG("\033[1;31m" << "-----------------\t" << "\033[0m" << "\033[1;36m" << "----------------- " << "\033[0m");
}


void	non_member_operator_test_1();
void	non_member_operator_test_2();
void	non_member_operator_test_3();


#endif