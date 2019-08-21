#include <iostream>
#include <new>

using std::cin; using std::cout; using std::nothrow;

int main()
{
    int n; cout << "n: "; cin >> n;
    double *v == new(nothrow) double [n];
    if (v==NULLPTR) {cout << "Sem memória!\n"; return 1;}

    delete[] v; //Vectors need [] when using delete.

}
