
#include <iostream>
#include <map>
#include "map.hpp"
#include <vector>

std::vector<std::pair<std::string, std::string>> g_vec_str;
std::vector<std::pair<int, int>> g_vec_int;

//void init_global() {
//    for (int i = 0; i < 50; ++i) {
//		g_vec_int.push_back(std::pair<int, int>(i, i * 10));
//		g_vec_str.push_back(std::pair<std::string, std::string>(i + "", i + " value"));
//	}
//}

void test_empty();

template<class T>
T get_map_int_int() {
	T map;
	std::pair<int, int> b1(1, 111);
	std::pair<int, int> b2(2, 222);
	std::pair<int, int> b3(3, 333);
	std::pair<int, int> b4(4, 444);
	std::pair<int, int> b5(5, 555);
	std::pair<int, int> b6(6, 666);
	std::pair<int, int> b7(7, 777);
	std::pair<int, int> b8(8, 888);
	std::pair<int, int> b9(9, 999);
	std::pair<int, int> b10(10, 101010);
	map.insert(b5);
	map.insert(b3);
	map.insert(b8);
	map.insert(b2);
	map.insert(b4);
	map.insert(b7);
	map.insert(b10);
	map.insert(b1);
	map.insert(b6);
	map.insert(b9);
	return map;
}

template<class T>
T get_map_int_int_mini() {
	T map;
	std::pair<int, int> b1(123, 123123);
	std::pair<int, int> b2(234, 234234);
	std::pair<int, int> b3(456, 345345);
	std::pair<int, int> b4(567, 456456);
	map.insert(b3);
	map.insert(b2);
	map.insert(b4);
	map.insert(b1);
	return map;
}

template<class T>
T get_map_string_string() {
	T map;
	std::pair<std::string, std::string> b1("1", "111");
	std::pair<std::string, std::string> b2("2", "222");
	std::pair<std::string, std::string> b3("3", "333");
	std::pair<std::string, std::string> b33("3", "345");
	std::pair<std::string, std::string> b4("4", "444");
	std::pair<std::string, std::string> b5("5", "555");
	std::pair<std::string, std::string> b6("6", "666");
	std::pair<std::string, std::string> b7("7", "777");
	std::pair<std::string, std::string> b8("8", "888");
	std::pair<std::string, std::string> b9("9", "999");
	std::pair<std::string, std::string> b10("10", "101010");
	map.insert(b5);
	map.insert(b3);
	map.insert(b8);
	map.insert(b2);
	map.insert(b4);
	map.insert(b7);
	map.insert(b10);
	map.insert(b1);
	map.insert(b6);
	map.insert(b9);
	return map;
}

template<class T>
T get_map_string_string_mini() {
	T map;
	std::pair<std::string, std::string> b2("22", "222");
	std::pair<std::string, std::string> b3("33", "333");
	std::pair<std::string, std::string> b5("55", "555");
	std::pair<std::string, std::string> b8("88", "888");
	map.insert(b5);
	map.insert(b3);
	map.insert(b8);
	map.insert(b2);
	return map;
}


//ft::map<std::string, std::string> test_insert() {
//    ft::map<std::string, std::string> ft_map;
//}

template<class T, class K>
void printer(std::map<T, K> &std_map, ft::map<T, K> &ft_map) {
	std::cout << "std::map : " << std::endl;
	for (typename std::map<T, K>::iterator i = std_map.begin(); i != std_map.end(); i++) {
		std::cout << "{ " << i->first << " " << i->second << " } ";
	}
	std::cout << "\nft::map : " << std::endl;
	for (typename ft::map<T, K>::iterator i = ft_map.begin(); i != ft_map.end(); i++) {
		std::cout << "{ " << i->first << " " << i->second << " } ";
	}
	std::cout << std::endl;
}

void insert_test() {
	std::cout << "insert map int int" << std::endl;
	ft::map<int, int> ft_map = get_map_int_int<ft::map<int, int>>();
	std::map<int, int> std_map = get_map_int_int<std::map<int, int>>();
	printer(std_map, ft_map);
	std::cout << std::endl;

	std::cout << "insert map string string" << std::endl;
	ft::map<std::string, std::string> ft_map_string = get_map_string_string<ft::map<std::string, std::string>>();
	std::map<std::string, std::string> std_map_string = get_map_string_string<std::map<std::string, std::string>>();
	printer(std_map_string, ft_map_string);
	std::cout << std::endl;
}

void construct_first_last() {
	std::cout << "construct first last int int" << std::endl;
	ft::map<int, int> ft_map = get_map_int_int<ft::map<int, int>>();
	std::map<int, int> std_map = get_map_int_int<std::map<int, int>>();

	ft::map<int, int> ft_map_copy = ft::map<int, int>(ft_map.begin(), (ft_map.end()--));
	std::map<int, int> std_map_copy = std::map<int, int>(std_map.begin(), (std_map.end()--));
	printer(std_map_copy, ft_map_copy);
	std::cout << std::endl;

	std::cout << "construct first last string string" << std::endl;
	ft::map<std::string, std::string> ft_map_string = get_map_string_string<ft::map<std::string, std::string>>();
	std::map<std::string, std::string> std_map_string = get_map_string_string<std::map<std::string, std::string>>();

	ft::map<std::string, std::string> ft_map_string_copy = ft::map<std::string, std::string>(ft_map_string.begin(),
																							 (ft_map_string.end()--));
	std::map<std::string, std::string> std_map_string_copy = std::map<std::string, std::string>(std_map_string.begin(),
																								(std_map_string.end()--));
	printer(std_map_string_copy, ft_map_string_copy);
	std::cout << std::endl;
}

void construct_copy() {
	std::cout << "construct copy int int" << std::endl;
	ft::map<int, int> ft_map = get_map_int_int<ft::map<int, int>>();
	std::map<int, int> std_map = get_map_int_int<std::map<int, int>>();

	ft::map<int, int> ft_map_copy = ft::map<int, int>(ft_map);
	std::map<int, int> std_map_copy = std::map<int, int>(std_map);
	printer(std_map_copy, ft_map_copy);
	std::cout << std::endl;

	std::cout << "construct copy string string" << std::endl;
	ft::map<std::string, std::string> ft_map_string = get_map_string_string<ft::map<std::string, std::string>>();
	std::map<std::string, std::string> std_map_string = get_map_string_string<std::map<std::string, std::string>>();

	ft::map<std::string, std::string> ft_map_string_copy = ft::map<std::string, std::string>(ft_map_string);
	std::map<std::string, std::string> std_map_string_copy = std::map<std::string, std::string>(std_map_string);
	printer(std_map_string_copy, ft_map_string_copy);
	std::cout << std::endl;
}

void operator_assign() {
	std::cout << "construct assign int int" << std::endl;
	ft::map<int, int> ft_map = get_map_int_int<ft::map<int, int>>();
	std::map<int, int> std_map = get_map_int_int<std::map<int, int>>();


	ft::map<int, int> ft_map_constructor = get_map_int_int_mini<ft::map<int, int>>();
	std::map<int, int> std_map_constructor = get_map_int_int_mini<std::map<int, int>>();

	ft_map = ft_map_constructor;
	std_map = std_map_constructor;
	printer(std_map, ft_map);
	std::cout << std::endl;

	std::cout << "construct assign string string" << std::endl;
	ft::map<std::string, std::string> ft_map_string = get_map_string_string<ft::map<std::string, std::string>>();
	std::map<std::string, std::string> std_map_string = get_map_string_string<std::map<std::string, std::string>>();

	ft::map<std::string, std::string> ft_map_string_construct = get_map_string_string_mini<ft::map<std::string, std::string>>();
	std::map<std::string, std::string> std_map_string_construct = get_map_string_string_mini<std::map<std::string, std::string>>();

	ft_map_string_construct = ft_map_string;
	std_map_string_construct = std_map_string;
	printer(std_map_string_construct, ft_map_string_construct);
	std::cout << std::endl;
}

void test_size() {
	std::cout<<"test size()"<<std::endl;
	ft::map<int, int> ft_map;
	std::map<int, int> std_map;

	assert(ft_map.size() == std_map.size());

	ft_map = get_map_int_int<ft::map<int, int>>();
	std_map = get_map_int_int<std::map<int, int>>();

	assert(ft_map.size() == std_map.size());

	ft_map = get_map_int_int_mini<ft::map<int, int>>();
	std_map = get_map_int_int_mini<std::map<int, int>>();

	assert(ft_map.size() == std_map.size());
	std::cout<<"SUCCESS"<<std::endl;
}


void test_empty() {
	std::cout<<"test empty()"<<std::endl;
	ft::map<int, int> ft_map;
	std::map<int, int> std_map;

	assert(ft_map.empty() == std_map.empty());

	ft_map = get_map_int_int<ft::map<int, int>>();
	std_map = get_map_int_int<std::map<int, int>>();

	assert(ft_map.empty() == std_map.empty());

	ft_map.clear();
	std_map.clear();

	assert(ft_map.empty() == std_map.empty());

	ft_map = get_map_int_int_mini<ft::map<int, int>>();
	std_map = get_map_int_int_mini<std::map<int, int>>();

	assert(ft_map.empty() == std_map.empty());

	ft_map.clear();
	std_map.clear();

	assert(ft_map.empty() == std_map.empty());
	std::cout<<"SUCCESS"<<std::endl;
}

void test_max_size() {
//	ft::map<int, int> ft_map;
//	std::map<int, int> std_map;
//	std::cout<<"max_size std::map = "<<std_map.max_size()<<std::endl;
//	std::cout<<"max_size ft::map = "<<ft_map.max_size()<<std::endl;
//
//	ft::map<std::string, std::string> ft_map_string;
//	std::map<std::string, std::string> std_map_string;
//	std::cout<<"max_size std::map = "<<std_map_string.max_size()<<std::endl;
//	std::cout<<"max_size ft::map = "<<ft_map_string.max_size()<<std::endl;
}

int main() {
	insert_test();
	construct_first_last();
	construct_copy();
	operator_assign();
	test_size();
	test_empty();
	test_max_size();

//    std::map<std::string, std::string> std_map;
//    ft::map<int, int> ft_map = get_map_int_int();
//    std::pair<std::string, std::string> a1("a1", "111");
//    std::pair<std::string, std::string> a2("a2", "222");
//    std::pair<std::string, std::string> a3("a2", "333");
//
//    ft::map<int, int>::iterator i;
//    i = ft_map.find(3);
//    i = ft_map.find(4);
//    i = ft_map.find(2);
//
//    for (int j = 10; j > 0; --j) {
//        ft_map.erase(j);
//    }
//
//    ft_map = get_map_int_int();
//    for (int j = 4; j < 8; ++j) {
//        if (ft_map.count(1) == 1) {
//            std::cout << "true"<<std::endl;
//        } else {
//            std::cout << "false"<<std::endl;
//        }
//    }
//    if (ft_map.count(12) == 0)
//        std::cout << "true"<<std::endl;
//    return 0;
}
