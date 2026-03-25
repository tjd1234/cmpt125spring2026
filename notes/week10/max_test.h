// max_test.h

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// declaration (not a definition!) of the max function
// Requirement: v.size() > 0
int max(const vector<int>& v);

struct Test_case
{
    string description;
    vector<int> input;
    int expected_output;
};

vector<Test_case> all_tests = {
    {"one element", {5}, 5},
    {"two sorted", {5, 8}, 8},
    {"two sorted", {5, 2}, 5},
    {"two same", {5, 5}, 5},

    {"one neg", {-5}, -5},
    {"two neg sorted", {-5, -8}, -5},
    {"two neg sorted", {-5, -2}, -2},
    {"two neg same", {-5, -5}, -5},
    {"big rand vec", {5, 4, 3, 6, 56, 3, 35, 35, 8, 9}, 56}
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
