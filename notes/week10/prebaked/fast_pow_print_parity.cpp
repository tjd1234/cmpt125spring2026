// fast_pow_print_parity.cpp

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

int mult_count = 0;

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
        cout << "E";
        mult_count += 1;
        return half * half;
    }
    else // odd case
    {
        int half = fast_pow(a, (n - 1) / 2);
        cout << "O";
        mult_count += 2;
        return a * half * half;
    }
}


int main()
{
    for(int i = 0; i <= 10; i++)
    {
        mult_count = 0;
        int result = fast_pow(2, i);
        cout << " 2^" << i << " = " << result << ": " << mult_count << " multiplications" << endl;
    }
}
