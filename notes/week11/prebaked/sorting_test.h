// sorting_test.h

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Returns true if v is in ascending sorted order, and false otherwise. An empty
// vector is considered to be sorted.
bool is_sorted(const vector<int>& v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] > v[i])
            return false;
    }
    return true;
}

ostream& operator<<(ostream& os, const vector<int>& v)
{
    os << "{";
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0)
            os << ", ";
        os << v[i];
    }
    os << "}";
    return os;
}

struct Test_case
{
    string description;
    vector<int> input;
    vector<int> expected;
};

vector<Test_case> all_tests = {
    {"empty vector", {}, {}},
    {"single element", {1}, {1}},
    {"two elements, in order", {2, 1}, {1, 2}},
    {"two elements, reversed", {1, 2}, {1, 2}},
    {"two elements, equal", {1, 1}, {1, 1}},
    {"three elements, in order", {1, 2, 3}, {1, 2, 3}},
    {"three elements, reversed", {3, 2, 1}, {1, 2, 3}},
    {"three elements, mixed", {1, 3, 2}, {1, 2, 3}},
    {"three elements, two equal sorted", {1, 2, 2}, {1, 2, 2}},
    {"three elements, two equal mixed", {2, 1, 2}, {1, 2, 2}},
    {"three elements, all equal", {3, 3, 3}, {3, 3, 3}},
    {"four elements, all equal", {7, 7, 7, 7}, {7, 7, 7, 7}},
    {"five elements, in order", {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},
    {"five elements, reverse order", {5, 4, 3, 2, 1}, {1, 2, 3, 4, 5}},
    {"five elements, two equal mixed", {1, 2, 1, 2, 1}, {1, 1, 1, 2, 2}},
    {"seven elements, mixed", {10, -1, 0, 3, 2, 2, -10}, {-10, -1, 0, 2, 2, 3, 10}},
    {"nine elements, 3 blocks", {3, 3, 3, 1, 1, 1, 2, 2, 2}, {1, 1, 1, 2, 2, 2, 3, 3, 3}}};

using SortFn = vector<int>(vector<int>);

void test_sort(const string& sort_name, SortFn sort)
{
    cout << "Calling " << sort_name << " ..." << endl;
    int failed = 0;
    for (const Test_case& tc : all_tests)
    {
        vector<int> result = sort(tc.input);
        if (result != tc.expected)
        {
            cout << "Test case failed: " << tc.description << endl;
            cout << "           Input: " << tc.input << endl;
            cout << "        Expected: " << tc.expected << endl;
            cout << "             Got: " << result << endl;
            cout << endl;
            failed++;
        }
    }
    int passed = all_tests.size() - failed;
    cout << "...  " << sort_name << " done, " << passed << "/" << all_tests.size()
         << " test cases passed" << endl;
}
