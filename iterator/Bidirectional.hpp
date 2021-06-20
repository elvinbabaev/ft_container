#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <ostream>//!!!!
#include "../Element/Node.hpp"

namespace ft {
	template<class T>
	class Bidirectional {
	public:
		struct iterator_tag {
		};

		typedef T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef Bidirectional<T> iterator;
		typedef Bidirectional<T> class_name;
		typedef Node<T> node;
		typedef iterator_tag iterator_category;
		node *elem;

		Bidirectional() {
			elem = nullptr;
		}

		Bidirectional(Node<T> *data) {
			elem = data;
		}

		~Bidirectional() {}

		Bidirectional(const Bidirectional<T> &arg) {
			*this = arg;
		}

		class_name &operator=(class_name const &arg) {
			if (this == &arg)
				return (*this);
			elem = arg.elem;
			return (*this);
		}

		bool operator==(const class_name &rhs) const {
			return elem == rhs.elem;
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

		value_type &operator*(const class_name &) const {
			return (elem->data);
		}

		class_name &operator++() {
			elem = elem->next;
			return (*this);
		}

		class_name operator++(int) {
			class_name tmp = *this;
			elem = elem->next;
			return (tmp);
		}

		class_name &operator--() {
			elem = elem->prev;
			return (*this);
		}

		class_name operator--(int) {
			class_name tmp = *this;
			elem = elem->prev;
			return (tmp);
		}

		value_type &operator*() {
			return (elem->data);
		}

		value_type *operator->() {
			return (elem->data);
		}

		value_type *operator->() const {
			return (elem->data);
		}
	};

	template<class T>
	class ReverseBidirectional {
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef ReverseBidirectional<T> reverse_iterator;
		typedef ReverseBidirectional<T> class_name;
		typedef Node<T> node;
		node *elem;

		ReverseBidirectional() {
			elem = nullptr;
		}

		ReverseBidirectional(Node<T> *data) {
			elem = data;
		}

		class_name &operator=(class_name const &arg) {
			if (this == &arg)
				return (*this);
			this->elem->prev = arg.elem.prev;
			this->elem->next = arg.elem.next;
			this->elem->data = arg.elem.data;
			return (*this);
		}

		~ReverseBidirectional() {}

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

		value_type &operator*(const class_name &) const {
			return (elem->data);
		}

		value_type &operator*()
		{
			return (elem->data);
		}

		class_name &operator--() {
			elem = elem->next;
			return (*this);
		}

		class_name operator--(int) {
			class_name tmp = *this;
			elem = elem->next;
			return (tmp);
		}

		class_name &operator++() {
			elem = elem->prev;
			return (*this);
		}

		class_name operator++(int) {
			class_name tmp = *this;
			elem = elem->prev;
			return (tmp);
		}

		class_name *operator->() {
			return (elem->data);
		}
	};

	template<class T>
	class ConstBidirectional {
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef ConstBidirectional<T> reverse_iterator;
		typedef ConstBidirectional<T> class_name;
		typedef Node<T> node;
		node *elem;

		ConstBidirectional() {
			elem = nullptr;
		}

		ConstBidirectional(Node<T> *data) {
			elem = data;
		}

		class_name &operator=(class_name const &arg) {
			if (this == &arg)
				return (*this);
			this->elem->prev = arg.elem.prev;
			this->elem->next = arg.elem.next;
			this->elem->data = arg.elem.data;
			return (*this);
		}

		~ConstBidirectional() {}

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

		const value_type &operator*(const class_name &) const {
			return (elem->data);
		}

		const value_type &operator*() const
		{
			return (elem->data);
		}

		const class_name &operator++() {
			elem = elem->next;
			return (*this);
		}

		const class_name operator++(int) {
			class_name tmp = *this;
			elem = elem->next;
			return (tmp);
		}

		const class_name &operator--() {
			elem = elem->prev;
			return (*this);
		}

		const class_name operator--(int) {
			class_name tmp = *this;
			elem = elem->prev;
			return (tmp);
		}

		const class_name *operator->() {
			return (elem->data);
		}



		ConstBidirectional &operator=(Bidirectional<T> &bidirectional ) {
			this->elem = bidirectional.elem;
			return *this;
		}

		ConstBidirectional(Bidirectional<T> bidirectional) {
			this->elem = bidirectional.elem;
		}
	};

	template<class T>
	class ConstReverseBidirectional {
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef ConstBidirectional<T> reverse_iterator;
		typedef ConstBidirectional<T> class_name;
		typedef Node<T> node;
		node *elem;

		ConstReverseBidirectional() {
			elem = nullptr;
		}

		ConstReverseBidirectional(Node<T> *data) {
			elem = data;
		}

		class_name &operator=(class_name const &arg) {
			if (this == &arg)
				return (*this);
			this->elem->prev = arg.elem.prev;
			this->elem->next = arg.elem.next;
			this->elem->data = arg.elem.data;
			return (*this);
		}

		~ConstReverseBidirectional() {}

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

		const value_type &operator*(const class_name &) const {
			return (elem->data);
		}

		const value_type &operator*() const
		{
			return (elem->data);
		}

		const class_name &operator--() {
			elem = elem->next;
			return (*this);
		}

		const class_name operator--(int) {
			class_name tmp = *this;
			elem = elem->next;
			return (tmp);
		}

		const class_name &operator++() {
			elem = elem->prev;
			return (*this);
		}

		const class_name operator++(int) {
			class_name tmp = *this;
			elem = elem->prev;
			return (tmp);
		}

		const class_name *operator->() {
			return (elem->data);
		}

		ConstReverseBidirectional &operator=(ReverseBidirectional<T> &bidirectional ) {
			this->elem = bidirectional.elem;
			return *this;
		}

		ConstReverseBidirectional(ReverseBidirectional<T> bidirectional) {
			this->elem = bidirectional.elem;
		}
	};
}

#endif
