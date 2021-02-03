#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace ft{
	template < class T, class Alloc = std::allocator<T> >
	class vector{
	public:
		typedef T		value_type;
		typedef Alloc	allocator_type;
		typedef T&		reference;
		typedef const T& const_reference;
		typedef T*		pointer;
		typedef const T* const_pointer;
		//
		//iterator
		//
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;
	private:
		value_type *c;
		size_type _size;
		size_type _capacity;
		std::allocator<T> _alloc;
	public:
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type());
		vector (const vector& x);
	};
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type &alloc) {
	c = nullptr;
	_size = 0;
	_capacity = 0;
	_alloc = alloc;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(ft::vector::size_type n, const value_type &val, const allocator_type &alloc) {
	_alloc = alloc;
	c = _alloc.allocate(n);
	for (int i = 0; i < n; ++i) {
		_alloc.construct(n, val);
	}
	_size = n;
	_capacity = n;
}

template<class T, class Alloc>
template<class InputIterator>
ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc) {
	_alloc = alloc;
	InputIterator *tmp = first;
	size_type i = 0;
	while (tmp != last)
		i++;
	c = _alloc.allocate(i);
	for (int j = 0; j < i; ++j) {
		_alloc.construct(n, first++);
	}
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const ft::vector &x) {
	if (this == &x)
		return *this;
	this->_alloc = xx.
}


#endif
