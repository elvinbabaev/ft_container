#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <ostream>
#include "Node.hpp"

namespace ft{
	template<class T>
	class Bidirectional{
	public:
		typedef T					value_type;
		typedef T*					pointer;
		typedef const T*			const_pointer;
		typedef T&					reference;
		typedef const T&			const_reference;
		typedef Bidirectional<T>	iterator;
		typedef Bidirectional<T>	class_name;
		typedef Node<T>				node;


		node *elem;
//		Bidirectional(){
//			elem.next = NULL;
//			elem.prev = NULL;
//		}

		Bidirectional(Node<T> *data){
			elem = data;
		}

//		Bidirectional(const Bidirectional<T> &arg){
//			*this = arg;
//		}
		class_name &operator=(class_name const &arg)
		{
			if (this == &arg)
				return (*this);
			this->elem->prev = arg.elem.prev;
			this->elem->next = arg.elem.next;
			this->elem->data = arg.elem.data;
			return (*this);
		}
		~Bidirectional(){}

		bool operator==(const class_name &rhs) const {
			return elem->data == rhs.elem->data;
		}

		bool operator!=(const class_name &rhs) const {
			return !(rhs == *this);
		}

		bool operator<(const class_name &rhs) const {
			return elem < rhs.elem;
		}

		bool operator>(const class_name &rhs) const {
			return rhs < *this;
		}

		bool operator<=(const class_name &rhs) const {
			return !(rhs < *this);
		}

		bool operator>=(const class_name &rhs) const {
			return !(*this < rhs);
		}

		value_type &operator*(const class_name &rhs) const{
			return (elem->data);
		}

		class_name &operator++()
		{
			elem = elem->next;
			return (*this);
		}
		class_name operator++(int)
		{
			class_name tmp = *this;
			elem = elem->next;
			return (tmp);
		}
		class_name &operator--()
		{
			elem = elem->prev;
			return (*this);
		}
		class_name operator--(int)
		{
			class_name tmp = *this;
			elem = elem->prev;
			return (tmp);
		}
		value_type &operator*() // создать с константной указателем
		{
			return (elem->data);
		}
	};

	template<class T>
	class ReverseBidirectional{
	public:
		typedef T					value_type;
		typedef T*					pointer;
		typedef const T*			const_pointer;
		typedef T&					reference;
		typedef const T&			const_reference;
		typedef ReverseBidirectional<T>	reverse_iterator;
		typedef ReverseBidirectional<T>	class_name;
		typedef Node<T>				node;
		node *elem;

		ReverseBidirectional(Node<T> *data){
			elem = data;
		}

		class_name &operator=(class_name const &arg)
		{
			if (this == &arg)
				return (*this);
			this->elem->prev = arg.elem.prev;
			this->elem->next = arg.elem.next;
			this->elem->data = arg.elem.data;
			return (*this);
		}
		~ReverseBidirectional(){}
		bool operator==(const class_name &rhs) const {
			return elem->data == rhs.elem->data;
		}

		bool operator!=(const class_name &rhs) const {
			return !(rhs == *this);
		}

		bool operator<(const class_name &rhs) const {
			return elem < rhs.elem;
		}

		bool operator>(const class_name &rhs) const {
			return rhs < *this;
		}

		bool operator<=(const class_name &rhs) const {
			return !(rhs < *this);
		}

		bool operator>=(const class_name &rhs) const {
			return !(*this < rhs);
		}

		value_type &operator*(const class_name &rhs) const{
			return (elem->data);
		}
		value_type &operator*() // создать с константной указателем
		{
			return (elem->data);
		}
		class_name &operator--()
		{
			elem = elem->next;
			return (*this);
		}
		class_name operator--(int)
		{
			class_name tmp = *this;
			elem = elem->next;
			return (tmp);
		}
		class_name &operator++()
		{
			elem = elem->prev;
			return (*this);
		}
		class_name operator++(int)
		{
			class_name tmp = *this;
			elem = elem->prev;
			return (tmp);
		}
	};

	template<class T>
	class Const_Bidirectional{
	public:
		typedef T					value_type;
		typedef T*					pointer;
		typedef const T*			const_pointer;
		typedef T&					reference;
		typedef const T&			const_reference;
		typedef Const_Bidirectional<T>	reverse_iterator;
		typedef Const_Bidirectional<T>	class_name;
		typedef Const_Node<T>				node;
		node *elem;

		Const_Bidirectional(Node<T> *data){
			elem = data;
		}

		class_name &operator=(class_name const &arg)
		{
			if (this == &arg)
				return (*this);
			this->elem->prev = arg.elem.prev;
			this->elem->next = arg.elem.next;
//			this->elem->data = arg.elem.data;
			return (*this);
		}
		~Const_Bidirectional(){}
		bool operator==(const class_name &rhs) const {
			return elem->data == rhs.elem->data;
		}

		bool operator!=(const class_name &rhs) const {
			return !(rhs == *this);
		}

		bool operator<(const class_name &rhs) const {
			return elem < rhs.elem;
		}

		bool operator>(const class_name &rhs) const {
			return rhs < *this;
		}

		bool operator<=(const class_name &rhs) const {
			return !(rhs < *this);
		}

		bool operator>=(const class_name &rhs) const {
			return !(*this < rhs);
		}

		value_type &operator*(const class_name &rhs) const{
			return (elem->data);
		}
		const value_type *operator*() // создать с константной указателем
		{
			return (elem->data);
		}
		class_name &operator++()
		{
			elem = elem->next;
			return (*this);
		}
		class_name operator++(int)
		{
			class_name tmp = *this;
			elem = elem->next;
			return (tmp);
		}
		class_name &operator--()
		{
			elem = elem->prev;
			return (*this);
		}
		class_name operator--(int)
		{
			class_name tmp = *this;
			elem = elem->prev;
			return (tmp);
		}
	};
}

#endif
