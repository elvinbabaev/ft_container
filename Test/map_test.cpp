
#include <iostream>
#include <map>
#include "map.hpp"

int main() {
    std::map<std::string, std::string> std_map;
    ft::map<int, int> ft_map;
    std::pair<std::string, std::string> a1("a1", "111");
    std::pair<std::string, std::string> a2("a2", "222");
    std::pair<std::string, std::string> a3("a2", "333");
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
    std::pair<int, int> b11(11, 111111);


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

    ft::map<int, int>::iterator i;
    i = ft_map.find(3);
    i = ft_map.find(4);
    i = ft_map.find(2);


    for (int j = 10; j > 0; --j) {
        ft_map.erase(j);
    }
    return 0;
}