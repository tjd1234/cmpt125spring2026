// swap_demo.cpp

#include <iostream>

using namespace std;

// wrong: a and b are passed by value
void swap1_bad(int a, int b)
{
    int temp = a;
    a        = b;
    b        = temp;
}

void swap1_bad_demo()
{
    cout << "swap1_bad_demo() ...\n";
    int x = 2;
    int y = 5;

    cout << "x: " << x << "  "; // 2
    cout << "y: " << y << "\n"; // 5

    swap1_bad(x, y);

    cout << "x: " << x << "  "; // 2
    cout << "y: " << y << "\n"; // 5

    // x and y are not swapped! That's because they are passed by value.
    // swap1_bad swaps the copies of x and y, but the original x and y values
    // are not changed.
}

// a and b are passed by value, but they are pointers to ints and so while the
// pointer values are copied, the values they point to are not copied
void swap2(int* a, int* b)
{
    int temp = *a;
    *a       = *b;
    *b       = temp;
}

void swap2_demo()
{
    cout << "swap2_demo() ...\n";
    int x = 2;
    int y = 5;

    cout << "x: " << x << "  "; // 2
    cout << "y: " << y << "\n"; // 5

    swap2(&x, &y); // note the &: must pass the addresses of x and y

    cout << "x: " << x << "  "; // 5
    cout << "y: " << y << "\n"; // 2
}

// a and b are passed by reference; we treat a and b as if they were
// regular ints
void swap3(int& a, int& b)
{
    int temp = a;
    a        = b;
    b        = temp;
}

void swap3_demo()
{
    cout << "swap3_demo() ...\n";
    int x = 2;
    int y = 5;

    cout << "x: " << x << "  "; // 2
    cout << "y: " << y << "\n"; // 5

    swap3(x, y); // no & needed: pass by reference lets us pass x and y directly

    cout << "x: " << x << "  "; // 5
    cout << "y: " << y << "\n"; // 2
}

int main()
{
    // swap1_bad_demo();
    // swap2_demo();
    swap3_demo();
}
