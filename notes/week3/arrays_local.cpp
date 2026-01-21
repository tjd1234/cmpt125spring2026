// arrays_local.cpp

#include <iostream>

using namespace std;

int main()
{
    int arr[] = {7, -2, 4, 4, 0};

    cout << "print the array using subscript notation\n";
    cout << arr[0] << "\n"; // 1
    cout << arr[1] << "\n"; // 2
    cout << arr[2] << "\n"; // 3
    cout << arr[3] << "\n"; // 4
    cout << arr[4] << "\n"; // 5

    cout << "\nprint the array using a loop\n";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << "\n";
    }

    cout << "\nprint the array using pointer arithmetic\n";
    cout << *(arr + 0) << "\n"; // 1
    cout << *(arr + 1) << "\n"; // 2
    cout << *(arr + 2) << "\n"; // 3
    cout << *(arr + 3) << "\n"; // 4
    cout << *(arr + 4) << "\n"; // 5

    cout << "\nprint the array using a pointer loop\n";
    for (int* p = arr; p < arr + 5; p++) {
        cout << *p << "\n";
    }

}