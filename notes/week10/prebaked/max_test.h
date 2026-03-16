// max_test.h

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// declaration (not a definition!) of the max function
int max(const vector<int>& v);

struct Test_case
{
    string description;
    vector<int> input;
    int expected_output;
};

vector<Test_case> all_tests = {
    {"single element", {5}, 5},
    {"two elements, in order", {5, 2}, 5},
    {"two elements, reversed", {2, 5}, 5},
    {"two elements, equal", {5, 5}, 5},
    {"three in order", {1, 2, 3}, 3},
    {"three reversed", {3, 2, 1}, 3},
    {"three in middle", {1, 3, 2}, 3},
    {"two threes a", {1, 3, 3}, 3},
    {"two threes b", {3, 1, 3}, 3},
    {"two threes c", {3, 3, 1}, 3},
    {"three threes", {3, 3, 3}, 3},
    {"six random elements", {6, 9, 8, 0, 3, 3, 6}, 9},
};

void max_test()
{
    cout << "Calling max_test ..." << endl;
    int failed = 0;
    for (Test_case tc : all_tests)
    {
        int actual_output = max(tc.input);
        if (actual_output != tc.expected_output)
        {
            failed++;
            cout << "Test case FAILED: " << tc.description << endl;
            cout << "        Expected:" << tc.expected_output << endl;
            cout << "             Got: " << actual_output << endl;
        }
    }
    int n      = all_tests.size();
    int passed = n - failed;
    cout << "max_test: " << passed << "/" << n << " tests passed" << endl;
}
