// double_deletion_demo.cpp

#include <iostream>

using namespace std;

void double_deletion_demo1()
{
    int* p = new int(25); // ok: p points to a new int on the free
                          // store

    // okay to use p ...
    cout << " p: " << p << "\n";
    cout << "*p: " << *p << "\n";

    delete p; // ok: we're done with p, de-allocate it

    // At this point p is a dangling pointer, i.e. it is pointing
    // to de-allocated memory. We should not use it in any way for
    // anything,

    delete p; // ERROR! Deleting p again is a double deletion, and
              // is not allowed. It could corrupt the entire free
              // store memory system.
}

void double_deletion_demo2()
{
    int* a = new int(25); // a points to a new int on the free store
    int* b = a;           // b points to the same thing as a

    // use a and b, no problems
    cout << " a: " << a << "\n";
    cout << "*a: " << *a << "\n";

    cout << " b: " << b << "\n";
    cout << "*b: " << *b << "\n";

    delete a; // ok: we're done with a, so de-allocate it

    // At this point a and b are both dangling pointers, i.e. they are pointing
    // to de-allocated memory. We should not use them in any way for anything,

    delete b; // ERROR! b points to the same thing as a, so deleting b is a
              // double deletion!
}

int main()
{
    // double_deletion_demo1();
    double_deletion_demo2();
}
