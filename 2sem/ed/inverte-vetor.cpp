#include <iostream>

using std::cin; using std::cout;

int main()
{
    double vetor[7];
    double invertido[7];
    for (int i = 0; i < 7; i++){
        cout << "Digite valor para entrar no vetor: ";
        cin >> vetor[i];
        cout << "\n";
        invertido[6 - i] = vetor[i];
    }
    for (int i = 0; i < 7; i++){
        cout << invertido[i] << " ";
    }
    double *p = &invertido[2];
    cout << "\n\n";
    cout << "Valor da posição 2: " << *p;
    p = p + 2;
    cout << "Valor da posição 4: " << *p;

}