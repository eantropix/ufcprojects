/*Escreva um programa em C++ que leia do usuário uma expressão
aritmética envolvendo números naturais e as operações (+,-,*,/),
e retorne o resultado (racional) da expressão.

Restrição da entrada: A expressão possuirá todos os parênteses,
um par para cada operador, com apenas números naturais.

Exemplo de entrada: 
((5/2)+(0-3))*(((2-7)/10)/(2*5))

O número de fatores da expressão não é conhecido a priori. No caso, o programa
deve solicitar ao usuário, no início da execução, a digitação de um limite superior n para o número de caracteres da expressão.
*/

#include <iostream>
#include <new>

using std::cin; using std::cout;

int calculator(int a, int b, char op)
{
    char operations[4] = {'+', '-', '*', '/'};
    char opened = '(';
    char closed = ')';
 
}
