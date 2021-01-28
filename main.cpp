//
// Created by Elwin Babaew on 1/27/21.
//

#include "Node.hpp"
#include "List.hpp"
#include <iostream>
#include <list>
#include <vector>

void	testConstructorFill()
{
	std::cout<<"TEST ConstructorFill"<<std::endl;
	ft::List<int> test(5, 10);
	for (ft::List<int>::iterator i = test.begin(); i != test.end() ; ++i) {
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
}

void	testConstructorRange()
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
		std::cout<<std::endl;
	}
}

void	testConstructorCopy(){
	{
		std::cout<<"TEST ConstructorCopy"<<std::endl;
		ft::List<std::string>test;
		test.push_back("test1");
		test.push_back("test2");
		test.push_back("test3");
		test.push_back("test4");
		test.push_back("test5");


		ft::List<std::string>copy(test);
		for (ft::List<std::string>::iterator i = copy.begin(); i != copy.end(); ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
	}
}

void	testAssign()
{
	{
		std::cout<<"TEST Assign"<<std::endl;
		ft::List<int> a1(4, 5);
		ft::List<int> a2(5, 1);

		for (ft::List<int>::iterator i = a1.begin(); i != a1.end(); ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
		a1.assign(a2.begin(), a2.end());
		for (ft::List<int>::iterator i = a1.begin(); i != a1.end(); ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
	}
	{
		std::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);

		ft::List<int> test2;
		test2.assign(test.begin(), test.end());
		for (ft::List<int>::iterator i = test2.begin(); i != test2.end() ; i++) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
	}
}

void testInsert()
{
	{
		std::cout<<"TEST insert"<<std::endl;
		ft::List<int> a1(4, 10);
		ft::List<int>::iterator i = a1.begin();
		i++;
		a1.insert(i, 123);
		for (ft::List<int>::iterator j = a1.begin(); j != a1.end() ; ++j) {
			std::cout<<*j<<" ";
		}
		std::cout<<std::endl;
	}
	{
		std::cout<<"TEST insert v2"<<std::endl;
		ft::List<int> a1(4, 10);
		ft::List<int>::iterator i = a1.begin();
		i++;
		a1.insert(i, 5, 1);
		for (ft::List<int>::iterator j = a1.begin(); j != a1.end() ; ++j) {
			std::cout<<*j<<" ";
		}
		std::cout<<std::endl;
	}
	{
		std::cout<<"TEST insert v3"<<std::endl;
		ft::List<int> a1;
		a1.push_back(1);
		a1.push_back(2);
		a1.push_back(3);
		a1.push_back(4);
		a1.push_back(5);
		a1.push_back(6);
		ft::List<int>::iterator i1 = a1.begin();
		ft::List<int>::iterator i2 = a1.begin();
		i1++;i2++;i2++;i2++;i2++;
		ft::List<int> a2(10, 10);
		ft::List<int>::iterator j = a2.begin();
		j++;j++;
		a2.insert(j, i1, i2);
		for (ft::List<int>::iterator i = a2.begin(); i != a2.end() ; ++i) {
			std::cout<<*i<<" ";
		}
	}
}

int main()
{
	testConstructorFill();
	testConstructorRange();
	testConstructorCopy();
	testAssign();
	testInsert();
}