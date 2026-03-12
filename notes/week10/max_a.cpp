// max_a.cpp

#include <cassert>
#include "max_test.h"

using namespace std;

int max(const vector<int>& v)
{
    int result = v[0];
    for(int i = 1; i < v.size(); i++) {
        if (v[i] > result) {
            result = v[i];
        }
    }
    return result;
}


int main()
{
    max_test();
}
