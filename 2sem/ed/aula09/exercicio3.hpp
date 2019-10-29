#ifndef STACK_HPP
#define STACK_HPP
#include <new>
#include <iostream>
using std::nothrow;

template <typename T>
struct Stack   //Stack is unlimited
{
    T array; int last; int size;
};

template <typename T>
bool init(Stack<T> &S)
{
    S.array = new(nothrow) T[1];  // Stack is initialized with size 1
    if (S.array == nullptr) {return true;}
    S.last = -1; S.size = 1;
    return false;
}
template <typename T>
bool resize(Stack<T> &S)
{
    
}
#endif