#ifndef LIST_HPP
# define LIST_HPP

#include <memory>
#include "Bidirectional.hpp"
#include "Node.hpp"

namespace ft{
	template<class T, class Alloc = std::allocator <T> >
	class List{
	public:
		typedef T						value_type;
		typedef Alloc					allocator_type;
		typedef T&						reference;
		typedef const T&				const_reference;
		typedef T*						pointer;
		typedef const T*				const_pointer;

		typedef Bidirectional<T>		iterator;
		typedef ReverseBidirectional<T>	reverse_iterator;
		typedef Bidirectional<T> const	const_iterator;
		typedef std::ptrdiff_t			difference_type;
		typedef std::size_t 			size_type;

		typedef Node<T>				node;
	private:
		node		*_begin;
		node		*_end;
		size_type	sizeType;
	public:
		List();
//		List(const List<T, Alloc> &arg);

		~List();

		iterator begin();
		reverse_iterator rbegin();
		iterator end();
		reverse_iterator rend();
		const_iterator end()const;
		const_iterator begin()const;


		void push_back(const value_type& _x);
		void push_front(const value_type& _x);
		void pop_front ();
		void pop_back ();
		bool empty () const;
		size_type size() const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
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
void ft::List<T, Alloc>::push_back(const value_type &_x) {
	Node<value_type> *element = new Node<value_type>();
	element->data = _x;
	_end->prev->next = element;
	element->prev = _end->prev;
	_end->prev = element;
	element->next = _end;
}

template<class T, class Alloc>
void ft::List<T, Alloc>::push_front(const value_type &_x) {
	Node<value_type> *element = new Node<value_type>();
	element->data = _x;
	_begin->next->prev = element;
	element->next = _begin->next;
	_begin->next = element;
	element->prev = _begin;
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
	return const_iterator (_begin);
}


#endif
