#ifndef LIST_HPP
# define LIST_HPP

#include <memory>
#include <ostream>
#include "Bidirectional.hpp"
#include "Node.hpp"

namespace ft{
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
	class List{
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
		typedef std::size_t 					size_type;
		typedef Node<T>							node;
	private:
		node		*_begin;
		node		*_end;
		size_type	sizeType;
	public:
		List();
		List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		List(iterator first, iterator last, const allocator_type& alloc = allocator_type());
		List(const List& x);
		~List();

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
		void swap (List& x);
		void resize (size_type n, value_type val = value_type ());
		void clear();
		void splice (iterator position, List& x);
		void splice (iterator position, List& x, iterator i);
		void splice (iterator position, List& x, iterator first, iterator last);
		void remove (const value_type& val);
		template <class Predicate>
		void remove_if (Predicate pred);
		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);
		void merge (List& x);
		template <class Compare>
		void merge (List& x, Compare comp);
		void sort();
		template <class Compare>
		void sort (Compare comp);
		void reverse();
	};
}

template<class T, class Alloc>
ft::List<T, Alloc>::List() {
	_begin = new Node<T>();
	_end = new Node<T>();
	_begin->next = _end;
	_end->prev = _begin;
	sizeType = 0;
}

template<class T, class Alloc>
ft::List<T, Alloc>::List(ft::List<T, Alloc>::size_type n, const value_type &val, const allocator_type &alloc) {
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
ft::List<T, Alloc>::List(ft::List<T, Alloc>::iterator first, ft::List<T, Alloc>::iterator last, const allocator_type &alloc) {
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
//	for (iterator i = first; i != last; ++i) {
//		this->push_back(*i);
//	}
}

template<class T, class Alloc>
ft::List<T, Alloc>::List(const ft::List<T, Alloc> &x) {
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
ft::List<T, Alloc>::~List() {

}

template<class T, class Alloc>
void ft::List<T, Alloc>::push_back(const value_type &_x) {
	Node<value_type> *element = new Node<value_type>();
	element->data = _x;
	_end->prev->next = element;
	element->prev = _end->prev;
	_end->prev = element;
	element->next = _end;
	sizeType++;
}

template<class T, class Alloc>
void ft::List<T, Alloc>::push_front(const value_type &_x) {
	Node<value_type> *element = new Node<value_type>();
	element->data = _x;
	_begin->next->prev = element;
	element->next = _begin->next;
	_begin->next = element;
	element->prev = _begin;
	sizeType++;
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::size_type ft::List<T, Alloc>::size() const {
	return sizeType;
}

template<class T, class Alloc>
bool ft::List<T, Alloc>::empty() const {
	return (!(static_cast<bool>(sizeType)));
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::iterator ft::List<T, Alloc>::begin() {
	return iterator(_begin->next);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::iterator ft::List<T, Alloc>::end() {
	return iterator(_end);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::reference ft::List<T, Alloc>::front() {
//	if (!empty())
	return (_begin->next->data);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::const_reference ft::List<T, Alloc>::front() const {
//	if (!empty())
	return (_begin->next->data);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::reference ft::List<T, Alloc>::back() {
	return (_end->prev->data);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::const_reference ft::List<T, Alloc>::back() const {
	return (_end->prev->data);
}

template<class T, class Alloc>
void ft::List<T, Alloc>::pop_front() {
	if (sizeType != 0){
		_begin->next = _begin->next->next;
		delete _begin->next->prev;
		_begin->next->prev = _begin;
		sizeType--;
	}
}

template<class T, class Alloc>
void ft::List<T, Alloc>::pop_back() {
	if (sizeType != 0){
		_end->prev = _end->prev->prev;
		delete _end->prev->next;
		_end->prev->next = _end;
		sizeType--;
	}
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::reverse_iterator ft::List<T, Alloc>::rbegin() {
	return reverse_iterator(_end->prev);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::reverse_iterator ft::List<T, Alloc>::rend() {
	return reverse_iterator (_begin);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::const_iterator ft::List<T, Alloc>::end() const {
	return const_iterator(_end);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::const_iterator ft::List<T, Alloc>::begin() const {
	return const_iterator(_begin->next);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::const_reverse_iterator ft::List<T, Alloc>::rbegin() const {
	return const_reverse_iterator (_end->prev);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::const_reverse_iterator ft::List<T, Alloc>::rend() const {
	return const_reverse_iterator (_begin);
}

template<class T, class Alloc>
template<class InputIterator>
void ft::List<T, Alloc>::assign(InputIterator first, InputIterator last, typename InputIterator::iterator_category*) {
	this->clear();
	while (first != last)
	{
		this->push_back(*first);
		first++;
	}
}

template<class T, class Alloc>
void ft::List<T, Alloc>::clear() {
	while (!empty())
		pop_back();
}

template<class T, class Alloc>
void ft::List<T, Alloc>::assign(ft::List<T, Alloc>::size_type n, const value_type &val) {
	this->clear();
	for (size_type i = 0; i < n; ++i) {
		this->push_back(val);
	}
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::iterator ft::List<T, Alloc>::insert(ft::List<T, Alloc>::iterator position, const value_type &val) {
	node *tmp = new node();
	tmp->data = val;
	tmp->next = position.elem;
	tmp->prev = position.elem->prev;
	position.elem->prev->next = tmp;
	position.elem->prev = tmp;
	return (tmp);
}

template<class T, class Alloc>
void ft::List<T, Alloc>::insert(ft::List<T, Alloc>::iterator position, ft::List<T, Alloc>::size_type n, const value_type &val) {
	for (size_type i = 0; i < n; ++i) {
		insert(position, val);
	}
}

template<class T, class Alloc>
template<class InputIterator>
void
ft::List<T, Alloc>::insert(ft::List<T, Alloc>::iterator position, InputIterator first, InputIterator last, typename InputIterator::iterator_category *) {
	while (first != last)
	{
		insert(position, *first);
		first++;
	}
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::iterator ft::List<T, Alloc>::erase(ft::List<T, Alloc>::iterator position) {
	node* tmp = position.elem;
	position.elem->next->prev = position.elem->prev;
	position.elem->prev->next = position.elem->next;
	position++;
	sizeType--;
	delete tmp;
	return (position);
}

template<class T, class Alloc>
typename ft::List<T, Alloc>::iterator ft::List<T, Alloc>::erase(ft::List<T, Alloc>::iterator first, ft::List<T, Alloc>::iterator last) {
	while (first != last)
	{
		first = erase(first);
	}
	return (last);
}

template<class T, class Alloc>
void ft::List<T, Alloc>::swap(ft::List<T, Alloc> &x) {
	swap_c(this, x);
}

template<class T, class Alloc>
void ft::List<T, Alloc>::resize(ft::List<T, Alloc>::size_type n, value_type val) {
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
void ft::List<T, Alloc>::splice(ft::List<T, Alloc>::iterator position, ft::List<T, Alloc> &x) {
	for (reverse_iterator i = x.rbegin(); i != x.rend() ; ++i) {
		this->insert(position, i.elem->data);
	}
	x.clear();
}

template<class T, class Alloc>
void ft::List<T, Alloc>::splice(ft::List<T, Alloc>::iterator position, ft::List<T, Alloc> &x, ft::List<T, Alloc>::iterator i) {
	this->insert(position, i.elem->data);
	x.erase(i);
}

template<class T, class Alloc>
void ft::List<T, Alloc>::splice(ft::List<T, Alloc>::iterator position, ft::List<T, Alloc> &x, ft::List<T, Alloc>::iterator first,
								ft::List<T, Alloc>::iterator last) {
	while (first != last)
	{
		this->insert(position, first.elem->data);
		first++;
	}
	x.erase(first, last);
}

template<class T, class Alloc>
void ft::List<T, Alloc>::remove(const value_type &val) {
	for (iterator i; i != this->end() ; ++i) {
		if((*i) == val)
		{
			i = this->erase(i);
			i--;
		}
	}
}

template<class T, class Alloc>
template<class Predicate>
void ft::List<T, Alloc>::remove_if(Predicate pred) {
	for (iterator i; i != this->end() ; ++i) {
		if(pred(*i))
		{
			i = this->erase(i);
			i--;
		}
	}
}

template<class T, class Alloc>
void ft::List<T, Alloc>::unique() {
	iterator j = this->begin();
	j++;
	for (iterator i = this->begin(); i != this->end(), j != this->end(); ++i, j++) {
		while (*j == *i)
		{
			i = this->erase(i);
			j++;
		}
	}
}

template<class T, class Alloc>
template<class BinaryPredicate>
void ft::List<T, Alloc>::unique(BinaryPredicate binary_pred) {
	iterator j = this->begin();
	j++;
	for (iterator i = this->begin(); i != this->end(), j != this->end(); ++i, j++) {
		while (binary_pred(*i, *j))
		{
			i = this->erase(i);
			j++;
		}
	}
}

template<class T, class Alloc>
void ft::List<T, Alloc>::merge(ft::List<T, Alloc> &x) {
	iterator iteratorThis = this->begin();
	iterator iteratorX = x.begin();
	while (iteratorThis != this->end() && iteratorX != x.end())
	{
		if (*iteratorThis < *iteratorX)
		{
			while (*iteratorThis < *iteratorX && iteratorThis != this->end())
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
void ft::List<T, Alloc>::merge(ft::List<T, Alloc> &x, Compare comp) {
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
void ft::List<T, Alloc>::sort() {
	for (iterator i = this->begin(); i != this->end(); ++i) {
		for (iterator j = this->begin(); j != this->end(); ++j) {
			if (*i < *j)
				swap_c(*i, *j);
		}
	}
}

template<class T, class Alloc>
template<class Compare>
void ft::List<T, Alloc>::sort(Compare comp) {
	for (iterator i = this->begin(); i != this->end(); ++i) {
		for (iterator j = this->begin(); j != this->end(); ++j) {
			if (comp(*i, *j))
				swap_c(*i, *j);
		}
	}
}

template<class T, class Alloc>
void ft::List<T, Alloc>::reverse() {
	iterator i = this->begin();
	swap_c(_begin->next, _begin->prev);
	for (; i != this->end() ; --i) {
		swap_c(i.elem->next, i.elem->prev);
	}
	swap_c(_end->next, _end->prev);
	swap_c(_end, _begin);
}

#endif
