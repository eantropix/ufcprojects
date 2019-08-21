#include <iostream>

using std::cout;

int main()
{
    char a = '1';
    char b = '2';
    char j = '4';     
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "a <= b? " << (a <= b) << '\n';
    cout << "b == a? " << (b == a) << '\n';
    char c = a + j;
    char d = a * b;
    char e = a / b;
    cout << "c: " << c << "\n";
    cout << "d: " << d << "\n"; 
    cout << "e: " << e << "\n"; 
}

