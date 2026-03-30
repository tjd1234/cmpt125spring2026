// binary_search_test.h

#pragma once

#include <iostream>
#include <vector>
using namespace std;

struct Test_case
{
    string description;
    vector<int> input; // in ascending sorted order
    int target;
    int expected_output;
};

vector<Test_case> all_tests = {
    {"empty vector", {}, 2, -1},
    {"single element found", {1}, 1, 0},
    {"single element not found", {1}, 2, -1},
    {"two elements, first found", {1, 3}, 1, 0},
    {"two elements, second found", {1, 3}, 3, 1},
    {"two elements, not found left", {1, 3}, 0, -1},
    {"two elements, not found mid", {1, 3}, 2, -1},
    {"two elements, not found right", {1, 3}, 4, -1},
    {"bigger list, found left", {3, 5, 7, 10, 15, 20, 25}, 7, 2},
    {"bigger list, found mid", {3, 5, 7, 10, 15, 20, 25}, 15, 4},
    {"bigger list, found right", {3, 5, 7, 10, 15, 20, 25}, 20, 5},
    {"bigger list, not found left", {3, 5, 7, 10, 15, 20, 25}, 2, -1},
    {"bigger list, not found mid", {3, 5, 7, 10, 15, 20, 25}, 12, -1},
    {"bigger list, not found right", {3, 5, 7, 10, 15, 20, 25}, 26, -1},
};

using SearchFn = int (*)(int, const vector<int>&);

void binary_search_test(const string& fn_name, SearchFn binary_search)
{
    cout << "Testing " << fn_name << " ..." << endl;
    int failed = 0;
    for (Test_case tc : all_tests)
    {
        int actual_output = binary_search(tc.target, tc.input);
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
    cout << "...  " << fn_name << " testing done, " << passed << "/" << n << " test cases passed"
         << endl;
}
