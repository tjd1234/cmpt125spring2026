// selection_sort.cpp

#include "sorting_test.h"

// returns the index of the smallest in in v start at begin
int index_of_min(const vector<int>& v, int begin)
{
    int min_index = begin;
    for (int i = begin + 1; i < v.size(); i++)
    {
        if (v[i] < v[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}

// selection sort
vector<int> selection_sort(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int min_index = index_of_min(v, i);
        swap(v[i], v[min_index]);
    }
    return v;
}

int main()
{
    test_sort("selection sort", selection_sort);
}
