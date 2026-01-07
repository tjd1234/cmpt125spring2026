// for_each.cpp

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {5, 6, 3, -2, 0, 5};
    for (int n : nums)
    {
        cout << n << "\n";
    }
}