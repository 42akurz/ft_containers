#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <exception>

# include "../utils/log_colors.hpp"
# include "../utils/pair.hpp"

namespace ft {

	template < class Key,											// map::key_type
			class T,												// map::mapped_type
			class Compare = std::less<Key>,							// map::key_compare
			class Alloc = std::allocator<ft::pair<const Key, T> >	// map::allocator_type
			> class map {

			public:
				typedef 			Key										key_type;
				typedef 			T										mapped_type;
				typedef typename	ft::pair<const key_type, mapped_type>	value_type;
				typedef				Compare									key_compare;		// The third template parameter (Compare)	defaults to: less<key_type>
				// value_compare																// Nested function class to compare elements	see value_comp
				typedef				Alloc									allocator_type;		// The fourth template parameter (Alloc)	defaults to: allocator<value_type>
				typedef typename	allocator_type::reference				reference;
				typedef typename	allocator_type::const_reference			const_reference;
				typedef typename	allocator_type::pointer					pointer;
				typedef typename	allocator_type::const_pointer			const_pointer;
				// iterator																	// a bidirectional iterator to value_type	convertible to const_iterator
				// const_iterator															// a bidirectional iterator to const value_type	
				// reverse_iterator	reverse_iterator<iterator>	
				// const_reverse_iterator	reverse_iterator<const_iterator>	
				// typedef typename	ft::iterator_traits<iterator>::difference_type		difference_type		// a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
				// size_type																// an unsigned integral type that can represent any non-negative value of difference_type

			private:
				allocator_type	_alloc;
				pointer			_ptr;
				size_t			_capacity;


			public:
				/* empty */
				explicit map( const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type() ) {
					_alloc = alloc;
					(void)comp;
					_ptr = nullptr;
				}

				/* range */
				// template <class InputIterator>
				// map( InputIterator first, InputIterator last,
				// 	const key_compare& comp = key_compare(),
				// 	const allocator_type& alloc = allocator_type() ) {

				// }
					
				/* copy */
				// map( const map& x ) {

				// }



				/* single element */
				// ft::pair<bool, bool>	insert( const value_type& val ) { // TODO: should return ft::pair<iterator, bool>
				// 	if (_ptr == nullptr) {
				// 		_ptr = _alloc.allocate(1);
				// 		_ptr[0] = val;
				// 		_capacity = 1;
				// 	}
				// 	else {
				// 		pointer	newPtr = _alloc.allocate(_capacity + 1);
				// 		for (size_t i = 0; i < _capacity; i++)
				// 			newPtr[i] = _ptr[i];
				// 		newPtr[_capacity] = val;
				// 		_alloc.deallocate(_ptr, _capacity);
				// 		_capacity++;
				// 		_ptr = newPtr;
				// 	}
				// 	return ft::make_pair(true, true);
				// }

				/* with hint */
				// iterator	insert( iterator position, const value_type& val ) {

				// }

				/* range */
				// template <class InputIterator>
				// void	insert( InputIterator first, InputIterator last ) {

				// }
	};
}


#endif