// arrays_freestore.cpp

#include <iostream>

using namespace std;

int main()
{
    // new allocates an array of size 5 ints on the free store
    int* a = new int[5];
    a[0] = 7;
    a[1] = -2;
    a[2] = 4;
    a[3] = 4;
    a[4] = 0;

    // or more compactly:
    // int* arr = new int[5] {7, -2, 4, 4, 0};

    cout << "\nprint the array using a loop\n";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << "\n";
    }

    // de-allocate the memory used by the array
    delete[] a;
}