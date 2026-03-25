// max_b.cpp

#include "max_test.h"

using namespace std;

int max(const vector<int>& v, int begin, int end)
{
    int max_value = v[begin];
    for (int i = begin + 1; i < end; i++)
    {
        if (v[i] > max_value)
        {
            max_value = v[i];
        }
    }
    return max_value;
}

int max(const vector<int>& v)
{
    return max(v, 0, v.size());
}

int main()
{
    max_test();
}
