// max_d.cpp

#include "max_test.h"
#include <cassert>

using namespace std;

int max(const vector<int>& v)
{
    int max_value = v[0];
    int i         = 1;
    while (i < v.size())
    {
        if (v[i] > max_value)
        {
            max_value = v[i];
        }
        i++;
    }
    return max_value;
}

int main()
{
    max_test();
}
