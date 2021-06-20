#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "../iterator/RandomAccessIterator.hpp"
#include <exception>

namespace ft{
    template <class T>
    void	swap_c(T &a, T &b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

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

	public:
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type());

        template<class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type());
		vector (const vector& x);
		vector& operator=(const vector& x) {
			if (_capacity != 0)
				this->clear();
			this->c = new value_type[x._capacity];
			assign(x.begin(), x.end());
			return *this;
		}
		~vector() {
			delete []c;
			c = nullptr;
			this->_size = 0;
			this->_capacity = 0;
		}
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
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
		void assign (InputIterator first, InputIterator last,  typename InputIterator::iterator_category* = nullptr);
		void assign (size_type n, const value_type& val);
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename InputIterator::iterator_category* = nullptr);
        iterator erase (iterator position);
        iterator erase (iterator first, iterator last);
        void swap (vector& x);
        void clear();
        allocator_type get_allocator() const;
    private:
        void realloc(size_type n);
	};
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
        x.swap(y);
    }
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
	c = new value_type[n];
	_alloc = alloc;
	_size = 0;
	while (_size != n) {
		c[_size] = val;
		_size++;
	}
	_capacity = n;
}

template<class T, class Alloc>
template<class InputIterator>
ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc) {
	c = nullptr;
	this->_alloc = alloc;
	this->_size = 0;
	this->_capacity = 0;
    assign(first, last);
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const ft::vector<T, Alloc> &x) {
	c = new value_type[x._capacity];
	this->_alloc = x._alloc;
	this->_capacity = x._capacity;
	this->_size = x._size;
	for (size_type i = 0; i < _size; i++) {
		this->c[i] = x.c[i];
	}
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
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rend() {
	return ft::vector<T, Alloc>::reverse_iterator(c - 1);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend() const {
	return ft::vector<T, Alloc>::const_reverse_iterator(c - 1);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rbegin(){
	return reverse_iterator(c + _size - 1);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rbegin() const {
	return ft::vector<T, Alloc>::const_reverse_iterator(c + _size - 1);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::size() const {
	return _size;
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::max_size() const {
	return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::resize(ft::vector<T, Alloc>::size_type n, value_type val) {
	if (n < _size)
	{
		while (n != _size)
			 pop_back();
	}
	else
	{
		while (n != _size)
			push_back(val);
		realloc(n);
	}
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::capacity() const {
	return _capacity;
}

template<class T, class Alloc>
bool ft::vector<T, Alloc>::empty() const {
	return !static_cast<bool>(_size);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::realloc(ft::vector<T, Alloc>::size_type n) {
	if (n == 0)
		n = 2;
	value_type *_c = new value_type[n];
	size_type i = 0;
	while(i < _size)
	{
		_c[i] = c[i];
		i++;
	}
	if (c && _capacity != 0) {
		delete []c;
		c = nullptr;
	}
	c = _c;
	_capacity = n;
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::reserve(ft::vector<T, Alloc>::size_type n) {
	if (n > _capacity)
		realloc(n);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::at(ft::vector<T, Alloc>::size_type n) {
	return *(c + n);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::at(ft::vector<T, Alloc>::size_type n) const {
	return *(c + n);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::front() {
	return (*c);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::front() const {
	return (*c);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::back() {
	return *(c + _size - 1);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::back() const {
	return *(c + _size - 1);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::push_back(const value_type &val) {
	if (_size == _capacity)
		realloc(_size * 2);
	c[_size] = val;
	_size++;
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::pop_back() {
	c[_size] = value_type();
	_size--;
}

template<class T, class Alloc>
template<class InputIterator>
void ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last, typename InputIterator::iterator_category*) {
	this->clear();
	while (first != last)
	{
		this->push_back(*first);
		first++;
	}
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::assign(ft::vector<T, Alloc>::size_type n, const value_type &val) {
	if (n > _capacity)
		realloc(n);
	while (!empty())
		pop_back();
	for (size_type i = 0; i < n; ++i) {
		push_back(val);
	}
}



template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, const value_type &val) {
    size_type len = 0;
    for (iterator i = this->begin(); i != position && i != this->end(); ++i) {
        len++;
    }
    if (_size == _capacity)
		realloc(_size * 2);
    size_type tmp_size = _size;
    while (tmp_size != len)
    {
        swap_c(this->c[tmp_size], this->c[tmp_size + 1]);
        tmp_size--;
    }
    swap_c(this->c[tmp_size], this->c[tmp_size + 1]);
    this->c[tmp_size] = val;
    _size++;
    return iterator(c) + tmp_size;
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, ft::vector<T, Alloc>::size_type n, const value_type &val) {
    for (size_type i = 0; i < n; i++) {
        insert(position, val);
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::clear() {
	delete []c;
    _capacity = 0;
	_size = 0;
}

template<class T, class Alloc>
template<class InputIterator>
void ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last, typename InputIterator::iterator_category *) {

	if (first >= last)
		return;
    while (first != last)
    {
        position = insert(position, *first);
        position++;
        first++;
    }
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(ft::vector<T, Alloc>::iterator position) {
    iterator begin(position);
    while (begin != this->end())
    {
        *begin = *(begin + 1);
        begin++;
        if (begin + 1 == this->end()) {
	        _size--;
	        return position;
        }
    }
    _size--;
    return (position);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(ft::vector<T, Alloc>::iterator first, ft::vector<T, Alloc>::iterator last) {
    iterator begin(first);
    size_type len = last - first;

    while (begin != this->end()){
        (*begin) = *(begin + len);
        begin++;
        if (begin + len == this->end())
        {
            _size -= len;
            break;
        }
    }
    return first;
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::swap(ft::vector<T, Alloc> &x) {
    swap_c(c, x.c);
    swap_c(_size, x._size);
    swap_c(_capacity, x._capacity);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::allocator_type ft::vector<T, Alloc>::get_allocator() const {
    return _alloc;
}

template <class T, class Alloc>
bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
    if (lhs.size() == rhs.size())
    {
        typename ft::vector<T>::const_iterator iL = lhs.begin();
        typename ft::vector<T>::const_iterator iR = rhs.begin();
        for (; iL != lhs.end() && iR != rhs.end() ; iL++, iR++) {
            if (!(*iL == *iR))
                return false;
        }
        if (iL == lhs.end() && iR == rhs.end())
            return true;
    }
    return false;
}

template <class T, class Alloc>
bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
    return (!operator==(lhs, rhs));
}

template <class T, class Alloc>
bool operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
    typename ft::vector<T>::const_iterator iL = lhs.begin();
    typename ft::vector<T>::const_iterator iR = rhs.begin();
    for (; iL != lhs.end() && iR != rhs.end() ; iL++, iR++) {
        if (!(*iL == *iR))
            return (*iL < *iR);
    }
    if (iL == lhs.end() && iR != rhs.end())
        return true;
    else
        return false;
}

template <class T, class Alloc>
bool operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
    return (!operator<(lhs, rhs));
}

template <class T, class Alloc>
bool operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
    typename ft::vector<T>::const_iterator iL = lhs.begin();
    typename ft::vector<T>::const_iterator iR = rhs.begin();
    for (; iL != lhs.end() && iR != rhs.end() ; iL++, iR++) {
        if (!(*iL == *iR))
            return (*iL > *iR);
    }
    if (iR == rhs.end() && iL != lhs.end())
        return true;
    else
        return false;
}

template <class T, class Alloc>
bool operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
    return (!operator>(lhs, rhs));
}
#endif
