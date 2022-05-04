#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <vector>
# include <exception>
// # include <iterator>

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

namespace ft {

	// struct input_iterator_tag {};
	// struct output_iterator_tag {};
	// struct forward_iterator_tag {};
	// struct bidirectional_iterator_tag {};
	// struct random_access_iterator_tag {};

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		// class iterator {
		// 	private:
		// 		T*	;
		// };

		public:
			typedef				T								value_type;
			typedef				Alloc							allocator_type;
			typedef typename	allocator_type::reference		reference;
			typedef typename	allocator_type::const_reference	const_reference;
			typedef typename	allocator_type::pointer			pointer; // T*
			typedef typename	allocator_type::const_pointer	const_pointer;
			typedef typename	allocator_type::size_type		size_type;



			explicit vector ( const allocator_type& alloc = allocator_type() ) {

				pointer						vPtr;
				Alloc						v = alloc;

				vPtr = v.allocate(0);

				this->_size = 0;
				this->_capacity = 0;
				this->_ptr = vPtr;
				this->_v = v;
			}

			explicit vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ) {

				pointer		vPtr;
				Alloc		v = alloc;

				vPtr = v.allocate(n);
				for (size_t i = 0; i < n; i++)
					v.construct(&vPtr[i], val);
				// vPtr[i] = val;// old one

				this->_size = n;
				this->_capacity = n;
				this->_ptr = vPtr;
				this->_v = v;
			}

			// range constructor
			// template <class InputIterator>
			// vector ( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ) {
			// }

			vector ( const vector& x ) {

				pointer	vPtr;
				Alloc	v = allocator_type();

				vPtr = v.allocate(x._size);
				for (size_t i = 0; i < x._size; i++)
					v.construct(&vPtr[i], x._ptr[i]);
				// vPtr[i] = x._ptr[i]; // old one

				this->_ptr = vPtr;
				this->_capacity = x._capacity;
				this->_size = x._size;
				this->_v = v;
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

				Alloc	newV = allocator_type();
				pointer	newPtr = newV.allocate(n);

				for (size_t i = 0; i < this->_size; i++)
					newV.construct(&newPtr[i], this->_ptr[i]);
				// newPtr[i] = this->_ptr[i]; // old one

				// TODO: destroy pointer or objects?
				// TODO: destroy length or capacity?
				// TODO: deos this even make sense?
				for (size_t i = 0; i < this->_capacity; i++)
					this->_v.destroy(&(this->_ptr[i]));
				this->_v.deallocate(this->_ptr, this->_capacity);

				this->_v = newV;
				this->_ptr = newPtr;
				this->_capacity = n;
			}

			void	printVector( void ) {
				LOG_CYAN(std::endl << "My Vector -------");
				for (size_t i = 0; i < this->_size; i++)
					LOG_CYAN(this->_ptr[i]);
				LOG_CYAN("-----------------");
			}

			// TODO: i can use construct on _v to copy the content
			// TODO: maybe have to use contruct to write elements into vector
			// TODO: maybe destroy objects when deallocating, or reuse them
			void	push_back( const value_type& val ) {
				if (this->_capacity > this->_size) {
					this->_v.construct(&this->_ptr[this->_size], val);
					// this->_ptr[this->_size] = val; // old one
					this->_size++;
				}
				else if (!this->_capacity && !this->_size) {
					Alloc	newV = allocator_type();
					pointer	newPtr = newV.allocate(1);
					this->_v.deallocate(this->_ptr, this->_capacity);
					this->_v = newV;
					this->_ptr = newPtr;
					// this->_ptr[this->_size] = val; // old one
					this->_v.construct(&this->_ptr[this->_size], val);
					this->_capacity++;
					this->_size++;
				}
				else if (this->_capacity == this->_size) {
					Alloc	newV = allocator_type();
					pointer	newPtr = newV.allocate(this->_capacity * 2);
					for (size_t i = 0; i < this->_size; i++)
						newV.construct(&newPtr[i], this->_ptr[i]);
					// newPtr[i] = this->_ptr[i]; // old one
					// TODO: capacity or size for destroying length
					for (size_t i = 0; i < this->_capacity; i++)
						this->_v.destroy(&(this->_ptr[i]));
					this->_v.deallocate(this->_ptr, this->_capacity);
					this->_v = newV;
					this->_ptr = newPtr;
					// this->_ptr[this->_size] = val; // old one
					this->_v.construct(&this->_ptr[this->_size], val);
					this->_capacity *= 2;
					this->_size++;
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

			void	clear() {
				for (size_t i = 0; i < this->_size; i++)
					this->_v.destroy(&(this->_ptr[i]));
				this->_size = 0;
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
			}

			void	resize( size_type n, value_type val = value_type() ) {
				LOG_WHITE("|" << val << "|");
				if (n < this->_size) { // TODO: tests (what is with capacity?)
					for (size_t i = n; i < this->_size; i++)
						this->_v.destroy(&this->_ptr[i]);
					this->_size = n;
				}
				else if (n > this->_size && n > this->_capacity) { // TODO: tests
					Alloc	newV = allocator_type();
					pointer	newPtr = newV.allocate(n); // TODO: guess i can usepush_back instead of doing perfect alloc
					for (size_t i = 0; i < this->_size; i++)
						newV.construct(&newPtr[i], this->_ptr[i]);
					for (size_t i = this->_size; i < n; i++)
						newV.construct(&newPtr[i], val);
					for (size_t i = 0; i < this->_capacity; i++)
						this->_v.destroy(&this->_ptr[i]);
					this->_v.deallocate(this->_ptr, this->_capacity);
					this->_v = newV;
					this->_ptr = newPtr;
					this->_capacity = n;
					this->_size = n;
				}
				else if (n > this->_size && n <= this->_capacity) { // TODO: tests
					for (size_t i = this->_size; i < n; i++)
						this->_v.construct(&this->_ptr[i], val);
					this->_size = n;
				}
			}

			void	swap( vector& x ) {
				size_type	temp_size;
				size_type	temp_capacity;
				pointer		temp_ptr;
				Alloc		temp_v;

				temp_size = this->_size;
				temp_capacity = this->_capacity;
				temp_ptr = this->_ptr;
				temp_v = this->_v;

				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_ptr = x._ptr;
				this->_v = x._v;

				x._size = temp_size;
				x._capacity = temp_capacity;
				x._ptr = temp_ptr;
				x._v = temp_v;
			}

			reference	operator[]( size_type n ) {
				return (this->_ptr[n]);
			}

			const_reference	operator[]( size_type n ) const {
				return (this->_ptr[n]);
			}

			// https://www.cplusplus.com/reference/vector/vector/operator=/
			// TODO: tests
			// it says: The container preserves its current allocator, which is used to allocate storage in case of reallocation.
			// call get_allocator?
			vector &	operator=( const vector& x ) {
				// TODO: size or capacity ?
				for (size_t i = 0; i < this->_size; i++) {
					this->_v.destroy(&this->_ptr[i]);
				}
			}


			private:
				size_type		_size;
				// size_type		_max_size;
				size_type		_capacity;
				pointer			_ptr;
				Alloc			_v;

	};

}


#endif