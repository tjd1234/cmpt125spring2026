// max_d.cpp

#include "max_test.h"
#include <cassert>

using namespace std;

int max(const vector<int>& v)
{
    int max_value = v[0];  // 1
    int i         = 1;     // 1
    while (i < v.size())   // about n
    {
        if (v[i] > max_value) // about n
        {
            max_value = v[i]; // 0 to n-1, n/2 ?
        }
        i++; // about n
    }
    return max_value; // 1
}

int main()
{
    max_test();
}
