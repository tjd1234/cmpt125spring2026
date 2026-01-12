// recurse.cpp

// This code uses recursion to intentionally create a stack overflow. In theory
// it should run forever, but in practice it runs out of call stack memory.

#include <iostream>

using namespace std;

void recurse(int n) {
  if (n >= 0) {
    cout << "recurse(" << n << ")\n";
    recurse(n + 1);
  }
}

int main() { 
    recurse(0); 
    // never reached
}
