#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_traits.hpp"

namespace ft {

	template<typename T>
	class vector_iterator {
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
	
		private:
			pointer	_ptr;

		public:
			// TODO: why is iterator constructor called 4 times
			vector_iterator( pointer ptr = nullptr ) : _ptr(ptr) {
				// std::cout << "iterator constrcutor called" << std::endl;
			}

			// TODO: i freestyled this
			value_type &	operator*() {
				return (*_ptr);
			}

			pointer	operator++() {
				++this->_ptr;
				return (this->_ptr);
			}

			pointer	operator++(int) {
				pointer	temp = this->_ptr;
				++this->_ptr;
				return (temp);
			}

			pointer	operator--() {
				--this->_ptr;
				return (this->_ptr);
			}

			pointer	operator--(int) {
				pointer	temp = this->_ptr;
				--this->_ptr;
				return (temp);
			}
	};

	
}

#endif