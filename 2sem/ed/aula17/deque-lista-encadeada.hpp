#ifndef DEQUE_LL_HPP
#define DEQUE_LL_HPP

#include <new>
using std::nothrow;

template <typename T>
struct Deque_ll
{
    struct node
    {
        node *previous, *next; T element;
    };
    node *left, *right;

    void init()  // Returns true if allocation fails
    {
        left = nullptr; right = nullptr;
    }

    node* addaux()
    {
        node *n = new(nothrow) node;
        if (n != nullptr) return n;
    }
    bool is_empty() {return ((left == nullptr) && (right == nullptr));}

    bool addleft(T e)
    {
        auto n = addaux();
        (*n).previous = nullptr; (*n).element = e; (*n).next = left;
        if (is_empty()) {right = n;}
        else {(*left).previous = n;}
        left = n;
        return false;
    }
    
    T remleft()
    {
        T e; node *n = left;
        e = (*n).element; left = (*n).next;
        if (left == nullptr) {right == nullptr;}
        else (*left).previous = nullptr;
        delete n; return e; 
    }

    bool addright(T e)
    {
        auto n = addaux();
        (*n).previous = right; (*n).element = e; (*n).next = nullptr;
        if (is_empty()) {left = n;}
        else {(*right).next = n;}
        right = n;
        return false;
    }
    
    T remright()
    {
        T e; node *n = right;
        e = (*n).element;
        if (right == nullptr) right = (*n).previous; (*right).next = nullptr;
        delete n; return e; 
    }

    void terminate()
    {
        while (left != nullptr && right != nullptr)
        {
            remleft();
        }
    }
};
#endif