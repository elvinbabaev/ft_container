#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "RandomAccessIterator.hpp"
#include <exception>

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
		typedef RandomAccess<T>	iterator;
		typedef ReverseRandomAccess<T> reverse_iterator;
		typedef ConstRandomAccess<T>	const_iterator;
		typedef ConstReverseRandomAccess<T> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;
	private:
		value_type *c;
		size_type _size;
		size_type _capacity;
		std::allocator<T> _alloc;

		void realloc(size_type n);
	public:
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type());
//		template <class InputIterator>
//		vector (InputIterator first, InputIterator last,
//				const allocator_type& alloc = allocator_type());
		vector (const vector& x);

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);
		reference       operator[](size_type n);
		const_reference operator[](size_type n) const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
		void push_back (const value_type& val);
		void pop_back();
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
ft::vector<T, Alloc>::vector(ft::vector<T, Alloc>::size_type n, const value_type &val, const allocator_type &alloc) {
	_alloc = alloc;
	c = _alloc.allocate(n);
	for (int i = 0; i < n; ++i) {
		_alloc.construct((c + i), val);
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
		_alloc.construct((c + j), *(first++));
	}
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const ft::vector<T, Alloc> &x) {
	if (this == &x)
		return *this;
	_alloc.deallocate(c, _capacity);
	c = _alloc.allocate(x._capacity);
	for (size_type i = 0; i < x._size; ++i) {
		_alloc.construct((c + i), *(x.c + i));
	}
	this->_alloc = x._alloc;
	this->_capacity = x._capacity;
	this->_size = x._size;
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::begin() {
	return (iterator(c));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end() {
	return (iterator(c + _size));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::operator[](ft::vector<T, Alloc>::size_type n) {
	return *(c + n);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::operator[](ft::vector<T, Alloc>::size_type n) const {
	return *(c + n);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::begin() const {
	return const_iterator(c);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::end() const {
	return const_iterator(c + _size);
}

template<class T, class Alloc>
typename ft::vectorr<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rend() {
	return ft::vectorr<T, Alloc>::reverse_iterator(c);
}

template<class T, class Alloc>
typename ft::vectorr<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend() const {
	return ft::vectorr<T, Alloc>::const_reverse_iterator(c);
}

template<class T, class Alloc>
typename ft::vectorr<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rend() {
	return ft::vectorr<T, Alloc>::reverse_iterator(c + _size);
}

template<class T, class Alloc>
typename ft::vectorr<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend() const {
	return ft::vectorr<T, Alloc>::const_reverse_iterator(c + _size);
}

template<class T, class Alloc>
ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::size() const {
	return _size;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::max_size() const {
	return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::resize(ft::vector::size_type n, value_type val) {
	if (n < _size)
	{
		while (n != _size)
			// pop_back();
	}
	else
	{
		while (n != _size)
			//push_back(val);
	}
}

template<class T, class Alloc>
ft::vector::size_type ft::vector<T, Alloc>::capacity() const {
	return _capacity;
}

template<class T, class Alloc>
bool ft::vector<T, Alloc>::empty() const {
	return static_cast<bool>(_size);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::realloc(ft::vector::size_type n) {
	pointer _c;
	_c = _alloc.allocate(n);
	size_type i = 0;
	while(i < _size)
	{
		_c[i] = c[i];
		i++;
	}
	_capacity = n;
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::reserve(ft::vector<T, Alloc>::size_type n) {
	if (n > _capacity)
		realloc(n);
}

template<class T, class Alloc>
reference ft::vector<T, Alloc>::at(ft::vector::size_type n) {
	if (n >= _size)
		throw std::out_of_range;
	return *(c + n);
}

template<class T, class Alloc>
const_reference ft::vector<T, Alloc>::at(ft::vector::size_type n) const {
	if (n >= _size)
		throw std::out_of_range;
	return *(c + n);
}

template<class T, class Alloc>
reference ft::vector<T, Alloc>::front() {
	return (*c);
}

template<class T, class Alloc>
const_reference ft::vector<T, Alloc>::front() const {
	return (*c);
}

template<class T, class Alloc>
reference ft::vector<T, Alloc>::back() {
	return (*c + _size);
}

template<class T, class Alloc>
const_reference ft::vector<T, Alloc>::back() const {
	return (*c + _size);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::push_back(const value_type &val) {
	if (_n == _capacity)
		realloc(_n * 2);
	c[_n] = val;
	_n++;
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::pop_back() {
	c[_n] = nullptr;
	_size--;
}

template<class T, class Alloc>
template<class InputIterator>
void ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last) {

}

#endif
