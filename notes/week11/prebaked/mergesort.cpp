// mergesort.cpp

#include "sorting_test.h"
#include <cassert>
#include <vector>

using namespace std;

//
// Pre-condition:
//    is_sorted(left)
//    is_sorted(right)
// Post-condition:
//    returned vector is left and right merged, i.e. it is in
//    ascending sorted order and contains all strings in left and right
// Note on performance:
//    The for-loop runs n = left.size() + right.size() times, and each iteration
//    does at 1-3 comparisons. So the total amount of work is at most 3n
//    comparisons.
//
vector<int> merge(const vector<int>& left, const vector<int>& right)
{
    assert(is_sorted(left));
    assert(is_sorted(right));

    // create result vector big enough to hold all the elements of left and
    // right
    vector<int> result(left.size() + right.size(), 0);

    // a points to the first unplaced element in left
    // b points to the first unplaced element in right
    int a = 0;
    int b = 0;

    // merge the two vectors into the result vector by always appending the
    // smaller of the two unplaced elements; if one of the vectors is exhausted,
    // append the remaining elements of the other vector
    for (int i = 0; i < result.size(); i++)
    {
        if (a >= left.size()) // if left is all done, append right[b]
        {
            result[i] = right[b];
            b++;
        }
        else if (b >= right.size()) // if right is all done, append left[a]
        {
            result[i] = left[a];
            a++;
        }
        else if (left[a] < right[b]) // if left[a] < right[b], append left[a]
        {
            result[i] = left[a];
            a++;
        }
        else // if left[a] >= right[b], append right[b]
        {
            result[i] = right[b];
            b++;
        }
    }
    assert(is_sorted(result));
    return result;
}

// Returns a new vector<int> containing a copy of the elements of v
// from v[begin] to v[end - 1].
vector<int> slice(const vector<int>& v, int begin, int end)
{
    vector<int> result(end - begin, 0);
    for (int i = begin; i < end; i++)
    {
        result[i - begin] = v[i];
    }
    return result;
}

// Pre-condition:
//    none
// Post-condition:
//    v has been sorted into ascending order using mergesort
// Note:
//    Using slice is not as efficient as it could be because it makes
//    unnecessary copies of the vector being sorted. However it still runs quite
//    quickly, usually much faster than insertion sort.
void mergesort_in_place(vector<int>& v)
{
    if (v.size() <= 1)
        return; // base case

    int mid           = v.size() / 2;
    vector<int> left  = slice(v, 0, mid);
    vector<int> right = slice(v, mid, v.size());
    mergesort_in_place(left);
    mergesort_in_place(right);
    v = merge(left, right);
}

vector<int> mergesort(vector<int> v)
{
    mergesort_in_place(v);
    return v;
}

int main()
{
    test_sort("mergesort", mergesort);
}
