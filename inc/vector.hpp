#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <vector>
# include <exception>

# include "vector_iterator.hpp"

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
			typedef				T										value_type;
			typedef				Alloc									allocator_type;
			typedef typename	allocator_type::reference				reference;
			typedef typename	allocator_type::const_reference			const_reference;
			typedef typename	allocator_type::pointer					pointer; // T*
			typedef typename	allocator_type::const_pointer			const_pointer;
			typedef typename	allocator_type::size_type				size_type;

			typedef typename	ft::vector_iterator<value_type>			iterator;
			typedef 			ft::vector_iterator<const value_type>	const_iterator;

		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_ptr;
			Alloc			_v;

			iterator		_first;
			iterator		_last;

		private:
			// TODO: im not even using it yet
			pointer	reallocate( size_type new_capacity ) {
				for (size_t i = 0; i < this->size(); i++)
					this->_v.destroy(&this->_ptr[i]);
				this->_v.deallocate(this->_ptr, this->_capacity);
				pointer	newPtr = this->_v.allocate(new_capacity);
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
				this->_v = alloc;
				this->_ptr = this->_v.allocate(0);
				this->_size = 0;
				this->_capacity = 0;
				// TODO: whats going on with the iterators here?
			}

			explicit vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ) {
				this->_v = alloc;
				this->_ptr = this->_v.allocate(n);
				for (size_t i = 0; i < n; i++)
					this->_v.construct(&this->_ptr[i], val);
				this->_size = n;
				this->_capacity = n;

				// iterators // TODO: not tested
				this->_first = this->_ptr;
				this->_last = &this->_ptr[this->_size - 1];
			}

			// range constructor
			// template <class InputIterator>
			// vector ( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ) {
			// }

			vector ( const vector& x ) {
				this->_v = x.get_allocator();
				this->_ptr = this->_v.allocate(x._capacity); // TODO: test if size or capacity is used?
				for (size_t i = 0; i < x._size; i++)
					this->_v.construct(&this->_ptr[i], x._ptr[i]);
				this->_capacity = x._capacity;
				this->_size = x._size;

				// iterators // TODO: not tested
				this->_first = this->_ptr;
				this->_last = &this->_ptr[this->_size - 1];
			}

			size_type size() const {
				return this->_size;
			}

			size_type max_size() const {
				return this->_v.max_size();
			}

			bool empty() const {
				if (this->_size == 0)
					return true;
				else
					return false;
			}

			size_type capacity() const {
				return this->_capacity;
			}

			// TODO: add exceptions
			void reserve ( size_type n ) {
				// if (n < 0)
				// 	throw exception
				if (n > this->_v.max_size())
					throw std::length_error("vector");
				if (n <= this->_capacity)
					return ;

				pointer	newPtr = this->_v.allocate(n);
				for (size_t i = 0; i < this->_size; i++)
					this->_v.construct(&newPtr[i], this->_ptr[i]);
				for (size_t i = 0; i < this->_size; i++)
					this->_v.destroy(&(this->_ptr[i]));
				this->_v.deallocate(this->_ptr, this->_capacity);
				this->_ptr = newPtr;
				this->_capacity = n;

				// iterators // TODO: not tested
				this->_first = this->_ptr;
				this->_last = &this->_ptr[this->_size - 1];
			}

			void	push_back( const value_type& val ) {
				if (this->_capacity > this->_size) {
					this->_v.construct(&this->_ptr[this->_size], val);
					this->_size++;
					
					// iterator
					this->_last++;
				}
				else if (!this->_capacity && !this->_size) {
					pointer	newPtr = this->_v.allocate(1);
					this->_v.deallocate(this->_ptr, this->_capacity); // TODO: capacity is zero, so do nothing?
					this->_ptr = newPtr;
					this->_v.construct(&this->_ptr[this->_size], val);
					this->_capacity++;
					this->_size++;

					// iterators
					this->_first = this->_ptr;
					this->_last = this->_ptr;
				}
				else if (this->_capacity == this->_size) {
					pointer	newPtr = this->_v.allocate(this->_capacity * 2);
					for (size_t i = 0; i < this->_size; i++)
						this->_v.construct(&newPtr[i], this->_ptr[i]);
					for (size_t i = 0; i < this->_size; i++)
						this->_v.destroy(&this->_ptr[i]);
					this->_v.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_v.construct(&this->_ptr[this->_size], val);
					this->_capacity *= 2;
					this->_size++;

					// iterators
					this->_first = this->_ptr;
					this->_last = &this->_ptr[this->_size - 1];
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
					this->_v.destroy(&this->_ptr[i]);
				this->_size = 0;

				// iterators TODO: not tested
				// this->_first = nullptr;
				// this->_last = nullptr;
			}

			allocator_type	get_allocator() const {
				Alloc	copy(this->_v);
				return copy;
			}

			// TODO: not sure, if element should be destroyed
			// TODO: not sure, what to do when container empty --> real has undefined behaviour
			void	pop_back() {
				if (this->_size == 0)
					return ;
				this->_v.destroy(&this->_ptr[this->_size - 1]);
				this->_size--;

				// iterators TODO: not tested
				this->_last = &this->_ptr[this->_size - 1];
			}

			void	resize( size_type n, value_type val = value_type() ) {
				if (n < this->_size) { // TODO: tests (what is with capacity?)
					for (size_t i = n; i < this->_size; i++)
						this->_v.destroy(&this->_ptr[i]);
					this->_size = n;

					// iterator
					this->_last = &this->_ptr[this->_size - 1];
				}
				else if (n > this->_size && n > this->_capacity) { // TODO: tests
					pointer	newPtr = this->_v.allocate(n); // TODO: guess i can usepush_back instead of doing perfect alloc
					for (size_t i = 0; i < this->_size; i++)
						this->_v.construct(&newPtr[i], this->_ptr[i]);
					for (size_t i = this->_size; i < n; i++)
						this->_v.construct(&newPtr[i], val);
					for (size_t i = 0; i < this->_size; i++)
						this->_v.destroy(&this->_ptr[i]);
					this->_v.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_capacity = n;
					this->_size = n;

					// iterator
					this->_first = this->_ptr;
					this->_last = &this->_ptr[this->_size - 1];
				}
				else if (n > this->_size && n <= this->_capacity) { // TODO: tests
					for (size_t i = this->_size; i < n; i++)
						this->_v.construct(&this->_ptr[i], val);
					this->_size = n;

					// iterator
					this->_last = &this->_ptr[this->_size - 1];
				}
			}

			void	swap( vector& x ) {
				size_type	temp_size;
				size_type	temp_capacity;
				pointer		temp_ptr;
				Alloc		temp_v;
				iterator	temp_first;
				iterator	temp_last;

				temp_size = this->_size;
				temp_capacity = this->_capacity;
				temp_ptr = this->_ptr;
				temp_v = this->_v;
				temp_first = this->_first;
				temp_last = this->_last;

				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_ptr = x._ptr;
				this->_v = x._v;
				this->_first = x._first;
				this->_last = x._last;

				x._size = temp_size;
				x._capacity = temp_capacity;
				x._ptr = temp_ptr;
				x._v = temp_v;
				x._first = temp_first;
				x._last = temp_last;
			}

			// TODO: when doing assignations, like mine[i] = i; something doesnt work!!!
			reference	operator[]( size_type n ) {
				return (this->_ptr[n]);
			}

			// TODO: when doing assignations, like mine[i] = i; something doesnt work!!!
			const_reference	operator[]( size_type n ) const {
				return (this->_ptr[n]);
			}

			// https://www.cplusplus.com/reference/vector/vector/operator=/
			// TODO: more tests
			// it says: The container preserves its current allocator, which is used to allocate storage in case of reallocation.
			// call get_allocator?
			vector &	operator=( const vector& x ) {
				// TODO: size or capacity ?
				if (this->_capacity >= x._capacity) {
					// TODO: size or capacity ?
					for (size_t i = 0; i < this->_size; i++)
						this->_v.destroy(&this->_ptr[i]);
					for (size_t i = 0; i < x._size; i++)
						this->_v.construct(&this->_ptr[i], x._ptr[i]);
					this->_size = x._size;

					// iterator
					this->_first = this->_ptr;
					this->_last = &this->_ptr[this->_size - 1];
				}
				else if (this->_capacity < x._capacity) {
					// TODO: size or capacity ?
					for (size_t i = 0; i < this->_size; i++)
						this->_v.destroy(&this->_ptr[i]);
					this->_v.deallocate(this->_ptr, this->_capacity);
					this->_ptr = this->_v.allocate(x._size);
					for (size_t i = 0; i < x._size; i++)
						this->_v.construct(&this->_ptr[i], x._ptr[i]);
					this->_size = x._size;
					this->_capacity = x._size;
					
					// iterator
					this->_first = this->_ptr;
					this->_last = &this->_ptr[this->_size - 1];
				}
				return *this;
			}

			iterator	begin() {
				return this->_first;
			}

			const_iterator	begin() const {
				return (const_iterator(this->_first.base()));
			}

			iterator	end() {
				iterator	temp = this->_last;
				temp++;
				return temp;
			}

			const_iterator	end() const {
				iterator	temp = this->_last;
				temp++;
				return (const_iterator(temp.base()));
			}

			reference	front() {
				return (this->_ptr[0]);
			}

			const_reference	front() const {
				return (this->_ptr[0]);
			}

			reference	back() {
				return (this->_ptr[this->_size - 1]);
			}

			const_reference	back() const {
				return (this->_ptr[this->_size - 1]);
			}

			// range // TODO: something aint right bro
			template <class InputIterator>
			void	assign( InputIterator first, InputIterator last ) {
				// TODO: improvised get distance
				size_t	distance = 0;
				for (InputIterator temp = first; temp != last; temp++)
					distance++;

				if (distance > this->_capacity) {
					pointer	newPtr = this->_v.allocate(distance);

					InputIterator	it = first;
					for (size_t i = 0; i < distance; i++) {
						this->_v.construct(&newPtr[i], (*it)); // todo something here sucks hard
						it++;
					}

					for (size_t i = 0; i < this->_size; i++) {
						this->_v.destroy(&this->_ptr[i]);
					}
					this->_v.deallocate(this->_ptr, this->_capacity);

					this->_ptr = newPtr;

					// TODO: not sure if this is true, test distances
					this->_size = distance;
					this->_capacity = distance;

					// iterators
					this->_first = first;
					this->_last = last;
					--this->_last;
				}
				else {
					for (size_t i = 0; i < this->_size; i++) {
						this->_v.destroy(&this->_ptr[i]);
					}

					InputIterator	it = first;
					for (size_t i = 0; i < distance; i++) {
						this->_v.construct(&this->_ptr[i], (*it)); // TODO: sucks as well most likely
						it++;
					}

					this->_size = distance;

					// iterators
					this->_first = first;
					this->_last = last;
					--this->_last;
				}
			}
			
			// fill // TODO: something aint right
			void	assign( size_type n, const value_type& val ) {
				if (n > this->_capacity) {
					pointer	newPtr = this->_v.allocate(n);
					for (size_t i = 0; i < n; i++)
						this->_v.construct(&newPtr[i], val);
					for (size_t i = 0; i < this->_size; i++)
						this->_v.destroy(&this->_ptr[i]);
					this->_v.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_size = n;
					this->_capacity = n;

					// iterators
					this->_first = this->_ptr;
					this->_last = &this->_ptr[this->_size - 1];
				}
				else {
					for (size_t i = 0; i < this->_size; i++)
						this->_v.destroy(&this->_ptr[i]);
					for (size_t i = 0; i < n; i++)
						this->_v.construct(&this->_ptr[i], val);
					this->_size = n;

					// iterators
					this->_first = this->_ptr;
					this->_last = &this->_ptr[this->_size - 1];
				}
			}

			// TODO: gibt safe efiizienter methoden, also bius zu position zu loopen
			iterator	erase( iterator position ) {
				pointer	newPtr = this->_v.allocate(this->size() - 1); // TODO: check if this makes sense!!
				for (size_t i = 0; i < this->_size; i++) {
					if (position != &this->_ptr[i])
						this->_v.construct(&this->newPtr[i], this->_ptr[i]);
				}
				for (size_t i = 0; i < this->_size; i++)
					this->_v.destroy(&this->_ptr[i]);
				this->_v.deallocate(this->_ptr, this->_capacity);

				this->_ptr = newPtr;
				this->_size--;
				this->_capacity = this->_size;
				this->_first = this->_ptr;
				this->_last = &this->_ptr[this->_size - 1];

				return (this->_last); // TODO: wrong, look here: https://www.cplusplus.com/reference/vector/vector/erase/
			}

			// iterator	erase( iterator first, iterator last ) {

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