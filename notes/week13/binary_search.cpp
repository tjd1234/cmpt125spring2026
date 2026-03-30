// binary_search.cpp

#include "binary_search_test.h"

using namespace std;

// Pre-condition:
//   v[begin] to v[end - 1] is in ascending sorted order
// Post-condition:
//   returns an index i such that v[i] == x and
//   begin <= i < end;
//   if x is not found, -1 is returned
int binary_search(int x, const vector<int>& v, int begin, int end)
{
    while (begin < end)
    {
        int mid = (begin + end) / 2;
        if (v[mid] == x)
        { // found x!
            return mid;
        }
        else if (x < v[mid])
        {
            end = mid;
        }
        else
        { // x > v[mid]
            begin = mid + 1;
        }
    }
    return -1; // x not found
}

// Pre-condition:
//    v is in ascending sorted order
// Post-condition:
//    returns an index i such that v[i] == x; if x is
//    not in v, -1 is returned
int binary_search(int x, const vector<int>& v)
{
    return binary_search(x, v, 0, v.size());
}

//
// Recursive binary search
//

int binary_search_rec(int x, const vector<int>& v, int begin, int end)
{
    int n = end - begin;

    // if the sub-vector being searched is empty,
    // then x is not in it
    if (n <= 0)
        return -1; // x not found

    int mid = (begin + end) / 2;
    if (x == v[mid])
    {
        return mid;
    }
    else if (x < v[mid])
    {
        return binary_search_rec(x, v, begin, mid);
    }
    else
    {
        return binary_search_rec(x, v, mid + 1, end);
    }
}

// Pre-condition:
//    v is in ascending sorted order
// Post-condition:
//    returns an index i such that v[i] == x;
//    if x is not in v, -1 is returned
int binary_search_rec(int x, const vector<int>& v)
{
    return binary_search_rec(x, v, 0, v.size());
}

int main()
{
    binary_search_test("binary_search", binary_search);
    binary_search_test("binary_search_rec", binary_search_rec);
}