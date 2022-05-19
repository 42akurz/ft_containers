#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <exception>

// # include "../utils/log_colors.hpp"
# include "../utils/pair.hpp"
# include "../utils/red_black_tree.hpp"

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

				typedef				Compare									key_compare;		// The third template parameter (Compare)	defaults to: less<key_type>															// Nested function class to compare elements	see value_comp
				typedef				Alloc									allocator_type;		// The fourth template parameter (Alloc)	defaults to: allocator<value_type>
				
				typedef typename	allocator_type::reference				reference;
				typedef typename	allocator_type::const_reference			const_reference;
				typedef typename	allocator_type::pointer					pointer;
				typedef typename	allocator_type::const_pointer			const_pointer;
				
				// typedef typename	ft::iterator_traits<iterator>::difference_type		difference_type		// a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
				// size_type																// an unsigned integral type that can represent any non-negative value of difference_type
				
				typedef				ft::RBTree<const key_type, mapped_type>					RBTree;

				typedef typename	RBTree::iterator						iterator;
				typedef typename	RBTree::const_iterator					const_iterator;
				typedef typename	RBTree::reverse_iterator				reverse_iterator;
				typedef typename	RBTree::const_reverse_iterator			const_reverse_iterator;

			private:
				// allocator_type	_alloc;
				// pointer			_ptr;
				// size_t			_capacity;
				RBTree				tree;


			public:
				/* empty */
				explicit map( const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type() ) {
					tree = RBTree();
					(void)comp;
					(void)alloc;
				}

				iterator begin () {
					return tree.begin();
				}


				pair<iterator,bool> insert (const value_type& val) {
					tree.insert(val);
					return ft::make_pair<iterator, bool>(tree.begin(), true);
				}

				void	print() {
					tree.printInOrder();
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