#include <stdio.h>
#include <stdlib.h>
#include "deque-lista-encadeada.hpp"
#include <new>
void main()
{
    Deque_ll<int> *n = new(nothrow) Deque_ll<int>();
    n->init();
    n->addright(4);
    n->addleft(5);
    n->addright(6);
}