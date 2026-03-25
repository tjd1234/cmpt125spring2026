// bubble_sort.cpp

#include "sorting_test.h"

// bubble sort
vector<int> bubble_sort(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
    return v;
}

int main()
{
    test_sort("bubble sort", bubble_sort);
}
