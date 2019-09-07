#include <iostream>

using std::cout;

int main()
{
    int *pointer;
    int value;
    value = 10;
    cout << "Value: " << value << "\n";
    pointer = &value;
    cout << "Value was found by pointer at: " << pointer << "\n";
	    *pointer -= 3;
    cout << "Value is now: " << value << "\n";
    cout << "Pointer says: " << *pointer << "\n";

}
