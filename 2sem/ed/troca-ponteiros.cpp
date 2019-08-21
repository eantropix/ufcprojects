#include <iostream>

using std::cout;

int main()
{
    int a = 2;
    int b = 4;
    int *p1 = &a;
    int *p2 = &b;
    cout << "Ponteiro de A: " << *p1 << "\n";
    cout << "Endereço de A: " << p1 << "\n";
    cout << "Ponteiro de B: " << *p2 << "\n";
    cout << "Endereço de B: " << p2 << "\n";
    int p3 = *p1;
    *p1 = *p2;
    *p2 = p3;
    cout << "Ponteiro de A: " << *p1 << "\n";
    cout << "Endereço de A: " << p1 << "\n";
    cout << "Ponteiro de B: " << *p2 << "\n";
    cout << "Endereço de B: " << p2 << "\n";
}
