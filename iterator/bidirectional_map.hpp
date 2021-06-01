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
        pointer _elem;
    private:
        pointer get_successor(pointer elem) {
            pointer next;
            if (!elem->right_child) {
                next = elem;
                while (next->parent && next == next->parent->right_child)
                    next = next->parent;
                next = next->parent;
            } else {
                next = elem->right_child;
                while (next->left_child)
                    next = next->left_child;
            }
            return (next);
        };

        pointer get_predecessor(pointer elem) {
            pointer next;

            if (!elem->left_child) {
                next = elem;
                while (next->parent && next == next->parent->left_child)
                    next = next->parent;
                next = next->parent;
            } else {
                next = elem->left_child;
                while (next->right_child)
                    next = next->right_child;
            }
            return (next);
        };
    public:
        bidirectional_map()
                : _elem(0) {};

        bidirectional_map(const pointer elem)
                : _elem(elem) {};

        bidirectional_map(const bidirectional_map &other) {
            *this = other;
        };

        bidirectional_map &operator=(const bidirectional_map &other) {
            _elem = other._elem;
            return (*this);
        };

        pointer node() {
            return (_elem);
        };

        value_type &operator*() {
            return (_elem->pair);
        };

        value_type *operator->() {
            return (&_elem->pair);
        };

        bool operator==(const bidirectional_map<K, T> &other) {
            return (_elem == other._elem);
        };

        bool operator!=(const bidirectional_map<K, T> &other) {
            return (!(*this == other));
        };

        bool operator>(const bidirectional_map<K, T> &other) {
            return (_elem > other._elem);
        };

        bool operator<(const bidirectional_map<K, T> &other) {
            return (_elem < other._elem);
        };

        bool operator>=(const bidirectional_map<K, T> &other) {
            return (_elem >= other._elem);
        };

        bool operator<=(const bidirectional_map<K, T> &other) {
            return (_elem <= other._elem);
        };

        bidirectional_map &operator++() {
            _elem = get_successor(_elem);
            return (*this);
        };

        bidirectional_map &operator--() {
            _elem = get_predecessor(_elem);
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
