#include <iostream>
#include <new>

using std::cin; using std::cout; using std::nothrow;

int main()
{
    int n;
    cout << "Numero de alunos: "; cin >> n;
    double v = new double[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "\nAluno " << i << ": "; cin >> v[i];
        
    }
}

