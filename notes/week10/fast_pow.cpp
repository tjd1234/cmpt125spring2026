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

//    a^0      = 1
//    a^(2k)   = a^k * a^k
//    a^(2k+1) = a * a^k * a^k
int mult_count = 0;
int fast_pow(int a, int n)
{
    assert(a > 1);
    assert(n >= 0);

    if (n == 0)
        return 1; // base case
    if (n % 2 == 0)
    { // n is even
        cout << "0";
        int k  = n / 2;
        int ak = fast_pow(a, k);
        mult_count += 1;
        return ak * ak;
    }
    else
    { // n is odd
        cout << "1";
        int k = (n - 1) / 2;
        int ak = fast_pow(a, k);
        mult_count += 2;
        return a * ak * ak;
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
    // fast_pow_test();
    for(int i = 0; i <= 20; i++) {
        mult_count = 0;
        fast_pow(2, i);
        cout << "  2^" << i << ": " << mult_count << endl;
    }
}