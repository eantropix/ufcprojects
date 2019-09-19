// FEITO
#include <iostream>  
using std::cout;  
void trocar (int x, int y)  // O "void" significa "não retorna valor".
{
int copia_de_x = x;
x = y;  
y = copia_de_x;
}
void trocar2 (int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
int main ()
{
    int a = 1, b = 2;
    trocar(a,b);
    cout << "a: " << a << ", b: " << b << '\n';
    trocar2(&a, &b);
    cout << "a: " << a << ", b: " << b << '\n';
}