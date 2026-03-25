// linear_search_faster.cpp

#include "linear_search_test.h"
#include <vector>

using namespace std;

// Pre-condition:
//    x is in v (i.e. there exists some i such that v[i] == x)
// Post-condition:
//    returns the smallest i >= 0 such that v[i] == x
int location_of(int x, const vector<int>& v)
{
    int i = 0;
    while (v[i] != x)
        i++;
    return i;
}

// v is *not* const so that the end value can be
// temporarily modified by the algorithm.
int linear_search_faster(int x, vector<int>& v)
{
    int n = v.size();

    //
    // first check if the vector is empty or has one element
    //
    if (n == 0)
    {
        return -1;
    }
    else if (n == 1)
    {
        if (v[0] == x)
            return 0;
        else
            return -1;
    }
    else
    { // n >= 2 at this point

        //
        // if x is the last element then we're done
        //
        if (v[n - 1] == x)
        {
            return n - 1;
        }
        else
        { // v[n-1] != x at this point

            int last = v[n - 1]; // save the last element
            v[n - 1] = x;        // set the last element to x

            int i = location_of(x, v); // search for x

            v[n - 1] = last; // restore the last element
            if (i == n - 1)  // check which x was found
                return -1;   // x is not in v
            else
                return i;
        }
    }
}

int linear_search(int x, const vector<int>& v)
{
    vector<int> v_copy = v;
    return linear_search_faster(x, v_copy);
}

int main()
{
    linear_search_test();
}
