// linear_search_recur.cpp

#include "linear_search_test.h"
#include <vector>

using namespace std;

int linear_search_recur(int x, const vector<int>& v, int begin)
{
    if (begin >= v.size()) // base case: not found
    {
        return -1;
    }
    else if (v[begin] == x) // base case: found
    {
        return begin;
    }
    else
    {
        return linear_search_recur(x, v, begin + 1); // recursive case: not found
    }
}

int linear_search(int x, const vector<int>& v)
{
    return linear_search_recur(x, v, 0);
}

int main()
{
    linear_search_test();
}
