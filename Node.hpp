#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template<class T>
class Node{
public:
	typedef T value_type;
	typedef Node* class_pointer;
public:
	class_pointer next;
	class_pointer prev;
	value_type data;

	Node():next(nullptr), prev(nullptr), data(value_type()){}
	Node(const Node &arg):next(arg.next), prev(arg.next), data(arg.data){}
	virtual ~Node() {}
	Node &operator=(Node const&arg){
		this->data = arg.data;
		this->next = arg.next;
		this->prev = arg.prev;
		return (*this);
	}

	bool operator==(const Node &rhs) const {
		return next == rhs.next &&
			   prev == rhs.prev &&
			   data == rhs.data;
	}

	bool operator!=(const Node &rhs) const {
		return !(rhs == *this);
	}

};

#endif
