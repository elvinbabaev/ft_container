#include <iostream>
#include <stack>
#include "../Container/stack.hpp"

# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

template<class T>
void print(ft::stack<T> ft_stack, std::stack<T> &std_stack)
{
	std::cout <<CYAN<< "ft::stack"<<RESET<<"\tstd::stack" << std::endl;
	std::cout << CYAN << "size\t" << ft_stack.size() << RESET << "\t" << "size\t" << std_stack.size() << std::endl;
	while (!ft_stack.empty() || !std_stack.empty()) {
		std::cout << CYAN << "" << ft_stack.top() << RESET << "\t\t" << std_stack.top() << std::endl;
		std_stack.pop();
		ft_stack.pop();
	}
	std::cout<<std::endl;
}

template<class T>
void test(std::stack<T> &std_stack, std::stack<T> &std_stack1, ft::stack<T> &ft_stack, ft::stack<T> &ft_stack1)
{
	if ((std_stack == std_stack1) == (ft_stack == ft_stack1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_stack != std_stack1) == (ft_stack != ft_stack1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_stack < std_stack1) == (ft_stack < ft_stack1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_stack <= std_stack1) == (ft_stack <= ft_stack1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_stack > std_stack1) == (ft_stack > ft_stack1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_stack >= std_stack1) == (ft_stack >= ft_stack1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;
}

int main()
{
	{
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;

		std::cout << MAGENTA << "\tTEST constructor, empty, size, top, push, pop (int)" << RESET << std::endl;
		for (int i = 0; i < 10; ++i) {
			ft_stack.push(i);
			std_stack.push(i);
		}

		print(ft_stack, std_stack);
	}
	{
		std::cout << MAGENTA << "\tTEST constructor, empty, size, top, push, pop (std::string)" << RESET << std::endl;
		ft::stack<std::string> ft_stack;
		std::stack<std::string> std_stack;
		ft_stack.push("text1");
		ft_stack.push("text2");
		ft_stack.push("text3");
		ft_stack.push("text4");
		std_stack.push("text1");
		std_stack.push("text2");
		std_stack.push("text3");
		std_stack.push("text4");

		print(ft_stack, std_stack);
	}
	{
		std::cout<<MAGENTA<<"\tTEST operator"<<RESET<<std::endl;
		ft::stack<int> ft_stack, ft_stack1;
		std::stack<int> std_stack, std_stack1;

		std_stack.push(5);
		std_stack.push(10);
		std_stack.push(15);
		std_stack1.push(5);
		std_stack1.push(10);


		ft_stack.push(5);
		ft_stack.push(10);
		ft_stack.push(15);
		ft_stack1.push(5);
		ft_stack1.push(10);

		test(std_stack, std_stack1, ft_stack, ft_stack1);

		std_stack1.push(15);
		ft_stack1.push(15);

		test(std_stack, std_stack1, ft_stack, ft_stack1);

		std_stack1.push(20);
		ft_stack1.push(20);

		test(std_stack, std_stack1, ft_stack, ft_stack1);
	}
}