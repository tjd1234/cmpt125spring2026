// max_c.cpp

#include "max_test.h"

using namespace std;

//
// A recursive implementation of the max function using this recurrence
// relation:
//
//    max({x}) = x                              // base case
//    max(v)   = max of v[0] and max(rest of v) // recursive case
//
int max(const vector<int>& v, int begin)
{
    if (v.size() - begin == 1)
    { // base case
        return v[begin];
    }
    else
    { // recursive case
        int rest_max = max(v, begin + 1);
        if (v[begin] > rest_max)
        {
            return v[begin];
        }
        else
        {
            return rest_max;
        }
    }
}

int max(const vector<int>& v)
{
    return max(v, 0);
}

int main()
{
    max_test();
}
