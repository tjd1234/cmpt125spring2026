// linear_search_test.h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// declarations for linear_search
int linear_search(int x, const vector<int>& v);

struct Test_case
{
    string description;
    vector<int> input_vec;
    int target;
    int expected_output;
};

//
// IMPORTANT: These test cases do NOT check for duplicates (since the definition
// of linear search being used doesn't way which index to return when there are
// duplicates).
//
vector<Test_case> all_tests = {
    {"empty vector", {}, 2, -1},
    {"single element found", {1}, 1, 0},
    {"single element not found", {1}, 2, -1},
    {"two elements, first found", {1, 2}, 1, 0},
    {"two elements, second found", {1, 2}, 2, 1},
    {"two elements, not found", {1, 2}, 3, -1},
    {"many elements, start found", {4, 3, 2, 1, 5}, 4, 0},
    {"many elements, end found", {4, 3, 2, 1, 5}, 5, 4},
    {"many elements, middle found", {4, 3, 2, 1, 5}, 2, 2},
    {"many elements, not found", {4, 3, 2, 1, 5}, 0, -1},
};

void linear_search_test()
{
    cout << "Calling linear_search_test ..." << endl;
    int failed = 0;
    for (Test_case tc : all_tests)
    {
        int actual_output = linear_search(tc.target, tc.input_vec);
        if (actual_output != tc.expected_output)
        {
            failed++;
            cout << "Test case FAILED: " << tc.description << endl;
            cout << "        Expected: " << tc.expected_output << endl;
            cout << "             Got: " << actual_output << endl;
        }
    }

    int n      = all_tests.size();
    int passed = n - failed;
    cout << "linear_search_test: " << passed << "/" << n << " tests passed" << endl;
}
