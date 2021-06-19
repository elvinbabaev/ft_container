#ifndef BIDIRECTIONAL_MAP_HPP
#define BIDIRECTIONAL_MAP_HPP

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
            return (_elem->node);
        };

        value_type *operator->() {
            return (&_elem->node);
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

    template<class K, class T>
    class const_bidirectional_map {
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
        const_bidirectional_map()
                : _elem(0) {};

        const_bidirectional_map(const pointer elem)
                : _elem(elem) {};

        const_bidirectional_map(const const_bidirectional_map &other) {
            *this = other;
        };

        const_bidirectional_map &operator=(const const_bidirectional_map &other) {
            _elem = other._elem;
            return (*this);
        };

        pointer node() {
            return (_elem);
        };

        const value_type &operator*() {
            return (_elem->node);
        };

        const value_type *operator->() {
            return (&_elem->node);
        };

        bool operator==(const const_bidirectional_map<K, T> &other) {
            return (_elem == other._elem);
        };

        bool operator!=(const const_bidirectional_map<K, T> &other) {
            return (!(*this == other));
        };

        bool operator>(const const_bidirectional_map<K, T> &other) {
            return (_elem > other._elem);
        };

        bool operator<(const const_bidirectional_map<K, T> &other) {
            return (_elem < other._elem);
        };

        bool operator>=(const const_bidirectional_map<K, T> &other) {
            return (_elem >= other._elem);
        };

        bool operator<=(const const_bidirectional_map<K, T> &other) {
            return (_elem <= other._elem);
        };

        const const_bidirectional_map &operator++() {
            _elem = get_successor(_elem);
            return (*this);
        };

        const const_bidirectional_map &operator--() {
            _elem = get_predecessor(_elem);
            return (*this);
        };

        const const_bidirectional_map operator++(int) {
            const_bidirectional_map tmp(*this);
            this->operator++();
            return (tmp);
        };

        const const_bidirectional_map operator--(int) {
            const_bidirectional_map tmp(*this);
            this->operator--();
            return (tmp);
        };

        const_bidirectional_map &operator=(bidirectional_map<K, T> &bidirectional_map) {
	        this->_elem = bidirectional_map._elem;
	        return *this;
        }

	    const_bidirectional_map(bidirectional_map<int, int> bidirectional_map) {
		    this->_elem = bidirectional_map.node();
	    }
    };

    template<class K, class T>
    class reverse_bidirectional_map {
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
        reverse_bidirectional_map()
                : _elem(0) {};

        reverse_bidirectional_map(const pointer elem)
                : _elem(elem) {};

        reverse_bidirectional_map(const reverse_bidirectional_map &other) {
            *this = other;
        };

        reverse_bidirectional_map &operator=(const reverse_bidirectional_map &other) {
            _elem = other._elem;
            return (*this);
        };

        pointer node() {
            return (_elem);
        };

        value_type &operator*() {
            return (_elem->node);
        };

        value_type *operator->() {
            return (&_elem->node);
        };

        bool operator==(const reverse_bidirectional_map<K, T> &other) {
            return (_elem == other._elem);
        };

        bool operator!=(const reverse_bidirectional_map<K, T> &other) {
            return (!(*this == other));
        };

        bool operator>(const reverse_bidirectional_map<K, T> &other) {
            return (_elem > other._elem);
        };

        bool operator<(const reverse_bidirectional_map<K, T> &other) {
            return (_elem < other._elem);
        };

        bool operator>=(const reverse_bidirectional_map<K, T> &other) {
            return (_elem >= other._elem);
        };

        bool operator<=(const reverse_bidirectional_map<K, T> &other) {
            return (_elem <= other._elem);
        };

        reverse_bidirectional_map &operator++() {
            _elem = get_predecessor(_elem);
            return (*this);
        };

        reverse_bidirectional_map &operator--() {
            _elem = get_successor(_elem);
            return (*this);
        };

        reverse_bidirectional_map operator++(int) {
            reverse_bidirectional_map tmp(*this);
            this->operator++();
            return (tmp);
        };

        reverse_bidirectional_map operator--(int) {
            reverse_bidirectional_map tmp(*this);
            this->operator--();
            return (tmp);
        };
    };


    template<class K, class T>
    class const_reverse_bidirectional_map {
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
        const_reverse_bidirectional_map()
                : _elem(0) {};

        const_reverse_bidirectional_map(const pointer elem)
                : _elem(elem) {};

        const_reverse_bidirectional_map(const const_reverse_bidirectional_map &other) {
            *this = other;
        };

        const_reverse_bidirectional_map &operator=(const const_reverse_bidirectional_map &other) {
            _elem = other._elem;
            return (*this);
        };

        pointer node() {
            return (_elem);
        };

        const value_type &operator*() {
            return (_elem->node);
        };

        const value_type *operator->() {
            return (&_elem->node);
        };

        bool operator==(const const_reverse_bidirectional_map<K, T> &other) {
            return (_elem == other._elem);
        };

        bool operator!=(const const_reverse_bidirectional_map<K, T> &other) {
            return (!(*this == other));
        };

        bool operator>(const const_reverse_bidirectional_map<K, T> &other) {
            return (_elem > other._elem);
        };

        bool operator<(const const_reverse_bidirectional_map<K, T> &other) {
            return (_elem < other._elem);
        };

        bool operator>=(const const_reverse_bidirectional_map<K, T> &other) {
            return (_elem >= other._elem);
        };

        bool operator<=(const const_reverse_bidirectional_map<K, T> &other) {
            return (_elem <= other._elem);
        };

        const const_reverse_bidirectional_map &operator++() {
            _elem = get_predecessor(_elem);
            return (*this);
        };

        const const_reverse_bidirectional_map &operator--() {
            _elem = get_successor(_elem);
            return (*this);
        };

        const const_reverse_bidirectional_map operator++(int) {
            const_reverse_bidirectional_map tmp(*this);
            this->operator++();
            return (tmp);
        };

        const const_reverse_bidirectional_map operator--(int) {
            const_reverse_bidirectional_map tmp(*this);
            this->operator--();
            return (tmp);
        };

	    const_reverse_bidirectional_map(reverse_bidirectional_map<int, int> map) {
		    this->_elem = map.node();
	    }

	    const_reverse_bidirectional_map &operator=(reverse_bidirectional_map<K, T> reverse) {
		    this->_elem = reverse._elem;
		    return *this;
	    }
    };
}

#endif
