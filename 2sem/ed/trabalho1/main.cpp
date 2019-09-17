#include <iostream>
#include <new>
#include "no-struct-deque.hpp"
using std::cin; using std::cout;

int main()
{
    Deque<int> d;
    inicializar(d);
    inserir_dir(d, 5);
    print_deque(d);
    inserir_esq(d, 3);
    print_deque(d);
    inserir_esq(d, 7);
    inserir_esq(d, 8);
    inserir_esq(d, 9);
    print_deque(d);
    inserir_dir(d, 10);
    print_deque(d);
    inserir_dir(d, 12);
    print_deque(d);
    inserir_dir(d, 11);
    inserir_dir(d, 13);
    inserir_dir(d, 14);
    inserir_dir(d, 15);
    print_deque(d);
    remover_dir(d);
    remover_esq(d);
    print_deque(d);
}