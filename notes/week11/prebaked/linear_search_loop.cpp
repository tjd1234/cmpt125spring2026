// linear_search.cpp

#include "linear_search_test.h"
#include <vector>

using namespace std;

int linear_search(int x, const vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    linear_search_test();
}
