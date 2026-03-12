// max_c.cpp

#include "max_test.h"
#include <cassert>

using namespace std;

//
// A recursive implementation of the max function using this recurrence
// relation:
//
//    max({x}) = x                                // base case
//    max(v)   = (max of v[0]) and max(rest of v) // recursive case
//
int max(const vector<int>& v, int begin)
{
    // implement max using recursion
}

int max(const vector<int>& v)
{
    return max(v, 0);
}

int main()
{
    max_test();
}
