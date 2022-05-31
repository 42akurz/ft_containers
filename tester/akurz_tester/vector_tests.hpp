#ifndef VECTOR_TESTS_HPP
# define VECTOR_TESTS_HPP

#include "../../container/vector.hpp"
#include <iostream>
#include <vector>

#ifdef USING_STD
	#define TESTED_NAMESPACE std
#else
	#define TESTED_NAMESPACE ft
#endif

template <typename T>
void	printVectorContent( TESTED_NAMESPACE::vector<T> & vector ) {
	std::cout << std::endl;
	typename TESTED_NAMESPACE::vector<T>::iterator	it;
	for (it = vector.begin(); it != vector.end(); it++)
		std::cout << (*it) << std::endl;
	std::cout << std::endl;
}

#endif