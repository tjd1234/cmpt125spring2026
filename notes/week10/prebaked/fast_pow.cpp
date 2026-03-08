// fast_pow.cpp

//
// This calculates a^n using this recurrence relation:
//
//    a^0      = 1
//    a^(2k)   = a^k * a^k
//    a^(2k+1) = a * a^k * a^k
//

#include <cassert>
#include <iostream>

using namespace std;

int fast_pow(int a, int n)
{
    assert(a > 1);
    assert(n >= 0);

    if (n == 0) // base case
    {
        return 1;
    }
    else if (n % 2 == 0) // even case
    {
        int half = fast_pow(a, n / 2);
        return half * half;
    }
    else // odd case
    {
        int half = fast_pow(a, (n - 1) / 2);
        return a * half * half;
    }
}

void fast_pow_test()
{
    cout << "Testing fast_pow..." << endl;
    assert(fast_pow(2, 0) == 1);
    assert(fast_pow(2, 1) == 2);
    assert(fast_pow(2, 2) == 4);
    assert(fast_pow(2, 3) == 8);
    assert(fast_pow(2, 4) == 16);
    assert(fast_pow(2, 5) == 32);
    assert(fast_pow(2, 6) == 64);
    assert(fast_pow(2, 7) == 128);
    assert(fast_pow(2, 8) == 256);
    assert(fast_pow(2, 9) == 512);
    assert(fast_pow(2, 10) == 1024);
    cout << "fast_pow_test: all tests passed" << endl;
}

int main()
{
    fast_pow_test();
}