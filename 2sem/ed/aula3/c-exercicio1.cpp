#include <iostream>

using std::cout; using std::cin;

int contar_ocorrencias(double *v, int n, double x) //X é o número, N é o tamanho
{
    int num = 0;
    for(int i = 0; i < n; ++i)
    {
        if (v[i] == x)
            num++;
	
    }
    return num;
}

int main()
{
    double v[5] = {};
    double *p = v;
    double x;
    for (int i = 0; i < 5; ++i)
    {
	cout << "v[" << i << "]: ";
	cin >> v[i];
	cout << '\n';
    }
    cout << "Número a ser verificado: "; cin >> x;
    cout << "O número " << x << " aparece " << contar_ocorrencias(p, 5, x) << " vez(es).\n\n";
}
