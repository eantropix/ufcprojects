#include <iostream>

using std::cin; using std::cout;

double v[4];

void printer(double v)
{
    for (int i = 0; i < 4; ++i)
	cout << v[i] << ' ';
}
void inverter(double *primeiro, double *ultimo)
{   
    double aux;
    for (int i = 0; i < 2; ++i)
    {
	printer(v);
	aux = *(primeiro+i);
	*(primeiro+i) = *(ultimo-i);
	*(ultimo-i) = aux;	
    }
    cout << '\n';;
}

int main()
{
    for (int i = 0; i < 4; ++i)
    {
	cout << "v[" << i << "]: "; cin >> v[i]; cout << '\n';
    }
    double *p = v;
    double *u = v+4;
    inverter(p, u);
   /* for (int i = 0; i < 4; ++i)
	cout << v[i] << ' ';*/
}
