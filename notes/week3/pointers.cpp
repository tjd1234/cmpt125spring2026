// pointers.cpp

#include <iostream>

using namespace std;

int main()
{
    char c = 'T';
    cout << "     c: " << c << "\n";         // T
    cout << "int(c): " << int(c) << "\n";    // 84
    cout << "    &c: " << (void*)&c << "\n"; // 0x7ffee572412a (or whatever the address is)

    // char* p = &c; // p is a char pointer that points to c
    // cout << "\n";
    // cout << "    *p: " << *p << "\n"; // T

    // cout << "\n";
    // *p = 'a';
    // cout << "*p = 'a';\n";
    // cout << "\n";
    // cout << "     c: " << c << "\n"; // a
    // cout << "    *p: " << *p << "\n"; // a
}
