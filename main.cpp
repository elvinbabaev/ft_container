//
// Created by Elwin Babaew on 1/27/21.
//

#include "Node.hpp"
#include "List.hpp"
#include <iostream>
#include <list>
int main()
{
	ft::List<int> *test = new ft::List<int>();
	test->push_back(5);
	test->push_back(10);
	test->push_back(15);
	test->push_front(4);
	test->push_front(3);
	test->push_front(2);
	test->push_front(1);
//	*(test->begin()) = 6666;
//	*(test->end().operator--().operator--().operator--()) = 3333;
//	ft::List<int>::const_iterator i = test->begin();
	for (ft::List<int>::iterator i = test->begin(); i != test->end() ; i++) {
		std::cout<<*i<<std::endl;
	}
	for (ft::List<int>::reverse_iterator i = test->rbegin(); i != test->rend(); ++i) {
		std::cout<<*i<<std::endl;
	}
//	std::list<int> *test1 = new std::list<int>();
//	if (test1->empty())
//		std::cout<<"1";
//	else
//		std::cout<<"2";
//	test1->push_front()
//	for (ft::List<int>::iterator i = test->begin(); i < 5; ++i) {
//		std::cout<<(*i);
//	}

}