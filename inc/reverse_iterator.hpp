#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "reverse_iterator.hpp"

namespace ft {

	template<typename Iterator>
	class reverse_iterator {
		public:
			typedef typename Iterator::iterator_category		iterator_category;
			typedef typename Iterator::value_type				value_type;
			typedef typename Iterator::pointer					pointer;
			typedef typename Iterator::reference				reference;
			typedef typename Iterator::difference_type			difference_type;

		private:
			Iterator	_it;

		public:
			reverse_iterator() : _it() {}
			reverse_iterator( Iterator it ) : _it(it) {}
			reverse_iterator( const reverse_iterator<Iterator> &in ) : _it(in.base()) {}
			~reverse_iterator() {}

			Iterator	base() const { return this->_it; }

			/* convert non-const to const */
			// operator			reverse_iterator<const T>() const { return (reverse_iterator<const T>(base())); }

			/* references */
			reference			operator*() { return (*_it); } 
			reference			operator[]( int pos ) { return *(operator+(pos)); }

			/* increments */
			reverse_iterator &	operator++() { --_it; return (*this); }

			reverse_iterator		operator++(int) {
				reverse_iterator	temp(*this);
				--_it;
				return (temp);
			}
			reverse_iterator &	operator+=( int offset ) {
				_it -= offset;
				return (*this);
			}

			/* decrements */
			reverse_iterator &	operator--() {
				++_it;
				return (*this);
			}
			reverse_iterator		operator--(int) {
				reverse_iterator	temp(*this);
				++_it;
				return (temp);
			}
			reverse_iterator &	operator-=( int offset ) {
				_it += offset;
				return (*this);
			}

			/* assign */
			reverse_iterator &	operator=( const reverse_iterator & in ) {
				_it = in.base();
				return (*this);
			}

			// /* addition / subtraction */
			difference_type	operator-( const reverse_iterator &in ) { return (_it + in.base()); }
			reverse_iterator	operator-( int offset ) { return (_it + offset); }
			reverse_iterator	operator+( int offset ) { return (_it - offset); }
	};
}




#endif