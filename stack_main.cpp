//
// Created by Elwin Babaew on 2/2/21.
//
//
#include <iostream>
#include <stack>
#include "stack.hpp"

int main()
{
	ft::stack<int> test;
	for (int i = 0; i < 10; ++i) {
		test.push(i);
	}
	while (!test.empty())
	{
		std::cout<<test.top()<<" ";
		test.pop();
	}
}