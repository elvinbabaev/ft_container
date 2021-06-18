
#include <iostream>
#include <map>
#include "map.hpp"
#include <vector>

std::vector<std::pair<std::string, std::string>> g_vec_str;
std::vector<std::pair<int, int>> g_vec_int;

void test_empty();

void init_vector() {
	for (int i = 1; i < 20; ++i) {
		g_vec_int.push_back(std::pair<int, int>(i, i * 10 + i));
	}
}

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

template<class T>
void check_assign(std::map<T, T> std_map, ft::map<T, T> ft_map) {
	typename std::map<T, T>::iterator std_iterator = std_map.begin();
	typename ft::map<T, T>::iterator ft_iterator = ft_map.begin();
	while (std_iterator != std_map.end() && ft_iterator != ft_map.end()) {
		assert(std_iterator->first == ft_iterator->first);
		assert(std_iterator->second == ft_iterator->second);
		std_iterator++;
		ft_iterator++;
		if ((std_iterator == std_map.end() && ft_iterator != ft_map.end())
		    || (std_iterator != std_map.end() && ft_iterator == ft_map.end())) {
			assert(false);
		}
	}
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
	{
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
	{

	}
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

	std::map<int, int> std_map_copy_vector(g_vec_int.begin(), (g_vec_int.end()--));
	ft::map<int, int> ft_map_copy_vector(g_vec_int.begin(), (g_vec_int.end()--));
	printer(std_map_copy_vector, ft_map_copy_vector);
	assert(std_map.size() == ft_map.size());
	assert(std_map_copy.size() == ft_map_copy.size());
	assert(std_map_string.size() == ft_map_string.size());
	assert(std_map_string_copy.size() == ft_map_string_copy.size());
	assert(std_map_copy_vector.size() == ft_map_copy_vector.size());
	check_assign(std_map, ft_map);
	check_assign(std_map_copy, ft_map_copy);
	check_assign(std_map_string, ft_map_string);
	check_assign(std_map_string_copy, ft_map_string_copy);
	check_assign(std_map_copy_vector, ft_map_copy_vector);
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
	assert(std_map.size() == ft_map.size());
	assert(std_map_copy.size() == ft_map_copy.size());
	assert(std_map_string.size() == ft_map_string.size());
	assert(std_map_string_copy.size() == ft_map_string_copy.size());
	check_assign(std_map, ft_map);
	check_assign(std_map_copy, ft_map_copy);
	check_assign(std_map_string, ft_map_string);
	check_assign(std_map_string_copy, ft_map_string_copy);
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

	assert(std_map.size() == ft_map.size());
	assert(std_map_string.size() == ft_map_string.size());
	assert(std_map_constructor.size() == ft_map_constructor.size());
	assert(std_map_string_construct.size() == ft_map_string_construct.size());
	check_assign(std_map, ft_map);
	check_assign(std_map_string, ft_map_string);
	check_assign(std_map_string_construct, ft_map_string_construct);
	check_assign(std_map_constructor, ft_map_constructor);
}

void test_size() {
	std::cout << "test size()" << std::endl;
	ft::map<int, int> ft_map;
	std::map<int, int> std_map;

	assert(ft_map.size() == std_map.size());

	ft_map = get_map_int_int<ft::map<int, int>>();
	std_map = get_map_int_int<std::map<int, int>>();

	assert(ft_map.size() == std_map.size());

	ft_map = get_map_int_int_mini<ft::map<int, int>>();
	std_map = get_map_int_int_mini<std::map<int, int>>();

	assert(ft_map.size() == std_map.size());
	std::cout << "SUCCESS" << std::endl;
}


void test_empty() {
	std::cout << "test empty()" << std::endl;
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
	std::cout << "SUCCESS" << std::endl;
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

void operator_read_write() {
	{
		ft::map<int, int> ft_map = get_map_int_int<ft::map<int, int>>();
		ft_map[15] = 1555;
		ft_map[12] = 123;
		ft_map[-1] = 432;
		ft_map[0] = -123;
		ft_map[2] = 12345;

		std::map<int, int> std_map = get_map_int_int<std::map<int, int>>();
		std_map[15] = 1555;
		std_map[12] = 123;
		std_map[-1] = 432;
		std_map[0] = -123;
		std_map[2] = 12345;

		std::cout << "operator read write int" << std::endl;
		printer(std_map, ft_map);
		assert(std_map.size() == ft_map.size());
		check_assign(std_map, ft_map);
		std::cout << std::endl;
	}
	{
		ft::map<std::string, std::string> ft_map = get_map_string_string<ft::map<std::string, std::string>>();
		ft_map["15"] = "1555";
		ft_map["12"] = "123";
		ft_map["-1"] = "432";
		ft_map["0"] = "-123";
		ft_map["2"] = "1234";

		std::map<std::string, std::string> std_map = get_map_string_string<std::map<std::string, std::string>>();
		std_map["15"] = "1555";
		std_map["12"] = "123";
		std_map["-1"] = "432";
		std_map["0"] = "-123";
		std_map["2"] = "1234";

		std::cout << "operator read write string" << std::endl;
		printer(std_map, ft_map);
		assert(std_map.size() == ft_map.size());
		check_assign(std_map, ft_map);
		std::cout << std::endl;
	}
}

void construct_default() {
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;
	assert(std_map.size() == ft_map.size());

	std_map = get_map_int_int<std::map<int, int>>();
	ft_map = get_map_int_int<ft::map<int, int>>();
	assert(std_map.size() == ft_map.size());
	check_assign(std_map, ft_map);
	std::cout << "construct default" << std::endl;
	printer(std_map, ft_map);
}

void begin_end_rbegin_rend() {
	std::map<int, int> std_map = get_map_int_int<std::map<int, int>>();
	ft::map<int, int> ft_map = get_map_int_int<ft::map<int, int>>();

	std::cout << "test begin end rbegin rend" << std::endl;

	for (std::map<int, int>::iterator std_iterator = std_map.begin(); std_iterator != std_map.end(); std_iterator++) {
		std::cout << "{ " << std_iterator->first << " " << std_iterator->second << " } ";
	}
	std::cout << std::endl;
	for (ft::map<int, int>::iterator ft_iterator = ft_map.begin(); ft_iterator != ft_map.end(); ft_iterator++) {
		std::cout << "{ " << ft_iterator->first << " " << ft_iterator->second << " } ";
	}
	std::cout << std::endl;
	for (std::map<int, int>::reverse_iterator std_reverse_iterator = std_map.rbegin();
	     std_reverse_iterator != std_map.rend(); std_reverse_iterator++) {
		std::cout << "{ " << std_reverse_iterator->first << " " << std_reverse_iterator->second << " } ";
	}
	std::cout << std::endl;
	for (ft::map<int, int>::reverse_iterator ft_reverse_iterator = ft_map.rbegin();
	     ft_reverse_iterator != ft_map.rend(); ft_reverse_iterator++) {
		std::cout << "{ " << ft_reverse_iterator->first << " " << ft_reverse_iterator->second << " } ";
	}
	std::cout << std::endl;

	std::map<int, int>::const_iterator const_std_it = std_map.begin();
	ft::map<int, int>::const_iterator const_ft_it = ft_map.begin();
	std::map<int, int>::const_iterator const_e_std_it = std_map.end();
	ft::map<int, int>::const_iterator const_e_ft_it = ft_map.end();
	std::map<int, int>::const_reverse_iterator rev_const_std_it = std_map.rbegin();
	ft::map<int, int>::const_reverse_iterator rev_const_ft_it = ft_map.rbegin();
	std::map<int, int>::const_reverse_iterator rev_const_e_std_it = std_map.rend();
	ft::map<int, int>::const_reverse_iterator rev_const_e_ft_it = ft_map.rend();

	for (; const_std_it != const_e_std_it; const_std_it++) {
		std::cout << " { " << const_std_it->first << " " << const_std_it->second << " } ";
	}
	std::cout << std::endl;

	for (; const_ft_it != const_e_ft_it; const_ft_it++) {
		std::cout << " { " << const_ft_it->first << " " << const_ft_it->second << " } ";
	}
	std::cout << std::endl;

	for (; rev_const_std_it != rev_const_e_std_it; rev_const_std_it++) {
		std::cout << " { " << rev_const_std_it->first << " " << rev_const_std_it->second << " } ";
	}
	std::cout << std::endl;

	for (; rev_const_ft_it != rev_const_e_ft_it; rev_const_ft_it++) {
		std::cout << " { " << rev_const_ft_it->first << " " << rev_const_ft_it->second << " } ";
	}
	std::cout << std::endl;
}

int main() {
	init_vector();

	// construct
	construct_first_last();
	construct_copy();
	construct_default();

	// operator=
	operator_assign();

	// begin const_begin rend const_rend rbegin const_rbegin rend const_rend
	begin_end_rbegin_rend();

	// empty()
	test_empty();

	// size()
	test_size();

	//TODO: max_size
//	test_max_size();

	// operator[]
//	operator_read_write();

	// insert()
	insert_test();
//	test_max_size();
	return 0;
}
