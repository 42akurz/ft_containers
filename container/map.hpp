#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <exception>

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
				
				typedef				ft::RBTree<const key_type, mapped_type>	RBTree;

				typedef typename	RBTree::iterator						iterator;
				typedef typename	RBTree::const_iterator					const_iterator;
				typedef typename	RBTree::reverse_iterator				reverse_iterator;
				typedef typename	RBTree::const_reverse_iterator			const_reverse_iterator;

			private:
				RBTree				tree;
				key_compare			_compare;
				allocator_type		_alloc_pair;

			public:

				void	print() {
					tree.printInOrder();
				}

				/* empty */
				explicit map( const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type() ) {
					_compare = comp;
					_alloc_pair = alloc;
				}

				/* range */
				template <class InputIterator>
				map( InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type() ) {
					for (; first != last; first++)
						tree.insert(*first);
					_compare = comp;
					_alloc_pair = alloc;
				}
				
				/* copy */
				map( const map& x ) {
					this->tree = x.tree;
					this->_compare = x._compare;
					this->_alloc_pair = x._alloc_pair;
				}

				mapped_type &			operator[]( const key_type& k ) {
					return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
				}

				iterator				begin() { return tree.begin(); }
				const_iterator			begin() const { return tree.begin(); }

				iterator				end() { return tree.end(); }
				const_iterator			end() const { return tree.end(); }

				reverse_iterator		rbegin() { return tree.rbegin(); }
				const_reverse_iterator	rbegin() const { return tree.rbegin(); }

				reverse_iterator		rend() { return tree.rend(); }
				const_reverse_iterator	rend() const { return tree.rend(); }

				iterator				find( const key_type& k ) {
					iterator	ret = tree.search(value_type(k, mapped_type()));
					if (ret->first != k)
						return end();
					return ret;
				}

				const_iterator			find( const key_type& k ) const {
					const_iterator	ret = tree.search(value_type(k, mapped_type()));
					if (ret->first != k)
						return end();
					return ret;
				}

				iterator				upper_bound( const key_type& k ) {
					for (iterator it = begin(); it != end(); it++) {
						if (_compare(k, it->first))
							return it;
					}
					return end();
				}

				const_iterator			upper_bound( const key_type& k ) const {
					for (const_iterator it = begin(); it != end(); it++) {
						if (_compare(k, it->first))
							return it;
					}
					return end();
				}

				iterator				lower_bound( const key_type& k ) {
					iterator	temp = begin();
					for (iterator it = begin(); it != end(); it++) {
						if (!_compare(it->first, k)) {
							if (it->first == k)
								return it;
							return temp;
						}
						temp = it;
					}
					return --end();
				}

				const_iterator			lower_bound( const key_type& k ) const {
					const_iterator	temp = begin();
					for (const_iterator it = begin(); it != end(); it++) {
						if (!_compare(it->first, k)) {
							if (it->first == k)
								return it;
							return temp;
						}
						temp = it;
					}
					return --end();
				}

				void					swap( map & x ) {
					RBTree			temp = this->tree;
					key_compare		temp2 = this->_compare;
					allocator_type	temp3 = this->_alloc_pair;
					this->tree = x.tree;
					this->_compare = x._compare;
					this->_alloc_pair = x._alloc_pair;
					x.tree = temp;
					x._compare = temp2;
					x._alloc_pair = temp3;
				}

				/* single element */
				pair<iterator, bool>	insert( const value_type& val ) {
					return (tree.insert(val));
				}

				/* with hint */
				// iterator	insert( iterator position, const value_type& val ) {

				// }

				/* range */
				template <class InputIterator>
				void	insert( InputIterator first, InputIterator last ) {
					for (; first != last; first++)
						tree.insert(*first);
				}

				void	erase( iterator position ) {
					tree.erase(position);
				}

				 void	erase( iterator first, iterator last ) {
					for (; first != last; first++)
						tree.erase(first);
				 }

	};
}


#endif