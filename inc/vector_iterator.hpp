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

			pointer	base() const { return this->_ptr;} 

			// TODO: why is iterator constructor called 4 times
			vector_iterator( pointer ptr = nullptr ) : _ptr(ptr) {}

			vector_iterator( const vector_iterator &in ) : _ptr(in._ptr) {}

			~vector_iterator() {}

			reference	operator*() { return (*_ptr); }

			vector_iterator	operator++() {
				++this->_ptr;
				return (this->_ptr);
			}

			vector_iterator	operator++(int) {
				pointer	temp = this->_ptr;
				++this->_ptr;
				return (temp);
			}

			vector_iterator	operator--() {
				--this->_ptr;
				return (this->_ptr);
			}

			vector_iterator	operator--(int) {
				pointer	temp = this->_ptr;
				--this->_ptr;
				return (temp);
			}

			vector_iterator &	operator=( const vector_iterator & in ) {
				this->_ptr = in._ptr;
				return *this;
			}

			vector_iterator &	operator+=( int offset ) {
				this->_ptr += offset;
				return *this;
			}

			vector_iterator &	operator-=( int offset ) {
				this->_ptr -= offset;
				return *this;
			}

			difference_type	operator-( const vector_iterator &in ) { return (this->_ptr - in.base()); }

			vector_iterator	operator-( int offset ) { return (this->_ptr - offset); }

			vector_iterator	operator+( int offset ) { return (this->_ptr + offset); }

			reference	operator[]( int pos ) { return *(operator+(pos)); }

	};

	template <class T>
	bool	operator!=( const vector_iterator<T>& lhs, const vector_iterator<T>& rhs ) { return (lhs.base() != rhs.base()); }

	template <class T>
	bool	operator==( const vector_iterator<T>& lhs, const vector_iterator<T>& rhs ) { return (lhs.base() == rhs.base()); }

	template <class T>
	bool	operator<=( const vector_iterator<T>& lhs, const vector_iterator<T>& rhs ) { return (lhs.base() <= rhs.base()); }

	template <class T>
	bool	operator>=( const vector_iterator<T>& lhs, const vector_iterator<T>& rhs ) { return (lhs.base() >= rhs.base()); }

	template <class T>
	bool	operator<( const vector_iterator<T>& lhs, const vector_iterator<T>& rhs ) { return (lhs.base() < rhs.base()); }

	template <class T>
	bool	operator>( const vector_iterator<T>& lhs, const vector_iterator<T>& rhs ) { return (lhs.base() > rhs.base()); }
}

#endif