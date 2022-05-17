#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template <class T1, class T2> // TODO: missing some operators in pair struct
	struct pair {
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type	first;
			second_type	second;

			/* default */
			pair() {}

			/* copy */
			template<class U, class V>
			pair( const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

			/* initialization */
			pair( const first_type& a, const second_type& b ) : first(a), second(b) {}

			/* destructor */
			~pair() {}

			/* assign */
			pair &	operator=( const pair& pr ) { this->first = pr.first; this->second = pr.second; return *this;}
	};

	template <class T1, class T2>
	ft::pair<T1, T2>	make_pair( T1 x, T2 y ) {
		return	ft::pair<T1, T2>(x, y);
	}

	template <class T1, class T2>
	bool	operator==( ft::pair<T1, T2> lhs, ft::pair<T1, T2> rhs ) {
		return (lhs.first == rhs.first);
	}

	template <class T1, class T2>
	bool	operator!=( ft::pair<T1, T2> lhs, ft::pair<T1, T2> rhs ) {
		return (lhs.first != rhs.first);
	}

	template <class T1, class T2>
	bool	operator<( ft::pair<T1, T2> lhs, ft::pair<T1, T2> rhs ) {
		return (lhs.first < rhs.first);
	}

	template <class T1, class T2>
	bool	operator<=( ft::pair<T1, T2> lhs, ft::pair<T1, T2> rhs ) {
		return (lhs.first <= rhs.first);
	}

	template <class T1, class T2>
	bool	operator>( ft::pair<T1, T2> lhs, ft::pair<T1, T2> rhs ) {
		return (lhs.first > rhs.first);
	}

	template <class T1, class T2>
	bool	operator>=( ft::pair<T1, T2> lhs, ft::pair<T1, T2> rhs ) {
		return (lhs.first >= rhs.first);
	}
}

#endif