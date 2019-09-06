#include <iostream>
#include <new>

using std::cin; using std::cout; using std::nothrow;

template <typename T>
struct set_array
{
    T *set_array;
    int end_index, size;

    T change_size(int new_size)
    {

    }

    bool is_empty()
    {return (end_index == -1);}

    bool init()
    {
        set_array = new(nothrow) T[1];
        if (set_array == nullptr) return true;
        size = 1; end_index = -1;
        return false;
    }

    bool insert(T e)  // Pre-condition: "e" is not inside the set.
    {
        if (end_index == size - 1)
        {
            if (change_size(2 * size)) return true;
        }
        ++end_index;
        set_array[end_index] = e;
        return false;
    }

    bool remove(T e)  // Pre-condition: "e" is inside the set.
    {
        for (int i = 0; i <= end_index; ++i)
        {
            if (set_array[i] == e)
            {
                set_array[i] = set_array[end_index];
                --end_index;
            }
        }
        if (!is_empty()  &&)
        return false;
    }
    bool is_in(T e)
    {
        for (int i = 0; i <= end_index; ++i)
        {
            if (set_array[i] == e) return true;
        }
        return false;
    }
};