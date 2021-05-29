//
// Created by OUT-BABAEV-E on 29.05.2021.
//

#ifndef FT_CONTAINER_BIDIRECTIONAL_MAP_HPP
#define FT_CONTAINER_BIDIRECTIONAL_MAP_HPP

#include "elem.hpp"
#include <iostream>

namespace ft {
    template<class K, class T>
    class bidirectional_map {
    public:
        typedef std::pair<K, T> value_type;
        typedef std::pair<K, T> &reference;
        typedef elem<K, T> *pointer;
    protected:
        pointer _ptr;
    private:
        pointer _successor(pointer ptr) {
            pointer next;
            if (!ptr->right_child) {
                next = ptr;
                while (next->parent && next == next->parent->right_child)
                    next = next->parent;
                next = next->parent;
            } else {
                next = ptr->right_child;
                while (next->left_child)
                    next = next->left_child;
            }
            return (next);
        };

        pointer _predecessor(pointer ptr) {
            pointer next;

            if (!ptr->left_child) {
                next = ptr;
                while (next->parent && next == next->parent->left_child)
                    next = next->parent;
                next = next->parent;
            } else {
                next = ptr->left_child;
                while (next->right_child)
                    next = next->right_child;
            }
            return (next);
        };
    public:
        bidirectional_map()
                : _ptr(0) {};

        bidirectional_map(const pointer ptr)
                : _ptr(ptr) {};

        bidirectional_map(const bidirectional_map &other) {
            *this = other;
        };

        bidirectional_map &operator=(const bidirectional_map &other) {
            _ptr = other._ptr;
            return (*this);
        };

        pointer node() {
            return (_ptr);
        };

        value_type &operator*(void) {
            return (_ptr->pair);
        };

        value_type *operator->(void) {
            return (&_ptr->pair);
        };

        bool operator==(const bidirectional_map<K, T> &other) {
            return (_ptr == other._ptr);
        };

        bool operator!=(const bidirectional_map<K, T> &other) {
            return (!(*this == other));
        };

        bool operator>(const bidirectional_map<K, T> &other) {
            return (_ptr > other._ptr);
        };

        bool operator<(const bidirectional_map<K, T> &other) {
            return (_ptr < other._ptr);
        };

        bool operator>=(const bidirectional_map<K, T> &other) {
            return (_ptr >= other._ptr);
        };

        bool operator<=(const bidirectional_map<K, T> &other) {
            return (_ptr <= other._ptr);
        };

        bidirectional_map &operator++() {
            _ptr = _successor(_ptr);
            return (*this);
        };

        bidirectional_map &operator--() {
            _ptr = _predecessor(_ptr);
            return (*this);
        };

        bidirectional_map operator++(int) {
            bidirectional_map tmp(*this);
            this->operator++();
            return (tmp);
        };

        bidirectional_map operator--(int) {
            bidirectional_map tmp(*this);
            this->operator--();
            return (tmp);
        };
    };
}

#endif //FT_CONTAINER_BIDIRECTIONAL_MAP_HPP
