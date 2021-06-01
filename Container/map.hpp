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
                size++;
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
                            parent->left_child->parent = parent;
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
                            parent->right_child->parent = parent;
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

        size_type count(const key_type& k) const {
            if (_find(k)) {
                return 1;
            }
            return 0;
        }

        iterator find(const key_type &k) const {
            iterator it = iterator(_find(k));
            if (it != nullptr) {
                return it;
            }
            //TODO: map::end
            return nullptr;
        }

//        void erase (iterator position);

        size_type erase(const key_type &k) {
            size_type size_type = 0;
            while (_delete(k)) {
                size_type++;
            }
            return size_type;
        }

//        void erase (iterator first, iterator last);

    private:
//        tree _find(const key_type &key) const {
//            elem<Key, T> *current = _tree;
//            elem<Key, T> *parent;
//            while (true) {
//                parent = current;
//                if (key < current->node.first) {
//                    current = current->left_child;
//                } else if (key > current->node.first) {
//                    current = current->right_child;
//                } else {
//                    if (current) {
//                        return current;
//                    } else {
//                        return nullptr;
//                    }
//                }
//            }
//        }
        tree _find(const key_type &key) const {
            tree current = _tree;
            while (current->node.first != key) {
                if (key < current->node.first) {
                    current = current->left_child;
                } else {
                    current = current->right_child;
                }
                if (current == nullptr) {
                    return nullptr;
                }
            }
            return current;
        }

        tree _delete(const key_type &key) {
            elem<Key, T> *delete_elem = _find(key);
            if (!delete_elem) {
                return nullptr;
            }
            if (!delete_elem->left_child && !delete_elem->right_child) {
                if (!delete_elem->parent) {
                    _tree = nullptr;
                } else if (is_left_child(delete_elem)) {
                    //TODO: delete left child + очистку
                    delete_elem->parent->left_child = nullptr;
                } else if (is_right_child(delete_elem)) {
                    //TODO: delete right child + очистку
                    delete_elem->parent->right_child = nullptr;
                }
            } else if (!delete_elem->right_child) {
                if (!delete_elem->parent) {
                    _tree = delete_elem->left_child;
                    _tree->parent = nullptr;
                } else if (is_left_child(delete_elem)) {
                    delete_elem->parent->left_child = delete_elem->left_child;
                    delete_elem->parent->left_child->parent = delete_elem->parent;
                } else {
                    delete_elem->parent->right_child = delete_elem->left_child;
                    delete_elem->parent->right_child->parent = delete_elem->parent;
                }
            } else if (!delete_elem->left_child) {
                if (!delete_elem->parent) {
                    _tree = delete_elem->right_child;
                    _tree->parent = nullptr;
                } else if (is_left_child(delete_elem)) {
                    delete_elem->parent->left_child = delete_elem->right_child;
                    delete_elem->parent->left_child->parent = delete_elem->parent;
                } else {
                    delete_elem->parent->right_child = delete_elem->right_child;
                    delete_elem->parent->right_child->parent = delete_elem->parent;
                }
            } else {
                //TODO: delete если есть оба наследника
                tree success = get_successor(delete_elem);

                if (!delete_elem->parent) {
                    _tree = success;
                    success->parent = nullptr;
                } else if (is_left_child(delete_elem)) {
                    delete_elem->parent->left_child = success;
                    success->parent = delete_elem->parent;
                } else {
                    delete_elem->parent->right_child = success;
                    success->parent = delete_elem->parent;
                }
            }
            //TODO: что возвращать??? вроде так / проверить!!!
            size--;
            if (!delete_elem->parent) {
                return _tree;
            } else if (is_left_child(delete_elem)) {
                return delete_elem->parent->left_child;
            } else {
                return delete_elem->parent->right_child;
            }
        }

        tree get_successor(tree delete_elem) {
            tree successor_parent = delete_elem;
            tree successor = delete_elem;
            tree current = delete_elem->right_child;
            while (!current) {
                successor_parent = successor;
                successor = current;
                current = current->left_child;
            }
            if (successor != delete_elem->right_child) {
                successor_parent->left_child = successor->right_child;
                successor->right_child = delete_elem->right_child;
            }
            return successor;
        }

        bool is_left_child(tree elem) const {
            if (elem->parent->left_child == elem) {
                return true;
            } else
                return false;
        }

        bool is_right_child(tree elem) const {
            if (elem->parent->right_child == elem) {
                return true;
            } else {
                return false;
            }
        }
    };
}

#endif //FT_CONTAINER_MAP_HPP
