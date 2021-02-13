//
// Created by Elwin Babaew on 2/3/21.
//

#include <iostream>
#include <queue>
#include "../Container/queue.hpp"

# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

template<class T>
void test(std::queue<T> &std_queue, std::queue<T> &std_queue1, ft::queue<T> &ft_queue, ft::queue<T> &ft_queue1)
{
	if ((std_queue == std_queue1) == (ft_queue == ft_queue1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_queue != std_queue1) == (ft_queue != ft_queue1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_queue < std_queue1) == (ft_queue < ft_queue1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_queue <= std_queue1) == (ft_queue <= ft_queue1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_queue > std_queue1) == (ft_queue > ft_queue1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;

	if ((std_queue >= std_queue1) == (ft_queue >= ft_queue1))
		std::cout<<"SUCCESS"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;
}

template<class T>
void print(ft::queue<T> &ft_queue, std::queue<T> &std_queue)
{
	std::cout <<CYAN<< "ft::queue"<<RESET<<"\tstd::queue" << std::endl;
	std::cout << CYAN << "size\t" << ft_queue.size() << RESET << "\t" << "size\t" << std_queue.size() <<"\n\n";
	while (!ft_queue.empty() || !std_queue.empty()) {
		std::cout << CYAN<<"back:  "<< ft_queue.back() << RESET << "\t\t" << std_queue.back() << std::endl;
		std::cout << CYAN<<"front: "<< ft_queue.front() << RESET << "\t\t" << std_queue.front() << std::endl;
		std::cout<<std::endl;
		std_queue.pop();
		ft_queue.pop();
	}
	std::cout<<std::endl;
}

int main()
{
	{
		ft::queue<int> ft_queue;
		std::queue<int> std_queue;

		std::cout << MAGENTA << "\tTEST constructor, empty, size, front, back, push, pop (int)" << RESET << std::endl;
		for (int i = 0; i < 10; ++i) {
			ft_queue.push(i);
			std_queue.push(i);
			std::cout << CYAN<<"back:  "<< ft_queue.back() << RESET << "\t\t" << std_queue.back() <<"\n";
		}
		std::cout<<std::endl;
		print(ft_queue, std_queue);
	}
	{
		std::cout << MAGENTA << "\tTEST constructor, empty, size, front, back, push, pop (std::string)" << RESET << std::endl;
		ft::queue<std::string> ft_queue;
		std::queue<std::string> std_queue;

		ft_queue.push("text1");
		ft_queue.push("text2");
		ft_queue.push("text3");
		ft_queue.push("text4");
		std_queue.push("text1");
		std_queue.push("text2");
		std_queue.push("text3");
		std_queue.push("text4");

		print(ft_queue, std_queue);
	}
	{
		std::cout<<MAGENTA<<"\tTEST operator"<<RESET<<std::endl;
		ft::queue<int> ft_queue, ft_queue1;
		std::queue<int> std_queue, std_queue1;

		std_queue.push(5);
		std_queue.push(10);
		std_queue.push(15);
		std_queue1.push(5);
		std_queue1.push(10);


		ft_queue.push(5);
		ft_queue.push(10);
		ft_queue.push(15);
		ft_queue1.push(5);
		ft_queue1.push(10);

		test(std_queue, std_queue1, ft_queue, ft_queue1);

		std_queue1.push(15);
		ft_queue1.push(15);

		test(std_queue, std_queue1, ft_queue, ft_queue1);

		std_queue1.push(20);
		ft_queue1.push(20);

		test(std_queue, std_queue1, ft_queue, ft_queue1);
	}
}