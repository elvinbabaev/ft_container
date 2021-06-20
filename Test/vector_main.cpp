//
// Created by Elwin Babaew on 2/5/21.
//

#include <vector>
#include "../Container/vector.hpp"
#include <iostream>

typedef std::vector<int> std_vector_int;
typedef ft::vector<int> ft_vector_int;
typedef std::vector<int>::iterator std_iterator_int;
typedef ft::vector<int>::iterator ft_iterator_int;

template<class T>
void check_assign(std::vector<T> &std_vector, ft::vector<T> &ft_vector) {
	typename std::vector<T>::iterator std_iterator = std_vector.begin();
	typename ft::vector<T>::iterator ft_iterator = ft_vector.begin();
	std::cout<<std::endl;
	while (std_iterator != std_vector.end() && ft_iterator != ft_vector.end()) {
//		std::cout<<"std: "<<*std_iterator<<" ft: "<<*ft_iterator<<std::endl;
		assert(*std_iterator == *ft_iterator);
		std_iterator++;
		ft_iterator++;
		if ((std_iterator == std_vector.end() && ft_iterator != ft_vector.end())
		    || (std_iterator != std_vector.end() && ft_iterator == ft_vector.end())) {
			assert(false);
			return;
		}
	}
}

template<class T>
T get_vector_int(int i, int len) {
	T vector;
	for (; i < len; i++) {
		vector.push_back(i * 10);
	}
	return vector;
}

void test_1()
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
	check_assign(std_vector, ft_vector);
	std::cout<<"size: "<<ft_vector.size()<<" == "<<std_vector.size()<<std::endl;
	std::cout<<"capacity: "<<ft_vector.capacity()<<" == "<<std_vector.capacity()<<std::endl;
	std::cout<<"max_size: "<<ft_vector.max_size()<<" == "<<std_vector.max_size()<<std::endl;
	std::cout<<"\tCheck resize"<<std::endl;
	std_vector.resize(7);
	ft_vector.resize(7);
	check_assign(std_vector, ft_vector);
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
	check_assign(std_vector, ft_vector);
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
	check_assign(std_vector, ft_vector);


	std::cout<<"\tCheck at()\n";
	for (size_t i = 0; i < ft_vector.size() || i < std_vector.size(); ++i) {
		std::cout<<std_vector.at(i)<<" == "<<ft_vector.at(i)<<std::endl;
	}
	check_assign(std_vector, ft_vector);
	std::cout<<"\tCheck back, pop_back\n";
	while (!ft_vector.empty() || !std_vector.empty())
	{
		std::cout<<ft_vector.back()<<" == "<<std_vector.back()<<std::endl;
		std_vector.pop_back();
		ft_vector.pop_back();
	}
	check_assign(std_vector, ft_vector);
	std::cout<<"Check ft_vector"<<std::endl;
	ft_vector.assign(1, 10);
	for (ft::vector<int>::iterator i = ft_vector.begin(); i != ft_vector.end() ; i++) {
		std::cout<<*i<<" ";
	}
	check_assign(std_vector, ft_vector);
	std::cout<<std::endl;
	std::cout<<"Capacity : "<<ft_vector.capacity()<<" Sise : "<<ft_vector.size()<<std::endl;
	ft_vector.assign(100, 5);
	for (ft::vector<int>::iterator i = ft_vector.begin(); i != ft_vector.end() ; i++) {
		std::cout<<*i<<" ";
	}
	check_assign(std_vector, ft_vector);
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
	check_assign(std_vector, ft_vector);
}

template<class T>
void printer(std::vector<T> &std, ft::vector<T> &ft)
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

void test_2(){
    {
        std::vector<int> std_vector;
        ft::vector<int> ft_vector;

        for (int i = 0; i < 16; ++i) {
            std_vector.push_back(i);
            ft_vector.push_back(i);
        }
        printer(std_vector, ft_vector);

	    check_assign(std_vector, ft_vector);
        std::cout<<"\tTest insert\n";
        std_vector.insert(((std_vector.begin()++)), -5);
        ft_vector.insert(((ft_vector.begin()++)), -5);
        printer(std_vector, ft_vector);

	    check_assign(std_vector, ft_vector);

	    std::vector<int>::iterator i1 = std_vector.begin();
        ft::vector<int>::iterator i2 = ft_vector.begin();
        for (int i = 0; i < 5; ++i) {
            i1++;i2++;
        }

        std_vector.insert(i1, 999);
        ft_vector.insert(i2, 999);
        printer(std_vector, ft_vector);
	    check_assign(std_vector, ft_vector);
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
	    check_assign(std_vector, ft_vector);
        std_vector.insert(i1, tmp.begin(), (--tmp.end()));
        ft_vector.insert(i2, tmp.begin(), (--tmp.end()));
        printer(std_vector, ft_vector);
        std::cout<<ft_vector.size()<<" == "<<std_vector.size()<<std::endl;
        std::cout<<ft_vector.capacity()<<" == "<<std_vector.capacity()<<std::endl;
	    check_assign(std_vector, ft_vector);
    }
}

void test_3() {
	{
		std_vector_int std_vector = get_vector_int<std_vector_int>(1, 5);
		ft_vector_int ft_vector = get_vector_int<ft_vector_int>(1, 5);
		std_vector_int std_vector2;
		ft_vector_int ft_vector2;
		std_vector_int std_vector3(std_vector);
		ft_vector_int ft_vector3(ft_vector);
		std_vector2 = std_vector3;
		ft_vector2 = ft_vector3;

		printer(std_vector, ft_vector);
		printer(std_vector2, ft_vector2);
		printer(std_vector3, ft_vector3);
		check_assign(std_vector, ft_vector);
		check_assign(std_vector2, ft_vector2);
		check_assign(std_vector3, ft_vector3);

		std_vector2.erase(std_vector2.begin(), (--(--std_vector2.end())));
		ft_vector2.erase(ft_vector2.begin(), (--(--ft_vector2.end())));

		std_vector.swap(std_vector2);
		ft_vector.swap(ft_vector2);

		std_vector3.clear();
		ft_vector3.clear();

		printer(std_vector, ft_vector);
		printer(std_vector2, ft_vector2);
		printer(std_vector3, ft_vector3);
		check_assign(std_vector, ft_vector);
		check_assign(std_vector2, ft_vector2);
		check_assign(std_vector3, ft_vector3);

		std_vector2.insert((std_vector2.begin()++), std_vector3.begin(), (--std_vector3.end()));
		ft_vector2.insert((ft_vector2.begin()++), ft_vector3.begin(), (--ft_vector3.end()));

		std_vector3.insert(std_vector3.begin(), 5);
		ft_vector3.insert(ft_vector3.begin(), 5);

		std_vector.insert((std_vector.end()--), 5, 10);
		ft_vector.insert((ft_vector.end()--), 5, 10);

		printer(std_vector, ft_vector);
		printer(std_vector2, ft_vector2);
		printer(std_vector3, ft_vector3);
		check_assign(std_vector, ft_vector);
		check_assign(std_vector2, ft_vector2);
		check_assign(std_vector3, ft_vector3);

		std_vector = std_vector2;
		ft_vector = ft_vector2;

		ft_vector3 = ft_vector;
		std_vector3 = std_vector;

		check_assign(std_vector, ft_vector);
		check_assign(std_vector2, ft_vector2);
		check_assign(std_vector3, ft_vector3);
		printer(std_vector, ft_vector);
		printer(std_vector2, ft_vector2);
		printer(std_vector3, ft_vector3);
	}
}

void test_4() {
	{
		ft_vector_int ft_vector1 = get_vector_int<ft_vector_int>(1, 10);
		std_vector_int std_vector1 = get_vector_int<std_vector_int>(1, 10);
		ft_vector_int ft_vector2 = get_vector_int<ft_vector_int>(20, 30);
		std_vector_int std_vector2 = get_vector_int<std_vector_int>(20, 30);
		std_iterator_int std_it = std_vector1.begin();
		ft_iterator_int ft_it = ft_vector1.begin();
		std_it++;
		std_it++;
		std_it++;
		ft_it++;
		ft_it++;
		ft_it++;
		std_vector1.insert(std_vector1.begin(), std_vector2.begin(), (--std_vector2.end()));
		ft_vector1.insert(ft_vector1.begin(), ft_vector2.begin(), (--ft_vector2.end()));
		printer(std_vector1, ft_vector1);
		printer(std_vector2, ft_vector2);
		check_assign(std_vector1, ft_vector1);
		check_assign(std_vector2, ft_vector2);
	}
}

int main()
{
	test_1();
	test_2();
	test_3();
	test_4();
	return (0);
}