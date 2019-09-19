/*Sabendo que:
fib(n) = {n, se n <= 1; fib(n-2) + fib(n-1), se n >= 2;},
escreva em pseudocódigo, uma implementação não recursiva da função Fibonnaci. (Use pilha(s))*/

//Torre de Hanoi
#include <iostream>
#include <new>

using std::cin; using std::cout; using std::nothrow;

int discos;

int cria_pilha(int discos)
{
    int pilha[discos];
    int *p = &pilha[discos];
}

int main()
{
cout <<  "Digite o numero de discos: ";
cin >> discos;
cout << discos << '\n';
}
