//
// Created by Elwin Babaew on 1/27/21.
//

#include "Node.hpp"
#include "List.hpp"
#include <iostream>
#include <list>


void testConstructorFill()
{
	std::cout<<"TEST ConstructorFill"<<std::endl;
	ft::List<int> test(5, 10);
	for (ft::List<int>::iterator i = test.begin(); i != test.end() ; ++i) {
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
}

void testConstructorRange()
{
	{
		std::cout<<"TEST ConstructRange"<<std::endl;
		ft::List<std::string>test;
		test.push_back("test1");
		test.push_back("test2");
		test.push_back("test3");
		test.push_back("test4");
		test.push_back("test5");


		ft::List<std::string>range(test.begin(), test.end());
		for (ft::List<std::string>::iterator i = range.begin(); i != range.end() ; ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
	}
	{
		ft::List<int>test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);


		ft::List<int>range(test.begin(), test.end());
		for (ft::List<int>::iterator i = range.begin(); i != range.end() ; ++i) {
			std::cout<<*i<<" ";
		}
	}
}

int main()
{
	testConstructorFill();
	testConstructorRange();
}