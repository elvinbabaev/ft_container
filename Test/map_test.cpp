
#include <iostream>
#include <map>
#include "map.hpp"
#include <vector>

std::vector<std::pair<std::string, std::string>> g_vec_str;
std::vector<std::pair<int, int>> g_vec_int;

void init_global() {
    for (int i = 0; i < 50; ++i) {
        g_vec_int.push_back(std::pair<int, int>(i, i * 10));
        g_vec_str.push_back(std::pair<std::string, std::string>(i + "", i + " value"));
    }
}

ft::map<int, int> get_map_int_int() {
    ft::map<int, int> ft_map;
    std::pair<int, int> b1(1, 111);
    std::pair<int, int> b2(2, 222);
    std::pair<int, int> b3(3, 333);
    std::pair<int, int> b33(3, 345);
    std::pair<int, int> b4(4, 444);
    std::pair<int, int> b5(5, 555);
    std::pair<int, int> b6(6, 666);
    std::pair<int, int> b7(7, 777);
    std::pair<int, int> b8(8, 888);
    std::pair<int, int> b9(9, 999);
    std::pair<int, int> b10(10, 101010);


    std::pair<ft::map<int, int>::iterator, bool> a;

    a = ft_map.insert(b5);
    a = ft_map.insert(b3);
    a = ft_map.insert(b8);
    a = ft_map.insert(b2);
    a = ft_map.insert(b4);
    a = ft_map.insert(b7);
    a = ft_map.insert(b10);
    a = ft_map.insert(b1);
    a = ft_map.insert(b6);
    a = ft_map.insert(b9);
    return ft_map;
}

ft::map<std::string, std::string> test_insert() {
    ft::map<std::string, std::string> ft_map;

}

int main() {
    std::map<std::string, std::string> std_map;
    ft::map<int, int> ft_map = get_map_int_int();
    std::pair<std::string, std::string> a1("a1", "111");
    std::pair<std::string, std::string> a2("a2", "222");
    std::pair<std::string, std::string> a3("a2", "333");

    ft::map<int, int>::iterator i;
    i = ft_map.find(3);
    i = ft_map.find(4);
    i = ft_map.find(2);

    for (int j = 10; j > 0; --j) {
        ft_map.erase(j);
    }

    ft_map = get_map_int_int();
    for (int j = 4; j < 8; ++j) {
        if (ft_map.count(1) == 1) {
            std::cout << "true"<<std::endl;
        } else {
            std::cout << "false"<<std::endl;
        }
    }
    if (ft_map.count(12) == 0)
        std::cout << "true"<<std::endl;
    return 0;
}