#ifndef FT_CONTAINER_ELEM_HPP
#define FT_CONTAINER_ELEM_HPP

#include <iostream>

namespace ft {
    template<class Key, class T>
    class elem {
    public:
        typedef elem *pointer;


        std::pair<Key, T> node;
        elem *left_child;
        elem *right_child;
        elem *parent;

        elem() : node(), left_child(nullptr), right_child(nullptr), parent(nullptr) {}

        elem(const elem &arg) : node(arg.node), left_child(arg.left_child), right_child(arg.right_child),
                                parent(arg.parent) {}

        elem(std::pair<Key, T> node, pointer parent) : node(node), left_child(nullptr), right_child(nullptr),
                                                       parent(nullptr) {}

        ~elem() {}

        elem &operator=(elem const &arg) {
            if (&arg == this)
                return *this;
            this->parent = arg.parent;
            this->left_child = arg.left_child;
            this->right_child = arg.right_child;
            this->parent = arg.parent;
            return *this;
        }

        bool operator==(const elem &rhs) const {
            return node == rhs.node &&
                   left_child == rhs.left_child &&
                   right_child == rhs.right_child &&
                   parent == rhs.parent;
        }

        bool operator!=(const elem &rhs) const {
            return !(rhs == *this);
        }
    };
}
#endif
