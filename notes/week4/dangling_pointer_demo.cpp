// dangling_pointer_demo.cpp

#include <iostream>

using namespace std;

void dangling_pointer_demo1()
{
    cout << "dangling_pointer_demo1 ...\n";

    int* p = new int(25); // p points to a new int on the
                          // free store

    // ... do things with p ...

    delete p; // Okay: we're done with p so we de-allocate the memory it points
              // to. But: p is now a dangling pointer, i.e. the memory it points
              // to is de-allocated and should not be used in any way

    *p = 42; // ERROR! The memory p points to is not allocated, so this is not
             // allowed. While it *may* appear to work correctly (the next cout
             // line may print 42), it writes to memory we are not allowed to
             // write to.

    cout << "*p: " << *p // ERROR! Prints 42 for me. But that p points to  is
         << "\n";        // not allocated, and so there is no guarantee what is
                         // there. It may be 42, but it may be something else.
}

void dangling_pointer_demo2()
{
    cout << "dangling_pointer_demo2 ...\n";

    int* p = new int(25); // p points to a new int on the
                          // free store

    // ... do things with p ...

    delete p; // Okay: we're done with p so we de-allocate the memory it points
              // to. But: p is now a dangling pointer, i.e. the memory it points
              // to is de-allocated and should not be used in any way

    *p = 42; // ERROR! The memory p points to is not allocated, so this is not
             // allowed. While it *may* appear to work correctly (the next cout
             // line may print 42), it writes to memory we are not allowed to
             // write to.

    cout << "*p: " << *p // ERROR! Prints 42 for me. But that p points to  is
         << "\n";        // not allocated, and so there is no guarantee what is
                         // there. It may be 42, but it may be something else.
}

int main()
{
    dangling_pointer_demo1();
    // dangling_pointer_demo2();
}
