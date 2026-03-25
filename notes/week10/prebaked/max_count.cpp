// max_count.cpp

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int max_change_count = 0;

int max(const vector<int>& v)
{
    int max_value = v[0];
    int i         = 1;
    while (i < v.size())
    {
        if (v[i] > max_value)
        {
            max_value = v[i];
            max_change_count++;
        }
        i++;
    }
    return max_value;
}

vector<int> rand_vec(int n)
{
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        // rand() returns a random int from 0 to RAND_MAX
        result[i] = rand();
    }
    return result;
}

int main()
{
    // set the seed for the random number generator to the current time (from
    // <ctime>)
    srand(time(NULL));

    const int n = 1000000;
    for (int i = 0; i < 5; i++)
    {
        vector<int> v    = rand_vec(n);
        max_change_count = 0;
        max(v);
        cout << "n = " << n << ", max_change_count = " << max_change_count << endl;
    }
}
