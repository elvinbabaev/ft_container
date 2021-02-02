//
// Created by Elwin Babaew on 2/2/21.
//

#ifndef STACK_HPP
#define STACK_HPP

#include "list.hpp"

namespace ft {
	template<class T, class Container = list<T> >
	class stack {
	public:
		typedef T value_type;
		typedef T const const_value_type;
		typedef Container container_type;
		typedef size_t size_type;
	protected:
		list<T> c;
	public:
		explicit stack(const container_type &ctnr = container_type())
		{
			this->c = ctnr;
		}

		bool empty() const
		{
			return c.empty();
		}

		size_type size() const
		{
			return c.size();
		}

		value_type &top(){
			return c.back();
		}

		const value_type &top() const
		{
			return c.back();
		}

		void push(const value_type &val)
		{
			c.push_back(val);
		}

		void pop()
		{
			c.pop_back();
		}

		friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return lhs.c == rhs.c;
		}

		friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return lhs.c != rhs.c;
		}

		friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return lhs.c < rhs.c;
		}

		friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return lhs.c <= rhs.c;
		}

		friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return lhs.c > rhs.c;
		}

		friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return lhs.c >= rhs.c;
		}
	};
}



#endif
