// max_a.cpp

#include "max_test.h"

using namespace std;

int max(const vector<int>& v)
{
    int max_value = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > max_value)
        {
            max_value = v[i];
        }
    }
    return max_value;
}


int main()
{
    max_test();
}
