#ifndef STACK_HPP
# define STACK_HPP

# include "../utils/log_colors.hpp"
# include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {

		public:
			typedef 	T			value_type;
			typedef 	Container	container_type;
			typedef 	size_t		size_type;

		private:
			container_type	_c;
			size_type		_size;

		public:
			container_type		base() const { return _c; }

			explicit stack( const container_type& ctnr = container_type() ) : _c(ctnr), _size(ctnr.size()) {}

			bool				empty() const { return (_size == 0); }

			size_type			size() const { return _size; }

			void				push( const value_type& val ) { _c.push_back(val); _size++; }

			void				pop() { if (_size) {_c.pop_back(); _size--;} }

			value_type &		top() { return _c.back(); }

			const value_type &	top() const { return _c.back(); }
	}; /* class stack */


	template <class T, class Container>
	bool	operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.base() == rhs.base());
	}

	template <class T, class Container>
	bool	operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.base() != rhs.base());
	}

	template <class T, class Container>
	bool	operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.base() < rhs.base());
	}

	template <class T, class Container>
	bool	operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.base() <= rhs.base());
	}

	template <class T, class Container>
	bool	operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.base() > rhs.base());
	}

	template <class T, class Container>
	bool	operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.base() >= rhs.base());
	}
} /* namespace ft */

#endif