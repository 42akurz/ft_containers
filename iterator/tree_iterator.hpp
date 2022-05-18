#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

namespace ft {

	template<class T_node, class var_type>
		class tree_iterator {
			public:
				typedef ptrdiff_t						difference_type;
				typedef T_node							value_type;
				typedef T_node *						pointer;
				typedef T_node &						reference;
				typedef ft::bidirectional_iterator_tag	iterator_category;
				typedef var_type						variable_type;
		
			private:
				pointer	_ptr;

			public:
				tree_iterator( pointer ptr = nullptr ) : _ptr(ptr) {}
				tree_iterator( const tree_iterator &in ) : _ptr(in._ptr) {}
				~tree_iterator() {}

				operator			tree_iterator<value_type, variable_type> () const { return tree_iterator<value_type, const variable_type>(this->_ptr); }

				tree_iterator &		operator=( const tree_iterator & in ) { this->_ptr = in.base(); return *this; }

				pointer				base() const { return _ptr; }

				variable_type &			operator*() { return _ptr->val; }

				variable_type *			operator->() { return &(operator*()); }
		
				tree_iterator &		operator++() {
					if (!_ptr)
						return *this;
					if (_ptr->right != NULL) {
						_ptr = _ptr->right;
						while (_ptr->left != NULL)
							_ptr = _ptr->left;
					}
					else {
						pointer	cur;
						cur = _ptr->parent;
						while (cur != NULL && cur->right == _ptr) {
							_ptr = cur;
							cur = _ptr->parent;
						}
						_ptr = cur;
					}
					return *this;
				}

				tree_iterator &		operator--() {
					if (!_ptr)
						return *this;
					if (_ptr->left != NULL) {
						_ptr = _ptr->left;
						while (_ptr->right != NULL)
							_ptr = _ptr->right;
					}
					else {
						pointer	cur;
						cur = _ptr->parent;
						while (cur != NULL && cur->left == _ptr) {
							_ptr = cur;
							cur = _ptr->parent;
						}
						_ptr = cur;
					}
					return *this;
				}

				tree_iterator		operator++(int) {
					tree_iterator	temp = *this;
					++(*this);
					return temp;
				}
		
				tree_iterator		operator--(int) {
					tree_iterator	temp = *this;
					--(*this);
					return temp;
				}

				bool		operator==( const tree_iterator & in ) {
					return (this->base() == in.base());
				}
		
				bool		operator!=( const tree_iterator & in ) {
					return (this->base() != in.base());
				}
		
		}; /* class tree_iterator */
} /* namespace ft */

#endif