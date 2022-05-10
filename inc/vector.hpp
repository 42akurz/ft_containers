#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <vector>
# include <exception>

# include "vector_iterator.hpp"
# include "enable_if.hpp"

# define LOG(x) (std::cout << x << std::endl)

# define LOG_RED(x) (std::cout << "\033[1;31m" << x << "\033[0m" << std::endl)
# define LOG_GREEN(x) (std::cout <<  "\033[1;32m" << x << "\033[0m" << std::endl)
# define LOG_YELLOW(x) (std::cout << "\033[1;33m" << x << "\033[0m" << std::endl)
# define LOG_BLUE(x) (std::cout << "\033[1;34m" << x << "\033[0m" << std::endl)
# define LOG_BLACK(x) (std::cout << "\033[1;30m" << x << "\033[0m" << std::endl)
# define LOG_PINK(x) (std::cout << "\033[1;35m" << x << "\033[0m" << std::endl)
# define LOG_CYAN(x) (std::cout << "\033[1;36m" << x << "\033[0m" << std::endl)
# define LOG_WHITE(x) (std::cout << "\033[1;37m" << x << "\033[0m" << std::endl)

# define LOG_RED_INFO(x) (std::cout << __FILE__ << ":" << __LINE__ << " " <<  "\033[1;31m" << x << "\033[0m" << std::endl)
# define LOG_GREEN_INFO(x) (std::cout << __FILE__ << ":" << __LINE__ << " " << "\033[1;32m" << x << "\033[0m" << std::endl)
# define LOG_YELLOW_INFO(x) (std::cout << __FILE__ << ":" << __LINE__ << " " << "\033[1;33m" << x << "\033[0m" << std::endl)
# define LOG_BLUE_INFO(x) (std::cout << __FILE__ << ":" << __LINE__ << " " << "\033[1;34m" << x << "\033[0m" << std::endl)
# define LOG_BLACK_INFO(x) (std::cout << __FILE__ << ":" << __LINE__ << " " << "\033[1;30m" << x << "\033[0m" << std::endl)
# define LOG_PINK_INFO(x) (std::cout << __FILE__ << ":" << __LINE__ << " " << "\033[1;35m" << x << "\033[0m" << std::endl)
# define LOG_CYAN_INFO(x) (std::cout << __FILE__ << ":" << __LINE__ << " " <<  "\033[1;36m" << x << "\033[0m" << std::endl)
# define LOG_WHITE_INFO(x) (std::cout << __FILE__ << ":" << __LINE__ << " " << "\033[1;37m" << x << "\033[0m" << std::endl)

// template< typename T >
// void	printVectors( std::vector<T> &real, ft::vector<T> &mine ) {
// 	LOG(std::endl << "\033[1;31m" << "Real Vector -----\t" << "\033[0m" << "\033[1;36m" << "My Vector -------" << "\033[0m");
// 	for(size_t i = 0; ((i < real.size()) && (i < mine.size())); i++) {
// 		LOG("\033[1;31m" << real[i] << "                \t" << "\033[0m" << "\033[1;36m" << mine[i] << "                " << "\033[0m");
// 	}
// 	LOG("\033[1;31m" << "-----------------\t" << "\033[0m" << "\033[1;36m" << "----------------- " << "\033[0m");
// }

// void	printRealVector( std::vector<int> &real ) {
// 	LOG_RED(std::endl << "Real Vector -----");
// 	for(std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
// 		LOG_RED(*it);
// 	LOG_RED("-----------------");
// }

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef				T													value_type;
			typedef				Alloc												allocator_type;
			typedef typename	allocator_type::reference							reference;
			typedef typename	allocator_type::const_reference						const_reference;
			typedef typename	allocator_type::pointer								pointer; // T*
			typedef typename	allocator_type::const_pointer						const_pointer;
			typedef typename	allocator_type::size_type							size_type;

			typedef typename	ft::vector_iterator<value_type>						iterator;
			typedef 			ft::vector_iterator<const value_type>				const_iterator;
			typedef typename	ft::vector_iterator<value_type>::difference_type	difference_type; // TOD: check if this is even allowed

		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_ptr;
			Alloc			_alloc;

			iterator		_front;
			iterator		_back;

		private:
			// TODO: im not even using it yet
			pointer	reallocate( size_type new_capacity ) {
				for (size_t i = 0; i < this->size(); i++)
					this->_alloc.destroy(&this->_ptr[i]);
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				pointer	newPtr = this->_alloc.allocate(new_capacity);
				return (newPtr);
			}

		public:
			// TODO: delete this function
			void	printVector( void ) {
				LOG_CYAN(std::endl << "My Vector -------");
				for (size_t i = 0; i < this->_size; i++)
					LOG_CYAN(this->_ptr[i]);
				LOG_CYAN("-----------------");
			}

			explicit vector ( const allocator_type& alloc = allocator_type() ) {
				this->_alloc = alloc;
				this->_ptr = this->_alloc.allocate(0);
				this->_size = 0;
				this->_capacity = 0;
				// TODO: whats going on with the iterators here?
			}

			explicit vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ) {
				this->_alloc = alloc;
				this->_ptr = this->_alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
					this->_alloc.construct(&this->_ptr[i], val);
				this->_size = n;
				this->_capacity = n;

				// iterators // TODO: not tested
				this->_front = this->_ptr;
				this->_back = &this->_ptr[this->_size - 1];
			}

			// range constructor
			// template <class InputIterator>
			// vector ( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ) {
			// }

			vector ( const vector& x ) {
				this->_alloc = x.get_allocator();
				this->_ptr = this->_alloc.allocate(x._capacity); // TODO: test if size or capacity is used?
				for (size_t i = 0; i < x._size; i++)
					this->_alloc.construct(&this->_ptr[i], x._ptr[i]);
				this->_capacity = x._capacity;
				this->_size = x._size;

				// iterators // TODO: not tested
				this->_front = this->_ptr;
				this->_back = &this->_ptr[this->_size - 1];
			}

			size_type size() const { return (this->_size); }

			size_type max_size() const { return (this->_alloc.max_size()); }

			bool empty() const { return (this->_size == 0); }

			size_type capacity() const { return (this->_capacity); }

			// TODO: add exceptions
			void reserve ( size_type n ) {
				// if (n < 0)
				// 	throw exception
				if (n > this->_alloc.max_size())
					throw std::length_error("vector");
				if (n <= this->_capacity)
					return ;

				pointer	newPtr = this->_alloc.allocate(n);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.construct(&newPtr[i], this->_ptr[i]);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&(this->_ptr[i]));
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_ptr = newPtr;
				this->_capacity = n;

				// iterators // TODO: not tested
				this->_front = this->_ptr;
				this->_back = &this->_ptr[this->_size - 1];
			}

			void	push_back( const value_type& val ) {
				if (this->_capacity > this->_size) {
					this->_alloc.construct(&this->_ptr[this->_size], val);
					this->_size++;
					
					// iterator
					this->_back = &this->_ptr[this->_size - 1];
				}
				else if (!this->_capacity && !this->_size) {
					pointer	newPtr = this->_alloc.allocate(1);
					this->_alloc.deallocate(this->_ptr, this->_capacity); // TODO: capacity is zero, so do nothing?
					this->_ptr = newPtr;
					this->_alloc.construct(&this->_ptr[this->_size], val);
					this->_capacity++;
					this->_size++;

					// iterators
					this->_front = this->_ptr;
					this->_back = this->_ptr;
				}
				else if (this->_capacity == this->_size) {
					pointer	newPtr = this->_alloc.allocate(this->_capacity * 2);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.construct(&newPtr[i], this->_ptr[i]);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_alloc.construct(&this->_ptr[this->_size], val);
					this->_capacity *= 2;
					this->_size++;

					// iterators
					this->_front = this->_ptr;
					this->_back = &this->_ptr[this->_size - 1];
				}
			}

			reference	at( size_type n ) {
				if (n >= this->_size) {
					throw std::out_of_range("vector");
				}
				return this->_ptr[n];
			}

			// gets called when vec is classified as const
			const_reference	at( size_type n ) const {
				if (n >= this->_size) {
					throw std::out_of_range("vector");
				}
				return this->_ptr[n];
			}

			// TODO: what happens to allocator and capacity?
			void	clear() {
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_ptr[i]);
				this->_size = 0;

				// iterators TODO: ??
			}

			allocator_type	get_allocator() const {
				Alloc	copy(this->_alloc);
				return copy;
			}

			// TODO: not sure, if element should be destroyed
			// TODO: not sure, what to do when container empty --> real has undefined behaviour
			void	pop_back() {
				if (this->_size == 0)
					return ;
				this->_alloc.destroy(&this->_ptr[this->_size - 1]);
				this->_size--;

				// iterators TODO: not tested
				this->_back = &this->_ptr[this->_size - 1];
			}

			void	resize( size_type n, value_type val = value_type() ) {
				if (n < this->_size) { // TODO: tests (what is with capacity?)
					for (size_t i = n; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_size = n;

					// iterator
					this->_back = &this->_ptr[this->_size - 1];
				}
				else if (n > this->_size && n > this->_capacity) { // TODO: tests
					pointer	newPtr = this->_alloc.allocate(n); // TODO: guess i can usepush_back instead of doing perfect alloc
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.construct(&newPtr[i], this->_ptr[i]);
					for (size_t i = this->_size; i < n; i++)
						this->_alloc.construct(&newPtr[i], val);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_capacity = n;
					this->_size = n;

					// iterator
					this->_front = this->_ptr;
					this->_back = &this->_ptr[this->_size - 1];
				}
				else if (n > this->_size && n <= this->_capacity) { // TODO: tests
					for (size_t i = this->_size; i < n; i++)
						this->_alloc.construct(&this->_ptr[i], val);
					this->_size = n;

					// iterator
					this->_back = &this->_ptr[this->_size - 1];
				}
			}

			void	swap( vector& x ) {
				size_type	temp_size;
				size_type	temp_capacity;
				pointer		temp_ptr;
				Alloc		temp_alloc;
				iterator	temp_front;
				iterator	temp_back;

				temp_size = this->_size;
				temp_capacity = this->_capacity;
				temp_ptr = this->_ptr;
				temp_alloc = this->_alloc;
				temp_front = this->_front;
				temp_back = this->_back;

				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_ptr = x._ptr;
				this->_alloc = x._alloc;
				this->_front = x._front;
				this->_back = x._back;

				x._size = temp_size;
				x._capacity = temp_capacity;
				x._ptr = temp_ptr;
				x._alloc = temp_alloc;
				x._front = temp_front;
				x._back = temp_back;
			}

			// TODO: when doing assignations, like mine[i] = i; something doesnt work!!!
			reference	operator[]( size_type n ) { return (this->_ptr[n]); }

			// TODO: when doing assignations, like mine[i] = i; something doesnt work!!!
			const_reference	operator[]( size_type n ) const { return (this->_ptr[n]); }

			// https://www.cplusplus.com/reference/vector/vector/operator=/
			// TODO: more tests
			// it says: The container preserves its current allocator, which is used to allocate storage in case of reallocation.
			// call get_allocator?
			vector &	operator=( const vector& x ) {
				// TODO: size or capacity ?
				if (this->_capacity >= x._capacity) {
					// TODO: size or capacity ?
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					for (size_t i = 0; i < x._size; i++)
						this->_alloc.construct(&this->_ptr[i], x._ptr[i]);
					this->_size = x._size;

					// iterator
					this->_front = this->_ptr;
					this->_back = &this->_ptr[this->_size - 1];
				}
				else if (this->_capacity < x._capacity) {
					// TODO: size or capacity ?
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = this->_alloc.allocate(x._size);
					for (size_t i = 0; i < x._size; i++)
						this->_alloc.construct(&this->_ptr[i], x._ptr[i]);
					this->_size = x._size;
					this->_capacity = x._size;
					
					// iterator
					this->_front = this->_ptr;
					this->_back = &this->_ptr[this->_size - 1];
				}
				return *this;
			}

			iterator	begin() { return this->_front; }

			const_iterator	begin() const { return (const_iterator(this->_front.base())); }

			iterator	end() {
				iterator	temp = this->_back;
				temp++;
				return temp;
			}

			const_iterator	end() const {
				iterator	temp = this->_back;
				temp++;
				return (const_iterator(temp.base()));
			}

			reference	front() { return (this->_ptr[0]); }

			const_reference	front() const { return (this->_ptr[0]); }

			reference	back() { return (this->_ptr[this->_size - 1]); }

			const_reference	back() const { return (this->_ptr[this->_size - 1]); }

			// range
			template <class InputIterator>
			void	assign( InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0 ) {
				// TODO: improvised get distance
				size_t	distance = 0;
				for (InputIterator temp = first; temp != last; temp++)
					distance++;

				if (distance > this->_capacity) {
					pointer	newPtr = this->_alloc.allocate(distance);

					InputIterator	it = first;
					for (size_t i = 0; i < distance; i++) {
						this->_alloc.construct(&newPtr[i], (*it));
						it++;
					}

					for (size_t i = 0; i < this->_size; i++) {
						this->_alloc.destroy(&this->_ptr[i]);
					}
					this->_alloc.deallocate(this->_ptr, this->_capacity);

					this->_ptr = newPtr;

					// TODO: not sure if this is true, test distances
					this->_size = distance;
					this->_capacity = distance;

					// iterators
					this->_front = first;
					this->_back = last;
					--this->_back;
				}
				else {
					for (size_t i = 0; i < this->_size; i++) {
						this->_alloc.destroy(&this->_ptr[i]);
					}

					InputIterator	it = first;
					for (size_t i = 0; i < distance; i++) {
						this->_alloc.construct(&this->_ptr[i], (*it));
						it++;
					}

					this->_size = distance;

					// iterators
					this->_front = first;
					this->_back = last;
					--this->_back;
				}
			}
			
			// fill
			void	assign( size_type n, const T& val ) {
				if (n > this->_capacity) {
					pointer	newPtr = this->_alloc.allocate(n);
					for (size_t i = 0; i < n; i++)
						this->_alloc.construct(&newPtr[i], val);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_size = n;
					this->_capacity = n;

					// iterators
					this->_front = this->_ptr;
					this->_back = &this->_ptr[this->_size - 1];
				}
				else {
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					for (size_t i = 0; i < n; i++)
						this->_alloc.construct(&this->_ptr[i], val);
					this->_size = n;

					// iterators
					this->_front = this->_ptr;
					this->_back = &this->_ptr[this->_size - 1];
				}
			}

			// TODO: gibt safe efiizienter methoden, als bis zu position loopen
			// TODO: real one segfauts, when end is passed
			// TODO: when last element of vector, i should return the one i removed
			iterator	erase( iterator position ) {
				pointer		newPtr = this->_alloc.allocate(this->_capacity);
				iterator	beg = this->_front;
				iterator	temp = this->_back;
				for (size_t i = 0; beg != this->end(); beg++) {
					if (position != beg) {
						this->_alloc.construct(&newPtr[i], (*beg));
						i++;
					}
				}
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_ptr[i]);
				this->_alloc.deallocate(this->_ptr, this->_capacity);

				this->_ptr = newPtr;
				this->_size--;
				this->_front = this->_ptr;
				this->_back = &this->_ptr[this->_size - 1];

				if (position == temp) {
					return position;
				}
				else {
					iterator	ret = position;
					return (++ret); // TODO: are there edgecases?
				}
			}

			/*	range
				the range includes all the elements between first and last,
				including the element pointed by first but not the one pointed by last.
			*/
			iterator	erase( iterator first, iterator last ) {
				if (last == end()) {
					while (end() != first)
						pop_back();
					return (_back + 1);
				}
				else {
					pointer		newPtr = this->_alloc.allocate(this->_capacity);
					size_t		i = 0;
					size_type	newSize = 0;
					for ( ; &this->_ptr[i] != &(*first); i++) {
						this->_alloc.construct(&newPtr[i], this->_ptr[i]);
						newSize++;
					}
					while (&this->_ptr[i] != &(*last))
						i++;
					for ( ; i < this->_size; i++) {
						this->_alloc.construct(&newPtr[newSize], this->_ptr[i]);
						newSize++;
					}

					for (size_t x = 0; x < this->_size; x++) // TODO: instead of doing this, do clear() everywhere
						this->_alloc.destroy(&this->_ptr[i]);
					this->_alloc.deallocate(this->_ptr, this->_capacity);

					this->_size = newSize;
					this->_ptr = newPtr;
					this->_front = this->_ptr;
					this->_back = &this->_ptr[this->_size  -1];

					return (last); // TODO: correct? ne weil iteartor ist nicht auf gleichem memory bereich, weil ich neu allocated habe
				}
			}

			// single element
			iterator	insert( iterator position, const value_type& val ) {
				pointer		newPtr;
				size_type	sizeToAllocate;
				if (this->_capacity == this->_size)
					sizeToAllocate = this->_capacity * 2;
				else
					sizeToAllocate = this->_capacity; // TODO: wieso allocate ich uerbhaupt neu??? ich kann einfach clearen in solchen cases
			
				newPtr = this->_alloc.allocate(sizeToAllocate);

				size_t	i = 0;
				for (; &this->_ptr[i] != &(*position); i++)
					this->_alloc.construct(&newPtr[i], this->_ptr[i]);
				// i++;
				this->_alloc.construct(&newPtr[i], val);
				iterator	ret = iterator(&newPtr[i]);
				i++;
				for (; i < this->_size + 1; i++)
					this->_alloc.construct(&newPtr[i], this->_ptr[i - 1]);

				size_type	newSize = this->_size + 1;
				this->clear();
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_ptr = newPtr;
				this->_size = newSize;
				this->_capacity = sizeToAllocate;

				this->_front = this->_ptr;
				this->_back = &this->_ptr[this->_size - 1];
				return ret;
			}

			// fill
			// void	insert( iterator position, size_type n, const value_type& val ) {

			// }

			// // range
			// template <class InputIterator>
			// void	insert( iterator position, InputIterator first, InputIterator last ) {

			// }

	};

	template <class T, class Alloc>
	bool	operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++) {
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool	operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return true;
		for (size_t i = 0; i < lhs.size(); i++) {
			if (lhs[i] != rhs[i])
				return true;
		}
		return false;
	}

	template <class T, class Alloc>
	bool	operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		for (size_t i = 0; ((i < lhs.size()) && (i < rhs.size())); i++) {
			if (lhs[i] < rhs[i])
				return true;
			if (lhs[i] > rhs[i])
				return false;
		}
		if (lhs.size() < rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool	operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		for (size_t i = 0; ((i < lhs.size()) && (i < rhs.size())); i++) {
			if (lhs[i] < rhs[i])
				return true;
			if (lhs[i] > rhs[i])
				return false;
		}
		if (lhs.size() <= rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool	operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		for (size_t i = 0; ((i < lhs.size()) && (i < rhs.size())); i++) {
			if (lhs[i] > rhs[i])
				return true;
			if (lhs[i] < rhs[i])
				return false;
		}
		if (lhs.size() > rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool	operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		for (size_t i = 0; ((i < lhs.size()) && (i < rhs.size())); i++) {
			if (lhs[i] > rhs[i])
				return true;
			if (lhs[i] < rhs[i])
				return false;
		}
		if (lhs.size() >= rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	void	swap( vector<T,Alloc>& x, vector<T,Alloc>& y ) {
		x.swap(y);
	}
}


#endif