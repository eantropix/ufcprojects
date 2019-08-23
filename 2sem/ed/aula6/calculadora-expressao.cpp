#include <iostream>
#include <new>

using std::cin; using std::cout; using std::nothrow;

int main()
{
    int n; do {cout << "n: "; cin >> n;} while (n <= 0);
    char c; cin.get(c); cout << "Digite a expressão: ";
    double *vnum = new(nothrow) double[n];
    char *vop = new(nothrow) char[n];
    if (vnum == nullptr) return 1;
    if (vop == nullptr) return 2;

    int ultnum = -1; int ultop = -1;
    for (;;)
    {
        cin.get(c);
        if (c == '\n') break;
        else if (c == '(' || c == ' ') continue;
        else if (c >= '0' && c <= '9')
        {
            int num = 0;
            for(;;)
            {
                num = num * 10 + (c - '0');
            }
        }
    }

    delete[] vnum;
    delete[] vop;

}