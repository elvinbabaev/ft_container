#include <iostream>
#include <vector>
#include <list>
#include "../Container/vector.hpp"
//#include "../List/list.hpp"
# define RESET   "\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define BOLDBLACK   "\033[1m\033[30m"
# define BOLDRED     "\033[1m\033[31m"
# define BOLDGREEN   "\033[1m\033[32m"
# define BOLDYELLOW  "\033[1m\033[33m"
# define BOLDBLUE    "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN    "\033[1m\033[36m"
# define BOLDWHITE   "\033[1m\033[37m"
typedef std::vector<std::string>::iterator SitStr;
typedef ft::vector<std::string>::iterator itStr;
typedef ft::vector<int>::iterator itInt;
typedef std::vector<int>::iterator SitInt;
class Test{
private:
    char *str;
    int _n;
    Test(){
        std::cout << "constructor"<<std::endl;
    };
public:
    virtual ~Test() {
        delete[] str;
        std::cout << "destructor"<<std::endl;
    }
    Test(int n)
    {
        this->_n = n;
        std::cout << "constructor2"<<std::endl;
        this->str = new char [n];
        for (int i = 0; i != n; ++i) {
            this->str[i] = 'a' + i;
        }
    }
    Test(const char *val) {
        this->str = new char [10];
        for (int i = 0;val[i]; ++i) {
            this->str[i] = val[i];
        }
        this->_n = 10;
        std::cout << "constructor2"<<std::endl;
    }
    Test (const Test &other)
    {
        std::cout << "copy constructor"<<std::endl;
        this->str =  new char[10];
        int i = 0;
        for (; i < other._n; ++i) {
            this->str[i] = other.str[i];
        }
        this->_n =other._n;
    }
    Test &operator = (const Test &other)
    {

        if (this == &other)
            return *this;
        delete[] this->str;
        this->str =  new char[10];
        int i = 0;
        for (; i < other._n; ++i) {
            this->str[i] = other.str[i];
        }
        this->str[i] = other.str[i];
        this->_n =other._n;
        return *this;
    }
    char *getStr() const {
        return str;
    }
    void change(int i, char c)
    {
        this->str[i] = c;
    }
};
//template<typename T>
//struct t_node
//{
//    T *data;
//    std::allocator<T>alloc;
//    t_node()
//    {
//        data = alloc.allocate(1);
//    }
//    t_node(const T &val){}
//};
void construtor(){
    std::cout << BLUE << "        CONSTRUCTOR     " << RESET <<std::endl;
    std::cout << MAGENTA << "default: std::vector<int>s_v_def\n";
    std::cout <<  CYAN << "default: ft::vector<int>f_v_def\n";
    std::vector<int>s_v_def;
    ft::vector<int>f_v_def;
    std::cout << MAGENTA << "fill: std::vector<int>s_v_fill(10, 5)\n" << RESET;
    std::cout <<  CYAN << "fill: ft::vector<int>f_v_fill(10, 5)\n" << RESET;
    std::vector<int>s_v_fill(10, 5);
    ft::vector<int>f_v_fill(10, 5);
    std::cout << RED<<"s_v_fill.size() = "<<RESET<< s_v_fill.size()<< RED<<"   s_v_fill.capacity() = "<<RESET << s_v_fill.capacity()<<std::endl;
    std::cout << GREEN<<"f_v_fill.size() = "<<RESET<< f_v_fill.size()<< GREEN<<"   f_v_fill.capacity() = "<<RESET << f_v_fill.capacity()<<std::endl;
    std::cout << RED << "s_v_fill: value = "<<RESET <<" ";
    for (SitInt it = s_v_fill.begin(); it != s_v_fill.end(); ++it){
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "s_v_fill: value = "<<RESET <<" ";
    for (itInt it = f_v_fill.begin(); it != f_v_fill.end(); ++it){
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << MAGENTA << "range: std::vector<int>s_v_range(s_v_fill.begin(), s_v_fill.end())\n" << RESET;
    std::cout << CYAN << "range: ft::vector<int>f_v_range(f_v_fill.begin(), f_v_fill.end())\n" << RESET;
    std::vector<int>s_v_range(s_v_fill.begin(), s_v_fill.end());
    ft::vector<int>::iterator::iterator_category *ptr =nullptr;
    ft::vector<int> f_v_range(f_v_fill.begin(), f_v_fill.end());
    /////////!!!!!!            ft::vector<int> f_v_range(f_v_fill.begin(), f_v_fill.end(), ptr);  !!!!!!!

    std::cout << RED<<"s_v_range.size() = "<<RESET << s_v_range.size()<<std::endl;
    std::cout << GREEN<<"f_v_range.size() = "<<RESET << f_v_range.size()<<std::endl;
    std::cout << RED << "s_v_range: value = "<<RESET <<" ";
    for (SitInt it = s_v_fill.begin(); it != s_v_fill.end(); ++it){
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << RED << "f_v_range: value = "<<RESET <<" ";
    for (itInt it = f_v_fill.begin(); it != f_v_fill.end(); ++it){
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << MAGENTA << "copy: std::vector<int>s_v_copy(s_v_fill)\n" << RESET;
    std::cout << CYAN << "copy: ft::vector<int>f_v_copy(f_v_fill)\n" << RESET;
    std::vector<int>s_v_copy(s_v_fill);
    ft::vector<int>f_v_copy(f_v_fill);
    std::cout << RED<<"s_v_range.size() = "<<RESET << s_v_range.size()<<std::endl;
    std::cout << GREEN<<"f_v_range.size() = "<<RESET << f_v_range.size()<<std::endl;
    std::cout << RED << "s_v_copy: value = "<<RESET <<" ";
    for (SitInt it = s_v_copy.begin(); it != s_v_copy.end(); ++it){
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "f_v_copy: value = "<<RESET <<" ";
    for (itInt it = f_v_copy.begin(); it != f_v_copy.end(); ++it){
        std::cout << *it <<" ";
    }
    std::cout <<std::endl;
}
void assign_operator(){
    std::cout << BLUE << "    ASSIGN OPERATOR " <<RESET<<std::endl;
    std::vector<std::string>s_v_tmp(2, "asf");
    s_v_tmp.push_back("qwe");
    s_v_tmp.push_back("213");
    std::vector<std::string>s_v_assign = s_v_tmp;
    ft::vector<std::string>f_v_tmp(2, "asf");
    f_v_tmp.push_back("qwe");
    f_v_tmp.push_back("213");
    ft::vector<std::string>f_v_assign = f_v_tmp;
    std::cout << MAGENTA <<"std::vector<std::string>s_v_tmp(2, \"asf\")" << RESET <<std::endl;
    std::cout << MAGENTA << "s_v_tmp.push_back(\"qwe\");"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_v_tmp.push_back(\"213\");"<<RESET<<std::endl;
    std::cout << MAGENTA <<"std::vector<std::string>s_v_assign = s_v_tmp" << RESET <<std::endl;
    std::cout << CYAN << "ft::vector<std::string>f_v_tmp(2, \"asf\");" << RESET<<std::endl;
    std::cout << CYAN << "f_v_tmp.push_back(\"qwe\");"<<RESET<<std::endl;
    std::cout << CYAN << "f_v_tmp.push_back(\"213\");"<<RESET<<std::endl;
    std::cout << CYAN << "ft::vector<std::string>f_v_assign = f_v_tmp;" << RESET<<std::endl;
    std::cout << RED << "s_v_tmp: value = "<<RESET;
    for (SitStr it = s_v_tmp.begin(); it != s_v_tmp.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << GREEN << "f_v_tmp: value = "<<RESET;
    for (itStr it = f_v_tmp.begin(); it != f_v_tmp.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << RED << "s_v_assign: value = "<<RESET;
    for (SitStr it = s_v_assign.begin(); it != s_v_assign.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << GREEN << "f_v_assign: value = "<<RESET;
    for (itStr it = f_v_assign.begin(); it != f_v_assign.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void iterators()
{
    std::cout << BLUE << "         ITERATORS" <<RESET <<std::endl;
    std::vector<int>s_v;
    ft::vector<int>f_v;
    std::cout << MAGENTA << "std::vector<int>s_v"<<RESET<<std::endl;
    std::cout << CYAN << "ft::vector<int>f_v"<<RESET<<std::endl;
    for (int i = 0; i < 10; ++i)
    {
        int r = rand() % 60;
        s_v.push_back(r);
        f_v.push_back(r);
    }
    SitInt s_it = s_v.begin();
    itInt f_it = f_v.begin();
    std::cout << GREEN << "      SIMPLE ITERATOR"<<RESET<<std::endl;
    std::cout << MAGENTA << "std::vector<int>::iterator s_it = s_v.begin()"<<RESET<<std::endl;
    std::cout << CYAN << "ft::vector<int>::iterator f_it = f_v.begin()"<<RESET<<std::endl;
    std::cout << GREEN << "     PREFIX INCREMENT"<<RESET<<std::endl;
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    for (; s_it != s_v.end(); ++s_it)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    for (; f_it != f_v.end(); ++f_it)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "     PREFIX DECREMENT"<<RESET<<std::endl;
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    --s_it;
    for (; s_it != --s_v.begin(); --s_it)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    --f_it;
    for (; f_it != --f_v.begin(); --f_it)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "     POSTFIX INCREMENT"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_it = s_v.begin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.begin()"<<RESET<<std::endl;
    s_it = s_v.begin();
    f_it = f_v.begin();
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    for (; s_it != s_v.end(); s_it++)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    for (; f_it != f_v.end(); f_it++)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "     POSTFIX DECREMENT"<<RESET<<std::endl;
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    s_it--;
    for (; s_it != --s_v.begin(); s_it--)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    f_it--;
    for (; f_it != --f_v.begin(); f_it--)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "     OPERATORS  DEREFERENCEABLE"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_it = s_v.begin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.begin()"<<RESET<<std::endl;
    s_it = s_v.begin();
    f_it = f_v.begin();
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    *s_it = 999;
    *f_it = 999;
    std::cout << MAGENTA << "*s_it = 999"<<RESET<<std::endl;
    std::cout << CYAN << "*f_it = 999" <<RESET<<std::endl;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    *s_it++;
    *f_it++;
    std::cout << MAGENTA << "*s_it++"<<RESET<<std::endl;
    std::cout << CYAN << "*f_it++" <<RESET<<std::endl;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    *s_it--;
    *f_it--;
    std::cout << MAGENTA << "*s_it--"<<RESET<<std::endl;
    std::cout << CYAN << "*f_it--" <<RESET<<std::endl;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    std::cout << MAGENTA << "s_it[4] = "<<RESET << s_it[4]<<std::endl;
    std::cout << CYAN << "f_it[4] = " <<RESET<< f_it[4]<<std::endl;
    std::cout << MAGENTA << "s_it[4] = 65"<<RESET<<std::endl;
    std::cout << CYAN << "f_it[4] = 65" <<RESET<<std::endl;
    s_it[4] = 65;
    f_it[4] = 65;
    std::cout << MAGENTA << "s_it[4] = "<<RESET << s_it[4]<<std::endl;
    std::cout << CYAN << "f_it[4] = " <<RESET<< f_it[4]<<std::endl;
    std::cout << GREEN << "     ARITHMETIC OPERATORS"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_it = s_v.begin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.begin()"<<RESET<<std::endl;
    s_it = s_it + 3;
    f_it = f_it + 3;
    std::cout << MAGENTA << "s_it = s_it + 3"<<RESET <<std::endl;
    std::cout << CYAN << "f_it = f_it + 3" <<RESET<<std::endl;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    std::cout << MAGENTA << "s_it = s_it - 1"<<RESET <<std::endl;
    std::cout << CYAN << "f_it = f_it - 1" <<RESET<<std::endl;
    s_it = s_it - 1;
    f_it = f_it - 1;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    std::cout << MAGENTA << "s_v.end() - s_v.begin() = "<<RESET << s_v.end() - s_v.begin()<<std::endl;
    std::cout << CYAN << "f_end() - f_v.begin() = " <<RESET<< s_v.end() - s_v.begin()<<std::endl;
    std::cout << GREEN << "     RELATIONAL OPERATORS"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_v.end() != s_v.begin()"<< RESET <<std::endl;
    if (s_v.end() != s_v.begin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.end() != f_v.begin()"<< RESET <<std::endl;
    if (f_v.end() != f_v.begin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.begin() == s_v.begin()"<< RESET <<std::endl;
    if (s_v.begin() == s_v.begin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.begin() == f_v.begin()"<< RESET <<std::endl;
    if (f_v.begin() == f_v.begin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.begin() <= s_v.begin()"<< RESET <<std::endl;
    if (s_v.begin() <= s_v.begin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.begin() <= f_v.begin()"<< RESET <<std::endl;
    if (f_v.begin() <= f_v.begin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.begin() < s_v.begin()"<< RESET <<std::endl;
    if (s_v.begin() < s_v.begin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.begin() < f_v.begin()"<< RESET <<std::endl;
    if (f_v.begin() < f_v.begin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.begin() > s_v.end()"<< RESET <<std::endl;
    if (s_v.begin() > s_v.end())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.begin() > f_v.end()"<< RESET <<std::endl;
    if (f_v.begin() > f_v.end())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.end() >= s_v.end()"<< RESET <<std::endl;
    if (s_v.end() >= s_v.end())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.end() >= f_v.end()"<< RESET <<std::endl;
    if (f_v.end() >= f_v.end())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << GREEN << "     COMPOUND ASSIGNMENT OPERATIONS"<<RESET<<std::endl;

    std::cout << MAGENTA << "s_it = s_v.begin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.begin()"<<RESET<<std::endl;
    s_it = s_v.begin();
    f_it = f_v.begin();
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    for (; s_it != s_v.end(); ++s_it)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    for (; f_it != f_v.end(); ++f_it)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    s_it = s_v.begin();
    f_it = f_v.begin();
    std::cout << MAGENTA << "s_it = s_v.begin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.begin()"<<RESET<<std::endl;
    std::cout << MAGENTA<< "s_it += 5 = "<<RESET<<*(s_it += 5)<<std::endl;
    std::cout << MAGENTA<< "f_it += 5 = "<<RESET<<*(f_it += 5)<<std::endl;
    std::cout << MAGENTA<< "s_it -= 3 = "<<RESET<<*(s_it -= 3)<<std::endl;
    std::cout << MAGENTA<< "f_it -= 3 = "<<RESET<<*(f_it -= 3)<<std::endl;

}
void revese_iterators(){
    std::cout << GREEN << "      REVERSE ITERATOR"<<RESET<<std::endl;
    std::vector<int>s_v;
    ft::vector<int>f_v;
    std::cout << MAGENTA << "std::vector<int>s_v"<<RESET<<std::endl;
    std::cout << CYAN << "ft::vector<int>f_v"<<RESET<<std::endl;
    for (int i = 0; i < 10; ++i)
    {
        int r = rand() % 60;
        s_v.push_back(r);
        f_v.push_back(r);
    }
    std::cout << MAGENTA << "std::vector<int>::iterator s_it = s_v.rbegin()" << RESET << std::endl;
    std::cout << CYAN << "ft::vector<int>::iterator f_it = f_v.rbegin()" << RESET << std::endl;
    std::vector<int>::reverse_iterator s_it = s_v.rbegin();
    ft::vector<int>::reverse_iterator f_it = f_v.rbegin();
    std::cout << GREEN << "     PREFIX INCREMENT"<<RESET<<std::endl;
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    for (; s_it != s_v.rend(); ++s_it)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    for (; f_it != f_v.rend(); ++f_it)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "     PREFIX DECREMENT"<<RESET<<std::endl;
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    --s_it;
    for (; s_it != --s_v.rbegin(); --s_it)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    --f_it;
    for (; f_it != --f_v.rbegin(); --f_it)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "     POSTFIX INCREMENT"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_it = s_v.rbegin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.rbegin()"<<RESET<<std::endl;
    s_it = s_v.rbegin();
    f_it = f_v.rbegin();
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    for (; s_it != s_v.rend(); s_it++)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    for (; f_it != f_v.rend(); f_it++)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "     POSTFIX DECREMENT"<<RESET<<std::endl;
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    s_it--;
    for (; s_it != --s_v.rbegin(); s_it--)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    f_it--;
    for (; f_it != --f_v.rbegin(); f_it--)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    std::cout << GREEN << "     OPERATORS  DEREFERENCEABLE"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_it = s_v.rbegin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.rbegin()"<<RESET<<std::endl;
    s_it = s_v.rbegin();
    f_it = f_v.rbegin();
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    *s_it = 999;
    *f_it = 999;
    std::cout << MAGENTA << "*s_it = 999"<<RESET<<std::endl;
    std::cout << CYAN << "*f_it = 999" <<RESET<<std::endl;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    *s_it++;
    *f_it++;
    std::cout << MAGENTA << "*s_it++"<<RESET<<std::endl;
    std::cout << CYAN << "*f_it++" <<RESET<<std::endl;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    *s_it--;
    *f_it--;
    std::cout << MAGENTA << "*s_it--"<<RESET<<std::endl;
    std::cout << CYAN << "*f_it--" <<RESET<<std::endl;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    std::cout << MAGENTA << "s_it[4] = "<<RESET << s_it[4]<<std::endl;
    std::cout << CYAN << "f_it[4] = " <<RESET<< f_it[4]<<std::endl;
    std::cout << MAGENTA << "s_it[4] = 65"<<RESET<<std::endl;
    std::cout << CYAN << "f_it[4] = 65" <<RESET<<std::endl;
    s_it[4] = 65;
    f_it[4] = 65;
    std::cout << MAGENTA << "s_it[4] = "<<RESET << s_it[4]<<std::endl;
    std::cout << CYAN << "f_it[4] = " <<RESET<< f_it[4]<<std::endl;
    std::cout << GREEN << "     ARITHMETIC OPERATORS"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_it = s_v.rbegin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.rbegin()"<<RESET<<std::endl;
    s_it = s_v.rbegin();
    f_it = f_v.rbegin();
    s_it = s_it + 3;
    f_it = f_it + 3;
    std::cout << MAGENTA << "s_it = s_it + 3"<<RESET <<std::endl;
    std::cout << CYAN << "f_it = f_it + 3" <<RESET<<std::endl;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    std::cout << MAGENTA << "s_it = s_it - 1"<<RESET <<std::endl;
    std::cout << CYAN << "f_it = f_it - 1" <<RESET<<std::endl;
    s_it = s_it - 1;
    f_it = f_it - 1;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it<<std::endl;
    std::cout << CYAN << "*f_it = " <<RESET<< *f_it<<std::endl;
    std::cout << MAGENTA << "s_v.rend() - s_v.rbegin() = "<<RESET << s_v.rend() - s_v.rbegin()<<std::endl;
    std::cout << CYAN << "f_rend() - f_v.rbegin() = " <<RESET<< s_v.rend() - s_v.rbegin()<<std::endl;
    std::cout << GREEN << "     RELATIONAL OPERATORS"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_v.rend() != s_v.rbegin()"<< RESET <<std::endl;
    if (s_v.rend() != s_v.rbegin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.rend() != f_v.rbegin()"<< RESET <<std::endl;
    if (f_v.rend() != f_v.rbegin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.rbegin() == s_v.rbegin()"<< RESET <<std::endl;
    if (s_v.rbegin() == s_v.rbegin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.rbegin() == f_v.rbegin()"<< RESET <<std::endl;
    if (f_v.rbegin() == f_v.rbegin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.rbegin() <= s_v.rbegin()"<< RESET <<std::endl;
    if (s_v.rbegin() <= s_v.rbegin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.rbegin() <= f_v.rbegin()"<< RESET <<std::endl;
    if (f_v.rbegin() <= f_v.rbegin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.rbegin() < s_v.rbegin()"<< RESET <<std::endl;
    if (s_v.rbegin() < s_v.rbegin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.rbegin() < f_v.rbegin()"<< RESET <<std::endl;
    if (f_v.rbegin() < f_v.rbegin())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.rbegin() > s_v.rend()"<< RESET <<std::endl;
    if (s_v.rbegin() > s_v.rend())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.rbegin() > f_v.rend()"<< RESET <<std::endl;
    if (f_v.rbegin() > f_v.rend())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << MAGENTA << "s_v.rend() >= s_v.rend()"<< RESET <<std::endl;
    if (s_v.rend() >= s_v.rend())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << CYAN << "f_v.rend() >= f_v.rend()"<< RESET <<std::endl;
    if (f_v.rend() >= f_v.rend())
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << GREEN << "     COMPOUND ASSIGNMENT OPERATIONS"<<RESET<<std::endl;

    std::cout << MAGENTA << "s_it = s_v.rbegin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.rbegin()"<<RESET<<std::endl;
    s_it = s_v.rbegin();
    f_it = f_v.rbegin();
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    for (; s_it != s_v.rend(); ++s_it)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    for (; f_it != f_v.rend(); ++f_it)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    s_it = s_v.rbegin();
    f_it = f_v.rbegin();
    std::cout << MAGENTA << "s_it = s_v.rbegin()"<<RESET<<std::endl;
    std::cout << CYAN << "f_it = f_v.rbegin()"<<RESET<<std::endl;
    std::cout << MAGENTA<< "s_it += 5 = "<<RESET<<*(s_it += 5)<<std::endl;
    std::cout << MAGENTA<< "f_it += 5 = "<<RESET<<*(f_it += 5)<<std::endl;
    std::cout << MAGENTA<< "s_it -= 3 = "<<RESET<<*(s_it -= 3)<<std::endl;
    std::cout << MAGENTA<< "f_it -= 3 = "<<RESET<<*(f_it -= 3)<<std::endl;
}
void const_iterator(){
    std::cout << GREEN << "      CONST ITERATOR"<<RESET<<std::endl;
    const std::vector<std::string>s_v(2, "abcd");
    const ft::vector<std::string>f_v(2, "abcd");
    std::vector<std::string>::const_iterator s_it = s_v.begin();
    ft::vector<std::string>::const_iterator f_it = f_v.begin();
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    for (; s_it != s_v.end(); ++s_it)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    for (; f_it != f_v.end(); ++f_it)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
//    f_it->assign("asfs");
//    s_it->assign("asfs");
//    ft::vector<std::strin
//    g>tm(2, "asd");
    std::vector<std::string>tm(2, "asd");
    tm.begin()->assign("sfds");
}
void capacity(){
    std::cout << BLUE << "      CAPACITY"<<RESET<<std::endl;
    std::vector<std::string>s_v(2, "abcd");
    ft::vector<std::string>f_v(2, "abcd");
    std::cout <<MAGENTA << "std::vector<std::string>s_v(2, \"abcd\")"<<RESET<<std::endl;
    std::cout <<CYAN << "ft::vector<std::string>f_v(2, \"abcd\")"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_v.size() = "<<RESET<<s_v.size()<<std::endl;
    std::cout << CYAN << "f_v.size() = "<<RESET<<f_v.size()<<std::endl;
    std::cout << MAGENTA << "s_v.max_size() = "<<RESET<<s_v.max_size()<<std::endl;
    std::cout << CYAN << "f_v.max_size() = "<<RESET<<f_v.max_size()<<std::endl;
    std::cout << MAGENTA << "s_v.capacity() = "<<RESET<<s_v.capacity()<<std::endl;
    std::cout << CYAN << "f_v.capacity() = "<<RESET<<f_v.capacity()<<std::endl;
    std::cout << MAGENTA << "s_v.empty()"<<RESET<<std::endl;
    if (s_v.empty())
        std::cout << "true"<<std::endl;
    else
        std::cout << "false"<<std::endl;
    std::cout << CYAN << "f_v.empty()"<<RESET<<std::endl;
    if (f_v.empty())
        std::cout << "true"<<std::endl;
    else
        std::cout << "false"<<std::endl;
    std::cout << MAGENTA<< "s_v.resize(10, \"sss\")"<<RESET<<std::endl;
    std::cout << CYAN<< "f_v.resize(10, \"sss\")"<<RESET<<std::endl;
    s_v.resize(10, "sss");
    f_v.resize(10, "sss");
    std::cout << MAGENTA<< "s_v.size() = "<<RESET<<s_v.size()<<std::endl;
    std::cout << CYAN<< "f_v.size() = "<<RESET<<f_v.size()<<std::endl;
    std::cout << MAGENTA << "s_v.capacity() = "<<RESET<<s_v.capacity()<<std::endl;
    std::cout << CYAN << "f_v.capacity() = "<<RESET<<f_v.capacity()<<std::endl;
    std::vector<std::string>::iterator s_it = s_v.begin();
    ft::vector<std::string>::iterator f_it = f_v.begin();
//    std::vector<std::string>::const_iterator s_it = s_v.begin();
//    ft::vector<std::string>::const_iterator f_it = f_v.begin();
    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    for (; s_it != s_v.end(); ++s_it)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    for (; f_it != f_v.end(); ++f_it)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    s_v.push_back("erte");
    f_v.push_back("erte");
    s_it = s_v.begin();
    f_it = f_v.begin();
    std::cout << MAGENTA<<"s_v.push_back(\"erte\")"<<RESET<<std::endl;
    std::cout << CYAN<<"f_v.push_back(\"erte\")"<<RESET<<std::endl;
    std::cout << MAGENTA<< "s_v.size() = "<<RESET<<s_v.size()<<std::endl;
    std::cout << CYAN<< "f_v.size() = "<<RESET<<f_v.size()<<std::endl;
    std::cout << MAGENTA << "s_v.capacity() = "<<RESET<<s_v.capacity()<<std::endl;
    std::cout << CYAN << "f_v.capacity() = "<<RESET<<f_v.capacity()<<std::endl;

    std::cout << MAGENTA << "vector s_v: value = " <<RESET;
    for (; s_it != s_v.end(); ++s_it)
    {
        std::cout << *s_it << " ";
    }
    std::cout <<std::endl;
    std::cout << CYAN << "vector f_v: value = " <<RESET;
    for (; f_it != f_v.end(); ++f_it)
    {
        std::cout << *f_it << " ";
    }
    std::cout <<std::endl;
    s_v.reserve(50);
    f_v.reserve(50);
    s_it = s_v.begin();
    f_it = f_v.begin();
    std::cout << MAGENTA<< "s_v.reserve(50)"<<RESET<<std::endl;
    std::cout << CYAN<< "f_v.reserve(50)"<<RESET<<std::endl;
    std::cout << MAGENTA<< "s_v.size() = "<<RESET<<s_v.size()<<std::endl;
    std::cout << CYAN<< "f_v.size() = "<<RESET<<f_v.size()<<std::endl;
    std::cout << MAGENTA << "s_v.capacity() = "<<RESET<<s_v.capacity()<<std::endl;
    std::cout << CYAN << "f_v.capacity() = "<<RESET<<f_v.capacity()<<std::endl;
}
void element_access(){
    std::cout << BLUE << "          ELEMENT ACCESS"<<RESET<<std::endl;
    std::cout <<MAGENTA <<"std::vector<int>s_v(10)"<<RESET <<std::endl;
    std::cout <<CYAN <<"ft:vector<int>f_v(10)"<<RESET <<std::endl;
    std::vector<int>s_v(10);
    ft::vector<int>f_v(10);
    for (int i = 0; i != 10; ++i)
    {
        int ran = rand() % 4654;
        s_v[i] = ran;
        f_v[i] = ran;
    }
    std::cout << GREEN << "         OPERATOR[]"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
    {
        std::cout << s_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << GREEN << "         AT"<<RESET<<std::endl;
    std::cout << MAGENTA << "s_v.at(i) = " <<RESET;
    for (std::vector<int>::size_type i = 0; i != s_v.size(); ++i)
    {
        std::cout << s_v.at(i)<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v.at(i) = " <<RESET;
    for (std::vector<int>::size_type i = 0; i != f_v.size(); ++i)
    {
        std::cout << f_v.at(i)<<" ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "s_v.at(-1)" <<RESET <<std::endl;
    try {
        s_v.at(-1);
    }catch(std::exception &err){
        std::cout << err.what()<<std::endl;
    }
    std::cout << CYAN << "f_v.at(-1)" <<RESET <<std::endl;
    try {
        f_v.at(-1);
    }catch(std::exception &err){
        std::cout << err.what()<<std::endl;
    }
    std::cout <<GREEN << "FRONT AND BACK"<<RESET <<std::endl;
    std::cout << MAGENTA << "s_v.front() "<<RESET;
    std::cout << s_v.front()<<std::endl;
    std::cout << CYAN << "f_v.front() "<<RESET;
    std::cout << f_v.front()<<std::endl;
    std::cout << MAGENTA << "s_v.back() "<<RESET;
    std::cout << s_v.back()<<std::endl;
    std::cout << CYAN << "f_v.back() "<<RESET;
    std::cout << f_v.back()<<std::endl;

}
void insert_single_element()
{
    std::cout << BLUE << "         SINGLE ELEMENT INSERT"<<RESET<<std::endl;
    std::cout <<MAGENTA <<"std::vector<int>s_v(10)"<<RESET <<std::endl;
    std::cout <<CYAN <<"ft:vector<int>f_v(10)"<<RESET <<std::endl;
    std::vector<int>s_v(10);
    ft::vector<int>f_v(10);
    for (int i = 0; i != 10; ++i)
    {
        int ran = rand() % 4654;
        s_v[i] = ran;
        f_v[i] = ran;
    }
    std::cout << MAGENTA << "s_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
    {
        std::cout << s_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "s_v.insert(s_v.begin(), 54)" << RESET<<std::endl;
    std::cout << CYAN  << "f_v.insert(f_v.begin(), 54)" << RESET<<std::endl;
    s_v.push_back(23);
    f_v.push_back(23);
    // SitInt s_it = s_v.begin();
    // itInt f_it =  f_v.begin();
    SitInt s_it =  s_v.insert(s_v.end(), 54);
    itInt f_it =  f_v.insert(f_v.end(), 54);
    std::cout << MAGENTA << "*s_it = "<<RESET;
    for (; s_it != s_v.end(); ++s_it)
    {
        std::cout << *s_it<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "*f_it = "<<RESET;
    for (; f_it != f_v.end(); ++f_it)
    {
        std::cout << *f_it<<" ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "s_v.size() = " << RESET<<s_v.size()<<std::endl;
    std::cout << CYAN  << "f_v.size() = " << RESET<<f_v.size()<<std::endl;
    std::cout << MAGENTA << "s_v.max_size() = " << RESET<<s_v.max_size()<<std::endl;
    std::cout << CYAN  << "f_v.max_size() = " << RESET<<f_v.max_size()<<std::endl;
    std::cout << MAGENTA << "s_v.capacity() = " << RESET<<s_v.capacity()<<std::endl;
    std::cout << CYAN  << "f_v.capacity() = " << RESET<<f_v.capacity()<<std::endl;
    std::cout << MAGENTA << "s_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
    {
        std::cout << s_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;

}
void insert_fill(){
    std::cout << BLUE << "         FILL INSERT"<<RESET<<std::endl;
    std::string tab("qwertyuiopasdfghjklzxcvbnm1234567890");
    std::cout <<MAGENTA <<"std::vector<std::string>s_v_fill"<<RESET <<std::endl;
    std::cout <<CYAN <<"ft:vector<std::string>f_v_fill"<<RESET <<std::endl;
    std::vector<std::string>s_v_fill;
    std::vector<std::string>s_v;
    ft::vector<std::string>f_v_fill;
    ft::vector<std::string>f_v;
    for (int i = 0; i != 10; ++i)
    {
        std::string s1;
        for (int k = 0; k != 10; ++k)
        {
            s1.push_back(tab[rand() % tab.length()]);
        }
        s_v.push_back(s1);
        f_v.push_back(s1);
    }
    std::cout << MAGENTA << "s_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
    {
        std::cout << s_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "s_v_fill.insert(s_v.begin(), 5, s_v.front())" << RESET<<std::endl;
    std::cout << CYAN  << "f_v_fill.insert(f_v.begin(), 5, f_v.front())" << RESET<<std::endl;
    s_v_fill.assign(10, "qwert");
    f_v_fill.assign(10, "qwert");
    s_v_fill.push_back("aaaa");
    f_v_fill.push_back("aaaa");
    s_v_fill.insert(s_v_fill.begin() + 5, 5, f_v.front());
    f_v_fill.insert(f_v_fill.begin() + 5, 5, f_v.front());
    std::cout << MAGENTA << "s_v_fill.size() = " << RESET<<s_v_fill.size()<<std::endl;
    std::cout << CYAN  << "f_v_fill.size() = " << RESET<<f_v_fill.size()<<std::endl;
    std::cout << MAGENTA << "s_v_fill.max_size() = " << RESET<<s_v_fill.max_size()<<std::endl;
    std::cout << CYAN  << "f_v_fill.max_size() = " << RESET<<f_v_fill.max_size()<<std::endl;
    std::cout << MAGENTA << "s_v_fill.capacity() = " << RESET<<s_v_fill.capacity()<<std::endl;
    std::cout << CYAN  << "f_v_fill.capacity() = " << RESET<<f_v_fill.capacity()<<std::endl;
    std::cout << MAGENTA << "s_v_fill[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v_fill.size(); ++i)
    {
        std::cout << s_v_fill[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v_fill[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v_fill.size(); ++i)
    {
        std::cout << f_v_fill[i]<<" ";
    }
    std::cout << std::endl;
}
void insert_range(){
    std::cout << BLUE << "         RANGE INSERT"<<RESET<<std::endl;
    std::string tab("qwertyuiopasdfghjklzxcvbnm1234567890");
    std::cout <<MAGENTA <<"std::vector<std::string>s_v_range"<<RESET <<std::endl;
    std::cout <<CYAN <<"ft:vector<std::string>f_v_range"<<RESET <<std::endl;
    std::vector<std::string>s_v_range;
    std::vector<std::string>s_v;
    ft::vector<std::string>f_v_range;
    ft::vector<std::string>f_v;
    for (int i = 0; i != 10; ++i)
    {
        std::string s1;
        for (int k = 0; k != 10; ++k)
        {
            s1.push_back(tab[rand() % tab.length()]);
        }
        s_v.push_back(s1);
        f_v.push_back(s1);
    }
    std::cout << MAGENTA << "s_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
    {
        std::cout << s_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "s_v_range.insert(s_v.begin() + 5, s_v.begin(), s_v.end())" << RESET<<std::endl;
    std::cout << CYAN  << "f_v_range.insert(f_v.begin() + 5, f_v.begin(), f_v.end())" << RESET<<std::endl;
    s_v_range.assign(10, "qwert");
    f_v_range.assign(10, "qwert");
    s_v_range.push_back("aaaa");
    f_v_range.push_back("aaaa");
    s_v_range.insert(s_v_range.begin(), s_v.begin(), s_v.end());
    f_v_range.insert(f_v_range.begin(),  f_v.begin(), f_v.end());
    std::cout << MAGENTA << "s_v_range.size() = " << RESET<<s_v_range.size()<<std::endl;
    std::cout << CYAN  << "f_v_range.size() = " << RESET<<f_v_range.size()<<std::endl;
    std::cout << MAGENTA << "s_v_range.max_size() = " << RESET<<s_v_range.max_size()<<std::endl;
    std::cout << CYAN  << "f_v_range.max_size() = " << RESET<<f_v_range.max_size()<<std::endl;
    std::cout << MAGENTA << "s_v_range.capacity() = " << RESET<<s_v_range.capacity()<<std::endl;
    std::cout << CYAN  << "f_v_range.capacity() = " << RESET<<f_v_range.capacity()<<std::endl;
    std::cout << MAGENTA << "s_v_range[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v_range.size(); ++i)
    {
        std::cout << s_v_range[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v_range[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v_range.size(); ++i)
    {
        std::cout << f_v_range[i]<<" ";
    }
    std::cout << std::endl;
}
void erase(){
    std::cout << BLUE << "         ERASE"<<RESET<<std::endl;
    std::string tab("qwertyuiopasdfghjklzxcvbnm1234567890");
    std::cout <<MAGENTA <<"std::vector<std::string>s_v"<<RESET <<std::endl;
    std::cout <<CYAN <<"ft:vector<std::string>f_v"<<RESET <<std::endl;
    std::vector<std::string>s_v;
    ft::vector<std::string>f_v;
    for (int i = 0; i != 10; ++i)
    {
        std::string s1;
        for (int k = 0; k != 10; ++k)
        {
            s1.push_back(tab[rand() % tab.length()]);
        }
        s_v.push_back(s1);
        f_v.push_back(s1);
    }
    std::cout << MAGENTA << "s_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
    {
        std::cout << s_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout <<MAGENTA <<"s_v.erase(s_v.begin() + 4)"<<RESET <<std::endl;
    std::cout <<CYAN <<"f_v.erase(f_v.begin() + 4)"<<RESET <<std::endl;
    SitStr s_it = s_v.begin() + 4;
    itStr f_it = f_v.begin() + 4;
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it <<std::endl;
    std::cout << CYAN << "*f_it = "<<RESET<< *f_it <<std::endl;
    s_it = s_v.erase(s_v.begin() + 4);
    f_it = f_v.erase(f_v.begin() + 4);
    std::cout << MAGENTA << "*s_it = "<<RESET;
    for (; s_it != s_v.end();++s_it)
    {
        std::cout << *s_it<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "*f_it = "<<RESET;
    for (; f_it != f_v.end();++f_it)
    {
        std::cout << *f_it<<" ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "s_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
    {
        std::cout << s_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
}
void erase_range(){
    std::cout << BLUE << "         ERASE RANGE"<<RESET<<std::endl;
    std::string tab("qwertyuiopasdfghjklzxcvbnm1234567890");
    std::cout <<MAGENTA <<"std::vector<std::string>s_v"<<RESET <<std::endl;
    std::cout <<CYAN <<"ft:vector<std::string>f_v"<<RESET <<std::endl;
    std::vector<std::string>s_v;
    ft::vector<std::string>f_v;
    for (int i = 0; i != 10; ++i)
    {
        std::string s1;
        for (int k = 0; k != 10; ++k)
        {
            s1.push_back(tab[rand() % tab.length()]);
        }
        s_v.push_back(s1);
        f_v.push_back(s1);
    }
    std::cout << MAGENTA << "s_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
    {
        std::cout << s_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout <<MAGENTA <<"s_v.erase(s_v.begin(), s_v.end())"<<RESET <<std::endl;
    std::cout <<CYAN <<"f_v.erase(f_v.begin(), f_v.end())"<<RESET <<std::endl;
    SitStr s_it = s_v.begin();
    itStr f_it = f_v.begin();
    std::cout << MAGENTA << "*s_it = "<<RESET << *s_it <<std::endl;
    std::cout << CYAN << "*f_it = "<<RESET<< *f_it <<std::endl;
    s_it = s_v.erase(s_v.begin(), s_v.end());
    f_it = f_v.erase(f_v.begin(), f_v.end());
    std::cout << MAGENTA << "*s_it = "<<RESET;
    for (; s_it != s_v.end();++s_it)
    {
        std::cout << *s_it<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "*f_it = "<<RESET;
    for (; f_it != f_v.end();++f_it)
    {
        std::cout << *f_it<<" ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "s_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
    {
        std::cout << s_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
}
void swap(){
    std::cout << BLUE << "       SWAP"<<RESET<<std::endl;
    ft::vector<int> s_v (3,100);   // three ints with a value of 100
    ft::vector<int> s_v2 (3,400);   // three ints with a value of 100
    ft::vector<int> f_v (2,200);
    ft::vector<int> f_v2 (2,100);
//    std::cout << MAGENTA << "s_v[i] = "<<RESET;
//    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
//    {
//        std::cout << s_v[i]<<" ";
//    }
//    std::cout << std::endl;
//    std::cout << MAGENTA << "s_v2[i] = "<<RESET;
//    for (std::vector<int>::size_type i = 0; i!= s_v2.size(); ++i)
//    {
//        std::cout << s_v2[i]<<" ";
//    }
//    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v2[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v2.size(); ++i)
    {
        std::cout << f_v2[i]<<" ";
    }
    std::cout << std::endl;
//    s_v.swap(s_v2);
    f_v.swap(f_v2);
//    std::cout << MAGENTA << "s_v.swap(s_v2)"<<RESET<<std::endl;
    std::cout << CYAN << "f_v.swap(f_v2)"<<RESET<<std::endl;
//    std::cout << MAGENTA << "s_v[i] = "<<RESET;
//    for (std::vector<int>::size_type i = 0; i!= s_v.size(); ++i)
//    {
//        std::cout << s_v[i]<<" ";
//    }
//    std::cout << std::endl;
//    std::cout << MAGENTA << "s_v2[i] = "<<RESET;
//    for (std::vector<int>::size_type i = 0; i!= s_v2.size(); ++i)
//    {
//        std::cout << s_v2[i]<<" ";
//    }
//    std::cout << std::endl;
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v2[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v2.size(); ++i)
    {
        std::cout << f_v2[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "ft::swap(f_v, f_v2)"<<RESET<<std::endl;
    ft::swap(f_v, f_v2);
    std::cout << CYAN << "f_v[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v.size(); ++i)
    {
        std::cout << f_v[i]<<" ";
    }
    std::cout << std::endl;
    std::cout << CYAN << "f_v2[i] = "<<RESET;
    for (std::vector<int>::size_type i = 0; i!= f_v2.size(); ++i)
    {
        std::cout << f_v2[i]<<" ";
    }
    std::cout << std::endl;
}
void relational_operators(){
    {
        std::cout << BLUE << "     RELATION OPERATORS" << RESET << std::endl;
        ft::vector<int> foo(3, 100);   // three ints with a value of 100
        ft::vector<int> bar(2, 200);   // two ints with a value of 200
        if (foo == bar) std::cout <<CYAN<< "foo and bar are equal\n";
        if (foo != bar) std::cout <<CYAN<< "foo and bar are not equal\n";
        if (foo < bar) std::cout << "foo is less than bar\n";
        if (foo > bar) std::cout << "foo is greater than bar\n";
        if (foo <= bar) std::cout << "foo is less than or equal to bar\n"<<RESET;
        if (foo >= bar) std::cout << "foo is greater than or equal to bar\n"<<RESET;
    }
    {
        std::cout << BLUE << "     RELATION OPERATORS"<<RESET<<std::endl;
        std::vector<int> foo (3,100);   // three ints with a value of 100
        std::vector<int> bar (2,200);   // two ints with a value of 200
        if (foo==bar) std::cout << "foo and bar are equal\n";
        if (foo!=bar) std::cout << "foo and bar are not equal\n";
        if (foo< bar) std::cout << "foo is less than bar\n";
        if (foo> bar) std::cout << "foo is greater than bar\n";
        if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
        if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    }
}
int main()
{
    std::string tab("qwertyuiopasdfghjklzxcvbnm1234567890");

    srand(time(nullptr));
//     construtor();
//     assign_operator();
//     iterators();
//     revese_iterators();
//     const_iterator();
//     capacity();
//     element_access();
//    insert_single_element();
//    insert_fill();
//                                insert_range();//fail
                            //    erase();//fail
//    erase_range();
//    swap();
//    relational_operators();
    {
        
        std::string *q = new std::string[10];
        std::vector<int> ft_int;
        std::vector<int> ft_int_test;
        for (int i = 0; i < 10; ++i) {
            ft_int.push_back(i);
            ft_int_test.push_back(100 - i);
        }
        std::vector<int>::iterator i = ft_int.begin();
        i++;i++;i++;
        std::cout<<"{"<<*i<<"}"<<std::endl;
        ft_int.insert(i, ft_int_test.begin(), (ft_int_test.end()--));

        for (int i : ft_int) {
            std::cout<<" "<< i<<" ";
        }
        std::cout<<std::endl;
    }

    {
        ft::vector<int> ft_int;
        ft::vector<int> ft_int_test;
        for (int i = 0; i < 10; ++i) {
            ft_int.push_back(i);
            ft_int_test.push_back(100 - i);
        }
        ft::vector<int>::iterator i = ft_int.begin();
        i++;i++;i++;
        std::cout<<"{"<<*i<<"}"<<std::endl;
        ft_int.insert(i, ft_int_test.begin(), (ft_int_test.end()--));

        for (int i : ft_int) {
            std::cout<<" "<< i<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}