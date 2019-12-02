#include "heap.hpp" // Aula anterior

template <typename T>
void heapsort(T* v, int n)
{
    Heap<T> h; h.inicializar(v, n);
    int i;
    for (int i = 0; i < n; ++i)
    {
        T e = v[i];
        h.inserir(e);
    }
    for (int i = n-1; i > 0; --i)
    {
        v[i] = h.remover_max();
    }
}