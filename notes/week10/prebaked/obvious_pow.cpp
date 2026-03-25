// obvious_pow.cpp

#include <cassert>
#include <iostream>

using namespace std;

//
// This calculates a^n by repeated multiplication.
//
int obvious_pow_loop(int a, int n)
{
    assert(a > 1);
    assert(n >= 0);

    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= a;
    }
    return result;
}

void obvious_pow_loop_test()
{
    cout << "Testing obvious_pow_loop..." << endl;
    assert(obvious_pow_loop(2, 0) == 1);
    assert(obvious_pow_loop(2, 1) == 2);
    assert(obvious_pow_loop(2, 2) == 4);
    assert(obvious_pow_loop(2, 3) == 8);
    assert(obvious_pow_loop(2, 4) == 16);
    assert(obvious_pow_loop(2, 5) == 32);
    assert(obvious_pow_loop(2, 6) == 64);
    assert(obvious_pow_loop(2, 7) == 128);
    assert(obvious_pow_loop(2, 8) == 256);
    assert(obvious_pow_loop(2, 9) == 512);
    assert(obvious_pow_loop(2, 10) == 1024);
    cout << "obvious_pow_loop_test: all tests passed" << endl;
}

//
// This calculates a^n using this recurrence relation:
//
//    a^0 = 1             base case
//    a^n = a * a^(n-1)   recursive case
//

int obvious_pow_recur(int a, int n)
{
    assert(a > 1);
    assert(n >= 0);

    if (n == 0) // base case
    {
        return 1;
    }
    else // recursive case
    {
        return a * obvious_pow_recur(a, n - 1);
    }
}

void obvious_pow_recur_test()
{
    cout << "Testing obvious_pow_recur..." << endl;
    assert(obvious_pow_recur(2, 0) == 1);
    assert(obvious_pow_recur(2, 1) == 2);
    assert(obvious_pow_recur(2, 2) == 4);
    assert(obvious_pow_recur(2, 3) == 8);
    assert(obvious_pow_recur(2, 4) == 16);
    assert(obvious_pow_recur(2, 5) == 32);
    assert(obvious_pow_recur(2, 6) == 64);
    assert(obvious_pow_recur(2, 7) == 128);
    assert(obvious_pow_recur(2, 8) == 256);
    assert(obvious_pow_recur(2, 9) == 512);
    assert(obvious_pow_recur(2, 10) == 1024);
    cout << "obvious_pow_recur_test: all tests passed" << endl;
}

int main()
{
    obvious_pow_loop_test();
    obvious_pow_recur_test();
}
