#ifndef DISP_T_HPP
#define DISP_T_HPP

#include <new>
#include <iostream>

using std::cin; using std::cout; using std::nothrow;

struct Table
{
    template <typename T>
    struct Node
    {
        T element; Node* prev, next;
    };
    
    Node *init (int size)
    {
        T *table_array = new(nothrow) T[size];
        if (table_array == nullptr) {return -1;}
        return table_array;
    }

};

#endif