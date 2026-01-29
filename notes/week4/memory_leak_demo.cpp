// memory_leak_demo.cpp

#include <iostream>

using namespace std;

void memory_leak_demo()
{
    int* p = new int(25); // p points to a new int on the free
                          // store

    // okay to use p ...
    cout << " p: " << p << "\n";
    cout << "*p: " << *p << "\n";

} // Error! We didn't de-allocate the memory p points to.
  // Running this with valgrind will catch the memory leak.

int main()
{
    memory_leak_demo();
}
