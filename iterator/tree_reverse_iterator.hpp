#ifndef TREE_REVERSE_ITERATOR_HPP
# define TREE_REVERSE_ITERATOR_HPP

namespace ft {

	template<class Iterator>
		class tree_reverse_iterator {
			public:
				typedef typename Iterator::difference_type		difference_type;
				typedef typename Iterator::value_type			value_type;
				typedef typename Iterator::pointer				pointer;
				typedef typename Iterator::reference			reference;
				typedef typename Iterator::iterator_category	iterator_category;
				typedef typename Iterator::variable_type		variable_type;
		
			private:
				Iterator	_it;

			public:
				tree_reverse_iterator( Iterator it = nullptr ) : _it(it) {}
				tree_reverse_iterator( const tree_reverse_iterator &in ) : _it(in._it) {}
				~tree_reverse_iterator() {}

				tree_reverse_iterator &		operator=( const tree_reverse_iterator & in ) { this->_it = in.base(); return *this; }

				Iterator					base() const { return _it; }

				variable_type &					operator*() { return (*_it); }

				variable_type *					operator->() { return &(operator*()); }
		
				tree_reverse_iterator &		operator++() {
					--(_it);
					return *this;
				}

				tree_reverse_iterator &		operator--() {
					++(_it);
					return *this;
				}

				tree_reverse_iterator		operator++(int) {
					tree_reverse_iterator	temp = *this;
					++(*this);
					return temp;
				}
		
				tree_reverse_iterator		operator--(int) {
					tree_reverse_iterator	temp = *this;
					--(*this);
					return temp;
				}

				bool		operator==( const tree_reverse_iterator & in ) {
					return (this->base() == in.base());
				}
		
				bool		operator!=( const tree_reverse_iterator & in ) {
					return (this->base() != in.base());
				}
		
		}; /* class tree_reverse_iterator */
} /* namespace ft */

#endif