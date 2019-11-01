#ifndef STACK_HPP
#define STACK_HPP
#include <new>
#include <iostream>
using std::nothrow;

template <typename T>
struct Stack   //Stack is unlimited
{
    T* array; int last; int size;
};

template <typename T>
bool init (Stack<T> &S)  // Returns true if init fails
{
    S.array = new(nothrow) T[1];  // Stack is initialized with size 1
    if (S.array == nullptr) {return true;} 
    S.last = -1; S.size = 1;
    return false;
}

template <typename T>
bool is_empty (Stack<T> &S)  // Returns true if empty
{
    if (S.size == -1) {return true;}
    return false;
}

template <typename T>
bool resize (Stack<T> &S, int new_size)  // Returns true if resizing fails
{
    T* new_array = new(nothrow) T[new_size];
    if (new_array == nullptr) {return true;}
    for (int i = 0; i <= S.size; ++i)
    {
        new_array[i] = S.array[i];
    }
    S.array = new_array;
    return false;
}

template <typename T>
bool push (Stack<T> &S, T element)
{
    if (++S.last >= S.size) // If 'last' is already at the size limit:
    {
        if (!resize(Stack<T> &S, S.size * 2))  // If resizing works: 
        {
            ++S.last;
            S.array[S.last] = element;
            ++S.size;
            return false;
        }
    }
    return true;
}

template <typename T>
T* pop (Stack<T> &S)
{
    if (!is_empty(Stack<T> &S))
    {
        return nullptr;
    }
    else if (--S.last < S.size / 4)  // If 'last' is at less than 25% of current array size: 
    {
        if (resize(Stack<T> &S, S.size / 4))  // If resizing doesn't work:
        {
            return nullptr;
        }
        else return nullptr;
    }
    
    
}

template <typename T>
T terminate (Stack<T> &S)
{
}

#endif