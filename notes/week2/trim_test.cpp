// trim_test.cpp

// " cat  " -> "cat"   leading and trailing spaces
// " cat  dog " -> "cat  dog"   spaces in the middle are not changed
// "  puppy" -> "puppy"   leading spaces only
// "puppy   " -> "puppy"   trailing spaces only
// "puppy" -> "puppy"   no leading/trailing spaces
// "        " -> ""   just spaces
// "" -> ""   always test the empty string

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

// // version 0: no implementation
// string trim(const string& s)
// {
//     // find the first non-space character
//     // find the last non-space character
//     // return the substring between the first and last non-space characters
//     return s;
// }

// version 1: has an error
// string trim(const string& s)
// {
//     int n = s.size();
//     // find the first non-space character
//     int first = 0;
//     while (first < n && s[first] == ' ')
//     {
//         first++;
//     }
//     // find the last non-space character
//     int last = n - 1;
//     while (last >= 0 && s[last] == ' ')
//     {
//         last--;
//     }
//     // return the substring between the first and last non-space characters
//     return s.substr(first, last - first);
// }

// version 2: passes all tests
string trim(const string& s)
{
    int n = s.size();
    // find the first non-space character
    int first = 0;
    while (first < n && s[first] == ' ')
    {
        first++;
    }
    // find the last non-space character
    int last = n - 1;
    while (last >= 0 && s[last] == ' ')
    {
        last--;
    }
    // return the substring between the first and last non-space characters
    string result = s.substr(first, last - first + 1);
    return result;
}

void test_ifs()
{
    cout << "Testing trim with if-statements ..." << endl;
    if (trim(" cat  ") != "cat")
    {
        throw runtime_error("test failed");
    }
    if (trim(" cat  dog ") != "cat  dog")
    {
        throw runtime_error("test failed");
    }
    if (trim("  puppy") != "puppy")
    {
        throw runtime_error("test failed");
    }
    if (trim("puppy   ") != "puppy")
    {
        throw runtime_error("test failed");
    }
    if (trim("puppy") != "puppy")
    {
        throw runtime_error("test failed");
    }
    if (trim("        ") != "")
    {
        throw runtime_error("test failed");
    }
    if (trim("") != "")
    {
        throw runtime_error("test failed");
    }
    cout << "All if-statements tests passed!\n";
}

void test_asserts()
{
    cout << "Testing trim with assert statements ...\n";
    assert(trim(" cat  ") == "cat");
    assert(trim(" cat  dog ") == "cat  dog");
    assert(trim("  puppy") == "puppy");
    assert(trim("puppy   ") == "puppy");
    assert(trim("puppy") == "puppy");
    assert(trim("        ") == "");
    assert(trim("") == "");
    cout << "All assert tests passed!\n";
}

struct Testcase
{
    string input;
    string expected_output;
};

vector<Testcase> all_tests = {
    Testcase{" cat  ", "cat"},
    Testcase{" cat  dog ", "cat  dog"},
    Testcase{"  puppy", "puppy"},
    Testcase{"puppy   ", "puppy"},
    Testcase{"puppy", "puppy"},
    Testcase{"        ", ""},
    Testcase{"", ""},

    // // more test cases
    // Testcase{" ", ""},                // Single space
    // Testcase{"  ", ""},               // Two spaces
    // Testcase{"   ", ""},              // Three spaces
    // Testcase{"a", "a"},               // Single character, no spaces
    // Testcase{" a ", "a"},             // Single character with spaces
    // Testcase{" a", "a"},              // Single character, leading space
    // Testcase{"a ", "a"},              // Single character, trailing space
    // Testcase{"  a  ", "a"},           // Single character, multiple spaces
    // Testcase{"ab", "ab"},             // Two characters, no spaces
    // Testcase{" ab ", "ab"},           // Two characters with spaces
    // Testcase{"a b", "a b"},           // Two characters with space in middle
    // Testcase{"  a b  ", "a b"},       // Two words with multiple spaces
    // Testcase{"a  b", "a  b"},         // Multiple spaces in middle (should be preserved)
    // Testcase{"   a   b   ", "a   b"}, // Multiple spaces everywhere
    // Testcase{"cat\tdog", "cat\tdog"}, // Tab in middle (should be preserved)
};

string quote(const string& s)
{
    return "\"" + s + "\"";
}

void test_table()
{
    cout << "Testing trim with table ...\n";
    const int n = all_tests.size();
    int passed  = 0;
    for (int i = 0; i < n; i++)
    {
        const Testcase tc = all_tests[i];
        cout << "Test " << i << ": trim(" << quote(tc.input) << ") ... ";
        string actual = trim(tc.input);
        if (actual == tc.expected_output)
        {
            passed++;
            cout << "passed\n";
        }
        else
        {
            cout << "failed:\n"
                 << "        expected " << quote(tc.expected_output) << "\n"
                 << "        returned " << quote(actual) << "\n";
        }
    }
    if (passed == n)
    {
        cout << "All " << n << " table tests passed!\n";
    }
    else
    {
        cout << "Testing done: " << passed << "/" << n << " tests passed.\n";
    }
}

int main()
{
    // test_ifs();
    // test_asserts();
    test_table();
}
