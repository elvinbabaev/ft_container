//
// Created by Elwin Babaew on 2/5/21.
//

//#include "vector.hpp"
#include <vector>
#include <iostream>

class test{
private:
	int _a;
public:
	test(const test &arg):_a(arg._a){}
//	test(){}
//	test(int a):_a(a){}
//	~test(){}
	int getA(){return _a;}
	void setA(int a){_a = a;}
//	test()
};

void ft(test a){
	std::cout<<"|"<<a.getA()<<"|"<<std::endl;
}

int main()
{
//	std::vector<int> std_vector(4, 10);
//	for (std::vector<int>::iterator i = std_vector.begin(); i != std_vector.end() ; ++i) {
//		std::cout<<*i<<" ";
//	}
//	std::cout<<std::endl;
//
//	ft::vector<int> ft_vector(4, 10);
//	for (ft::vector<int>::iterator i = ft_vector.begin(); i != ft_vector.end() ; ++i) {
//		std::cout<<*i<<" ";
//	}
//	std::cout<<std::endl;
//
//	ft_vector[0] = 1;
//	ft_vector[1] = 2;
//	ft_vector[2] = 3;
//	ft_vector[3] = 4;
//	for (ft::vector<int>::iterator i = ft_vector.begin(); i != ft_vector.end() ; ++i) {
//		std::cout<<*i<<" ";
//	}
	test a;
	a.setA(10);
	ft(a);
}