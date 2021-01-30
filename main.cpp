//
// Created by Elwin Babaew on 1/27/21.
//

#include "Node.hpp"
#include "List.hpp"
#include <iostream>
#include <list>
#include <vector>
# define RESET   "\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define BOLDBLACK   "\033[1m\033[30m"
# define BOLDRED     "\033[1m\033[31m"
# define BOLDGREEN   "\033[1m\033[32m"
# define BOLDYELLOW  "\033[1m\033[33m"
# define BOLDBLUE    "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN    "\033[1m\033[36m"
# define BOLDWHITE   "\033[1m\033[37m"

void	testConstructorFill()
{
	{
		std::cout <<MAGENTA<< "\tTEST ConstructorFill ft::List" <<RESET<< std::endl;
		ft::List<int> test(5, 10);
		for (ft::List<int>::iterator i = test.begin(); i != test.end(); ++i) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
	{
		std::cout<<MAGENTA<< "\tTEST ConstructorFill std::list" <<RESET<< std::endl;
		std::list<int> test(5, 10);
		for (std::list<int>::iterator i = test.begin(); i != test.end(); ++i) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
	std::cout<<std::endl;
}

void	testConstructorRange()
{
	{
		{
			std::cout << MAGENTA << "\tTEST ConstructRange ft::List" <<RESET<< std::endl;
			ft::List<std::string> test;
			test.push_back("test1");
			test.push_back("test2");
			test.push_back("test3");
			test.push_back("test4");
			test.push_back("test5");


			ft::List<std::string> range(test.begin(), test.end());
			for (ft::List<std::string>::iterator i = range.begin(); i != range.end(); ++i) {
				std::cout << *i << " ";
			}
			std::cout << std::endl;
		}
		{
			ft::List<int> test;
			test.push_back(1);
			test.push_back(2);
			test.push_back(3);
			test.push_back(4);
			test.push_back(5);


			ft::List<int> range(test.begin(), test.end());
			for (ft::List<int>::iterator i = range.begin(); i != range.end(); ++i) {
				std::cout << *i << " ";
			}
			std::cout << std::endl;
		}
	}
	{
		{
			std::cout << MAGENTA << "\tTEST ConstructRange std::List" <<RESET<< std::endl;
			std::list<std::string> test;
			test.push_back("test1");
			test.push_back("test2");
			test.push_back("test3");
			test.push_back("test4");
			test.push_back("test5");


			std::list<std::string> range(test.begin(), test.end());
			for (std::list<std::string>::iterator i = range.begin(); i != range.end(); ++i) {
				std::cout << *i << " ";
			}
			std::cout << std::endl;
		}
		{
			std::list<int> test;
			test.push_back(1);
			test.push_back(2);
			test.push_back(3);
			test.push_back(4);
			test.push_back(5);


			std::list<int> range(test.begin(), test.end());
			for (std::list<int>::iterator i = range.begin(); i != range.end(); ++i) {
				std::cout << *i << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

}

void	testConstructorCopy(){
	{
		std::cout<<MAGENTA<<"\tTEST ConstructorCopy ft::List"<<RESET<<std::endl;
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
	{
		std::cout<<MAGENTA<<"\tTEST ConstructorCopy std::list"<<RESET<<std::endl;
		std::list<std::string>test;
		test.push_back("test1");
		test.push_back("test2");
		test.push_back("test3");
		test.push_back("test4");
		test.push_back("test5");


		std::list<std::string>copy(test);
		for (std::list<std::string>::iterator i = copy.begin(); i != copy.end(); ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
		std::cout<<std::endl;
	}
}

void	testAssign()
{
	{
		std::cout<<"TEST Assign"<<std::endl;
		ft::List<int> a1(4, 5);
		ft::List<int> a2(5, 1);
		std::list<int> b1(4, 5);
		std::list<int> b2(5, 1);

		std::cout<<CYAN;
		for (ft::List<int>::iterator i = a1.begin(); i != a1.end(); ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<RESET;
		std::cout<<std::endl;
		for (std::list<int>::iterator i = b1.begin(); i != b1.end(); ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
		a1.assign(a2.begin(), a2.end());
		b1.assign(b2.begin(), b2.end());
		std::cout<<CYAN;
		for (ft::List<int>::iterator i = a1.begin(); i != a1.end(); ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<RESET;
		std::cout<<std::endl;
		for (std::list<int>::iterator i = b1.begin(); i != b1.end(); ++i) {
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
		std::cout<<CYAN;
		for (ft::List<int>::iterator i = test2.begin(); i != test2.end() ; i++) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
		std::cout<<RESET;
	}
	{
		std::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);

		std::list<int> test2;
		test2.assign(test.begin(), test.end());
		for (std::list<int>::iterator i = test2.begin(); i != test2.end() ; i++) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
	}
}

void testInsert()
{
	{
		{
			std::cout<<MAGENTA << "\tTEST insert" << RESET<<std::endl;
			ft::List<int> a1(4, 10);
			ft::List<int>::iterator i = a1.begin();
			i++;
			a1.insert(i, 123);
			std::cout<<CYAN;
			for (ft::List<int>::iterator j = a1.begin(); j != a1.end(); ++j) {
				std::cout << *j << " ";
			}
			std::cout << RESET<<std::endl;
		}
		{
			std::list<int> a1(4, 10);
			std::list<int>::iterator i = a1.begin();
			i++;
			a1.insert(i, 123);
			for (std::list<int>::iterator j = a1.begin(); j != a1.end(); ++j) {
				std::cout << *j << " ";
			}
			std::cout << std::endl;
		}
	}
	{
		{
			std::cout << MAGENTA << "\tTEST insert v2" << std::endl;
			ft::List<int> a1(4, 10);
			ft::List<int>::iterator i = a1.begin();
			i++;
			a1.insert(i, 5, 1);
			std::cout<<CYAN;
			for (ft::List<int>::iterator j = a1.begin(); j != a1.end(); ++j) {
				std::cout << *j << " ";
			}
			std::cout << std::endl;
			std::cout<<RESET;
		}
		{
			std::list<int> a1(4, 10);
			std::list<int>::iterator i = a1.begin();
			i++;
			a1.insert(i, 5, 1);
			for (std::list<int>::iterator j = a1.begin(); j != a1.end(); ++j) {
				std::cout << *j << " ";
			}
			std::cout << std::endl;
		}
	}
	{
		{
			std::cout<<MAGENTA << "\tTEST insert v3" <<RESET<< std::endl;
			ft::List<int> a1;
			a1.push_back(1);
			a1.push_back(2);
			a1.push_back(3);
			a1.push_back(4);
			a1.push_back(5);
			a1.push_back(6);
			ft::List<int>::iterator i1 = a1.begin();
			ft::List<int>::iterator i2 = a1.begin();
			i1++;
			i2++;
			i2++;
			i2++;
			i2++;
			ft::List<int> a2(10, 10);
			ft::List<int>::iterator j = a2.begin();
			j++;
			j++;
			a2.insert(j, i1, i2);
			std::cout<<CYAN;
			for (ft::List<int>::iterator i = a2.begin(); i != a2.end(); ++i) {
				std::cout << *i << " ";
			}
			std::cout<<RESET;
			std::cout << std::endl;
		}
		{
			std::list<int> a1;
			a1.push_back(1);
			a1.push_back(2);
			a1.push_back(3);
			a1.push_back(4);
			a1.push_back(5);
			a1.push_back(6);
			std::list<int>::iterator i1 = a1.begin();
			std::list<int>::iterator i2 = a1.begin();
			i1++;
			i2++;
			i2++;
			i2++;
			i2++;
			std::list<int> a2(10, 10);
			std::list<int>::iterator j = a2.begin();
			j++;
			j++;
			a2.insert(j, i1, i2);
			for (std::list<int>::iterator i = a2.begin(); i != a2.end(); ++i) {
				std::cout << *i << " ";
			}
			std::cout << std::endl;
		}
	}
	std::cout<<std::endl;
}


bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

void testMerge()
{
	{
		{
			std::cout << MAGENTA << "\tTEST merge" << RESET << std::endl;
			ft::List<int> first, second;

			first.push_back(1);
			first.push_back(10);
			first.push_back(4);
			first.push_back(5);

			second.push_back(2);
			second.push_back(0);
			second.push_back(2);
			second.push_back(3);

			first.merge(second);
			std::cout << CYAN;
			for (ft::List<int>::iterator it = first.begin(); it != first.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << std::endl;
			std::cout << RESET;
		}
		{
			std::list<int> first, second;

			first.push_back(1);
			first.push_back(10);
			first.push_back(4);
			first.push_back(5);

			second.push_back(2);
			second.push_back(0);
			second.push_back(2);
			second.push_back(3);

			first.merge(second);
			for (std::list<int>::iterator it = first.begin(); it != first.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << std::endl;
		}
	}
	{
		{
			std::cout<<MAGENTA<<"\tTEST merge v2"<<RESET<<std::endl;
			ft::List<int> first;
			first.push_back(1);
			first.push_back(2);
			first.push_back(3);
			first.push_back(4);
			ft::List<int> second;
			second.push_back(5);
			second.push_back(6);
			second.push_back(7);
			second.push_back(8);
			first.merge(second);
			std::cout << CYAN;
			for (ft::List<int>::iterator it = first.begin(); it != first.end(); ++it)
				std::cout << ' ' << *it;
			std::cout <<RESET<< std::endl;
		}
		{
			std::list<int> first;
			first.push_back(1);
			first.push_back(2);
			first.push_back(3);
			first.push_back(4);
			std::list<int> second;
			second.push_back(5);
			second.push_back(6);
			second.push_back(7);
			second.push_back(8);
			first.merge(second);
			for (std::list<int>::iterator it = first.begin(); it != first.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << std::endl;
		}
	}
	{
		{
			std::cout<<MAGENTA<<"\tTEST merge v3"<<RESET<<std::endl;
			ft::List<std::string> first;
			first.push_back("2abc");
			first.push_back("4abc");
			first.push_back("6abc");
			first.push_back("8abc");
			ft::List<std::string> second;
			second.push_back("1abc");
			second.push_back("3abc");
			second.push_back("5abc");
			second.push_back("7abc");
			first.merge(second);
			std::cout << CYAN;
			for (ft::List<std::string>::iterator it = first.begin(); it != first.end(); ++it)
				std::cout << ' ' << *it;
			std::cout <<RESET<< std::endl;
		}
		{
			std::list<std::string> first;
			first.push_back("2abc");
			first.push_back("4abc");
			first.push_back("6abc");
			first.push_back("8abc");
			std::list<std::string> second;
			second.push_back("1abc");
			second.push_back("3abc");
			second.push_back("5abc");
			second.push_back("7abc");
			first.merge(second);
			for (std::list<std::string>::iterator it = first.begin(); it != first.end(); ++it)
				std::cout << ' ' << *it;
		}
		std::cout<<std::endl;
	}
	{
		std::cout<<MAGENTA<<"\tTEST merge v4"<<RESET<<std::endl;
		ft::List<double> first, second;

		first.push_back(2.2);
		first.push_back(2.9);
		first.push_back(3.1);

		second.push_back(1.4);
		second.push_back(3.7);
		second.push_back(7.1);
		first.merge(second);
		second.push_back(2.9);
		first.merge(second, mycomparison);
		std::cout<<CYAN;
		for (ft::List<double>::iterator it = first.begin(); it != first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout <<RESET<< '\n';
	}
	{
		std::list<double> first, second;

		first.push_back(2.2);
		first.push_back(2.9);
		first.push_back(3.1);

		second.push_back(1.4);
		second.push_back(3.7);
		second.push_back(7.1);
		first.merge(second);
		second.push_back(2.9);
		first.merge(second, mycomparison);
		for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it) {
			std::cout << ' ' << *it;
		}
		std::cout << '\n';
	}
	std::cout<<std::endl;
}

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

void testSort(){
	{
		std::cout<<MAGENTA<<"\tTEST sort"<<RESET<<std::endl;
		ft::List<int> test;
		test.push_back(3);
		test.push_back(0);
		test.push_back(-2);
		test.push_back(-1);
		test.push_back(6);
		test.push_back(4);
		test.push_back(1);
		test.push_back(10);
		std::cout<<CYAN;
		for (ft::List<int>::iterator i = test.begin(); i != test.end() ; ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
		test.sort();
		for (ft::List<int>::iterator i = test.begin(); i != test.end() ; ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<RESET<<std::endl;
	}
	{
		std::list<int> test;
		test.push_back(3);
		test.push_back(0);
		test.push_back(-2);
		test.push_back(-1);
		test.push_back(6);
		test.push_back(4);
		test.push_back(1);
		test.push_back(10);
		for (std::list<int>::iterator i = test.begin(); i != test.end() ; ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
		test.sort();
		for (std::list<int>::iterator i = test.begin(); i != test.end() ; ++i) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
	}
	{
		{
			std::cout<<MAGENTA<<"\tTEST sort v2"<<RESET<<std::endl;
			ft::List<std::string> mylist;
			ft::List<std::string>::iterator it;
			mylist.push_back("one");
			mylist.push_back("two");
			mylist.push_back("Three");

			mylist.sort();

			std::cout<<CYAN;
			for (it = mylist.begin(); it != mylist.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
			mylist.sort(compare_nocase);
			for (it = mylist.begin(); it != mylist.end(); ++it)
				std::cout << ' ' << *it;
			std::cout<<RESET<<std::endl;
		}
		{
			std::list<std::string> mylist;
			std::list<std::string>::iterator it;
			mylist.push_back("one");
			mylist.push_back("two");
			mylist.push_back("Three");

			mylist.sort();

			for (it = mylist.begin(); it != mylist.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			mylist.sort(compare_nocase);

			for (it = mylist.begin(); it != mylist.end(); ++it)
				std::cout << ' ' << *it;
			std::cout<<std::endl;
		}
	}
}

void testReverse()
{
	{
		std::cout<<MAGENTA<<"\tTEST reverse"<<std::endl;
		ft::List<int> test;
		for (int i = 1; i < 10; ++i) {
			test.push_back(i);
		}
		for (ft::List<int>::iterator i = test.begin(); i != test.end() ; i++) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
		test.reverse();
		for (ft::List<int>::iterator i = test.begin(); i != test.end() ; i++) {
			std::cout<<*i<<" ";
		}
		std::cout<<std::endl;
	}
}

int main()
{
	testConstructorCopy();
	testConstructorFill();
	testConstructorRange();
	testAssign();
	testInsert();
	testMerge();
	testSort();
	testReverse();
}