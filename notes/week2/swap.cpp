// swap.cpp

#include <iostream>

using namespace std;

// a and b are passed by reference, i.e. the function has access to the original
// variables, not copies of them.
void swap(int& a, int& b)
{
    int temp = a;
    a        = b;
    b        = temp;
}

// a and b are passed by value, i.e. the function has access to copies of the
// original variables, so the originals are not changed
void bad_swap(int a, int b)
{
    int temp = a;
    a        = b;
    b        = temp;
}

int main()
{
    int a = 2;
    int b = 3;
    cout << "a=" << a << ", b=" << b << '\n'; // 2 3
    bad_swap(a, b);
    cout << "a=" << a << ", b=" << b << '\n';
}
