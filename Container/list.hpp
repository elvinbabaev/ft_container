#ifndef LIST_HPP
# define LIST_HPP

#include <memory>
#include <ostream>
#include "../iterator/Bidirectional.hpp"
#include "../Element/Node.hpp"

namespace ft{
	template<class T, class Alloc>
	class list;

	template <class T>
	bool compare(T a, T b)
	{
		return (a <= b);
	}

	template <class T>
	void	swap_c(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template<class T, class Alloc = std::allocator <T> >
	class list{
	public:
		typedef T								value_type;
		typedef Alloc							allocator_type;
		typedef T&								reference;
		typedef const T&						const_reference;
		typedef T*								pointer;
		typedef const T*						const_pointer;

		typedef Bidirectional<T>				iterator;
		typedef ReverseBidirectional<T>			reverse_iterator;
		typedef ConstBidirectional<T>			const_iterator;
		typedef ConstReverseBidirectional<T>	const_reverse_iterator;
		typedef std::ptrdiff_t					difference_type;
		typedef size_t 							size_type;
		typedef Node<T>							node;
	private:
		node		*_begin;
		node		*_end;
		size_type	sizeType;
	public:
		list();
		list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		list(iterator first, iterator last, const allocator_type& alloc = allocator_type());
		list(const list& x);
		~list();
		list<T, Alloc> operator=(const list<T, Alloc> &arg);

		iterator begin();
		const_iterator begin()const;
		iterator end();
		const_iterator end()const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		bool empty () const;
		size_type size() const;
		size_type max_size() const;

		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename InputIterator::iterator_category* = nullptr);
		void assign (size_type n, const value_type & val);
		void push_front(const value_type& _x);
		void pop_front ();
		void push_back(const value_type& _x);
		void pop_back ();
		iterator insert(iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template<class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename InputIterator::iterator_category* = nullptr);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap (list& x);
		void resize (size_type n, value_type val = value_type ());
		void clear();
		void splice (iterator position, list& x);
		void splice (iterator position, list& x, iterator i);
		void splice (iterator position, list& x, iterator first, iterator last);
		void remove (const value_type& val);
		template <class Predicate>
		void remove_if (Predicate pred);
		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);
		void merge (list& x);
		template <class Compare>
		void merge (list& x, Compare comp);
		void sort();
		template <class Compare>
		void sort (Compare comp);
		void reverse();

	};

	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y)
	{
		x.swap(y);
	}
}

template<class T, class Alloc>
ft::list<T, Alloc>::list() {
	_begin = new Node<T>();
	_end = new Node<T>();
	_begin->next = _end;
	_end->prev = _begin;
	sizeType = 0;
}

template<class T, class Alloc>
ft::list<T, Alloc>::list(ft::list<T, Alloc>::size_type n, const value_type &val, const allocator_type &) {
	_begin = new Node<T>();
	_end = new Node<T>();
	_begin->next = _end;
	_end->prev = _begin;
	sizeType = 0;
	for (size_type i = 0; i < n; ++i) {
		this->push_back(val);
	}
}

template<class T, class Alloc>
ft::list<T, Alloc>::list(ft::list<T, Alloc>::iterator first, ft::list<T, Alloc>::iterator last, const allocator_type &) {
	_begin = new Node<T>();
	_end = new Node<T>();
	_begin->next = _end;
	_end->prev = _begin;
	sizeType = 0;
	while (first != last)
	{
		this->push_back(*first);
		first++;
	}
}

template<class T, class Alloc>
ft::list<T, Alloc> ft::list<T, Alloc>::operator=(const ft::list<T, Alloc> &arg) {
	if (this == &arg)
		return (*this);
	this->clear();
	_begin->next = _end;
	_end->prev = _begin;
	sizeType = 0;
	for (list<T, Alloc>::const_iterator i = arg.begin(); i != arg.end() ; i++) {
		this->push_back(*i);
	}
	return (*this);
}

template<class T, class Alloc>
ft::list<T, Alloc>::list(const ft::list<T, Alloc> &x) {
	_begin = new Node<T>();
	_end = new Node<T>();
	_begin->next = _end;
	_end->prev = _begin;
	sizeType = 0;
	for (const_iterator i = x.begin(); i != x.end(); ++i) {
		this->push_back(*i);
	}
}

template<class T, class Alloc>
ft::list<T, Alloc>::~list() {
	this->clear();
	delete _begin;
	delete _end;
}

template<class T, class Alloc>
void ft::list<T, Alloc>::push_back(const value_type &_x) {
	Node<value_type> *element = new Node<value_type>();
	element->data = _x;
	_end->prev->next = element;
	element->prev = _end->prev;
	_end->prev = element;
	element->next = _end;
	sizeType++;
}

template<class T, class Alloc>
void ft::list<T, Alloc>::push_front(const value_type &_x) {
	Node<value_type> *element = new Node<value_type>();
	element->data = _x;
	_begin->next->prev = element;
	element->next = _begin->next;
	_begin->next = element;
	element->prev = _begin;
	sizeType++;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::size_type ft::list<T, Alloc>::size() const {
	return sizeType;
}

template<class T, class Alloc>
bool ft::list<T, Alloc>::empty() const {
	return (!(static_cast<bool>(sizeType)));
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::begin() {
	return iterator(_begin->next);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::end() {
	return iterator(_end);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::reference ft::list<T, Alloc>::front() {
	return (_begin->next->data);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::const_reference ft::list<T, Alloc>::front() const {
	return (_begin->next->data);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::reference ft::list<T, Alloc>::back() {
	return (_end->prev->data);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::const_reference ft::list<T, Alloc>::back() const {
	return (_end->prev->data);
}

template<class T, class Alloc>
void ft::list<T, Alloc>::pop_front() {
	if (sizeType != 0){
		_begin->next = _begin->next->next;
		delete _begin->next->prev;
		_begin->next->prev = _begin;
		sizeType--;
	}
}

template<class T, class Alloc>
void ft::list<T, Alloc>::pop_back() {
	if (sizeType != 0){
		_end->prev = _end->prev->prev;
		delete _end->prev->next;
		_end->prev->next = _end;
		sizeType--;
	}
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::reverse_iterator ft::list<T, Alloc>::rbegin() {
	return reverse_iterator(_end->prev);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::reverse_iterator ft::list<T, Alloc>::rend() {
	return reverse_iterator (_begin);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::const_iterator ft::list<T, Alloc>::end() const {
	return const_iterator(_end);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::const_iterator ft::list<T, Alloc>::begin() const {
	return const_iterator(_begin->next);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::const_reverse_iterator ft::list<T, Alloc>::rbegin() const {
	return const_reverse_iterator (_end->prev);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::const_reverse_iterator ft::list<T, Alloc>::rend() const {
	return const_reverse_iterator (_begin);
}

template<class T, class Alloc>
template<class InputIterator>
void ft::list<T, Alloc>::assign(InputIterator first, InputIterator last, typename InputIterator::iterator_category*) {
	this->clear();
	while (first != last)
	{
		this->push_back(*first);
		first++;
	}
}

template<class T, class Alloc>
void ft::list<T, Alloc>::clear() {
	while (!empty())
		pop_back();
}

template<class T, class Alloc>
void ft::list<T, Alloc>::assign(ft::list<T, Alloc>::size_type n, const value_type &val) {
	this->clear();
	for (size_type i = 0; i < n; ++i) {
		this->push_back(val);
	}
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::insert(ft::list<T, Alloc>::iterator position, const value_type &val) {
	node *tmp = new node();
	tmp->data = val;
	tmp->next = position.elem;
	tmp->prev = position.elem->prev;
	position.elem->prev->next = tmp;
	position.elem->prev = tmp;
	sizeType++;
	return (tmp);
}

template<class T, class Alloc>
void ft::list<T, Alloc>::insert(ft::list<T, Alloc>::iterator position, ft::list<T, Alloc>::size_type n, const value_type &val) {
	for (size_type i = 0; i < n; ++i) {
		insert(position, val);
	}
}

template<class T, class Alloc>
template<class InputIterator>
void
ft::list<T, Alloc>::insert(ft::list<T, Alloc>::iterator position, InputIterator first, InputIterator last, typename InputIterator::iterator_category *) {
	while (first != last)
	{
		insert(position, *first);
		first++;
	}
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::erase(ft::list<T, Alloc>::iterator position) {
	node* tmp = position.elem;
	position.elem->next->prev = position.elem->prev;
	position.elem->prev->next = position.elem->next;
	position++;
	sizeType--;
	delete tmp;
	return (position);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::erase(ft::list<T, Alloc>::iterator first, ft::list<T, Alloc>::iterator last) {
	while (first != last)
	{
		first = erase(first);
	}
	return (last);
}

template<class T, class Alloc>
void ft::list<T, Alloc>::swap(ft::list<T, Alloc> &x) {
	swap_c(this->_begin, x._begin);
	swap_c(this->_end, x._end);
	swap_c(this->sizeType, x.sizeType);
}

template<class T, class Alloc>
void ft::list<T, Alloc>::resize(ft::list<T, Alloc>::size_type n, value_type val) {
	if (n < sizeType)
	{
		while (n != sizeType)
			this->pop_back();
	} else
	{
		while (n != sizeType)
			this->push_back(val);
	}
}

template<class T, class Alloc>
void ft::list<T, Alloc>::splice(ft::list<T, Alloc>::iterator position, ft::list<T, Alloc> &x) {
	iterator begin_it2 = x.begin();
	iterator end_it2 = x.end();

	node *tmp;
	while (begin_it2 != end_it2)
	{
		tmp = begin_it2.elem->next;
		splice(position, x, begin_it2);
		begin_it2.elem = tmp;
	}
}

template<class T, class Alloc>
void ft::list<T, Alloc>::splice(ft::list<T, Alloc>::iterator position, ft::list<T, Alloc> &x, ft::list<T, Alloc>::iterator i) {
	i.elem->prev->next = i.elem->next;
	i.elem->next->prev = i.elem->prev;
	i.elem->next = position.elem;
	i.elem->prev = position.elem->prev;
	position.elem->prev->next = i.elem;
	position.elem->prev = i.elem;
	this->sizeType++;
	x.sizeType--;
}

template<class T, class Alloc>
void ft::list<T, Alloc>::splice(ft::list<T, Alloc>::iterator position, ft::list<T, Alloc> &x, ft::list<T, Alloc>::iterator first,
								ft::list<T, Alloc>::iterator last) {
	node *tmp;
	while (first != last)
	{
		tmp = first.elem->next;
		splice(position, x, first);
		first.elem = tmp;
	}
}

template<class T, class Alloc>
void ft::list<T, Alloc>::remove(const value_type &val) {
	for (iterator i = this->begin(); i != this->end() ; ++i) {
		if((*i) == val)
		{
			i = this->erase(i);
			i--;
		}
	}
}

template<class T, class Alloc>
template<class Predicate>
void ft::list<T, Alloc>::remove_if(Predicate pred) {
	for (iterator i = this->begin(); i != this->end() ; ++i) {
		if(pred(*i))
		{
			i = this->erase(i);
			i--;
		}
	}
}

template<class T, class Alloc>
void ft::list<T, Alloc>::unique() {
	iterator j = this->begin();
	iterator i = this->begin();
	j++;
	for (; i != this->end() && j != this->end(); ++i, ++j) {
		while (*j == *i && i != this->end() && j != this->end())
		{
			i = this->erase(i);
			j++;
		}
	}
}

template<class T, class Alloc>
template<class BinaryPredicate>
void ft::list<T, Alloc>::unique(BinaryPredicate binary_pred) {
	iterator j = this->begin();
	j++;
	for (iterator i = this->begin(); i != this->end() && j != this->end(); ++i, ++j) {
		while (binary_pred(*i, *j) && i != this->end() && j != this->end())
		{
			j = this->erase(j);
		}
	}
}

template<class T, class Alloc>
void ft::list<T, Alloc>::merge(ft::list<T, Alloc> &x) {
	iterator iteratorThis = this->begin();
	iterator iteratorX = x.begin();
	while (iteratorThis != this->end() && iteratorX != x.end())
	{
		if (*iteratorThis <= *iteratorX)
		{
			while (*iteratorThis <= *iteratorX && iteratorThis != this->end())
			{
				iteratorThis++;
			}
		} else
		{
			iteratorThis = this->insert(iteratorThis, *iteratorX);
			iteratorThis++;
			iteratorX++;
		}
	}
	if (iteratorThis == this->end() && iteratorX != x.end())
	{
		while (iteratorX != x.end())
		{
			this->insert(this->end(), *iteratorX);
			iteratorX++;
		}
	}
	x.clear();
}

template<class T, class Alloc>
template<class Compare>
void ft::list<T, Alloc>::merge(ft::list<T, Alloc> &x, Compare comp) {
	iterator iteratorThis = this->begin();
	iterator iteratorX = x.begin();
	while (iteratorThis != this->end() && iteratorX != x.end())
	{
		if (!comp(*iteratorX, *iteratorThis))
		{
			while (!comp(*iteratorX, *iteratorThis) && iteratorThis != this->end())
			{
				iteratorThis++;
			}
		} else
		{
			iteratorThis = this->insert(iteratorThis, *iteratorX);
			iteratorThis++;
			iteratorX++;
		}
	}
	if (iteratorThis == this->end() && iteratorX != x.end())
	{
		while (iteratorX != x.end())
		{
			this->insert(this->end(), *iteratorX);
			iteratorX++;
		}
	}
	x.clear();
}

template<class T, class Alloc>
void ft::list<T, Alloc>::sort() {
	for (iterator i = this->begin(); i != this->end(); ++i) {
		for (iterator j = this->begin(); j != this->end(); ++j) {
			if (*i < *j)
				swap_c(*i, *j);
		}
	}
}

template<class T, class Alloc>
template<class Compare>
void ft::list<T, Alloc>::sort(Compare comp) {
	for (iterator i = this->begin(); i != this->end(); ++i) {
		for (iterator j = this->begin(); j != this->end(); ++j) {
			if (comp(*i, *j))
				swap_c(*i, *j);
		}
	}
}

template<class T, class Alloc>
void ft::list<T, Alloc>::reverse() {
	iterator i = this->begin();
	swap_c(_begin->next, _begin->prev);
	for (; i != this->end() ; --i) {
		swap_c(i.elem->next, i.elem->prev);
	}
	swap_c(_end->next, _end->prev);
	swap_c(_end, _begin);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::size_type ft::list<T, Alloc>::max_size() const {
	return (std::numeric_limits<size_type>::max() / sizeof(Node<value_type>));
}

template <class T, class Alloc>
bool operator==(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	if (lhs.size() == rhs.size())
	{
		typename ft::list<T>::const_iterator iL = lhs.begin();
		typename ft::list<T>::const_iterator iR = rhs.begin();
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
bool operator!=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	return (!operator==(lhs, rhs));
}

template <class T, class Alloc>
bool operator<(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	typename ft::list<T>::const_iterator iL = lhs.begin();
	typename ft::list<T>::const_iterator iR = rhs.begin();
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
bool operator>=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	return (!operator<(lhs, rhs));
}

template <class T, class Alloc>
bool operator>(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	typename ft::list<T>::const_iterator iL = lhs.begin();
	typename ft::list<T>::const_iterator iR = rhs.begin();
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
bool operator<=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	return (!operator>(lhs, rhs));
}
#endif
