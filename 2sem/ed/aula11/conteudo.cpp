/*
1. INTRODUÇÃO: Uma fila é, assim como uma pilha, um contêiner, de forma que
elementos podem nela ser inseridos e removidos. A diferença essencial entre as
duas é que, enquanto numa pilha a operação de remoção remove o *último* elemento
inserido, numa fila a remoção retira o primeiro elemento inserido (dentre aqueles
ainda presentes na estrutura).

2. EXEMPLOS:

OPERAÇÃO     ||   RESULTADO
inicializar  ->  < > (fila vazia)
enfilar(A)   ->  <A>
enfilar(B)   ->  <A B>
enfilar(C)   ->  <A B C>
desenfilar() ->  <B C>
enfilar(D)   ->  <B C D>
desenfilar() ->  <C D>
desenfilar() ->  <D>
desenfilar() ->  < >

4. ESTRATÉGIA:

a) Usar índices "circulares" para utilizar o vetor inteiro sempre.
b) Ao expandir ou contrair, copiar os elementos para o início do novo vetor, 
*na ordem de enfilamento*
c)Fila vazia <--> Início = -1

5. Exemplo de uso de uma fila (main.cpp)
*/
#include <iostream>
using std::cin; using std::cout;
#include "fila.hpp"
int main()
{
    Fila <double> F;
    if (F.inicializar()) return 1;
    for(;;)
    {
        cout << "Digite um número" << " (negativo para parar): ";
        double num; cin >> num;
        if (num < 0) break;
        if(F.enfilar(num)) return 2;
    }
    cout << "Aqui estão os números: ";
    while(!f.vazia())
    {
        cout << ' ' << F.primeiro();
        if(F.desenfilar()) return 3;
    }
    F.terminar();
}

