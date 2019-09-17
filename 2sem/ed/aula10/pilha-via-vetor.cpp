/*Um exemplo de uso (main.cpp)*/

#include <iostream>
using std::cin; using std::cout;
#include "pilha.hpp"

int main()
{
    pilha<double> p;

    if (p.inicializar()) return 1; // Se inicializar for true, dá erro
    for(;;)
    {
        cout << "Número para empilhar" << "(negativo para terminar): ";
        double num; cin >> num;
        if (num < 0) break;
        if (p.empilhar(num)) return 2; // Se empilhar for true, dá erro
    }
    cout << "Os números digitados, do último para o primeiro, foram: ";
    while (!p.vazia())
    {
        cout << ' ' << p.topo();
        if (p.desempilhar()) return 3;
    }
    p.terminar();
}