//
// Created by OUT-BABAEV-E on 29.05.2021.
//

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "elem.hpp"
#include "bidirectional_map.hpp"

namespace ft {

    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>>>
    class map {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const Key, T> value_type;
        typedef Compare key_compare;

        class value_compare {
        };

        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef std::size_t size_type;
        //TODO:iterator
        typedef bidirectional_map<Key, T> iterator;
        typedef elem<Key, T> *tree;
    private:
        allocator_type allocator;
        tree _tree;
        size_type size;
        key_compare compare;

    public:
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) {
            _tree = nullptr;
            compare = comp;
            allocator = alloc;
        }

        std::pair<iterator, bool> insert(const value_type &val) {
            if (!_tree) {
                _tree = new elem<Key, T>();
                _tree->node = val;
                _tree->left_child = nullptr;
                _tree->right_child = nullptr;
                _tree->parent = nullptr;
                return std::pair<iterator, bool>(_tree, true);
            } else {
                elem<Key, T> *current = _tree;
                elem<Key, T> *parent;
                while (true) {
                    parent = current;
                    if (val.first < current->node.first) {
                        //налево
                        current = current->left_child;
                        if (!current) {
                            parent->left_child = new elem<Key, T>(val, _tree);
                            size++;
                            //TODO:iterator(pair, bool) убрать nullptr
                            return std::pair<iterator, bool>(parent->left_child, true);
//                            tmp.first = iterator(parent->left_child);
//                            tmp.second = true;
//                            return tmp;
//                            return std::pair<iterator, bool>(std::pair<iterator, bool>(new iterator(parent->left_child), true));
                        }
                    } else if (val.first > current->node.first) {
                        current = current->right_child;
                        if (!current) {
                            parent->right_child = new elem<Key, T>(val, _tree);
                            size++;
                            //TODO:iterator(pair, bool) убрать nullptr
                            return std::pair<iterator, bool>(parent->right_child, true);
                        }
                    } else {
                        //TODO: iterator на элемент который с этим ключом и false
//                        return std::pair<iterator, bool>(std::pair<iterator, bool>(new iterator(current), true));
                        return std::pair<iterator, bool>(current, false);
                    }
                }
            }
            return std::pair<iterator, bool>(nullptr, false);
        }

        iterator find(const key_type &k) const {
            iterator it = _find(k);
            if (it != nullptr) {
                return it;
            }
            //TODO: map::end
            return nullptr;
        }

    private:
        tree _find(const key_type &key) const {
            elem<Key, T> *current = _tree;
            elem<Key, T> *parent;
            while (true) {
                parent = current;
                if (key < current->node.first) {
                    current = current->left_child;
                } else if (key > current->node.first) {
                    current = current->right_child;
                } else {
                    if (current) {
                        return current;
                    } else {
                        return nullptr;
                    }
                }
            }
        }
    };
}

#endif //FT_CONTAINER_MAP_HPP
