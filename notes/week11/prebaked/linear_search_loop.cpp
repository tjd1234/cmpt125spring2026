// linear_search.cpp

#include "linear_search_test.h"
#include <vector>

using namespace std;

// // for-loop
// int linear_search(int x, const vector<int>& v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (v[i] == x)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// while-loop version
int linear_search(int x, const vector<int>& v)
{
    int i = 0;
    while (i < v.size()) {
        if (v[i] == x) {
            return i;
        }
        i++;
    }
    return -1;
}

int main()
{
    linear_search_test();
}
