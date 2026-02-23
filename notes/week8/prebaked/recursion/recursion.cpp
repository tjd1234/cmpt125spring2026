// recursion.cpp

#include <iostream>

using namespace std;

void f(int n) {
    cout << n << ": hello!\n";
    f(n + 1);
}

int main() {
    f(5);
}
