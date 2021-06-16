//
// Created by OUT-BABAEV-E on 29.05.2021.
//

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "elem.hpp"
#include "bidirectional_map.hpp"

namespace ft {
    template<typename T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    };

    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>>>
    class map {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const Key, T> value_type;
        typedef Compare key_compare;

        class value_compare
                : public std::binary_function<value_type, value_type, bool> {
            friend class map;

        protected:
            Compare comp;

            value_compare(Compare c) : comp(c) {}
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;

            bool operator()(const value_type &x, const value_type &y) const {
                return comp(x.first, y.first);
            }
        };

        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef std::size_t size_type;
        //TODO:iterator
        typedef bidirectional_map<Key, T> iterator;
        typedef const_bidirectional_map<Key, T> const_iterator;
        typedef reverse_bidirectional_map<Key, T> reverse_iterator;
        typedef const_reverse_bidirectional_map<Key, T> const_reverse_iterator;
        typedef elem<Key, T> *tree;
    private:
        allocator_type allocator;
        tree _tree;
        size_type _size;
        key_compare compare;
        tree _begin;
        tree _end;

    public:
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) {

            _tree = new elem<Key, T>;
            _end = new elem<Key, T>;
            _begin = _tree;
            _size = 0;
            _tree->right_child = _end;
            _end->parent = _tree;
            compare = comp;
            allocator = alloc;
        }

        template<class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) {
            _tree = new elem<Key, T>;
            _end = new elem<Key, T>;
            _begin = _tree;
            _tree->right_child = _end;
            _end->parent = _tree;
            compare = comp;
            allocator = alloc;
            _size = 0;
            insert(first, last);
        }

        map(const map &x) {
            _tree = new elem<Key, T>;
            _end = new elem<Key, T>;
            _begin = _tree;
            _tree->right_child = _end;
            _end->parent = _tree;
            compare = x.compare;
            allocator = x.allocator;
            _size = 0;
            insert(iterator(x._begin), (iterator(x._end)));
        }

        map &operator=(const map &x) {
            this->clear();
            this->compare = x.compare;
            this->allocator = x.allocator;
            this->insert(iterator(x._begin), (iterator(x._end)));
            return *this;
        }

        std::pair<iterator, bool> insert(const value_type &val) {
            if (_size == 0) {
                _tree->node = val;
                _tree->left_child = nullptr;
                _tree->right_child = nullptr;
                _tree->parent = nullptr;
                _size++;
                search_begin_end();
                return std::pair<iterator, bool>(_tree, true);
            } else {
                elem<Key, T> *current = _tree;
                elem<Key, T> *parent;
                while (true) {
                    parent = current;
                    if (val.first < current->node.first) {
                        current = current->left_child;
                        if (!_check_end(current)) {
                            parent->left_child = new elem<Key, T>(val, _tree);
                            parent->left_child->parent = parent;
                            _size++;
                            //TODO:iterator(pair, bool) убрать nullptr
                            search_begin_end();
                            return std::pair<iterator, bool>(parent->left_child, true);
                        }
                    } else if (val.first > current->node.first) {
                        current = current->right_child;
                        if (!_check_end(current)) {
                            parent->right_child = new elem<Key, T>(val, _tree);
                            parent->right_child->parent = parent;
                            _size++;
                            //TODO:iterator(pair, bool) убрать nullptr
                            search_begin_end();
                            return std::pair<iterator, bool>(parent->right_child, true);
                        }
                    } else {
                        //TODO: iterator на элемент который с этим ключом и false
                        return std::pair<iterator, bool>(current, false);
                    }
                }
            }
            return std::pair<iterator, bool>(nullptr, false);
        }

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last) {
            while (first != last) {
                insert(*first);
                first++;
            }
        }

        iterator insert(iterator position, const value_type &val) {
            insert(val);
        }

        size_type count(const key_type &k) const {
            if (_find(k)) {
                return 1;
            }
            return 0;
        }

        iterator find(const key_type &k) {
            iterator it = iterator(_find(k));
            if (it != nullptr) {
                return it;
            }
            //TODO: map::end
            return _end;
        }

        const_iterator find (const key_type& k) const {
            const_iterator it = const_iterator(_find(k));
            if (it != nullptr) {
                return it;
            }
            //TODO: map::end
            return _end;
        }

        void erase(iterator position) {
            _delete(position._elem->node.first);
        }

        size_type erase(const key_type &k) {
            _delete(k);
            return 1;
        }

        void erase(iterator first, iterator last) {
            while (first != last) {
                _delete(first._elem->node.first);
                first++;
            }
        }

        bool empty() const {
            return !_size;
        }

        size_type size() const {
            return _size;
        }

        size_type max_size() const {
            return (std::numeric_limits<size_type>::max() / sizeof(elem<Key, T>));
        }

        mapped_type &operator[](const key_type &k) {
            elem<Key, T> *tmp = _find(k);
            if (tmp)
                return tmp->node.second;
            else
                return insert(std::pair<Key, T>(k, T())).first.node()->node.second;
        }

        void clear() {
            for (ft::bidirectional_map<Key, T> it = begin(); it != end(); it++) {
                _delete(it->first);
            }
            _size = 0;
        }

        iterator begin() {
            return (iterator(_begin));
        }

        const_iterator begin() const {
            return (const_iterator(_begin));
        }

        iterator end() {
            return iterator(_end);
        }

        const_iterator end() const {
            return (const_iterator(_end));
        }

        reverse_iterator rbegin() {
            iterator i = end();
            i--;
            return (reverse_iterator(i.node()));
        }

        const_reverse_iterator rbegin() const {
            iterator i = end();
            i--;
            return (reverse_iterator(i.node()));
        }

        reverse_iterator rend() {
            return reverse_iterator(_tree);
        }

        const_reverse_iterator rend() const {
            return reverse_iterator(_tree);
        }

        void swap(map &x) {
            ft::swap(_size, x._size);
            ft::swap(_tree, x._tree);
            ft::swap(compare, x.compare);
            ft::swap(allocator, x.allocator);
            x.search_begin_end();
            this->search_begin_end();
        }

        key_compare key_comp() const {
            return compare;
        }

        value_compare value_comp() const {
            return value_compare(compare);
        }


    private:
        elem<Key, T> *_find(const key_type &key) const {
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

        bool _check_end(tree el) const {
            return (el && el != _end);
        }

        tree _delete(const key_type &key) {
            elem<Key, T> *delete_elem = _find(key);
            if (!delete_elem) {
                return nullptr;
            }
            if (!delete_elem->left_child && !_check_end(delete_elem->right_child)) {
                if (!delete_elem->parent) {
                    _tree = new elem<Key, T>();
                } else if (is_left_child(delete_elem)) {
                    //TODO: delete left child + очистку
                    delete_elem->parent->left_child = nullptr;
                } else if (is_right_child(delete_elem)) {
                    //TODO: delete right child + очистку
                    delete_elem->parent->right_child = nullptr;
                }
            } else if (!_check_end(delete_elem->right_child)) {
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
            } else if (!_check_end(delete_elem->left_child)) {
                if (!_check_end(delete_elem->parent)) {
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
            _size--;
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

        void search_begin_end() {
            tree tmp = _tree;
            _begin = _tree;
            while (tmp->left_child) {
                _begin = tmp->left_child;
                tmp = tmp->left_child;
            }
            tmp = _tree;
            tree max = new elem<Key, T>();
            while (tmp->right_child && tmp->right_child != _end) {
                max = tmp->right_child;
                tmp = tmp->right_child;
            }
            max->right_child = _end;
            _end->parent = max;
        }
    };
}

#endif //FT_CONTAINER_MAP_HPP
