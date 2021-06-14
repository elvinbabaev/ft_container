//
// Created by Elwin Babaew on 2/5/21.
//

#include <vector>
#include "../Container/vector.hpp"
#include <iostream>

void testBegin()
{
	std::vector<int> std_vector(4, 10);
	ft::vector<int> ft_vector(4, 10);

	for (int i = 1; i < 5; ++i) {
		std_vector.push_back(i);
		ft_vector.push_back(i);
	}

	std::vector<int>::iterator i_std = std_vector.begin();
	ft::vector<int>::iterator i_ft = ft_vector.begin();

	while (i_ft != ft_vector.end() || i_std != std_vector.end())
	{
		std::cout<<*i_std<<"\t"<<*i_ft<<std::endl;
		i_ft++;
		i_std++;
	}

	std::cout<<"size: "<<ft_vector.size()<<" == "<<std_vector.size()<<std::endl;
	std::cout<<"capacity: "<<ft_vector.capacity()<<" == "<<std_vector.capacity()<<std::endl;
	std::cout<<"max_size: "<<ft_vector.max_size()<<" == "<<std_vector.max_size()<<std::endl;
	std::cout<<"\tCheck resize"<<std::endl;
	std_vector.resize(7);
	ft_vector.resize(7);

 	i_std = std_vector.begin();
	i_ft = ft_vector.begin();
	while (i_ft != ft_vector.end() || i_std != std_vector.end())
	{
		std::cout<<*i_std<<"\t"<<*i_ft<<std::endl;
		i_ft++;
		i_std++;
	}
	for (int i = 0; i < 6; ++i) {
		std_vector[i] = i;
		ft_vector[i] = i;
	}
	std::cout<<"Check reserve: ";
	std::cout<<"Capacity before: "<<ft_vector.capacity()<<" == "<<std_vector.capacity()<<std::endl;
	ft_vector.reserve(100);
	std_vector.reserve(100);
	std::cout<<"Capacity after: "<<ft_vector.capacity()<<" == "<<std_vector.capacity()<<std::endl;
	std::cout<<"\tOperator[]"<<std::endl;
	for (ft::vector<int>::size_type i = 0; i < ft_vector.size(); ++i) {
		std::cout<<std_vector[i]<<" == "<<ft_vector[i]<<std::endl;
	}
	std::cout<<"\tCheck empty()"<<std::endl;
	if ((ft_vector.empty()) == (std_vector.empty()))
		std::cout<<"Success"<<std::endl;



	std::cout<<"\tCheck at()\n";
	for (int i = 0; i < ft_vector.size() || i < std_vector.size(); ++i) {
		std::cout<<std_vector.at(i)<<" == "<<ft_vector.at(i)<<std::endl;
	}
	std::cout<<"\tCheck back, pop_back\n";
	while (!ft_vector.empty() || !std_vector.empty())
	{
		std::cout<<ft_vector.back()<<" == "<<std_vector.back()<<std::endl;
		std_vector.pop_back();
		ft_vector.pop_back();
	}

	std::cout<<"Check ft_vector"<<std::endl;
	ft_vector.assign(1, 10);
	for (ft::vector<int>::iterator i = ft_vector.begin(); i != ft_vector.end() ; i++) {
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Capacity : "<<ft_vector.capacity()<<" Sise : "<<ft_vector.size()<<std::endl;
	ft_vector.assign(100, 5);
	for (ft::vector<int>::iterator i = ft_vector.begin(); i != ft_vector.end() ; i++) {
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Capacity : "<<ft_vector.capacity()<<" Sise : "<<ft_vector.size()<<std::endl;


	std::cout<<"\nCheck std_vector"<<std::endl;
	std_vector.assign(1, 10);
	for (std::vector<int>::iterator i = std_vector.begin(); i != std_vector.end() ; i++) {
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Capacity : "<<std_vector.capacity()<<" Sise : "<<std_vector.size()<<std::endl;
	std_vector.assign(100, 5);
	for (std::vector<int>::iterator i = std_vector.begin(); i != std_vector.end() ; i++) {
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Capacity : "<<std_vector.capacity()<<" Sise : "<<std_vector.size()<<std::endl;

	std_vector.clear();
	ft_vector.clear();

	std::cout<<"Check front: "<<std::endl;
	std_vector[0] = 10;
	ft_vector[0] = 10;
	std::cout<<"front : "<<std_vector.front()<<" == "<<ft_vector.front()<<std::endl;
	std_vector.front() = 20;
	ft_vector.front() = 20;
	std::cout<<"front : "<<std_vector.front()<<" == "<<ft_vector.front()<<std::endl;
}

template<class T>
void printer(std::vector<T> std, ft::vector<T> ft)
{
    for (typename std::vector<T>::iterator i = std.begin(); i != std.end(); ++i) {
        if (i == std.begin())
            std::cout<<"std::vector\t";
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
    for (typename ft::vector<T>::iterator i = ft.begin(); i != ft.end(); ++i) {
        if (i == ft.begin())
            std::cout<<"ft::vector\t";
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
}

void testSecond(){
    {
        std::vector<int> std_vector;
        ft::vector<int> ft_vector;

        for (int i = 0; i < 16; ++i) {
            std_vector.push_back(i);
            ft_vector.push_back(i);
        }
        printer(std_vector, ft_vector);

        std::cout<<"\tTest insert\n";
        std_vector.insert(((std_vector.begin()++)), -5);
        ft_vector.insert(((ft_vector.begin()++)), -5);
        printer(std_vector, ft_vector);

        std::vector<int>::iterator i1 = std_vector.begin();
        ft::vector<int>::iterator i2 = ft_vector.begin();
        for (int i = 0; i < 5; ++i) {
            i1++;i2++;
        }
        std_vector.insert(i1, 999);
        ft_vector.insert(i2, 999);
        printer(std_vector, ft_vector);
        std::cout<<ft_vector.size()<<" == "<<std_vector.size()<<std::endl;
        std::cout<<ft_vector.capacity()<<" == "<<std_vector.capacity()<<std::endl;

        std_vector.insert(i1, 5, -3);
        ft_vector.insert(i2, 5, -3);
        printer(std_vector, ft_vector);
        std::cout<<ft_vector.size()<<" == "<<std_vector.size()<<std::endl;
        std::cout<<ft_vector.capacity()<<" == "<<std_vector.capacity()<<std::endl;

        std::vector<int> tmp;
        for (int i = 100; i < 105; ++i) {
            tmp.push_back(i);
        }

        std_vector.insert(i1, tmp.begin(), (--tmp.end()));
        ft_vector.insert(i2, tmp.begin(), (--tmp.end()));
        printer(std_vector, ft_vector);
        std::cout<<ft_vector.size()<<" == "<<std_vector.size()<<std::endl;
        std::cout<<ft_vector.capacity()<<" == "<<std_vector.capacity()<<std::endl;
    }
}


void testInsert(){
	std::vector<int> std_vector_int;
	std::vector<std::string> std_vector_string;
	ft::vector<int> ft_vector_int;
	ft::vector<std::string> ft_vector_string;

	for (int i = 0; i < 10; ++i) {
		std_vector_int.push_back(i * 10);
		ft_vector_int.push_back(i * 10);
	}
}

int main()
{
	testBegin();
	testSecond();
	testInsert();
//    std::vector<int> test;
//    for (int i = 0; i < 20; ++i) {
//        test.push_back(i);
//    }
//    std::cout<<test.size()<<" "<<test.capacity()<<std::endl;
//    std::cout<<"|"<<*(test.erase((++(++(++(test.begin())))), (--(--(--test.end())))))<<"|\n";
//    std::cout<<*(test.erase((++(++(++(test.begin()))))))<<"|\n";
//    std::cout<<test.size()<<" "<<test.capacity()<<std::endl;
//    for (std::vector<int>::iterator i = test.begin(); i != test.end() ; i++) {
//        std::cout<<*i<<" ";
//    }
//    std::cout<<std::endl;
//    ft::vector<int> test1;
//    for (int i = 0; i < 20; ++i) {
//        test1.push_back(i);
//    }
//    std::cout<<test1.size()<<" "<<test1.capacity()<<std::endl;
//    std::cout<<"|"<<*(test1.erase((++(++(++(test1.begin())))), (--(--(--test1.end())))))<<"|\n";
//    std::cout<<*(test1.erase((++(++(++(test1.begin()))))))<<"|\n";
//    std::cout<<test1.size()<<" "<<test1.capacity()<<std::endl;
//    for (ft::vector<int>::iterator i = test1.begin(); i != test1.end() ; i++) {
//        std::cout<<*i<<" ";
//    }
//    std::cout<<std::endl;

	return (0);
}