//
// Created by Elwin Babaew on 2/5/21.
//

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include <iostream>

namespace ft {
	template<typename T>
	class RandomAccess {
	public:
		struct iterator_tag {
		};

		typedef T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef RandomAccess<T> iterator;
		typedef RandomAccess<T> class_name;
		//const;
		typedef iterator_tag iterator_category;
		typedef size_t size_type;

		pointer elem;

		RandomAccess() {
			elem = nullptr;
		}

		RandomAccess(const pointer p) {
			elem = p;
		}

		RandomAccess(const RandomAccess<T> &arg) : elem(arg.elem) {
		}

		class_name &operator=(class_name const &arg) {
			if (this == &arg)
				return (*this);
			elem = arg.elem;
			return (*this);
		}

		~RandomAccess() {}

		bool operator==(const RandomAccess &rhs) const {
			return elem == rhs.elem;
		}

		bool operator!=(const RandomAccess &rhs) const {
			return !(rhs == *this);
		}

		bool operator<(const RandomAccess &rhs) const {
			return elem < rhs.elem;
		}

		bool operator>(const RandomAccess &rhs) const {
			return rhs < *this;
		}

		bool operator<=(const RandomAccess &rhs) const {
			return !(rhs < *this);
		}

		bool operator>=(const RandomAccess &rhs) const {
			return !(*this < rhs);
		}

		value_type &operator*(const class_name &rhs) const {
			return (*elem);
		}

		value_type &operator*() {
			return (*elem);
		}

		value_type *operator->() {
			return (*elem);
		}

		value_type *operator->() const {
			return (*elem);
		}

		class_name &operator++() {
			elem++;
			return (*this);
		}

		class_name operator++(int) {
			class_name tmp = *this;
			elem++;
			return (tmp);
		}

		class_name &operator--() {
			elem--;
			return (*this);
		}

		class_name operator--(int) {
			class_name tmp = *this;
			elem--;
			return (tmp);
		}

		reference operator[](size_type n) {
			return *(elem + n);
		}

		const_reference operator[](size_type n) const {
			return *(elem + n);
		}

		class_name operator+(size_type n) const {
			class_name tmp = *this;
			tmp.elem += n;
			return (tmp);
		}

		class_name operator-(size_type n) const {
			class_name tmp = *this;
			tmp.elem -= n;
			return (tmp);
		}

		class_name &operator+=(size_type n) {
			this->elem += n;
			return (*this);
		}

		class_name &operator-=(size_type n) {
			this->elem -= n;
			return (*this);
		}
	};

	template<typename T>
	class ReverseRandomAccess {
	public:
		struct iterator_tag {
		};

		typedef T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef RandomAccess<T> iterator;
		typedef RandomAccess<T> class_name;
		//const;
		typedef iterator_tag iterator_category;
		typedef size_t size_type;

		pointer elem;

		ReverseRandomAccess() {
			elem = nullptr;
		}

		ReverseRandomAccess(const pointer p) {
			elem = p;
		}

		ReverseRandomAccess(const ReverseRandomAccess<T> &arg) : elem(arg.elem) {
		}

		class_name &operator=(class_name const &arg) {
			if (this == &arg)
				return (*this);
			elem = arg.elem;
			return (*this);
		}

		~ReverseRandomAccess() {}

		bool operator==(const ReverseRandomAccess &rhs) const {
			return elem == rhs.elem;
		}

		bool operator!=(const ReverseRandomAccess &rhs) const {
			return !(rhs == *this);
		}

		bool operator<(const ReverseRandomAccess &rhs) const {
			return elem < rhs.elem;
		}

		bool operator>(const ReverseRandomAccess &rhs) const {
			return rhs < *this;
		}

		bool operator<=(const ReverseRandomAccess &rhs) const {
			return !(rhs < *this);
		}

		bool operator>=(const ReverseRandomAccess &rhs) const {
			return !(*this < rhs);
		}

		value_type &operator*(const class_name &rhs) const {
			return (*elem);
		}

		value_type &operator*() {
			return (*elem);
		}

		value_type *operator->() {
			return (*elem);
		}

		value_type *operator->() const {
			return (*elem);
		}

		class_name &operator++() {
			elem++;
			return (*this);
		}

		class_name operator++(int) {
			class_name tmp = *this;
			elem--;
			return (tmp);
		}

		class_name &operator--() {
			elem++;
			return (*this);
		}

		class_name operator--(int) {
			class_name tmp = *this;
			elem++;
			return (tmp);
		}

		reference operator[](size_type n) {
			return *(elem - n);
		}

		const_reference operator[](size_type n) const {
			return *(elem - n);
		}

		class_name operator+(size_type n) const {
			class_name tmp = *this;
			tmp.elem -= n;
			return (tmp);
		}

		class_name operator-(size_type n) const {
			class_name tmp = *this;
			tmp.elem += n;
			return (tmp);
		}

		class_name &operator+=(size_type n) {
			this->elem -= n;
			return (*this);
		}

		class_name &operator-=(size_type n) {
			this->elem += n;
			return (*this);
		}
	};

	template<typename T>
	class ConstRandomAccess {
	public:
		struct iterator_tag {
		};

		typedef T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef RandomAccess<T> iterator;
		typedef RandomAccess<T> class_name;
		//const;
		typedef iterator_tag iterator_category;
		typedef size_t size_type;

		pointer elem;

		ConstRandomAccess() {
			elem = nullptr;
		}

		ConstRandomAccess(const pointer p) {
			elem = p;
		}

		ConstRandomAccess(const ConstRandomAccess<T> &arg) : elem(arg.elem) {
		}

		class_name &operator=(class_name const &arg) {
			if (this == &arg)
				return (*this);
			elem = arg.elem;
			return (*this);
		}

		~ConstRandomAccess() {}

		bool operator==(const ConstRandomAccess &rhs) const {
			return elem == rhs.elem;
		}

		bool operator!=(const ConstRandomAccess &rhs) const {
			return !(rhs == *this);
		}

		bool operator<(const ConstRandomAccess &rhs) const {
			return elem < rhs.elem;
		}

		bool operator>(const ConstRandomAccess &rhs) const {
			return rhs < *this;
		}

		bool operator<=(const ConstRandomAccess &rhs) const {
			return !(rhs < *this);
		}

		bool operator>=(const ConstRandomAccess &rhs) const {
			return !(*this < rhs);
		}

		const value_type &operator*(const class_name &rhs) const {
			return (*elem);
		}

		const value_type &operator*() {
			return (*elem);
		}

		const value_type *operator->() {
			return (*elem);
		}

		const value_type *operator->() const {
			return (*elem);
		}

		const class_name &operator++() {
			elem++;
			return (*this);
		}

		const class_name operator++(int) {
			class_name tmp = *this;
			elem++;
			return (tmp);
		}

		const class_name &operator--() {
			elem--;
			return (*this);
		}

		const class_name operator--(int) {
			class_name tmp = *this;
			elem--;
			return (tmp);
		}

		reference operator[](size_type n) {
			return *(elem + n);
		}

		const_reference operator[](size_type n) const {
			return *(elem + n);
		}

		const class_name operator+(size_type n) const {
			class_name tmp = *this;
			tmp.elem += n;
			return (tmp);
		}

		const class_name operator-(size_type n) const {
			class_name tmp = *this;
			tmp.elem -= n;
			return (tmp);
		}

		const class_name &operator+=(size_type n) {
			this->elem += n;
			return (*this);
		}

		const class_name &operator-=(size_type n) {
			this->elem -= n;
			return (*this);
		}
	};

	template<typename T>
	class ConstReverseRandomAccess {
	public:
		struct iterator_tag {
		};

		typedef T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef RandomAccess<T> iterator;
		typedef RandomAccess<T> class_name;
		//const;
		typedef iterator_tag iterator_category;
		typedef size_t size_type;

		pointer elem;

		ConstReverseRandomAccess() {
			elem = nullptr;
		}

		ConstReverseRandomAccess(const pointer p) {
			elem = p;
		}

		ConstReverseRandomAccess(const ConstReverseRandomAccess<T> &arg) : elem(arg.elem) {
		}

		class_name &operator=(class_name const &arg) {
			if (this == &arg)
				return (*this);
			elem = arg.elem;
			return (*this);
		}

		~ConstReverseRandomAccess() {}

		bool operator==(const ConstReverseRandomAccess &rhs) const {
			return elem == rhs.elem;
		}

		bool operator!=(const ConstReverseRandomAccess &rhs) const {
			return !(rhs == *this);
		}

		bool operator<(const ConstReverseRandomAccess &rhs) const {
			return elem < rhs.elem;
		}

		bool operator>(const ConstReverseRandomAccess &rhs) const {
			return rhs < *this;
		}

		bool operator<=(const ConstReverseRandomAccess &rhs) const {
			return !(rhs < *this);
		}

		bool operator>=(const ConstReverseRandomAccess &rhs) const {
			return !(*this < rhs);
		}

		const value_type &operator*(const class_name &rhs) const {
			return (*elem);
		}

		const value_type &operator*() {
			return (*elem);
		}

		const value_type *operator->() {
			return (*elem);
		}

		const value_type *operator->() const {
			return (*elem);
		}

		const class_name &operator++() {
			elem++;
			return (*this);
		}

		const class_name operator++(int) {
			class_name tmp = *this;
			elem--;
			return (tmp);
		}

		const class_name &operator--() {
			elem++;
			return (*this);
		}

		const class_name operator--(int) {
			class_name tmp = *this;
			elem++;
			return (tmp);
		}

		reference operator[](size_type n) {
			return *(elem - n);
		}

		const_reference operator[](size_type n) const {
			return *(elem - n);
		}

		class_name operator+(size_type n) const {
			class_name tmp = *this;
			tmp.elem -= n;
			return (tmp);
		}

		class_name operator-(size_type n) const {
			class_name tmp = *this;
			tmp.elem += n;
			return (tmp);
		}

		const class_name &operator+=(size_type n) {
			this->elem -= n;
			return (*this);
		}

		const class_name &operator-=(size_type n) {
			this->elem += n;
			return (*this);
		};
	};

}
#endif
